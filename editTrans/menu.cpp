#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "menu.h"
#include "removeUnacceptableWords.h"
#include "transliterateText.h"
using namespace std;

void menu()
{
    setlocale(LC_ALL, "");
    int choice;

    do
    {
        cout << "\x1b[31mМеню:" << endl;
        cout << "\x1b[32m1. Удалить неприемлемые слова из текстового файла.\033[0m" << endl;
        cout << "\x1b[32m2. Транслитерация с русского на английский и наоборот.\033[0m" << endl;
        cout << "\x1b[32m3. Exit." << endl;
        cout << "\x1b[33mВыберите опцию (1,2,3): ";
        cin >> choice;

        if (choice == 1) {
            string inputFile, unacceptableFile, outputFile;
            cout << "\x1b[33mВведите имя входного файла: \033[0m";
            cin >> inputFile;
            cout << "\x1b[33mВведите имя файла с неприемлемыми словами: \033[0m";
            cin >> unacceptableFile;
            cout << "\x1b[33mВведите имя выходного файла: \033[0m";
            cin >> outputFile;

            removeUnacceptableWords(inputFile, unacceptableFile, outputFile);
        }
        else if (choice == 2) {
            string inputFile, outputFile;
            char direction;
            cout << "\x1b[33mВведите имя входного файла: \033[0m";
            cin >> inputFile;
            cout << "\x1b[33mВведите имя выходного файла: \033[0m";
            cin >> outputFile;
            cout << "\x1b[33mВыберите направление перевода (r - с русского на английский, e - с английского на русский): \033[0m";
            cin >> direction;

            bool russianToEnglish = (direction == 'r' || direction == 'R');
            transliterateText(inputFile, outputFile, russianToEnglish);
        }
        else if (choice == 3) {
            return;
        }
        else {
            cout << "\x1b[31mНеверный выбор.\033[0m" << endl;
        }
    } while (choice != 3);
}