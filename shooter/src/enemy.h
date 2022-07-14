#pragma once
#include <QGraphicsRectItem>
#include <QTimer>


class Enemy: public QObject, public QGraphicsRectItem
{
Q_OBJECT
  public:
  Enemy();
  ~Enemy();

  void move();

  private:
  QTimer *timer;
  float speed = 10;
};
