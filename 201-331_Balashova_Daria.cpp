#include <iostream> //ввод вывод
#include <vector> //библиотека работы с векторами
#include <string> //библиотека работы со строками 
#include <fstream> //библиотека рабоы с файлами
using namespace std;

int num_of_args(vector<bool> f)
{
	int n=0;// колличество элементов 
	while (pow(2, n) != f.size())
		n++;
	return  n;
}

vector<bool> read_from_file(string file_name)
{
	ifstream inf(file_name);//открываем файл для чтения
	vector <bool> f;
	while (inf)
	{
		bool i;
		inf >> i;//считываем 
		f.push_back(i);//добавляем в вектор
	}
	inf.close();
	return f;
}

bool write_to_file(string file_name, vector<bool> f)
{
	ofstream outf(file_name);//открываем файл для ввода
	int i = 0;
	for (int i = 0; i < f.size(); i++)
		outf << f[i] << ' ';//вводим в файл
	outf.close();
	return true;
}

string table(vector<bool> f)
{
	string tabl;
	int n = num_of_args(f);//находим количкство элементов 
	for (int i = 0; i <= n; i++)
		tabl += "x" + to_string(i) + " ";
	tabl += "f" + '\n';
	
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{

		}
		int bin;
		for (int j = 0; i > 0; j++)
		{
			bin += (i % 2) * pow(10.0, j);
			i /= 2;
		}
	}
	return tabl;
}
string func_sdnf(vector<bool> f)
{

}
std::string func_sknf(vector<bool> f)
{

}
std::string func_Zhegalkin(vector<bool> f)
{

}