#include <functional>
#include <iostream>
#include<functional>

using ArithmeticFunction = std::function<int(int,int)>;

int getInteger()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

char getOperation()
{
    char op{};

    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    }
    while (op!='+' && op!='-' && op!='*' && op!='/');

    return op;
}

int add (int x, int y)
{
  return x+y;
}

int substruct (int x, int y)
{
  return x-y;
}
int multyply (int x, int y)
{
  return  x*y;
}

int divide (int x, int y)
{
  return x/y;
}

ArithmeticFunction getArithmeticFunction (char op)
{
  
  switch (op)
  {
    case '+': return &add;
    case '-': return &substruct;
    case '*': return &multyply;
    case '/': return &divide;
  }
}
int main()
{
    int x{ getInteger() };
    char op{ getOperation() };
    int y{ getInteger() };
    ArithmeticFunction fcnPtr {getArithmeticFunction (op)};
    if (fcnPtr)
    std::cout << x << ' ' << op << ' ' << y << ' = ' << fcnPtr (x,y) << '\n';
    return 0;
}

