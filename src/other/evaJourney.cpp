#include <iostream>
#include <cmath>

double lenght_aravia (double araviax,double araviay)
{
	return sqrt ((araviax * araviax) + (araviay*araviay));
}

double lenght_rysnya (double rysnyax, double rysnyay)
{
	return sqrt ((rysnyax*rysnyax)+(rysnyay*rysnyay));
}

double lenght_monga (double mongax, double mongay){
	return sqrt ((mongax*mongax)+(mongay*mongay));
}

int main ()
{
	std::cout << "Ева хочет узнать, куда ей отправиться, введите координаты следующих мест через пробел (x,y): " << '\n';

	std::cout << "Аравия: ";
	double araviax {}, araviay {};
	std::cin >> araviax >> araviay;

	std::cout << "Рысня: ";
	double rysnyax {}, rysnyay {};
	std::cin >> rysnyax >> rysnyay;

	std::cout << "Монга: ";
	double mongax {}, mongay {};
	std::cin >> mongax >> mongay;

	double saravia {lenght_aravia(araviax,araviay)};
	double srysnya {lenght_rysnya(rysnyax,rysnyay)};
	double smonga {lenght_monga (mongax,mongay)};

	if ((saravia<srysnya)&&(saravia<smonga))
	{
		std::cout << "Еве ближе всего к Аравии, поэтому она в жаркую страну!\n";
	}
	else if ((srysnya<saravia)&&(srysnya<smonga))
	{
		std::cout << "Ева хочет в родные края, ее там встретит офицер Рысь, так как ей ближе!" <<'\n';
	}
	else if ((smonga<saravia&&(smonga<srysnya)))
	{
		std::cout << "Эта страна диких джунглей, Ева не любит такие места, но через них она сможет попасть в Мексику!" << '\n';
	}
	else
	{
		std::cout << "Ева запуталась, она не знает, куда ей ближе всего путешествовать!" << '\n';
	}
	return 0;
}
	

