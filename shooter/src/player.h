#pragma once

#include <QGraphicsRectItem>
#include <QTimer>

class Player: public QObject, public QGraphicsRectItem {

  Q_OBJECT

  public:
    Player();

  public slots:
    void update_state();

  private:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    QTimer *timer;
    float speed = 10;
    QPoint direction = {0, 0};
    bool shooting = false;
    unsigned shooting_time = 0;
};
