#pragma once

#include <QGraphicsRectItem>

class Bullet : public QObject, public QGraphicsRectItem {
  Q_OBJECT
public:
  Bullet();
  ~Bullet();

public slots:
  void move();

private:
  QTimer *timer;
};
