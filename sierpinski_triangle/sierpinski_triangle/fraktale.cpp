#include "fraktale.h"
#include <cmath>
#include <cstdlib>

void rysujFraktal(QPainter *painter){
    float A[2];
    float B[2];
    float C[2];
    float P[2];
    A[0]=200;
    A[1]=50;
    B[0]=50;
    B[1]=250;
    C[0]=350;
    C[1]=250;
    P[0]=0;
    P[1]=0;

    for (int i=0;i<100000; i++){
        int losuj=floor(rand()%3);
        switch(losuj){
        case 0:
            P[0]=(P[0]+A[0])/2;
            P[1]=(P[1]+A[1])/2;
            painter->setPen(Qt::red);
            break;
        case 1:
            P[0]=(P[0]+B[0])/2;
            P[1]=(P[1]+B[1])/2;
            painter->setPen(Qt::green);
            break;
        case 2:
            P[0]=(P[0]+C[0])/2;
            P[1]=(P[1]+C[1])/2;
            painter->setPen(Qt::blue);
            break;
        }
        painter->drawPoint(P[0],P[1]);
    }
}
