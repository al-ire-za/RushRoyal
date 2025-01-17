#ifndef BOMB_H
#define BOMB_H

#include "AgentBase.h"


namespace Ui {
class Bomb;
}

class Bomb : public AgentBase
{
    Q_OBJECT

public:
    Bomb(QWidget *parent = nullptr);
    Bomb(const Bomb &other);
    int getElixirCost() const override;
    void checkCollision(const QVector<Enemy*>& enemies);
    int getcollisionCount() const;
    QTimer* getTimer() const;
    virtual ~Bomb();
    void startTimer();
    int type() const override { return 5;}
    void setpowerkill(int pow);
    int getpowerkill() const;

signals:
    void removeEnemies(const QVector<Enemy*>& enemiesToRemove);
    void bombExpired(Bomb* bomb);
    void enemyKilledByBomb();

private slots:
    void onTimeout();

private:
    int collisionCount;
    int powerkill;
    QTimer *timerStart;
    Ui::Bomb *ui;


};

#endif // BOMB_H
