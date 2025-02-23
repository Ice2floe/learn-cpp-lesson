#include <iostream>

class Eva 
{
private:
    int m_health{100};
    double m_shovelDurability{37.5}; // Переименовал для ясности
    bool m_magicEva{false};
    bool m_deviceActive{false};      // Добавил устройство связи

public:
    Eva() {
        printGetStart();
    }

    int getHealth() { return m_health; }
    double getShovel() { return m_shovelDurability; }
    bool getMagic() { return m_magicEva; }
    bool getDevice() { return m_deviceActive; }

    void useMagic() { m_magicEva = true; }   // Метод для активации магии
    void activateDevice() { m_deviceActive = true; } // Активация устройства

    void printGetStart() const {
        std::cout << "Ева имеет: " << m_health << " здоровья, "
                  << m_shovelDurability << " - прочность лопаты, "
                  << "магия: " << (m_magicEva ? "активна" : "неактивна") << ", "
                  << "устройство связи: " << (m_deviceActive ? "активно" : "неактивно") << '\n';
    }
};

void evaShovel(Eva& eva) {
    double shovelDurability{eva.getShovel()};
    int healthScientists{100}; // Начальное здоровье учёных
    int danger{15};            // Урон от вихря за ход
    int digs{0};               // Счётчик копаний

    while (digs < 3 && shovelDurability > 0) {
        std::cout << "Ева копает снег! (попытка " << digs + 1 << ")\n";
        shovelDurability -= 12.5; // Уменьшение прочности лопаты
        digs++;

        // Вихрь наносит урон учёным
        healthScientists -= danger;
        std::cout << "Здоровье учёных: " << healthScientists << '\n';

        // Уменьшение опасности после копания
        if (digs == 2) {
            danger = 5; // Буря слабеет
            eva.useMagic(); // Активируем магию
            std::cout << "Буря ослабла, Ева применила магию!\n";
        }

        // Устройство связи активируется, если магия включена и лопата почти сломана
        if (eva.getMagic() && shovelDurability <= 12.5) {
            eva.activateDevice();
            std::cout << "Устройство связи активировано, помощь в пути!\n";
            break; // Прерываем цикл, помощь вызвана
        }
    }

    if (healthScientists > 0) {
        std::cout << "Ева спасла учёных! Остаток здоровья: " << healthScientists << '\n';
    } else {
        std::cout << "Учёные не выжили...\n";
    }
}

int main() {
    Eva eva{};
    evaShovel(eva);
    return 0;
}
