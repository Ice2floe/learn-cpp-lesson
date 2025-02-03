#include <iostream>
#include<string>

std::string_view getQuantityPhrase(int numApples)
{
	switch (numApples)
	{
		case 0:
                return "no";
	        break;
		
		case 1: 
                return "a single";

		case 2:
		return "a couple of";
		break;
		
		case 3:
		return "a few";
		break;

		default:
		if (numApples<0)
			return "negative";
		else 
			return "many";
	}
}



std::string_view getApplesPluralized(int numApples)
{
	return numApples==1 ? "aplle" : "apples";
}

int main()
{
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}
