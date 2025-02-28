include <iostream>
#include<string>
#include<string_view>
#include<array>


namespace Animal
{
  enum TypeAnimal
  {
    chicken,//0
    dog,//1
    cat,//2
    elephant,//3
    duck,//4
    snake,//5
    max_animal //6
  };
  
  struct Data 
  {
    std::string_view name {};
    int legs {};
    std::string_view roar {};
  };
  
  
  constexpr std::array<Data,6> animal {{
                                        {"chicken",2,"kudah"}, 
                                        {"dog",4, "gav"},
                                        {"cat",4,"meow"}, 
                                        {"elephant", 4, "Trrrr"}, 
                                        {"duck", 2, "cryak"},
                                        {"snake",0,"shhh"}
                                                          }};
  
  static_assert(std::size(animal)==max_animal);
  
  constexpr std::array typeAnimal {chicken, dog, cat, elephant, duck, snake};
  
  static_assert(std::size(animal)==max_animal);
  
  constexpr Data getAnimalName (Animal::TypeAnimal type)
  {
    return Animal::animal[static_cast<std::size_t>(type)];
  }
  
  std::ostream& operator<<(std::ostream& out, Animal::TypeAnimal type)
  {
    const Data data {getAnimalName(type)};
    return out << "A " << data.name << " has " << data.legs
    << " legs and says " << data.roar;
  }
  
  std::istream& operator>>(std::istream& in, Animal::TypeAnimal& type)
  {
    std::string input {};
    std::getline(in>>std::ws,input);
    
    for(std::size_t index{0}; index<Animal::animal.size(); ++index)
    {
      if(input==Animal::animal[index].name)
      {
        type=static_cast<Animal::TypeAnimal>(index);
        return in;
      }
    }
    in.setstate(std::ios_base::failbit);
    return in;
  }
}

int main ()
{
  Animal::TypeAnimal type {};
  auto userAnimal{type};
  std::cout << "Enter an animal: ";
  std::cin >> userAnimal;
  
  if (!std::cin)
  {
    std::cout << "Animal couldn't be find!" << '\n';
  }
  else
  {
    std::cout << userAnimal << '\n';
  }
  std::cout << "Here is the data for the rest of the animal: " << '\n';
  for (auto e: Animal::typeAnimal)
  {
    if (e==userAnimal)
    {
    continue;
    }
    else
    {
    std::cout << e << '\n';
    }
  }
  return 0;
}

