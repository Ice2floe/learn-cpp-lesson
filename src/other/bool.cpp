#include <iostream>

int num_result (int numOne, int numTwo, int numThree)
{
	return numOne * (numOne >= numTwo && numOne>= numThree) + 
           numTwo * (numTwo >= numOne && numTwo>= numThree) + 
           numThree * (numThree >= numOne && numThree >= numTwo);
}

int main ()
{
	std::cout << "Введите три числа через пробел:";
	int numOne {};
	int numTwo {};
	int numThree {};

	std::cin >> numOne >> numTwo >> numThree;

	int max {num_result (numOne, numTwo, numThree)};

	std::cout << "Наибольшее число равно: " <<max << '\n';
	return 0;
}
