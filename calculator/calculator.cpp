#include "calculator.h"

Calculator::Calculator(QObject *parent) :
    QObject(parent), m_lastResult(0), m_currentNumber(0), m_isAdding(true)

{
}

void Calculator::numEntered(int num)
{
    m_currentNumber = m_currentNumber*10 + num;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::clear()
{
    m_currentNumber = 0;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::allClear()
{
    m_isAdding = true;
    m_currentNumber = 0;
    m_lastResult = 0;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::additionMode()
{
    calculate();
    m_isAdding = true;
}

void Calculator::subtractionMode()
{
    calculate();
    m_isSubstracting = true;
}
void Calculator::multiplicationMode()
{
    calculate();
    m_isMultiplying=true;

}
void Calculator::divisionMode()
{
    calculate();
    m_isDivision=true;

}
void Calculator::minusMode()
{

    emit displayChanged("-"+QString::number(m_currentNumber));
    m_currentNumber*=-1;
}
void Calculator::calculate()
{
    if(m_isAdding){
        m_lastResult+=m_currentNumber;
    }
    if(m_isSubstracting){
        m_lastResult-=m_currentNumber;
    }
    if(m_isMultiplying){
        m_lastResult*=m_currentNumber;
    }
    if(m_isDivision){
        m_lastResult/=m_currentNumber;
    }

    m_isAdding = false;
    m_isSubstracting = false;
    m_isMultiplying = false;
    m_isDivision = false;
    m_currentNumber = 0;
    emit displayChanged(QString::number(m_lastResult));
}
