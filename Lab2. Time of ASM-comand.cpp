// Lab2. Time of ASM-comand.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

    using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    __int64 start, end, elapsed;

    for (int i = 0; i < 10; i++) {
        // Получаем текущее время
        __asm {
            rdtsc;          // Чтение временной метки процессора
            mov dword ptr[start], eax
                mov dword ptr[start + 4], edx // Сохраняем начальное время

                mov ecx, 0x11111111
                m1:
            MOV EAX, 1000; // Делимое
            MOV EDX, 0;    // Обнуляем остаток
            MOV EBX, 1;    // Делитель
            DIV EBX;       // EAX = EAX / EBX

            loop m1

                rdtsc;          // Чтение временной метки процессора
            mov dword ptr[end], eax
                mov dword ptr[end + 4], edx   // Сохраняем конечное время
        }

        // Рассчитываем разницу во времени
        elapsed = end - start;

        // Получаем текущее время
        __asm {
            rdtsc;          // Чтение временной метки процессора
            mov dword ptr[start], eax
                mov dword ptr[start + 4], edx // Сохраняем начальное время

                mov ecx, 0x11111111
                m2:
            MOV EAX, 1000; // Делимое
            MOV EDX, 0;    // Обнуляем остаток
            MOV EBX, 1;    // Делитель
            loop m2

                rdtsc;          // Чтение временной метки процессораы
            mov dword ptr[end], eax
                mov dword ptr[end + 4], edx   // Сохраняем конечное время
        }

        // Рассчитываем разницу во времени
        elapsed = elapsed - (end - start);

        std::cout << "Время выполнения команды в " << i + 1 << " итерации: " << elapsed / 286331153 << " тактов" << endl;
    }

    system("pause");

    return 0;
}