#include <iostream>
#include <string>

// Функции для игры "Оборона Киева"
int attackpvo(int moskalpower, int deftower, bool &pvoEnabled) {
    int pvoattack{20};
    if (deftower > 0 && pvoEnabled) {
        std::cout << "- Ваши ПВО истощают врага, отпразднуйте салом! \n";
        int newMoskalPower = moskalpower - pvoattack;
        if (newMoskalPower < 0) {
            return 0;
        }
        return newMoskalPower;
    } else if (moskalpower <= 0) {
        std::cout << "ПВО полностью истощило врага!\n";
        return 0;
    } else {
        if (pvoEnabled) {
            std::cout << "- Сало закончилось, как и Ваше ПВО!\n";
        } else {
            std::cout << "- ПВО не активно и не может стрелять!\n";
        }
        return moskalpower;
    }
}

int attackmoskal(int deftower, int moskalpower, bool pvoEnabled) {
    int moskalattack{20};
    if (pvoEnabled) {
        if (moskalpower == 100) {
            std::cout << "- Москали атакуют разрушая город!!!\n";
            deftower -= moskalattack;
        } else if (100 > moskalpower && moskalpower >= 80) {
            std::cout << "- истребители СУ бомбят столицу (атака теперь равна 25)\n";
            deftower -= (moskalattack + 5);
        } else if (80 > moskalpower && moskalpower >= 60) {
            std::cout << "- москали зляться, теперь они используют Т90 (атака равна 30)\n";
            deftower -= (moskalattack + 10);
        } else if (60 > moskalpower && moskalpower >= 40) {
            std::cout << "- Путин стуча пынеходами вызвал резонанс у москалей (атака равно 35)\n";
            deftower -= (moskalattack + 15);
        } else if (40 > moskalpower && moskalpower > 0) {
            std::cout << "- СУПЕРОРЕШНИК атакует снося половину города!(атака равно 50)\n";
            deftower -= (moskalattack + 30);
        } else {
            std::cout << "- запас врага исчерпан!\n";
        }
    } else {
        std::cout << "- ПВО не активно, враг не атакует!\n";
    }
    return deftower;
}

int healthtower(int deftower, bool pvoEnabled) {
    if (pvoEnabled) {
        std::cout << "- Восстановление города невозможно, ПВО активно!!!\n";
        return deftower;
    }
    std::cout << "- Вы пытаетесь восстановить город из говна, палок и черного хлеба с салом, город немного восстановлен!\n";
    int health{20};
    if (deftower >= 100) {
        std::cout << "- Вам нравится жрать говно? Хохлы уже наелись говна и палок!\n";
        return 100;
    } else {
        return deftower += health;
    }
}

std::string getTowerState(int deftower) {
    if (deftower >= 100) {
        return std::string("Город полностью целый!");
    } else if (deftower >= 80) {
        return std::string("В Киеве не кладут больше асфальт!");
    } else if (deftower >= 60) {
        return std::string("Жители незалежной укрываются обломками бетона!");
    } else if (deftower >= 40) {
        return std::string("Жители Киева теперь едят крыс в метро!");
    } else if (deftower >= 20) {
        return std::string("Киявлянчане больше не взломают сервера РКН!");
    } else {
        return std::string("Боевые комары высасывают кровь в ядерном тумане!");
    }
}

void printState(bool pvoEnabled, bool isVictory = false) {
    if (isVictory) {
        std::cout << "- Атаковать нет смысла уже, празднуем советским салом!\n";
    } else {
        std::cout << "Состояние ПВО: " << (pvoEnabled ? "Активно" : "Не активно") << "\n";
    }
}

void defkiev() {
    int deftower = 100;
    int moskalpower = 100;
    bool pvoEnabled = false;

    while (true) {
        std::cout << "Москали вошли в столицу Незалежной, что будете делать?\n1)Защита Киева\n2)восстановить город\n3)Активировать/Деактивировать ПВО\n4)Выйти в главное меню\nваш выбор:";
        int choicedef{};
        std::cin >> choicedef;

        if (choicedef == 1) {
            if (!pvoEnabled) {
                std::cout << "- Внимание ПВО не активно, враг не атакует!\n";
            }
            if (deftower > 0) {
                moskalpower = attackpvo(moskalpower, deftower, pvoEnabled);
                deftower = attackmoskal(deftower, moskalpower, pvoEnabled);
                std::cout << "Состояние города: " << getTowerState(deftower) << "\n"; // Вывод состояния города после атаки
            }
        } else if (choicedef == 2) {
            if (!pvoEnabled) {
                std::cout << "- Восстановление города происходит безопасно, враг не атакует!\n";
            }
            deftower = healthtower(deftower, pvoEnabled);
            std::cout << "Состояние города: " << getTowerState(deftower) << "\n"; // Вывод состояния города после лечения
        } else if (choicedef == 3) {
            pvoEnabled = !pvoEnabled;
            if (pvoEnabled) {
                std::cout << "- ПВО активировано!!!\n";
            } else {
                std::cout << "- ПВО деактивировано!!!\n";
            }
        } else if (choicedef == 4) {
            std::cout << "Возвращаемся в главное меню...\n";
            break;
        } else {
            std::cout << "- Не бойся, твои предки копали черное море, а ты не можешь принять решения?\n";
        }

        if (deftower <= 0) {
            std::cout << "- Kличко теперь Мэр города Майами!\n"
                      << "- ПВО больше нечем стрелять!\n"
                      << "- Город полностью разрушен, вы проиграли!\n";
            break;
        } else if (moskalpower <= 0) {
            std::cout << "- Поздравляю, вы подебил, теперь вы глава сельского разрушенного толчка и то без унитазов, стоило ли оно того?\n"
                      << "Состояние города: " << getTowerState(deftower) << "\n";
            printState(pvoEnabled, true); // Сообщение о победе
            break;
        } else {
            printState(pvoEnabled); // Обычное состояние ПВО
        }
    }
}

// Мини-игра "Угадай слово"
int guesshohol() {
    std::cout << "Если вы из незалежной, попробуйте ввести букву (только строчные буковкii): ";
    char wordhol{};
    std::cin >> wordhol;
    std::cout << "хм... буква " << wordhol << '\n';
    return static_cast<int>(wordhol);
}

void hohloword() {
    const int targethol{static_cast<int>('u') + static_cast<int>('k') + static_cast<int>('r') + static_cast<int>('a') + static_cast<int>('i') + static_cast<int>('n') + static_cast<int>('e')};

    int letterone{guesshohol()};
    int lettertwo{guesshohol()};
    int lettertre{guesshohol()};
    int letterfour{guesshohol()};
    int letterfive{guesshohol()};
    int lettersix{guesshohol()};
    int letterseven{guesshohol()};
    int resulthol{letterone + lettertwo + lettertre + letterfour + letterfive + lettersix + letterseven};

    if (resulthol == targethol) {
        std::cout << "Вы истинный патриот Украины, так держать!\n";
    } else {
        std::cout << "Что ж, ваше руководство недовольно вами, вас сослали в Магадан, где вы с Гордоном ловите птиц, как падающие сосульки!\n";
    }
}

// Главное меню
int main() {
    while (true) {
        std::cout << "В какую игру вы хотите сыграть?\n1) Оборона Киева\n2) Угадай слово\n3) Выйти\nваш выбор: ";
        int choice{};
        std::cin >> choice;

        switch (choice) {
            case 1:
                defkiev(); // Запуск игры "Оборона Киева"
                break;
            case 2:
                hohloword(); // Запуск мини-игры "Угадай слово"
                break;
            case 3:
                std::cout << "Выход из программы...\n";
                return 0;
            default:
                std::cout << "Неверный выбор! Попробуйте снова.\n";
                break;
        }
    }
}
