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

    m_firstValue->setText("3");
    m_secondValue->setText("3");
}

void CalculatorWidget::valueChanged()
{
    QString firstValueText = m_firstValue->text();
    QString secondValueText = m_secondValue->text();
    bool isNumber1;
    bool isNumber2;
    int firstValue=firstValueText.toInt(&isNumber1);
    int secondValue=secondValueText.toInt(&isNumber2);
    int sum=firstValue+secondValue;
    QString result=QString::number(sum);
    if(isNumber1&&isNumber2){
        m_result->setText(result);
    }else{
        m_result->setText("no result");
    }

}
