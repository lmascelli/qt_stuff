#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"

class Game: public QGraphicsView {
  public:
    Game();

  private:
    QGraphicsScene *scene;
    Player *player;

};
