
#include "trafficlightwidget.h"

#include <QTimer>
#include <QPainter>

CTrafficlightWidget::CTrafficlightWidget(QWidget *pParent)
    : QWidget(pParent), m_pLogic(std::make_shared<CTrafficlightLogic>())
{
    resize(200, 600);
    if (m_pLogic != nullptr)
        m_pLogic->setState(std::make_shared<CRedLight>());
}

void CTrafficlightWidget::Run()
{
    m_bRun = true;

    QTimer* pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, this, &CTrafficlightWidget::onTimerChange);
    pTimer->start(5000);
}

void CTrafficlightWidget::paintEvent(QPaintEvent *pEvent)
{
    QRect rectTrafficLight = pEvent->rect();

    QPainter oPainter(this);
    oPainter.setPen(QPen(Qt::black));
    oPainter.setBrush(QBrush(Qt::black));
    oPainter.setRenderHint(QPainter::Antialiasing);

    oPainter.drawRect(rectTrafficLight);

    int iOffset = height() / 3;

    QRect rectRedLight = QRect(rectTrafficLight.left(), rectTrafficLight.top(), width(), iOffset);
    QRect rectYellowLight = QRect(rectTrafficLight.left(), rectTrafficLight.top() + iOffset, width(), iOffset);
    QRect rectGreenLight = QRect(rectTrafficLight.left(), rectTrafficLight.top() + (2 * iOffset), width(), iOffset);

    if (m_pLogic != nullptr)
    {
        oPainter.setBrush(QBrush("#ecf0f1", Qt::Dense1Pattern));

        switch (m_pLogic->currentLight())
          {
          case ITrafficLight::ELight::eRed:
          {
              oPainter.save();
              oPainter.setBrush(QBrush(Qt::red, Qt::Dense1Pattern));
              oPainter.drawEllipse(rectRedLight);
              oPainter.restore();

              oPainter.drawEllipse(rectYellowLight);
              oPainter.drawEllipse(rectGreenLight);
              break;
          }
          case ITrafficLight::ELight::eYellow:
          {
              oPainter.save();
              oPainter.setBrush(QBrush("#f39c12", Qt::Dense1Pattern));
              oPainter.drawEllipse(rectYellowLight);
              oPainter.restore();

              oPainter.drawEllipse(rectRedLight);
              oPainter.drawEllipse(rectGreenLight);
              break;
          }
          case ITrafficLight::ELight::eGreen:
          {
              oPainter.save();
              oPainter.setBrush(QBrush(Qt::green, Qt::Dense1Pattern));
              oPainter.drawEllipse(rectGreenLight);
              oPainter.restore();

              oPainter.drawEllipse((rectRedLight));
              oPainter.drawEllipse(rectYellowLight);
              break;
          }
        }
    }
}

void CTrafficlightWidget::onTimerChange()
{
    if (m_bRun && m_pLogic != nullptr)
        m_pLogic->changeLight();

    update();
}
