#include<iostream>

int main ()
{
	std::cout << "Enter a integer number: ";
	int smaller {};
	std::cin >> smaller; //smaller enters scope and is created here


	std::cout << "Enter a larger integer: ";
	int larger {};
	std::cin >> larger; //enters scope and is created here


	if (larger<smaller)
	{
		int swap {smaller}; //swap enters scope and is created here

		smaller=larger;
		larger=swap;
		std::cout << "Swapping the variables!\n";
	} // swap goes out of scope and is destroyed here

	std::cout << "The smaller value: " << smaller << '\n';
	std::cout << "The larger value: " << larger << '\n';
	return 0;
} //larger and smaller goes out of scope and is destroyed here
