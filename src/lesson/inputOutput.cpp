#include <iostream>

int main ()
{
  std::cout << "Enter three numbers: ";

  int numOne {}, numTwo {}, numThree {};
  std::cin >> numOne >> numTwo >> numThree;

  std::cout << "You Entered " << numOne << ", " << numTwo << ", and " << numThree << ".\n";

  return 0;
}
