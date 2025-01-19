#include<iostream>

double inputUser ()
{
  double  userNum {};
  std::cout << "Enter a number: ";
  std::cin >> userNum;
  return userNum;
}

char inputChar ()
{
  char userChar {};
  std::cout << "Choose what you want to do with it. (+-/*):";
  std::cin >> userChar;
  return userChar;
}

void printResult (double  numUser,double numUserx,char charUser)
{
  switch (charUser)
    {
    case '+':
      std::cout << numUser << " + " << numUserx << " = " << numUser+numUserx << '\n';
      break;
    case '-':
      std::cout << numUser << " - " << numUserx << " = " << numUser-numUserx << '\n';
      break;
    case '*':
      std::cout << numUser << " * " << numUserx << " = " << numUser*numUserx << '\n';
      break;
    case '/':
	if (numUserx==0)
	  {
	    std::cout << "You can't divide by zero!\n";
	    break;
	  }
	else
	  {
	    std::cout << numUser << " / " << numUserx << " = " << numUser/numUserx << '\n';
	    break;
	  }
    default:
      std::cout << "That's not what we agreed on.\n";
	}
}

int main ()
{
  double numUser {inputUser()};
  double numUserx {inputUser()};
  char charUser {inputChar()};
  printResult (numUser,numUserx,charUser);
  return 0;
}
