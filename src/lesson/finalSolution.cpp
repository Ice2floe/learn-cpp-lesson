#include<iostream>

int main()
{

  std::cout << "Enter a integer: ";

  int num {};
  std::cin >> num;

  std::cout << "Enter another integer: ";

  int numTwo {};
  std::cin >> numTwo;

  std::cout << num << " + " << numTwo << " is " << num+numTwo << ".\n";

  std::cout << num << " - " << numTwo << " is " << num+numTwo <<".\n";

  return 0;
}

  
