#include "Agentbase.h"
#include <QTimer>

AgentBase::AgentBase(QWidget *parent, const QString &imageUrl, int power, int firerate)
    : QLabel(parent), AgentBaseimageUrl(imageUrl), AgentBasePower(power), AgentBaseFireRate(firerate)

{
    updateimagUrl(imageUrl);
    fireTimer = new QTimer(this);
    connect(fireTimer, &QTimer::timeout, this, &AgentBase::shoot);
}

AgentBase::AgentBase(const AgentBase &other): AgentBasePower(other.AgentBasePower), AgentBaseFireRate(other.AgentBaseFireRate),
    AgentBaseimageUrl(other.AgentBaseimageUrl)
{
    updateimagUrl(other.AgentBaseimageUrl);
}

AgentBase::~AgentBase()
{

}

int AgentBase::getpower() const{
    return AgentBasePower;
}

double AgentBase::getspeed() const{
    return AgentBaseFireRate;
}

void AgentBase::updateimagUrl(const QString &image){
    AgentBaseimageUrl = image;
    setStyleSheet("background-image: url(" + image + "); background-color: rgb(238, 145, 84);");
}

void AgentBase::shoot() {
    emit bulletFired(AgentBasePower, geometry());
}

void AgentBase::startShooting(){
    fireTimer->start(AgentBaseFireRate);
}

void AgentBase::stopShooting() {
    fireTimer->stop();
}
