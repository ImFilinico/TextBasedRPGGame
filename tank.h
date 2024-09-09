#ifndef TANK_H
#define TANK_H

#include "robot.h"

class Tank : public Robot {
private:
  int armorPlates;
  
public:
  Tank(int, const string, int, int, int, int,int); //Tank overloaded constructor (xp,name,health,energy,level,damage,xp)


  //gerneral functions
  void repair(); //this function allows robot to gain health for a turn. parameter is health
  void charge(); //allows for robot to gain energy
  void gainXp();
  void setArmorPlates(int);
  int getArmorPlates();
  

  //combat functions
  void standardAttack(Robot& enemy); //all robots have a standard attack but they vary depending on what robot is chosen
  void gainLevel(); //when xp equals max x, the robot levels up and allows for player to increase a stat 

 

  void printInfo();

  void specialOne(Robot& enemy);
  void specialTwo(Robot& enemy);

  void loadProgressFromFile(string);
  void saveProgressToFile(string);
};

#endif