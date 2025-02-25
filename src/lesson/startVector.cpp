#include<iostream>
#include<vector>

int main()
{
  std::vector sqrt {1,4,9,16,25};
  std::vector<double> temperature(365);
  
  std::vector<int> userNumber(2);
  
  std::cout << "Введите три целых числа: ";
  std::cin >> userNumber[0] >> userNumber [1] >> userNumber[2];
  
  std::cout << "Сумма: " << userNumber[0]+userNumber[1]+userNumber[2] << '\n';
  std::cout << "произведение: " << userNumber[0]*userNumber[1]*userNumber[2] << '\n';
}

