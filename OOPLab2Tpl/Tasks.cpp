#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Examples of problems using bitwise operations \n";
    int num;
    cout << "    6.  Exit \n";
    cout << " Input num \n";
    cin >> num;
    switch (num) {
    case 1: task1(); break;
    case 2: task2(); break;
    default: cout << "No number";
    }
}
void task1() {  
    int a, b, c, d;
    int x, x1, x2;
    std::cout << "Input a: ";
    std::cin >> a;
    std::cout << "Input b: ";
    std::cin >> b;
    std::cout << "Input c: ";
    std::cin >> c;
    std::cout << "Input d: ";
    std::cin >> d;
    x2 = (15 * a + 312 * b) / 64 - 120 * c + 121 * d;
    x1 = ((a * 16 - a) + (b * 256) + (b * 64) - (b * 8)) / 64 - (c * 128 - c * 8) + (d * 128 - d * 8 + d);
    x = ((((a << 4) - a) + ((b << 8) + (b << 6) - (b << 3))) >> 6) - (c << 7) + (c << 3) + (d << 7) - (d << 3) + d;
    
    //cout << "x1= " << x1 << "\n";
    cout << "x= " << x << "\n";
    cout << "x1= " << x1 << "\n";
    cout << "x2= " << x2 << "\n";
    // Обчислення виразів з використанням побітових операцій
    // Calculation of expressions using bitwise operations 
    cout << " Calculation of expressions using bitwise operations  \n";
}

void task2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations  \n";

}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields \n";
}


void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

}



