#ifndef SNIPER_H
#define SNIPER_H
#include "robot.h"

using namespace std;

class Sniper : public Robot{
private:
  int critChance;
  double critDamage;

public:
  Sniper(int, double, const string, int, int, int, int,int); //(critChance, critDamage)
  void setCritChance(int);
  int getCritChance();
  void setCritDamage(double);
  double getCritDamage();

  void repair(); //this function allows robot to gain health for a turn. parameter is health
  void charge(); //allows for robot to gain energy
  void gainXp();

  void standardAttack(Robot& enemy); //all robots have a standard attack but they vary depending on what robot is chosen
  void gainLevel(); //when xp equals max x, the robot levels up and allows for player to increase a stat

  //Special attacks
  void trickShot(Robot& enemy); //have a 30 percent chance to do a lot of damage, 70 percetn to do none
  void doubleShot(Robot& enemy); //attack twice for .75 damage but each has a chance to crit

  void printInfo();

  void specialOne(Robot& enemy);
  void specialTwo(Robot& enemy);

  void loadProgressFromFile(string);
  void saveProgressToFile(string);
};
#endif