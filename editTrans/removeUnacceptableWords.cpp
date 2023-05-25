#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void removeUnacceptableWords(string& inputFile, string& unacceptableFile, string& outputFile) {

    ifstream input(inputFile);
    ifstream unacceptable(unacceptableFile);
    ofstream output(outputFile);


    if (!input.is_open() || !unacceptable.is_open() || !output.is_open()) {
        cout << "\x1b[31mОшибка открытия файлов.\033[0m" << endl;
        return;
    }

    vector<string> unacceptableWords;
    string word;
    while (unacceptable >> word) {
        unacceptableWords.push_back(word);
    }

    string line;
    while (getline(input, line)) {

        vector<string> words;
        string currentWord;
        for (char c : line) {
            if (isalpha(c)) {
                currentWord += c;
            }
            else {
                if (!currentWord.empty()) {
                    words.push_back(currentWord);
                    currentWord.clear();
                }
            }
        }
        if (!currentWord.empty()) {
            words.push_back(currentWord);
        }

        for (string& word : words) {
            if (find(unacceptableWords.begin(), unacceptableWords.end(), word) == unacceptableWords.end()) {
                output << word << " ";
            }
        }
        output << endl;
    }

    input.close();
    unacceptable.close();
    output.close();

    cout << "\x1b[33mУбраны неприемлемые слова. Результат сохранен в файле: \033[0m" << outputFile << endl;
}
