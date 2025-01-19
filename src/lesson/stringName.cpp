#include<iostream>
#include<string>

int main ()
{
	std::cout << "Enter your full name: ";
        
	std::string userName {};
	std::getline (std::cin >> std::ws, userName);
	std::cout << "Enter your age: ";

	int ageUser {};
	std::cin >> ageUser;

	int userChar {static_cast<int>(std::size (userName))};

	std::cout << "Your age + lenght of name is: " << ageUser+userChar << '\n';

	return 0;
}
	
