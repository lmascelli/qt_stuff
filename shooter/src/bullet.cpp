#include "bullet.h"
#include <QTimer>

Bullet::Bullet() {
  setRect(0, 0, 10, 50);
  timer = new QTimer;
  connect(timer, SIGNAL(timeout()), this, SLOT(move()));
  timer->start(50);
}

Bullet::~Bullet() { delete timer; }

void Bullet::move() {
  setY(y() - 10);
  if (y() < -this->rect().height())
    delete this;
}
