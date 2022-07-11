#include "game.h"

Game::Game(){
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFixedSize(800, 600);
  scene = new QGraphicsScene;
  scene->setSceneRect(0, 0, 800, 600);

  player = new Player;
  player->setPos(400 - 50, 450);

  scene->addItem(player);
  setScene(scene);
}
