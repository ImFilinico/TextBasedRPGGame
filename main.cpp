#include <iostream>
#include "robot.h"
#include "tank.h"
#include "enemy.h"
#include "scrapper.h"
#include "sniper.h"
using namespace std;


int main() {
cout << "██     ██ ███████ ██       ██████  ██████  ███    ███ ███████     ██" << endl; 
cout << "██     ██ ██      ██      ██      ██    ██ ████  ████ ██          ██" << endl;
cout << "██  █  ██ █████   ██      ██      ██    ██ ██ ████ ██ █████       ██" << endl; 
cout << "██ ███ ██ ██      ██      ██      ██    ██ ██  ██  ██ ██            " << endl; 
cout << " ███ ███  ███████ ███████  ██████  ██████  ██      ██ ███████     ██" << endl;
  bool playerMade =false;
  int select=0;
  Robot* player=nullptr;
  Robot* enemy=nullptr;
  while (select!=4){
    cout << "what do u wanna do?" << endl;
    cout << endl;
    cout << "1. Make new character" << endl;
    cout << "2. load previous character" << endl;
    cout << "3. Battle" << endl;
    cout << "4. exit game" << endl;
    cin >> select;
    if(select==1){
      cout << endl;
      int confirm = 0;
      int confirm2;
      int option;
      string name;
      cout << "Welcome to Scuffed Robo Arena! Nice to meet you, uhh...." << endl;
      cout << "What is your name?" << endl;
      cin >> name;
      cout << endl;
      cout << "Ok ok bet. What's poppin' " << name << endl;
      cout << "What class do you wanna be?" << endl;
      cout << endl;
      while(confirm == 0){
        confirm2=0;
        cout << "1. Tank" << endl;
        cout << "2. Scrapper" << endl;
        cout << "3. Sniper" << endl;
        cout << endl;
        cin >> option;
        cout << endl;
        if(option==1){
          while(confirm2==0){
            cout << "1. Tank Class Description" << endl;
            cout << "2. Confirm Tank Selection" << endl;
            cout << "3. Go back to class menu" << endl;
            cout << endl;
            cin >> option;
              if(option==1){
                cout << endl;
                cout << "Tank: You are an abosulte unit. Buffed up and swole you focus on health and armor. You use armor plates to protect yourself and to dish out more damage" << endl;
                cout << "Starting stats: 1000 Health, 100 energy, 100 damage" << endl;
                cout << "Special 1: Plaster Blaster, deal damage while gaining an armor plate" << endl;
                cout << "Special 2: Harmer Armor, take off an armor plate and use it as a weapon and deal extra damage" << endl;
                cout << endl;
            }
              else if (option==2){
                
                player = new Tank(2, name , 1000, 100, 1, 100, 0);
                player->setNeededXp(100);
                playerMade=true;
                confirm = 1;
                player->setCombatOption(1);
                break;
            }
              else if(option==3){
                confirm2=1;
                cout << endl;
            }
          }
        }
      
        else if(option==2){
          while(confirm2==0){
            cout << "1. Scrapper Class Description" << endl;
            cout << "2. Confirm Scrapper Selection" << endl;
            cout << "3. Go back to class menu" << endl;
            cout << endl;
            cin >> option;
              if(option==1){
                cout << endl;
                cout << "Scrapper: You are the lunatic on the battlefield. You don't give any F's and you wildly strike your oppenents with little regard of your well being" << endl;
                cout << "Starting stats: 800 health, 100 energy, 150 damage" << endl;
                cout << "Special 1: Maniac's Charge, deal extra damage at the cost of taking damage to yourself" << endl;
                cout << "Special 2: Scrapper Rapper, deal extra damage at the cost of extra energy" << endl;
                cout << endl;
            }
              else if (option==2){
               
                player = new Scrapper (2, name , 800, 100, 1, 150, 0);
                player->setNeededXp(100);
                playerMade=true;
                confirm = 1;
                player->setCombatOption(2);
                break;
            }
              else if(option==3){
                confirm2=1;
                cout << endl;
            }
          }
        }
        else if(option==3){
          while(confirm2==0){
            cout << "1. Sniper Class Description" << endl;
            cout << "2. Confirm Sniper Selection" << endl;
            cout << "3. Go back to class menu" << endl;
            cout << endl;
            cin >> option;
              if(option==1){
                cout << endl;
                cout << "Sniper: A weapons expert that relies on aim and precision to hit the right spots to deal critical damage" << endl;
                cout << "Starting Stats: 750 health, 100 energy, 125 damage" << endl;
                cout << "Special 1: Trick Shot, try making yourself to look cool and doing a trick shot for a chance to deal extra damage but there is a large chance that you may miss and do no damage" << endl;
                cout << "Special 2: Double shot, shoot twice with both having a chance to deal dritical damage" << endl;
                cout << endl;
            }
              else if (option==2){
                
                player = new Sniper (20, .30, name, 750, 100, 1, 125, 0);
                playerMade=true;
                confirm = 1;
                player->setNeededXp(100);
                player->setCombatOption(3);
                break;
            }
              else if(option==3){
                confirm2=1;
                cout << endl;
            }
          }

        }
      }
        cout << endl;
        cout << "Character successfully made" << endl;
        
    }
      
    else if(select ==2){
      cout << endl;
        player = new Tank(0, "", 0, 0, 0, 0, 0);
        player->loadProgressFromFile("savefile");
        cout << endl;
      
    }
    else if(select == 3){
      if (player->getCombatOption()==1){
        enemy = new Enemy("The Challenger", 1000,100,1,100,0);
        int combat; //what user inputs action choice into
        while (player->getHealth() > 0 && enemy->getHealth() > 0) { //condition that keeps going until someone is defeated
          // player action menu
          cout << "What is your next action?" << endl;
          cout << endl;
          cout << "1. Normal Attack" << endl;
          cout << "2. Repair and heal" << endl;
          cout << "3. Charge" << endl;
          cout << "4. Plaster Blaster" << endl;
          cout << "5. Harmer Armor" << endl;
          cout << "6. Flee" << endl;
          cout << endl;
          // prompt for input and handle the selected action
          cin >> combat;
            if (combat ==1){ //normal attack
              player->standardAttack(*enemy);
            }
            else if (combat == 2){ //heal
              player->repair();
            }
            else if (combat ==3){ //gain energy
              player->charge();
            }
            else if (combat == 4){ //special 1
              player->specialOne(*enemy);
            }
            else if (combat== 5){ //special 2
              player->specialTwo(*enemy);
            }
            else if (combat == 6){ //flee like the pansy you are
              cout << "You wussed out and fled" << endl;
              break;
            }
            else{
              cout << "Not a valid option" << endl;
            }
          
          // opponent's part of the battle
          int action = rand() % 3; //lets computer randomly choose an action to do
          switch (action) {
              case 0:
                  if(player->getArmorPlates()>0){
                    player->setArmorPlates(player->getArmorPlates()-1);
                    cout << "-1 plate and damage was mitigated" << endl;
                    enemy->standardAttack(*player);
                    if(player->getHealth()>=player->getMaxHealth()-150)
                      player->setHealth(player->getMaxHealth());
                    else{
                      player->setHealth(player->getHealth() + 150);
                    }
                  }
                  else{
                    enemy->standardAttack(*player);
                  }
                  break;
              case 1:
                  enemy->repair();
                  break;
              case 2:
                  enemy->charge();
                  break;
          }
        cout << endl;
        player->printInfo();
        enemy->printInfo();
        }
        player->setArmorPlates(2);
        player->setHealth(player->getMaxHealth());
        player->setEnergy(player->getMaxEnergy());
        if (player->getHealth() > enemy->getHealth() && combat !=6){
          cout << "You win" << endl;
          player->gainXp();
      
        }
        else{
          cout << "You lose" <<endl;
      }
        player->saveProgressToFile("savefile");
    }
      else if(player->getCombatOption()==2){
        enemy = new Enemy("The Challenger", 1000,100,1,100, 0);
        int combat; //what user inputs action choice into
        while (player->getHealth() > 0 && enemy->getHealth() > 0) { //condition that keeps going until someone is defeated
        // player action menu
        cout << "What is your next action?" << endl;
        cout << endl;
        cout << "1. Normal Attack" << endl;
        cout << "2. Repair and heal" << endl;
        cout << "3. Charge" << endl;
        cout << "4. Maniac's Charge" << endl;
        cout << "5. Scrapper Rapper" << endl;
        cout << "6. Flee" << endl;
        cout << endl;
        // prompt for input and handle the selected action
        cin >> combat;
        if (combat ==1){ //normal attack
          player->standardAttack(*enemy);
        }
        else if (combat == 2){ //heal
          player->repair();
        }
        else if (combat ==3){ //gain energy
          player->charge();
        }
        else if (combat == 4){ //special 1
          player->specialOne(*enemy);
        }
        else if (combat == 5){ //special 2
          player->specialTwo(*enemy);
        }
        else if (combat == 6){ //flee like the pansy you are
          cout << "You wussed out and fled" << endl;
          break;
        }
        else{
          cout << "Not a valid option" << endl;
        }
    
    // opponent's part of the battle
        int action = rand() % 3; //lets computer randomly choose an action to do
        switch (action) {
            case 0:
                enemy->standardAttack(*player);
                break;
            case 1:
                enemy->repair();
                break;
            case 2:
                enemy->charge();
                break;
        }
  cout << endl;
  player->printInfo();
  enemy->printInfo();
  }
  player->setBerzerkCharges(2);
  player->setHealth(player->getMaxHealth());
  player->setEnergy(player->getMaxEnergy());
  if (player->getHealth() > enemy->getHealth() && combat !=6){
    cout << "You win" << endl;
    player->gainXp();
  }
  else{
    cout << "You lose" <<endl;
  }
        player->saveProgressToFile("savefile");
      }
  else if(player->getCombatOption()==3){
    enemy = new Enemy("The Challenger", 1000,100,1,100, 0);
  int combat; //what user inputs action choice into
  while (player->getHealth() > 0 && enemy->getHealth() > 0) { //condition that keeps going until someone is defeated
    // player action menu
    cout << "What is your next action?" << endl;
    cout << endl;
    cout << "1. Normal Attack" << endl;
    cout << "2. Repair and heal" << endl;
    cout << "3. Charge" << endl;
    cout << "4. Trick Shot" << endl;
    cout << "5. Double Shot" << endl;
    cout << "6. Flee" << endl;
    cout << endl;
    // prompt for input and handle the selected action
    cin >> combat;
    if (combat==1){ //normal attack
      player->standardAttack(*enemy);
    }
    else if (combat== 2){ //heal
      player->repair();
    }
    else if (combat==3){ //gain energy
      player->charge();
    }
    else if (combat== 4){ //special 1
      player->specialOne(*enemy);
    }
    else if (combat== 5){ //special 2
      player->specialTwo(*enemy);
    }
    else if (combat== 6){ //flee like the pansy you are
      cout << "You wussed out and fled" << endl;
      break;
    }
    else{
      cout << "Not a valid option" << endl;
    }
    
    // opponent's part of the battle
    int action = rand() % 3; //lets computer randomly choose an action to do
    switch (action) {
        case 0:
            enemy->standardAttack(*player);
            break;
        case 1:
            enemy->repair();
            break;
        case 2:
            enemy->charge();
            break;
    }
  cout << endl;
  player->printInfo();
  enemy->printInfo();
  }
 
  player->setHealth(player->getMaxHealth());
  player->setEnergy(player->getMaxEnergy());
  if (player->getHealth() > enemy->getHealth() && combat !=6){
    cout << "You win" << endl;
    player->gainXp();
  }
  else{
    cout << "You lose" <<endl;
  }
    player->saveProgressToFile("savefile");
    }
    else{
      cout << "bye bye" << endl;
      exit(1);
      }
  }
  }

  return 0;
}

