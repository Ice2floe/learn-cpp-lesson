#include<iostream>
#include<string>
#include<string_view>

template<typename T>
bool isValueInArray (const std::vector<T>& arrName, const T& userName)
{
   for (const auto& name: arrName) 
  {
    if (userName==name)
    {
    return true;
    }

  }
  return false;
}

int main()
{
  std::vector<std::string_view> arrName{"Alex", "Betty", "Caroline", "Dave", "Emily", 
                                 "Fred", "Greg", "Holly" };
  
  std::string userName {}; 
  std::cout << "Enter a Name:";
  std::cin >> userName;
  
  
  if (isValueInArray<std::string_view>(arrName,userName)) 
  std::cout <<  userName << " is find it!\n";
  else
  std::cout << userName << " is not find!\n";
  
  return 0;                  
}
