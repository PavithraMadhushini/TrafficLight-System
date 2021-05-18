#include "trafficlightlogic.h"

ITrafficLight::ELight CRedLight::currentLight() const
{
    return ELight::eRed;
}

void CRedLight::changeLight(CTrafficlightLogic *pLogic)
{
    if (pLogic != nullptr)
        pLogic->setState(std::make_shared<CYellowLight>());

}

ITrafficLight::ELight CYellowLight::currentLight() const
{
    return ELight::eYellow;
}

void CYellowLight::changeLight(CTrafficlightLogic *pLogic)
{
    if (pLogic != nullptr)
        pLogic->setState(std::make_shared<CGreenLight>());
}

ITrafficLight::ELight CGreenLight::currentLight() const
{
    return ELight::eGreen;
}

void CGreenLight::changeLight(CTrafficlightLogic *pLogic)
{
    if (pLogic != nullptr)
        pLogic->setState(std::make_shared<CRedLight>());
}

void CTrafficlightLogic::changeLight()
{
    if (m_pState != nullptr)
        m_pState->changeLight(this);
}

ITrafficLight::ELight CTrafficlightLogic::currentLight() const
{
    if (m_pState != nullptr)
        return  m_pState->currentLight();

    return ITrafficLight::ELight();
}

void CTrafficlightLogic::setState(CTrafficlightLogic::t_ptrTrafficLight pState)
{
    m_pState = pState;
}
