﻿#include <iostream>
#include <cstdlib>

using namespace std;

// Функция для вычисления суммы цифр в числе независимо от знака
int elementSum(int n) {
    n = abs(n); // Преобразуем число в модуль его значения, чтобы учесть случаи отрицательных чисел
    int sum = 0;
    while (n != 0) {
        sum += n % 10;//к  sum добавляется последняя цифра числа n, 
                      //далее оператор % вычисляет остаток от деления числа n на 10, то есть последнюю цифру числа
        n /= 10; // оператор деления  удаляет последнюю цифру числа n, сдвигая его вправо на одну позицию
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian"); // Установка русской локализации

    int number;         // Переменная для хранения введенных чисел
    int maxNumber = 0;  // Для хранения максимального числа 
    int maxDigitSum = 0;// Для хранения суммы чисел максимального числа 

    // Ввод чисел с клавиатуры до тех пор, пока не будет введен 0
    do {
        cout << "Введите целое число  и нажмите Enter (для завершения введите 0): ";
        cin >> number;

        // Если введен 0, выходим из цикла
        if (number == 0)
            break;

        // Вычисляем сумму цифр в текущем числе
        int currentDigitSum = elementSum(number);

        // Если сумма цифр текущего числа больше суммы цифр максимального числа,
        // то обновляем максимальное число и его сумму цифр
        if (currentDigitSum > maxDigitSum) {
            maxNumber = number;
            maxDigitSum = currentDigitSum;
        }
    } while (true);

    // Выводим результат
    cout << "Число с максимальной суммой цифр: " << maxNumber << endl;

    return 0;
}