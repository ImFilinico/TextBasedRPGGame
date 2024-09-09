#include "robot.h"

Robot::Robot(){ //default constructor
  name = "";
  health = 1000;
  maxHealth = 1000;
  energy = 100;
  maxEnergy = 100;
  level = 1;
}

Robot::Robot(const string _name, int _health, int _energy, int _level , int _damage, int _xp){ //Robot overloaded constructor
  name = _name;
  health = _health;
  maxHealth = _health;
  energy = _energy;
  maxEnergy = _energy;
  level = _level;
  damage = _damage;
  xp = _xp;
} 
 //getters and setters

string Robot::getName(){
  return name;
}
void Robot::setHealth(int h){
  health = h;
}
int Robot::getHealth(){
  return health;
}
void Robot::setMaxHealth(int mh){
  maxHealth=mh;
}
int Robot::getMaxHealth(){
  return maxHealth;
}
void Robot::setEnergy(int e){
  energy =e;
}
int Robot::getEnergy(){
  return energy;
}
void Robot::setMaxEnergy(int me){
  maxEnergy = me;
}
int Robot::getMaxEnergy(){
  return maxEnergy;
}
void Robot::setXp(int _xp){
  xp = _xp;
}
int Robot::getXp(){
  return xp;
}
void Robot::setNeededXp(int nx){
  neededXp = nx;
}
int Robot::getNeededXp(){
  return neededXp;
}
void Robot::setDamage(int d){
  damage = d;
}
int Robot::getDamage(){
  return damage;
}
void Robot::setLevel(int l){
  level = l;
}
int Robot::getLevel(){
  return level;
}
void Robot::setCombatOption(int c){
  combatOption = c;
}
int Robot::getCombatOption(){
  return combatOption;
}
//file work
void Robot::saveProgressToFile(string filename){ //puts all info about character in file
  ofstream fout(filename);
  fout << name << endl;
  fout << health << endl;
  fout << maxHealth << endl;
  fout << energy << endl;
  fout << maxEnergy << endl;
  fout << xp << endl;
  fout << neededXp << endl;
  fout << damage << endl;
  fout << combatOption << endl;
  
  cout << "Saving Progress" << endl;
  fout.close();
}
void Robot::loadProgressFromFile(string filename){ //loads progress from file
  ifstream fin(filename);
  fin >> name;
  fin >> health;
  fin >> maxHealth;
  fin >> energy;
  fin >> maxEnergy;
  fin >> xp;
  fin >> neededXp;
  fin >> damage;
  fin >> combatOption;
  cout << "Loading Progress";
  fin.close();
} 

