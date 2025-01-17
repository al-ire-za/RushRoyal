#ifndef AGENTBASE_H
#define AGENTBASE_H
#include "Enemy.h"
#include <QLabel>

namespace Ui {
class AgentBase;
}

class AgentBase : public QLabel
{
    Q_OBJECT

public:
    AgentBase(QWidget *parent = nullptr, const QString &imageUrl = "", int power = 10, int fireRate = 1, int elixirCost = 1);
    AgentBase(const AgentBase &other);
    virtual ~AgentBase();
    int getpower() const;
    double getspeed() const;
    void updateimagUrl(const QString &image);
    virtual int getElixirCost() const = 0;
    void startShooting();
    void stopShooting();
    bool isFrozen() const;
    void setFrozen(bool frozen);
    void setpower(int po);
    void setAgentBaseFireRate(double fire);
    double getAgentBaseFireRate();
    virtual int type() const = 0;
    void setlevelspeedup(int level);
    int getlevelspeedup();

protected:
    int AgentBasePower;
    int AgentBaseElixirCost;
    double AgentBaseFireRate;
    QString AgentBaseimageUrl;
    QTimer *shootTimer;


private:
    Ui::AgentBase *ui;
    int levelspeedup;
    bool frozen;
};

#endif // AGENTBASE_H
