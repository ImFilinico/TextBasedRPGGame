#ifndef SCRAPPER_H
#define SCRAPPER_H
#include "robot.h"

using namespace std;

class Scrapper : public Robot {
private:
  int berzerkCharges;
public:
  Scrapper(int, const string, int, int, int, int,int);
  void setBerzerkCharges(int);
  int getBerzerkCharges();

  void repair(); //this function allows robot to gain health for a turn. parameter is health
  void charge(); //allows for robot to gain energy
  void gainXp();

  void standardAttack(Robot& enemy); //all robots have a standard attack but they vary depending on what robot is chosen
  void gainLevel(); //when xp equals max x, the robot levels up and allows for player to increase a stat 

  //special attacks

  void printInfo();

  void specialOne(Robot& enemy);
  void specialTwo(Robot& enemy);

  void loadProgressFromFile(string);
  void saveProgressToFile(string);
};
#endif