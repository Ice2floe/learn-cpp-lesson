#include<iostream>
#include<string>

struct Monster
{
  std::string monster {};
  std::string nameMonster {};
  int healthMonster {};
};

void printMonster (const Monster& monster)
  {
    std::cout << "This " << monster.monster << " is named " << monster.nameMonster << " and has " <<monster.healthMonster << " health!\n";

  }

int main ()
  {
    Monster ogre {"Ogre","Torg", 145};
    Monster slime {"Slime","Blurp", 23};

    printMonster (ogre);
    printMonster (slime);
    return 0;
  }
