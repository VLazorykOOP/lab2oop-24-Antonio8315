#include <bitset>
#include <iostream>
#include <fstream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
using std::cout;
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    int num;
    cout << " Input num \n";
    cin >> num;
    switch (num) {
    case 1: task1(); break;
    case 2: task2(); break;
    default: cout << "No number";
    }
}
void task1() {  
    // Обчислення виразів з використанням побітових операцій
    // Calculation of expressions using bitwise operations 

    //оголошення змінних
    int a, b, c, d;
    int x, x1, x2;

    //введення користувачем значень змінних
    std::cout << "Input a: ";
    std::cin >> a;
    std::cout << "Input b: ";
    std::cin >> b;
    std::cout << "Input c: ";
    std::cin >> c;
    std::cout << "Input d: ";
    std::cin >> d;

    //перевірка результату звичайним множенням/діленням
    x2 = (15 * a + 312 * b) / 64 - 120 * c + 121 * d;

    //перевірка результату множенням/діленням на числа, що = 2^n
    x1 = ((a * 16 - a) + (b * 256) + (b * 64) - (b * 8)) / 64 - (c * 128 - c * 8) + (d * 128 - d * 8 + d);

    //результат, що обчислюється з використанням побітових операцій
    x = ((((a << 4) - a) + ((b << 8) + (b << 6) - (b << 3))) >> 6) - (c << 7) + (c << 3) + (d << 7) - (d << 3) + d;
    
    //виведення на екран перевірок результату і самого результату
    cout << "x1= " << x1 << "\n";
    cout << "x2= " << x2 << "\n";

    //результат
    cout << "Vidpovid = " << x << "\n";
}

void task2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations  \n";
    
    //оголошення змінних
    char S[4][33], Rozshufr[4][33];
    unsigned short Shufr[4][33];
    int i, j;

    //відкриття текстового файлу
    ofstream ofs("in.txt");

    //Перевірка чи відкривається файл
    if (!ofs) {
        cout << "File not open \n";
    }

        cout << "Input text 32 / 4: \n";

    //запис у текстовий файл, добавляємо пробіли
    for (i = 0;i < 4;i++) {
        cin.get();
        cin.get(S[i], 33);
        ofs << S[i];
        int n = strlen(S[i]);
        for (j = n; j < 32; j++) {
            S[i][j] = '\0'; ofs << S[i][j];
        }
         
    }
    //закриття текстового файлу
    ofs.close();


    //ШИФРУВАННЯ
    
    //відкриття текстового файлу для читання
    ifstream ifs("in.txt");

    //перевірка чи відкривається файл
    if (!ifs) {
        cout << "File in.txt not open" << endl;
    }

    else {
        //зчитуємо інформацію з файлу
        for (i = 0;i < 4;i++) {
            ifs.get(S[i], 33);
        }

        //оголошення системних змінних для шифрування
        unsigned char c;
        unsigned short b, k, t, r, w;

        //механізм шифрування
        for (i = 0;i < 4;i++) {
            for (j = 0;j < 32;j++) {
                r = i;
                w = j << 2;
                r |= w;
                c = S[i][j];
                t = c << 7;
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
    //закриття файлу
    ifs.close();

    //виведення шифрованого тексту на екран (у форматі unsigned short)
    cout << "\nShufr (unsigned short): \n";
    for (i = 0;i < 4;i++) {
        for (j = 0;j < 32;j++) { cout << Shufr[i][j]; }
        cout << "\n";
    }

    //оголошення системних змінних
    unsigned short sd2[128];
    int l1 = 0;

    //виведення шифрованого тексту на екран (у форматі char)
    cout << "\nShufr (char): \n";
    for (i = 0, l1 = 0;i < 4;i++) {
        for (j = 0;j < 32;j++) {
            sd2[l1] = Shufr[i][j];
            cout << (char)sd2[l1]; l1++;
        }
        cout << endl;
    }

    //відкриття бінарного файлу, запис зашифрованого тексту у бінарний файл
    ofstream ofsb("outb.bin", ios::out | ios::binary);

    //запис зашифрованих даних у бінарний файл
    for (i = 0;i < 4;i++) {
        ofsb.write((char*)Shufr, 128 * sizeof(unsigned short));
    }

    //закриття файлу
    ofs.close();



    //РОЗШИФРОВКА

    cout << "\n\nRozshufrovka...\n";
    //відкриття бінарного файлу для читання
    ifs.open("outb.dat", ios::in | ios::binary);

    //оголошення системних змінних для розшифровки
    short indi, indj;
    unsigned short r, w, ch;

    //зчитування даних з файлу
    ifs.read((char*)sd2, 128 * sizeof(char));
    cout << endl;
    
    //механізм розшифровки
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
    
    //Виведення розшифрованого тексту на екран
    cout << "Rozshufr: " << endl;
    for (i = 0;i < 4; i++) {
        for (j = 0;j < 32; j++)
            cout << Rozshufr[i][j];
        cout << endl;
    }

    //відкриття файлу для запису
    ofstream ofs1("Rozviazok.txt");

    //перевірка чи відкривається файл
    if (!ofs1) {
        cout << "File not open \n";
    }
    else {
        //запис розшифрованих даних у текстовий файл
        for (i = 0;i < 4; i++) {
            ofs1.write((char*)Rozshufr[i], 32 * sizeof(char));
            ofs1 << endl;
        }
    }

    //закриття файлу
    ofs1.close();
}