#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject
{
Q_OBJECT
public:
    explicit Calculator(QObject *parent = 0);

public slots:
    void numEntered(int);

    void clear();
    void allClear();

    void additionMode();
    void subtractionMode();
    void multiplicationMode();
    void divisionMode();
    void minusMode();

    void calculate();

signals:
    void displayChanged(QString);

private:
    double m_lastResult;
    double m_currentNumber;
    bool m_isAdding;
    bool m_isSubstracting;
    bool m_isMultiplying;
    bool m_isDivision;

};

#endif // CALCULATOR_H
