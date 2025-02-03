#include<iostream>

int printUpto (int outter)
{
	int inner {outter};
	while (inner>=1)
	{
		std::cout << inner << ' ';
		--inner;
		
	}
	return outter;
}


int printAnother (int anotherOutter)
{
        int anotherInner {anotherOutter};
        while (anotherInner>=1)
        {
                std::cout << ' ' << ' ';
                --anotherInner;                          
        }
        return anotherOutter;
}

void printAnotherUpto (int myNumber)
{
	int myInner {myNumber};
	while (myInner>=1)
	{
		std::cout << myInner << ' ';
		--myInner;
	}
}



int main ()
{
	char symChar {'a'};

	while (symChar<='z')
	{
		std::cout << symChar << "-" << static_cast<int>(symChar) << '\n';

		++symChar;
	}

	int outter {5};
	while(outter>=1)
	{
	  printUpto (outter);

	  std::cout << '\n';
	
	  --outter;
}

        int anotherOutter {5};
        int myNumber {1};
while (anotherOutter>=1 && myNumber<=5)
{
	printAnother (anotherOutter);
	printAnotherUpto (myNumber);
	
	std::cout << " " << '\n';

	
	--anotherOutter;
	++myNumber;
}

	return 0;
}



