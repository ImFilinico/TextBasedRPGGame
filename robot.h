#ifndef ROBOT_H
#define ROBOT_H
#include <string>
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class Robot{
private://protected variables all inherited classes need to share
  string name;
  int health;
  int maxHealth;
  int energy;
  int maxEnergy;
  int xp;
  int neededXp;
  int level;
  int damage;
  int combatOption;
public:
  Robot(); //default constructor
  Robot(const string, int, int, int, int, int); //Robot overloaded constructor (name,health,energy,level,damage,xp)
  
  //getters and setters
  string getName();
  void setHealth(int);
  int getHealth();
  void setMaxHealth(int);
  int getMaxHealth();
  void setEnergy(int);
  int getEnergy();
  void setMaxEnergy(int);
  int getMaxEnergy();
  void setXp(int);
  int getXp();
  void setNeededXp(int);
  int getNeededXp();
  void setDamage(int);
  int getDamage();
  void setLevel(int);
  int getLevel();
  void setCombatOption(int);
  int getCombatOption();

  //file work
  void saveProgressToFile(string filename); //puts all info about character in file
  void loadProgressFromFile(string filename); //loads progress from file

  //general character interaction functions, set to pure virtual because all inherited classes do the following
  virtual void repair() = 0; //this function allows robot to gain health for a turn. parameter is health
  virtual void charge() = 0; //allows for robot to gain energy
  virtual void gainXp() =0;

  //combat functions shared among the robots
  virtual void standardAttack(Robot& enemy) = 0; //all robots have a standard attack but they vary depending on what robot is chosen
  virtual void gainLevel() = 0; //when xp equals max x, the robot levels up and allows for player to increase a stat
  virtual void specialOne(Robot& enemy) =0;
  virtual void specialTwo(Robot& enemy) =0;
  //print info
  virtual void printInfo() =0;

//virtual tank specific
  void harmerArmor(Robot& enemy){};
  void plasterBlaster(Robot& enemy){};
  void setArmorPlates(int){};
  int getArmorPlates(){return 0;};

//virtual Scrapper specific
  int getBerzerkCharges(){return 0;};
  void setBerzerkCharges(int){};

//virtual Sniper Specific
  void setCritChance(int) {};
  int getCritChance() {return 0;};
  void setCritDamage(double){};
  double getCritDanmage(){return 0;};
};

#endif