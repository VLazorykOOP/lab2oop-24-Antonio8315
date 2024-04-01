#include <iostream>
#include <fstream>
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
    case 3: task3(); break;
    case 4: task4(); break;
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
    int i, j;


    char S[4][33], Shufr[4][32], Rozshufr[4][32], ch; 
    //відкриття текстового файлу
    ofstream ofs("in.txt");
    if (!ofs) {
        cout << "File not open \n";
    }
    if (ofs) {
        cout << "Input text 32 / 4: \n";
    }

    //запис у текстовий файл, добавляємо пробіли
    for (i = 0;i < 4;i++) {
        cin.get();
        cin.get(S[i], 33);
        ofs << S[i];
        int n = strlen(S[i]);
        for (j = n; j < 32; j++) {
            S[i][j] = '\0'; ofs << S[i][j];
        }
        ofs << endl;
    }
    
    
        ofs.close();
    
    
    //шифрування
    ifstream ifs("in.txt");
    if (!ifs) {
     cout << "File in.txt not open" << endl; 
    }
    else {
        for (i = 0;i < 4;i++) {
            ifs.get(S[i], 32);
        }
        unsigned char c;
        unsigned short sh_dat[64];
        unsigned short  l, b, k, t, r, w;
        for (i = 0;i < 4;i++) {
            for (j = 0;j < 32;j++) {
                r = i;
                w = j << 2;
                r |= w;
                c = S[i][j]; 
                t = c << 6;
                r |= t;

                b = 0; t = 1;
                for (k = 0;k < 16;k++) // обчислення біта парності
                {
                    if (r & t) {
                        if (b == 0) b = 1; else b = 0;
                    }
                    t <<= 1;
                }
                r |= b << 15;


                Shufr[i][j] = r;

            }

        }
    }
    ifs.close();
    //виведення шифрованого тексту на екран
    cout << "Shufr: \n";
    for (i = 0;i < 4;i++) {
        for (j = 0;j < 32;j++) { cout << Shufr[i][j]; }
        cout << "\n";
    }

    unsigned short sd2[128];
    sd2[i] = Shufr[i][j];
    for (i = 0;i < 128;i++) {
        cout << sd2[i];
    }
    ofstream ofsb("outb.bin", ios::out | ios::binary);
    for (i = 0;i < 4;i++) {
        ofsb.write((char*)Shufr[i][j], 32 * sizeof(unsigned short));
    }
    ofsb.write((char*)sd2[i], 128 * sizeof(unsigned short));
    
    ofs.close();

    //Розшифровка
    
    ifs.open("outb.dat", ios::in | ios::binary);
    short indi, indj;
    unsigned short  l, b, k, t, r, w;
    
        ifs.read((char*)sd2, 128 * sizeof(unsigned short));
    
    for (i = 0;i < 128;i++) {
        r = sd2[i];
        indj = r & 0x007c; // 0000 0000 0111 1100 = 0x007c
        indj >>= 2;
        indi = r & 0x0003; // 0000 0000 0000 0011 = 0x0003
        w = r & 0x7f80;    // 0111 1111 1000 0000 = 0x7f80 
        w >>= 7;
        ch = w;
        Rozshufr[indi][indj] = ch;

        
    }

    //Виведення розшифрованого тексту
    cout << "Rozshufr: " << endl;
    for (i = 0;i < 4; i++) {
        for (j = 0;j < 32; j++)
            cout << Rozshufr[i][j];
        cout << endl;
    }
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



