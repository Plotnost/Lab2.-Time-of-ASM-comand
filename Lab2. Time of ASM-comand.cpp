// Lab2. Time of ASM-comand.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <stdio.h>

int main()
{
    __int64 clock1 = 0xaabbccdd112233ff;
    __int64 clock2 = 0xaabbccdd112233ff;
    unsigned long long ticks1;
    unsigned long long ticks2;
    unsigned long long tick_of_comand;

    for (int i = 0; i <= 5; i++) {
        __asm
        {
            rdtsc; edx:eax
            mov dword ptr[clock1], eax
            mov dword ptr[clock1 + 4], edx

            mov ecx, 0x1fffffff
            m1:
            mov eax, 3
            add eax, 2
            mov eax, 3
            add eax, 2
            mov eax, 3
            add eax, 2
            mov eax, 3
            add eax, 2
            loop m1

            rdtsc; edx:eax
            mov dword ptr[clock2], eax
            mov dword ptr[clock2 + 4], edx

        }

        ticks1 = clock2 - clock1;

        clock1 = 0xaabbccdd112233ff;
        clock2 = 0xaabbccdd112233ff;

        __asm
        {
            rdtsc; edx:eax
            mov dword ptr[clock1], eax
            mov dword ptr[clock1 + 4], edx

            mov ecx, 0x1fffffff
            m2:
            loop m2

            rdtsc; edx:eax
            mov dword ptr[clock2], eax
            mov dword ptr[clock2 + 4], edx

        }

        ticks2 = clock2 - clock1;
        tick_of_comand = ticks1 - ticks2;

        printf("%lld\n%lld\n", ticks1, ticks2);
        printf("%f\n%lld\n", float(tick_of_comand / 536870911), tick_of_comand);
    }
    return 0;

}
