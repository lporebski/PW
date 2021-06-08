#include "calculatorinterface.h"
#include "ui_calculatorinterface.h"

#include <QSignalMapper>
#include "calculator.h"

CalculatorInterface::CalculatorInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorInterface),
    m_calculator(new Calculator(this))
{
    ui->setupUi(this);

    // Add code here
    QSignalMapper *m = new QSignalMapper(this);
    connect(ui->buttonOne, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->buttonOne, 1);
    connect(ui->buttonTwo, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->buttonTwo, 2);
    connect(ui->buttonThree, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->buttonThree, 3);
    connect(ui->buttonFour, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->buttonFour, 4);
    connect(ui->buttonFive, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->buttonFive, 5);
    connect(ui->buttonSix, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->buttonSix, 6);
    connect(ui->buttonSeven, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->buttonSeven, 7);
    connect(ui->buttonEight, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->buttonEight, 8);
    connect(ui->buttonNine, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->buttonNine, 9);
    connect(ui->buttonZero, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->buttonZero, 0);

    connect(m, SIGNAL(mapped(int)), m_calculator, SLOT(numEntered(int)));
    connect(m_calculator, SIGNAL(displayChanged(QString)), ui->entryLabel, SLOT(setText(QString)));
    connect(ui->buttonClear, SIGNAL(clicked()), m_calculator, SLOT(clear()));
    connect(ui->buttonAllClear, SIGNAL(clicked()), m_calculator, SLOT(allClear()));
    connect(ui->buttonAdd, SIGNAL(clicked()), m_calculator, SLOT(additionMode()));
    connect(ui->buttonSubtract, SIGNAL(clicked()), m_calculator, SLOT(subtractionMode()));
    connect(ui->buttonMulti, SIGNAL(clicked()), m_calculator, SLOT(multiplicationMode()));
    connect(ui->buttonDivision, SIGNAL(clicked()), m_calculator, SLOT(divisionMode()));
    connect(ui->buttonMinus, SIGNAL(clicked()), m_calculator, SLOT(minusMode()));
    connect(ui->buttonCalculate, SIGNAL(clicked()), m_calculator, SLOT(calculate()));

     m_calculator->allClear();
}

CalculatorInterface::~CalculatorInterface()
{
    delete ui;
}

void CalculatorInterface::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
