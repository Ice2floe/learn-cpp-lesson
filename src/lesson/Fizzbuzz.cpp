#include <iostream>//подключение библиотеки ввода и вывода

bool playAgain () //булевая функция которая спрашивает хоттм мы играть снова
  {
    std::cout << "Хотите ли вы играть снова?(y/n):";

    char userChar {};
    std::cin >> userChar;

    while (true)
      {
        if (userChar=='y')
          return true;
        else
          return false;

      }
  }

void fizzBuzz (int userNumber)//сама функция вывода чиселтот одного до n
  {
    for (int i{0}; i<=userNumber; ++i)
      {
        if (i%3==0 && i%5==0)//проверяет условие и если оба верны печатает FizzBuzz
          std::cout << "FizzBuzz!\n";
        else
          std::cout << i << '\n';
      }


  }
int main () //функция, с которой все начинается
{
  do//предусловие которое всегда выполнится один раз, даже если цикл ложный
    {

      std::cout << "До какого числа вы хотите играть?:";
      int userNumber {};
      std::cin >> userNumber;

      fizzBuzz (userNumber);
    } while (playAgain());//здесь спрятана булевая функция которая станет 0 или 1 после выбора и запустит цикл или не запустит
  return 0; //успешно выполнена программа!
}
