#include <iostream>
#include <cmath> //sqrt корень важная вещь
#include <string>

int main ()
{
	std::cout << "введите целое число: ";
	int numUser {}; //инициализация фигурных скобок безопасная
	std::cin >> numUser; //когда определили тип переменной, больше не надо писать ее тип

	std::cout << "введите другое целое число: ";
	int otherNumber {};
	std::cin >> otherNumber;

	int numSum {numUser+otherNumber}; //так лучше, потому что если мы захотим мы сможем исполтзрвать это снова в других операциях

	std::cout << "сумма введенных вами чисел равна: " << numSum << '\n';

	std::cout << "Введите ваше имя: ";
	std::string userName {};
	std::cin >> userName; //вводите без пробелов
	
	std::cout << "введите фамилию: ";
	std::string userSurname {};
	std::cin >> userSurname;

	std::cout << "Здравствуйте, " << userName << '\t' << userSurname << '\n';

	const double Pi {3.14};//пришлось немного глянуть вперед, мы это не изучали
        std::cout << "введите радиус круга: ";
	double radius {};
	std::cin >> radius;
	
	double areaCircle { Pi * radius * radius};        double lenghtCircle {2 * Pi * radius};

	std::cout << "Длина окружности равна: " <<
lenghtCircle << ", а его площадь - " << areaCircle << '\n';

	std::cout << "Ввведите первую кординату X:";
	double userXone {};
	std::cin >> userXone;

	std::cout << "Введите вторую координату X:";
	double userXtwo {};
	std::cin >> userXtwo;

	std::cout << "Введите первую координату Y:";
	double userYone {};
	std::cin >> userYone;

	std::cout << "Введите вторую координпту Y:";
	double userYtwo {};
	std::cin >> userYtwo;

	double disXY {sqrt((userYone-userXone)*(userYone-userXone)+(userYtwo-userXtwo)*(userYtwo-userXtwo))};

	std::cout << "расстояние между X и У равно: " << disXY << '\n';

	return 0;
}

