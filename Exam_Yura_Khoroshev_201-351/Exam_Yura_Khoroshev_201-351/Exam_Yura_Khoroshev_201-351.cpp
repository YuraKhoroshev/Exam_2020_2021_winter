#include <iostream>
#include <vector>
#include <string>
#include "Header.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main()
{

    setlocale(LC_ALL, "Russian");

    while (true)
    {
        string file_name;
        int k;
        std::string input_str = "bmhhbmbmnbbbbnnndfghjkl";
        std::string roman_number = "LLMMIVII";
        vector <bool> f;
        int N;
        cout << "1.\n";
        cout << "2.\n";
        cout << "3.\n";
        cin >> N;
        switch (N)
        {
        case 1:
            roman_to_arab(roman_number);
            break;
        case 2:
            std::cin >> k;
            func_Pascal(k);
            break;

        case 3:
            func_substr_len(input_str);
            break;
        default:
            break;
        }
    }
}

