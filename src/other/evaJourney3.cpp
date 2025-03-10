#include<iostream>//директива препроцессора
//меняем состояние путешествия Евы, передача по ссылке чтобы значения не копировались, а менялся оригинал, чем-то похоже на сеттер)
void changeStatus (float& temperature, int& size, unsigned short& quantStar, bool& weather )
{
  temperature += 10.5; 
  size-=1350;
  weather=true; //погода яснее
  if(weather) //если погода яснее то и количество звёзд больше 
  quantStar+=20;
}
//проверяем условия и выводим их
void checkEnvironment (float& temperature, int& size, unsigned short& quantStar)
{
  if (temperature>=-5.0)
  std::cout << "На улице Тепло, Ева не привыкла к такой жаре!\n";
  else
  std::cout << "Ева обожает холод, потому что другой погоды она не знает!\n";
  
  if(size<=150)
  std::cout << "Ева почти прибыла на другую научную станцию!\n";
  else
  std::cout << "Ева слишком далеко пока что!\n";
  if (quantStar>=40) //погода и количество звёзд связаны я мог бы сделать (weather||star>=40), но так я считаю лучше
  std::cout << "Звёзд на небе много, погода ясная!\n";
  else
  std::cout << "Сегодня пасмурно, звёзд почти не видно!\n";
  }
  //выводим переменные на консоль
  void printReport (float& temperature, int& size, unsigned short& quantStar, bool& weather )
{
  std::cout << "На улице " << temperature << " градусов по Цельсию!\n";
  std::cout << "расстояние до станции " << size << " метров!\n";
  std::cout << "Звёзд на небе " << quantStar << '\n';
  std::cout << "Погода на станции " << std::boolalpha << weather << "!\n";
  }
  /*Я немного решил улучшить задачу, сначала написать изначальные усилврия и проверить их
  до путешествия Евы, а потом обновить их, чтобы посмотреть, что изменилось за время пушетсвия Евы*/
int main ()
{
  float temperature {-12.3f}; //на северном Полюсе минус
  int size {1500}; //расстояние до ближайшей союзной станции
  unsigned short quantStar {25}; //не думаю что Ева сможет посчитать больше 255
  bool weather {false}; //пасмурно
  
  printReport(temperature, size, quantStar, weather);
  std::cout << '\n';
  checkEnvironment(temperature, size, quantStar);
 
  std::cout << "\nЕва начинает свое приключение!\n";
  changeStatus (temperature, size, quantStar, weather);
  
  printReport(temperature, size, quantStar, weather);
  std::cout << '\n';
  checkEnvironment(temperature, size, quantStar);
  return 0;
  
}

