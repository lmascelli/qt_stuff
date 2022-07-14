#include "enemy.h"
#include <stdlib.h>
#include <QGraphicsScene>

Enemy::Enemy(){
  setPos(rand() % 700, -100);
  timer = new QTimer;
  timer->setInterval(33);
  connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

Enemy::~Enemy(){
  scene()->removeItem(this);
  delete timer;
  delete this;
}

void Enemy::move(){
  setY(y() + speed);
  if (y() > 600)
    delete this;
}
