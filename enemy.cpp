#include "enemy.h"

Enemy::Enemy(const string n, int h, int e, int l, int d, int xp) : Robot(n,h,e,l,d,xp){
}
void Enemy::repair(){
  cout << getName() << " is repairing now." << endl;
  setHealth(getHealth()+getMaxHealth() * .1);
  if(getHealth()>getMaxHealth()){
    setHealth(getMaxHealth());
  }
  cout << endl;
}
void Enemy::charge(){
    cout << getName() << " is now charging" << endl;
    setEnergy(getEnergy()+30);
    if(getEnergy()>100){
      setEnergy(100);
    }
    cout <<endl;
  } 


void Enemy::standardAttack(Robot& target){
    cout << getName() << " the challenger decided to throw hands and dealt " << getDamage() << " damage." << endl;
    target.setHealth((target.getHealth()) - getDamage());
    cout << endl;  
}

void Enemy::printInfo(){
  cout << getName()<< endl;
  cout << "HP: " << getHealth() << "/" << getMaxHealth() << endl;
  cout << "Energy: " << getEnergy() << "/" << getMaxEnergy() << endl;
  cout << endl;
}
void Enemy::gainLevel(){}
void Enemy::gainXp(){}
void Enemy::specialOne(Robot& enemy){
  cout << "test" << endl;
}
void Enemy::specialTwo(Robot& enemy){
  cout << "test " << endl;
  }
  

