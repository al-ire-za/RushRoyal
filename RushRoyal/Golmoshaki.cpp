#include "Golmoshaki.h"
#include "Agentbase.h"


Golmoshaki::Golmoshaki(QWidget *parent)
    :AgentBase(parent, ":/prefix2/images/golmoshaki2.png", 35, 1200)
{

}

Golmoshaki::Golmoshaki(const Golmoshaki &other)
    : AgentBase(other){

}

Golmoshaki::~Golmoshaki()
{

}
