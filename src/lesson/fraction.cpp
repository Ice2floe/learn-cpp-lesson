#include<iostream>

struct Fraction
{
  int numerator {};
  int denominator {};
};

Fraction getFraction ()
{
  Fraction temp {};

  std::cout << "enter the numerator: ";
  std::cin >> temp.numerator;

  std::cout << "enter the denominator: ";
  std::cin >> temp.denominator;

  return temp;
}

Fraction multFraction (Fraction one, Fraction two)
  {
    Fraction mult {one.numerator*two.numerator, one.denominator*two.denominator};
    return mult;
  }

void printResultFraction (Fraction multResult)
  {
    std::cout << "your fractions multiplied together: " << multResult.numerator << "/" << multResult.denominator << '\n';

  }

int main ()
  {
    Fraction oneFraction {getFraction()};

    std::cout << '\n';

    Fraction otherFraction {getFraction()};

    std::cout << '\n';

    Fraction multResult {multFraction(oneFraction, otherFraction)};

    printResultFraction (multResult);
    return 0;
  }
