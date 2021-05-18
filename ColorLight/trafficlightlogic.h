#ifndef TRAFFICLIGHTLOGIC_H
#define TRAFFICLIGHTLOGIC_H

#include <memory>

class CTrafficlightLogic;

class ITrafficLight
{
public:
    virtual ~ITrafficLight() = default;

public:
    enum class ELight
    {
        eRed, eYellow, eGreen
    };

    virtual ELight currentLight() const = 0;
    virtual void changeLight(CTrafficlightLogic* pLogic) = 0;
};

class CRedLight : public ITrafficLight
{
public:
    ELight currentLight() const override;
    void changeLight(CTrafficlightLogic* pLogic) override;
};

class CYellowLight : public ITrafficLight
{
public:
    ELight currentLight() const override;
    void changeLight(CTrafficlightLogic* pLogic) override;
};

class CGreenLight : public ITrafficLight
{
public:
    ELight currentLight() const override;
      void changeLight(CTrafficlightLogic* pLogic) override;
};

class CTrafficlightLogic
{
public:
    CTrafficlightLogic() = default;
    virtual ~CTrafficlightLogic() = default;

public:
    typedef std::shared_ptr<ITrafficLight> t_ptrTrafficLight;

    virtual void changeLight();
    virtual ITrafficLight::ELight currentLight() const;

    void setState(t_ptrTrafficLight pState);

private:
    t_ptrTrafficLight m_pState;
};

#endif // TRAFFICLIGHTLOGIC_H
