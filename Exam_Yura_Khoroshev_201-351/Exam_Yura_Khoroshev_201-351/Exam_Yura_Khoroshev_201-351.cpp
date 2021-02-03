#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int num_of_args(vector <bool> f)
{
	int n, s;
	n = f.size();
	s = pow(2, n);
	return s;
}

vector <bool> read_from_file(string file_name, vector<bool> f)
{

}

bool write_to_file(string file_name, vector<bool> f)
{

}

string table(vector<bool> f)
{

}

string func_sdnf(vector<bool> f)
{

}

string func_schf(vector<bool> f)
{

}

string func_Zhegalkin(vector<bool> f)
{

}


int main()
{

    setlocale(LC_ALL, "Russian");
    while (true)
    {
        string file_name;
        vector <bool> f;
        int N;
        cout << "1.Проверка на палиндром\n";
        cout << "2.Поиск выпуклой оболочки\n";
        cout << "3.Выход\n";
        cin >> N;
        switch (N)
        {
        case 1:
            int num_of_args(vector <bool> f);
            break;
        case 2:

            break;

        case 3:
            break;
        default:
            break;
        }
    }
}

