#include "player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"

Player::Player() {
  setRect(0, 0, 100, 100);
  setFlags(QGraphicsItem::ItemIsFocusable);
  setFocus();
  timer = new QTimer;
  timer->setInterval(33);
  connect(timer, SIGNAL(timeout()), this, SLOT(update_state()));
  timer->start();
}

void Player::keyPressEvent(QKeyEvent *event) {
  qDebug() << "KEYPRESSED";
  switch (event->key()) {
  case Qt::Key::Key_Up: 
    direction.setY(-1);
    break;
  case Qt::Key::Key_Down: 
    direction.setY(1);
    break;
  case Qt::Key::Key_Left: 
    direction.setX(-1);
    break;
  case Qt::Key::Key_Right: 
    direction.setX(1);
    break;
  case Qt::Key::Key_Space: 
    shooting = true;
    break;
  }
  qDebug();
}

void Player::keyReleaseEvent(QKeyEvent *event) {
  switch (event->key()) {
  case Qt::Key::Key_Up: 
    direction.setY(0);
    break;
  case Qt::Key::Key_Down: 
    direction.setY(0);
    break;
  case Qt::Key::Key_Left: 
    direction.setX(0);
    break;
  case Qt::Key::Key_Right: 
    direction.setX(0);
    break;
  case Qt::Key::Key_Space: 
    shooting = false;
    break;
  }
}

void Player::update_state(){
  setPos(x() + direction.x() * speed, y() + direction.y() * speed);
  if (x() < 0) setX(0);
  if (x() > 700) setX(700);
  if (shooting) {
    if (shooting_time == 0) {
      Bullet *bullet = new Bullet();
      bullet->setPos(x()+45, y());
      scene()->addItem(bullet);
      shooting_time += 33;
    } else if (shooting_time > 1000){
      shooting_time = 0;
    } else 
      shooting_time += 33;
  } else {
    if (shooting_time > 0) {
      shooting_time += 33;
      if (shooting_time > 1000)
        shooting_time = 0;
    }
  }
}

