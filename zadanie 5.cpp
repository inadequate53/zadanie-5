#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <sstream>

using namespace std;

void answer(const string& input) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    istringstream stream(input);
    string word;
    vector <string> shortWord, longWord;
    int shortLength = INT_MAX, longLength = INT_MIN;

    while (stream >> word) {
        int length = word.length();

        if (length < shortLength) {
            shortWord.clear();
            shortWord.push_back(word);
            shortLength = length;
        }
        else if (length == shortLength) {
            shortWord.push_back(word);
        }

        if (length > longLength) {
            longWord.clear();
            longWord.push_back(word);
            longLength = length;
        }
        else if (length == longLength) {
            longWord.push_back(word);
        }
    }

    cout << "Самое короткое слово: ";
    for (const auto& shortestWord : shortWord) {
        cout << shortestWord << " - " << shortLength << " символа " << endl;
    }

    cout << "Самое длинное слово: ";
    for (const auto& longestWord : longWord) {
        cout << longestWord << " - " << longLength << " символа " << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;
    cout << "Введите фразу: ";
    getline(cin, str);
    std::replace(str.begin(), str.end(), '?', ' ');
    std::replace(str.begin(), str.end(), '.', ' ');
    std::replace(str.begin(), str.end(), ',', ' ');
    std::replace(str.begin(), str.end(), '!', ' ');
    answer(str);

    return 0;
}