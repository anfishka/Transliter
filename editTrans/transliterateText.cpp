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
        cout << "\x1b[31mОшибка открытия файлов.\033[0m" << endl;
        return;
    }

    vector<pair<string, string>> translitTable;

    if (russianToEnglish)
    {
        translitTable = {
            {"а", "a"}, {"б", "b"}, {"в", "v"}, {"г", "g"}, {"д", "d"}, {"е", "e"},
            {"ё", "yo"}, {"ж", "zh"}, {"з", "z"}, {"и", "i"}, {"й", "y"}, {"к", "k"},
            {"л", "l"}, {"м", "m"}, {"н", "n"}, {"о", "o"}, {"п", "p"}, {"р", "r"},
            {"с", "s"}, {"т", "t"}, {"у", "u"}, {"ф", "f"}, {"х", "kh"}, {"ц", "ts"},
            {"ч", "ch"}, {"ш", "sh"}, {"щ", "sch"}, {"ъ", ""}, {"ы", "y"}, {"ь", ""},
            {"э", "e"}, {"ю", "yu"}, {"я", "ya"}, {"в", "w"}, {"х", "h"}
        };
    }
    else {
        translitTable = {
            {"a", "а"}, {"b", "б"}, {"v", "в"}, {"g", "г"}, {"d", "д"}, {"e", "е"},
            {"yo", "ё"}, {"zh", "ж"}, {"z", "з"}, {"i", "и"}, {"y", "й"}, {"k", "к"},
            {"l", "л"}, {"m", "м"}, {"n", "н"}, {"o", "о"}, {"p", "п"}, {"r", "р"},
            {"s", "с"}, {"t", "т"}, {"u", "у"}, {"f", "ф"}, {"kh", "х"}, {"ts", "ц"},
            {"ch", "ч"}, {"sh", "ш"}, {"sch", "щ"}, {"yu", "ю"}, {"ya", "я"}, {"w", "в"}, {"h", "х"}
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

        cout << "\x1b[33mТекст успешно транслитерирован. Результат сохранен в файле: \033[0m" << outputFile << endl;
    
}