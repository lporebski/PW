#include "leaf.h"
#include <cmath>
#include <cstdlib>
TForm1 *Form1;
/* Render area coordinates */
float minX = -8.0;
float maxX =  8.0;
float minY = 11.0;
float maxY = -5.0;

/* IFS data */
float a[9];
float b[9];
float c[9];
float d[9];
float e[9];
float f[9];
float p[9];
int funCnt = 0;

/* add new function to IFS */
void addFunction(float paramA, float paramB, float paramC, float paramD,
   float paramE, float paramF, float paramP)
{
   if (funCnt < 9)
   {
      a[funCnt] = paramA;
      b[funCnt] = paramB;
      c[funCnt] = paramC;
      d[funCnt] = paramD;
      e[funCnt] = paramE;
      f[funCnt] = paramF;
      p[funCnt] = paramP;
   }
   funCnt++;
}

/* removes all functions */
void clearFunctions()
{
   funCnt = 0;
}

void SetFunctions()
{
   clearFunctions();
   switch(Form1->Function->ItemIndex+1) {
      case 1:
         addFunction(0.5, 0.0, 0.0, 0.5, -0.5,  0.5, 0.3333);
         addFunction(0.5, 0.0, 0.0, 0.5, -0.5, -0.5, 0.3333);
         addFunction(0.5, 0.0, 0.0, 0.5,  0.5, -0.5, 0.3333);
         minX = -1.0;
         maxX = 1.0;
         minY = -1.0;
         maxY = 1.0;
         break;
      case 2:
         addFunction(0.787879, -0.424242, 0.242424, 0.859848,  1.758647, 1.408065, 0.895652);
         addFunction(-0.121212, 0.257576, 0.151515, 0.053030, -6.721654, 1.377236, 0.052174);
         addFunction(0.181818, -0.136364, 0.090909, 0.181818,  6.086107, 1.568035, 0.052174);
         minX = -8.0;
         maxX =  8.0;
         minY = 11.0;
         maxY = -1.0;
         break;
      case 3:
         addFunction(0.824074, 0.281428, -0.212346,  0.864198, -1.882290, -0.110607, 0.787473);
         addFunction(0.088272, 0.520988, -0.463889, -0.377778,  0.785360,  8.095795, 0.212527);
         minX = -8.0;
         maxX =  8.0;
         minY = 11.0;
         maxY = -1.0;
         break;
      case 4:
         addFunction(0.0,   0.0,   0.0,   0.16,  0.0,  0.0,   0.01);
         addFunction(0.85,  0.04, -0.04,  0.85,  0.0,  1.6,   0.85);
         addFunction(0.2,  -0.26,  0.23,  0.22,  0.0,  1.6,   0.07);
         addFunction(-0.15, 0.28,  0.26,  0.24,  0.0,  0.44,  0.07);
         minX = -5.0;
         maxX =  5.0;
         minY = 10.5;
         maxY =  0.0;
         break;
      case 5:
         addFunction(0.1400,  0.0100,  0.0000, 0.5100, -0.0800, -1.3100, 0.20);
         addFunction(0.4300,  0.5200, -0.4500, 0.5000,  1.4900, -0.7500, 0.20);
         addFunction(0.4500, -0.4900,  0.4700, 0.4700, -1.6200, -0.7400, 0.20);
         addFunction(0.4900,  0.0000,  0.0000, 0.5100,  0.0200,  1.6200, 0.40);
         minX = -5.0;
         maxX =  5.0;
         minY =  5.0;
         maxY = -5.0;
         break;
      case 6:
         addFunction( 0.0500,  0.0000,  0.0000,  0.4000, -0.0600, -0.4700, 0.142);
         addFunction(-0.0500,  0.0000,  0.0000, -0.4000, -0.0600, -0.4700, 0.142);
         addFunction( 0.0300, -0.1400,  0.0000,  0.2600, -0.1600, -0.0100, 0.142);
         addFunction(-0.0300,  0.1400,  0.0000, -0.2600, -0.1600, -0.0100, 0.142);
         addFunction( 0.5600,  0.4400, -0.3700,  0.5100,  0.3000,  0.1500, 0.142);
         addFunction( 0.1900,  0.0700, -0.1000,  0.1500, -0.2000,  0.2800, 0.142);
         addFunction(-0.3300, -0.3400, -0.3300,  0.3400, -0.5400,  0.3900, 0.142);
         minX = -1.0;
         maxX =  1.0;
         minY =  1.0;
         maxY = -1.0;
         break;
   }
}
//---------------------------------------------------------------------------
void rysuj()
{
   float x, xtmp, y, ytmp, r;
   float ratioX, ratioY, prob, *data;
   int i, j, n, curr, biggest, level;

   /* initialize all variables */
   SetFunctions();
   ratioX = (maxX - minX) / (Fractal->Width * 1.0);
   ratioY = (maxY - minY) / (Fractal->Height * 1.0);
   data = new float[Fractal->Width*Fractal->Height];
   for (i=0; i<Fractal->Width*Fractal->Height; i++)
   {
      data[i] = 0;
   }

   x = 0;
   y = 0;

   /* Clear image */
   Fractal->Canvas->Brush->Color = clWhite;
   Fractal->Canvas->Rectangle(0, 0, Fractal->Width, Fractal->Height);
   Fractal->Canvas->Brush->Color = clBlack;

   n = StrToInt(IterNum->Text);

   randomize();

   for (i=0; i<n; i++)
   {
       /* Choose random function */
       r = rand() / (RAND_MAX * 1.0);
       curr = 0;
       prob = 0;
       for (j=0; j<funCnt; j++)
       {
          prob += p[j];
          if (prob > r)
          {
             curr = j;
             break;
          }
       }

       /* Perform calculation */
       xtmp = a[curr]*x + b[curr]*y + e[curr];
       ytmp = c[curr]*x + d[curr]*y + f[curr];
       x = xtmp;
       y = ytmp;

       /* Draw point */
       data[(int)((int)((x - minX)/ratioX) * Fractal->Width + ((y - minY)/ratioY))]++;
       ;
   }

   /* Check range */
   biggest = data[0];
   for (i=1; i<Fractal->Width * Fractal->Height; i++)
   {
      if (data[i] > biggest)
      {
         biggest = data[i];
      }
   }

   /* Generate image */
   for (i=0; i<Fractal->Height; i++)
   {
      for (j=0; j<Fractal->Width; j++)
      {
         if (data[j+i*Fractal->Width] > 0)
         {
            level = (log(data[j+i*Fractal->Width])/log(biggest))*0xff;
            Fractal->Canvas->Pixels[i][j] = (TColor)(0x80-level/2 <<  16) + (0xff-level << 8) + 0x80-level/2;
         }
      }
   }

   Fractal->Refresh();

   delete data;
}
