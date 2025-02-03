#include <iostream>

constexpr bool isEven (int userNum)
{
	// if x % 2 == 0, 2 divides evenly into our number, which means it must be an even number
	if (userNum % 2 == 0)
		return true;
	else
		return false;
}

int main ()
{
	std::cout << "Enter an integer number: ";
	
	int userNum {};
	std::cin >> userNum;

	if (isEven(userNum))
		std::cout << userNum << " is Even Number!\n";
	else
		std::cout << userNum << " is not Even Number!\n";

	return 0;
}
