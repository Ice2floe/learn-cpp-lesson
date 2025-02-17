#include <iostream>

// Шаблонная структура Triade
template <typename T>
struct Triade {
    T one {};
    T second {};  // Исправлено с "two" на "second"
    T third {};
};

// Использование CTAD для автоматического определения типов
template <typename T>
Triade(T, T, T) -> Triade<T>; // Исправлено для третьего аргумента

// Шаблонная функция для печати Triade
template <typename T>
void print(const Triade<T>& t0) {
    std::cout << '[' << t0.one << ", " << t0.second << ", " << t0.third << "] "; // Исправлено "two" на "second" и "to" на "t0"
}

int main() {
    Triade t1{1, 2, 3}; // Использует CTAD для выведения типов
    print(t1);


    Triade t2{1.2, 3.4, 5.6}; // Использует CTAD для выведения типов
    print(t2);

    return 0;
}
