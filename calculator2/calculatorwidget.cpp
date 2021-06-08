#include "calculatorwidget.h"

#include <QHBoxLayout>
#include <QFont>

CalculatorWidget::CalculatorWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget( m_firstValue = new QLineEdit() );
    layout->addWidget( new QLabel("+") );
    layout->addWidget( m_secondValue = new QLineEdit() );
    layout->addWidget( new QLabel("=") );
    layout->addWidget( m_result = new QLabel() );

    QFont font = m_result->font();
    font.setBold(true);
    m_result->setFont(font);

    connect(m_firstValue, SIGNAL(textChanged(QString)), this, SLOT(valueChanged()));
    connect(m_secondValue, SIGNAL(textChanged(QString)), this, SLOT(valueChanged()));

    m_firstValue->setText("0");
    m_secondValue->setText("0");
}

void CalculatorWidget::valueChanged()
{
    QString firstValueText = m_firstValue->text();
    QString secondValueText = m_secondValue->text();
    bool number1, number2;
    int firstValue=firstValueText.toInt(&number1);
    int secondValue=secondValueText.toInt(&number2);
    int sum=firstValue+secondValue;
    if(number1&&number2){
        QString tmp=QString::number(sum);
        m_result->setText(tmp);
    }else{
        m_result->setText("no result");
    }





}
