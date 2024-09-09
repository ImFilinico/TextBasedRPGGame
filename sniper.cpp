#include "sniper.h"

Sniper::Sniper(int cC, double cD, const string _name, int _health, int _energy, int _level , int _damage, int _xp ):Robot(_name,_health,_energy,_level,_damage,_xp){
  critChance = cC;
  critDamage= cD;
} 

void Sniper::setCritChance(int cC){
  critChance = cC;
}
int Sniper::getCritChance(){
  return critChance;
}
void Sniper::setCritDamage(double cD){
  critDamage = cD;
}
double Sniper::getCritDamage(){
  return critDamage;
}

void Sniper::repair(){ //this function allows robot to gain health for a turn.
  cout << getName() << " the sniper is repairing now." << endl;
  setHealth(getHealth()+getMaxHealth() * .1);
  if(getHealth()>=getMaxHealth()){
    setHealth(getMaxHealth());
  }
  cout << endl;
} 
void Sniper::charge(){//allows for robot to gain energy
  cout << getName() << " the sniper is now charging" << endl;
  setEnergy(getEnergy()+30);
  if(getEnergy()>getMaxEnergy()){
    setEnergy(getMaxEnergy());
  }
  cout << endl;
} 
void Sniper::gainXp(){
  setXp(getXp() + (getNeededXp() * .10));
  cout << "+" << (getNeededXp() * .10) << " experience" << endl;
  if(getXp() >= getNeededXp()){
    gainLevel();
    cout << "Congrats! You have leveled up to level " << getLevel() << endl;
    setXp(getXp()-getNeededXp());
    setNeededXp(getNeededXp()+(getLevel()*50));
  }
  cout << "XP: "<< getXp() << "/" << getNeededXp() << endl;
}

void Sniper::standardAttack(Robot& target){ //costs 10 energy
  if(getEnergy() < 10){
    cout<< "Not enough energy" << endl;
    cout << endl;
  }
  else {
    setEnergy(getEnergy()-10);
    int chance = rand() % (100);
    if (chance < critChance){
      cout << getName() << " the sniper landed a critical hit and did " << (getDamage() + (getDamage() * critDamage)) << " damage." << endl;
      target.setHealth((target.getHealth()) - (getDamage() * critDamage));
      cout << endl;
    }
    else{
        cout << getName() << " the sniper fires a shot and dealt " << getDamage() << " damage." << endl;
      target.setHealth((target.getHealth()) - getDamage());
      cout << endl;      
    }
  }   
}

void Sniper::gainLevel(){//when xp equals max x, the robot levels up and allows for player to increase a stat
  setLevel(getLevel()+1);
  int statChose;
  cout << "select an attribute to increase" << endl;
  cout << endl;
  cout << "1. Damage + 75" << endl;
  cout << "2. Health + 100" << endl;
  cout << "3. Energy + 10" << endl;
  cin >> statChose;
  if(statChose==1){
    setDamage(getDamage()+75);
  }
  else if(statChose==2){
    setMaxHealth(getHealth()+100);
  }
  else if(statChose==3){
    setMaxEnergy(getMaxEnergy()+10);
  }
} 

void Sniper::printInfo(){
  cout << getName() << " the tank" << endl;
  cout << "HP: " << getHealth() << "/" << getMaxHealth() << endl;
  cout << "Energy: " << getEnergy() << "/" << getMaxEnergy() << endl;
  cout << endl;
}

void Sniper::specialOne(Robot& enemy){
  if(getEnergy()<25){
    cout << "Not enough energy" << endl;
  }
  else{
    setEnergy(getEnergy()-25);
    int chance = rand() % 100;
    if (chance < 30){
      cout << getName() << " the sniper just landed a 360 no-scope and did " << (getDamage()*3) << " damage." << endl;
      enemy.setHealth((enemy.getHealth()) - (getDamage()*3));
      cout << endl;      
    }
    else{
      cout << getName() << " tried to look really cool but missed" << endl;
      cout << endl;
    }
  }
}

void Sniper::specialTwo(Robot& enemy){
  if(getEnergy()<35){
    cout << "Not enough energy" << endl;
  }
  else{
    setEnergy(getEnergy()-35);
    int chance1 = rand() %100;
    int chance2 = rand() %100;
    if (chance1 < critChance){
      cout << getName() << " the sniper's first shot landed a critical hit and did " << ((getDamage()*.75) + ((getDamage()*.75) * critDamage)) << " damage." << endl;
      enemy.setHealth((enemy.getHealth()) - ((getDamage()*.75) + ((getDamage()*.75) * critDamage)));
      cout << endl;
    }
    else{
        cout << getName() << " the sniper's first shot did " << (getDamage()*.75) << " damage." << endl;
      enemy.setHealth((enemy.getHealth()) - (getDamage()*.75));
      cout << endl;      
    }
    if (chance2 < critChance){
      cout << getName() << " the sniper's second shot landed a critical hit and did " << ((getDamage()*.75) + ((getDamage()*.75) * critDamage)) << " damage." << endl;
      enemy.setHealth((enemy.getHealth()) - ((getDamage()*.75) + ((getDamage()*.75) * critDamage)));
      cout << endl;
    }
    else{
        cout << getName() << " the sniper's second shot did " << (getDamage()*.75) << " damage." << endl;
      enemy.setHealth((enemy.getHealth()) - (getDamage()*.75));
      cout << endl;      
    }
  }
}

void Sniper::loadProgressFromFile(string filename){ //loads progress from file
  ifstream fin(filename);
  fin >> critChance;
  fin >> critDamage;
  Robot::loadProgressFromFile(filename);
  cout << "Loading Progress";
  fin.close();
}

void Sniper::saveProgressToFile(string filename){ //puts all info about character in file
  ofstream fout(filename);
  fout << critChance << endl;
  Robot::saveProgressToFile(filename);
  cout << "Saving Progress" << endl;
  fout.close();
}