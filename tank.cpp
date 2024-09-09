#include "tank.h"

Tank::Tank(int p, const string _name, int _health, int _energy, int _level , int _damage, int _xp):Robot(_name,_health,_energy,_level,_damage,_xp){ //Tank overloaded constructor (name,health,energy,level,attack, plates)
  armorPlates = p;
}
void Tank::setArmorPlates(int ap){
  armorPlates=ap;
}
int Tank::getArmorPlates(){
  return armorPlates;
}
  //gerneral functions
void Tank::repair(){ //this function allows robot to gain health for a turn.
  cout << getName() << " the tank is repairing now." << endl;
  setHealth(getHealth()+getMaxHealth() * .15);
  if(getHealth()>=getMaxHealth()){
    setHealth(getMaxHealth());
  }
  cout << endl;
} 
void Tank::charge(){//allows for robot to gain energy
  cout << getName() << " the tank is now charging" << endl;
  setEnergy(getEnergy()+30);
  if(getEnergy()>getMaxEnergy()){
    setEnergy(getMaxEnergy());
  }
  cout << endl;
} 
void Tank::gainXp(){
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

  //combat functions
void Tank::standardAttack(Robot& target) { //costs 10 energy
  if(getEnergy() < 10){
    cout<< "Not enough energy" << endl;
    cout << endl;
  }
  else {
    setEnergy(getEnergy()-10);
    cout << getName() << " the tank decided to throw hands and dealt " << getDamage() << " damage." << endl;
    target.setHealth((target.getHealth()) - getDamage());
    cout << endl;
  }   
}

void Tank::gainLevel(){//when xp equals max x, the robot levels up and allows for player to increase a stat
  setLevel(getLevel()+1);
  int statChose;
  cout << "select an attribute to increase" << endl;
  cout << endl;
  cout << "1. Damage +50" << endl;
  cout << "2. Health + 100" << endl;
  cout << "3. Energy + 10" << endl;
  cin >> statChose;
  if(statChose==1){
    setDamage(getDamage()+50);
  }
  else if(statChose==2){
    setMaxHealth(getHealth()+150);
  }
  else if(statChose==3){
    setMaxEnergy(getMaxEnergy()+10);
  }
} 


//special attacks


void Tank::printInfo(){
  cout << getName() << " the tank" << endl;
  cout << "HP: " << getHealth() << "/" << getMaxHealth() << endl;
  cout << "Energy: " << getEnergy() << "/" << getMaxEnergy() << endl;
  cout << "Armor plates: " << getArmorPlates() << endl;
  cout << endl;
}


void Tank::specialOne(Robot& enemy){ //plaster blaster
  if(getEnergy()<25){
    cout << "Not enough energy" << endl;
  }
  else{
    setEnergy(getEnergy()-25);
    armorPlates+=1;
    cout << getName() << " the tank has used Plaster Blaster and did " << (getDamage()*.5) << " damage." << endl;
    cout << "+1 plate" << endl;
    enemy.setHealth((enemy.getHealth()) - (getDamage()*.5));
   }
  cout << endl;
}

void Tank::specialTwo(Robot& enemy){ //harmer armor
  if(getEnergy()<25){
    cout << "Not enough energy" << endl;
  }
  else{
    if(armorPlates<=0){
      cout << "you have no plates to use.";
      cout << "Instead ";
      standardAttack(enemy);

    }
    else{
      armorPlates-=1;
      cout << getName() << " the tank used harmerArmor and dealt " << (getDamage()*1.5) << " damage"<< endl;
      enemy.setHealth((enemy.getHealth()) - (getDamage()*1.5));     
    }
  }
  cout << endl;
}

void Tank::saveProgressToFile(string filename){ //puts all info about character in file
  ofstream fout(filename);
  fout << armorPlates << endl;
  Robot::saveProgressToFile(filename);
  cout << "Saving Progress" << endl;
  fout.close();
}

void Tank::loadProgressFromFile(string filename){ //loads progress from file
  ifstream fin(filename);
  fin >> armorPlates;
  Robot::loadProgressFromFile(filename);
  
  cout << "Loading Progress";
  fin.close();
}