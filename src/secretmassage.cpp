#include<iostream>
#include<string>

int main ()
{
	std::string nameObj {"Eva"};
	std::string codeName {"Ice2Floe"};
	double x {123.456};
	double y {-78.910};
        double z {42.0};
	char symbol {'*'};
	bool answer {true};

	std::cout << "Enter your Name: ";

	std::string userName {};
        std::getline(std::cin, userName);//имя пользователя

	std::cout << "Здравствуйте, " << userName << '!' << " Вам пришло сообщение от объекта " << nameObj <<" с кодовым именем " << codeName <<'.'<< " Объект пересылает координаты местоположения: " << x << ',' << y << ',' << z << ',' << "ее состояние " << answer << " подпись: " << symbol << std::endl;
	return 0;
}

