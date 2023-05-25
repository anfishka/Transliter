#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void transliterateText(string& inputFile, string& outputFile, bool russianToEnglish)
{
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open() || !output.is_open())
    {
        cout << "\x1b[31m������ �������� ������.\033[0m" << endl;
        return;
    }

    vector<pair<string, string>> translitTable;

    if (russianToEnglish)
    {
        translitTable = {
            {"�", "a"}, {"�", "b"}, {"�", "v"}, {"�", "g"}, {"�", "d"}, {"�", "e"},
            {"�", "yo"}, {"�", "zh"}, {"�", "z"}, {"�", "i"}, {"�", "y"}, {"�", "k"},
            {"�", "l"}, {"�", "m"}, {"�", "n"}, {"�", "o"}, {"�", "p"}, {"�", "r"},
            {"�", "s"}, {"�", "t"}, {"�", "u"}, {"�", "f"}, {"�", "kh"}, {"�", "ts"},
            {"�", "ch"}, {"�", "sh"}, {"�", "sch"}, {"�", ""}, {"�", "y"}, {"�", ""},
            {"�", "e"}, {"�", "yu"}, {"�", "ya"}, {"�", "w"}, {"�", "h"}
        };
    }
    else {
        translitTable = {
            {"a", "�"}, {"b", "�"}, {"v", "�"}, {"g", "�"}, {"d", "�"}, {"e", "�"},
            {"yo", "�"}, {"zh", "�"}, {"z", "�"}, {"i", "�"}, {"y", "�"}, {"k", "�"},
            {"l", "�"}, {"m", "�"}, {"n", "�"}, {"o", "�"}, {"p", "�"}, {"r", "�"},
            {"s", "�"}, {"t", "�"}, {"u", "�"}, {"f", "�"}, {"kh", "�"}, {"ts", "�"},
            {"ch", "�"}, {"sh", "�"}, {"sch", "�"}, {"yu", "�"}, {"ya", "�"}, {"w", "�"}, {"h", "�"}
        };
    }

    string line;

    while (getline(input, line))
    {
        string transliteratedLine;
        for (char c : line)
        {
            string currentSymbol(1, c);
            auto it = find_if(translitTable.begin(), translitTable.end(), [&](pair<string, string>& pair)
                {
                    return pair.first == currentSymbol;
                });

            if (it != translitTable.end())
            {
                transliteratedLine += it->second;
            }
            else
            {
                transliteratedLine += currentSymbol;
            }
        }
        output << transliteratedLine << endl;
}
        input.close();
        output.close();

        cout << "\x1b[33m����� ������� ����������������. ��������� �������� � �����: \033[0m" << outputFile << endl;
    
}