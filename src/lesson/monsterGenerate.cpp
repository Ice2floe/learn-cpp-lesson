#include"random.h"
#include<iostream>
#include<string>
#include<string_view>


namespace MonsterGenerator
{
  
}
class Monster
{
  public:
enum MonsterType
{
  DRAGON,
  GOBLIN,
  OGRE, 
  ORK,
  SKELETON,
  TROLL,
  VAMPIRE,
  ZOMBIE,
  MAXMONSTERTYPES,
};

private: 
MonsterType m_type {};
std::string m_nameMonster {"???"};
std::string m_roar {"???"};
int m_hitPoints {};

public:

Monster (MonsterType type, std::string_view nameMonster, std::string_view roar, int heatPoint)
: m_type{type}
, m_nameMonster {nameMonster}
, m_roar {roar}
, m_hitPoints {heatPoint}
{
}

 constexpr std::string_view getTypeString() const
{
  switch (m_type)
  {
    case Monster::DRAGON: return"Dragon"; break;
    case Monster::GOBLIN: return "Goblin"; break;
    case Monster::OGRE: return "Ogre"; break;
    case Monster::SKELETON: return "Skeleton"; break;
    case Monster::TROLL: return "Troll"; break;
    case Monster::VAMPIRE: return "Vampire"; break;
    case Monster::ZOMBIE: return "Zombie"; break;
    default: return "???";
  }
}

void print() const
	{
		std::cout << m_nameMonster << " the " << getTypeString();

		if (m_hitPoints <= 0)
			std::cout << " is dead.\n";
		else
			std::cout << " has " << m_hitPoints << " hit points and says " << m_roar << ".\n";
	}
};

namespace MonsterGenerator
{
 std::string_view getName(int x)
{
  switch (x)
  {
    case 0: return "Barton"; break;
    case 1: return "Jones"; break;
    case 2: return "Smolen"; break;
    case 3: return "Gven"; break;
    case 4: return "Eline"; break;
    case 5: return "Mukstar"; break;
    default: return "???"; 
  }
 }
  
  std::string_view getRoar (int x)
  {
    switch (x)
    {
      case 0: return "roar"; break;
      case 1: return "grh"; break;
      case 2: return "num"; break;
      case 3: return "chaw"; break;
      case 4: return "ayyh"; break;
      case 5: return "kill"; break;
      default: return "???"; break;
    }
   }
   
   Monster generate()
	{
		return Monster{ static_cast<Monster::MonsterType>(Random::get (0,Monster::MAXMONSTERTYPES-1)), getName(Random::get(0,5)), getRoar(Random::get(0, 5)),  Random::get(0, 100)};
	}
};




int main ()
{
 Monster m{ MonsterGenerator::generate() };
 m.print();
  return 0;
}
