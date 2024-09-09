#ifndef ENEMY_H
#define ENEMY_H

#include "robot.h"

class Enemy : public Robot{
public:
  Enemy(string, int, int, int, int,int); 
  void repair();
  void charge();
  void gainXp();
  void standardAttack(Robot& other);
  void gainLevel();
  void printInfo();
  void specialOne(Robot& enemy);
  void specialTwo(Robot& enemy);
};
#endif