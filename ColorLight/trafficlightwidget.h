#ifndef TRAFFICLIGHTWIDGET_H
#define TRAFFICLIGHTWIDGET_H

#include <QWidget>
#include <QPaintEvent>

#include "trafficlightlogic.h"

class CTrafficlightWidget : public QWidget
{
    Q_OBJECT
public:
    CTrafficlightWidget(QWidget* pParent = nullptr);

    void Run();

protected:
    void paintEvent(QPaintEvent *event) override;

protected slots:
    void onTimerChange();

private:
    bool m_bRun = false;
    std::shared_ptr<CTrafficlightLogic> m_pLogic;
};

#endif // TRAFFICLIGHTWIDGET_H
