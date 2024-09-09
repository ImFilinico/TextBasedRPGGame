#include "scrapper.h"

Scrapper::Scrapper(int b, const string _name, int _health, int _energy, int _level , int _damage, int _xp):Robot(_name,_health,_energy,_level,_damage,_xp){
  berzerkCharges=b;
}

void Scrapper::setBerzerkCharges(int b){
  berzerkCharges=b;
}
int Scrapper::getBerzerkCharges(){
  return berzerkCharges;
}

void Scrapper::repair(){ //this function allows robot to gain health for a turn.
  cout << getName() << " the Scrapper is repairing now." << endl;
  setHealth(getHealth()+getMaxHealth() * .1);
  if(getHealth()>=getMaxHealth()){
    setHealth(getMaxHealth());
  }
  cout << endl;
} 
void Scrapper::charge(){//allows for robot to gain energy
  cout << getName() << " the Scrapper is now charging" << endl;
  setEnergy(getEnergy()+30);
  if(getEnergy()>getMaxEnergy()){
    setEnergy(getMaxEnergy());
  }
  cout << endl;
} 
void Scrapper::gainXp(){
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
void Scrapper::standardAttack(Robot& target){ //costs 10 energy
  if(getEnergy() < 10){
    cout<< "Not enough energy" << endl;
    cout << endl;
  }
  else {
    setEnergy(getEnergy()-10);
    cout << getName() << " the scrapper decided to throw hands and dealt " << getDamage() << " damage." << endl;
    target.setHealth((target.getHealth()) - getDamage());
    cout << endl;
  }   
}

void Scrapper::gainLevel(){//when xp equals max x, the robot levels up and allows for player to increase a stat
  setLevel(getLevel()+1);
  int statChose;
  cout << "select an attribute to increase" << endl;
  cout << endl;
  cout << "1. Damage + 100" << endl;
  cout << "2. Health + 75" << endl;
  cout << "3. Energy + 10" << endl;
  cin >> statChose;
  if(statChose==1){
    setDamage(getDamage()+100);
  }
  else if(statChose==2){
    setMaxHealth(getHealth()+75);
  }
  else if(statChose==3){
    setMaxEnergy(getMaxEnergy()+10);
  }
} 

void Scrapper::printInfo(){
  cout << getName() << " the Scrapper" << endl;
  cout << "HP: " << getHealth() << "/" << getMaxHealth() << endl;
  cout << "Energy: " << getEnergy() << "/" << getMaxEnergy() << endl;
  cout << "Berzerk Charges: " << getBerzerkCharges() << endl;
  cout << endl;
}


void Scrapper::specialOne(Robot& enemy){
  if(getEnergy()<25){
    cout << "Not enough energy" << endl;
  }
  else{
    if(berzerkCharges<=0){
      setEnergy(getEnergy()-10);
      cout << "you are on the verge of collapse so instead ";
      standardAttack(enemy);
    }
    else{
      berzerkCharges-=1;
      cout << getName() << " the scrapper used Maniac's Charge and went buckwild. It dealt " << (getDamage()*2) << " damage but took " << getDamage() << " damage"<< endl;
      enemy.setHealth((enemy.getHealth()) - (getDamage()*2));
      setHealth(getHealth()-getDamage());
    }
  }
  cout << endl;
}

void Scrapper::specialTwo(Robot& enemy){
    if(getEnergy() < 40){
    cout<< "Not enough energy" << endl;
    cout << endl;
  }
  else {
    setEnergy(getEnergy()-40);
    cout << getName() << " the scrapper decided to start rapping. It was so bad it dealt " << (getDamage()*1.5) << " damage." << endl;
    enemy.setHealth((enemy.getHealth()) - getDamage());
    cout << endl;
  }
}

void Scrapper::saveProgressToFile(string filename){ //puts all info about character in file
  ofstream fout(filename);
  fout << berzerkCharges << endl;
  Robot::saveProgressToFile(filename);
  cout << "Saving Progress" << endl;
  fout.close();
}

void Scrapper::loadProgressFromFile(string filename){ //loads progress from file
  ifstream fin(filename);
  fin >> berzerkCharges;
  Robot::loadProgressFromFile(filename);
  cout << "Loading Progress";
  fin.close();
}