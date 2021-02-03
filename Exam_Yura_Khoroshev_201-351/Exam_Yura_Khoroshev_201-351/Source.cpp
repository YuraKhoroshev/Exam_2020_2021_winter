#include "Header.h"
#include <iostream> 
#include <vector>
#include <fstream>
#include <sstream>
#include <set> 

/*
int num_of_args(std::vector <bool> f) // нахождение количества аргументов
{
	int n, s;
	n = f.size();
	s = pow(2, n);
	return s;
}

std::vector <bool> read_from_file(std::string file_name, std::vector<bool> f) // ввод из файла
{
	std::string buf;
	bool bufb;
	std::ifstream file(file_name);
	if (file.is_open()) // ввод с файла 
	{
		int i = 0;
		while (!file.eof())
		{
			getline(file, buf, ' ');
			bufb = buf[0];
			f.push_back(buf[i]);
			i++;
		}
		file.close();
	}
	else
	{
		std::cout << "no fale\n";
	}
}

bool write_to_file(std::string file_name, std::vector<bool> f)
{

}


std::string table(std::vector<bool> f) // перевод массива чисел вектора в значение функции, как таблица истинности
{
	std::ostringstream out; // строка для результата
	int y = num_of_args(f); 
	int n = f.size(); 
	for (int i = 0; i < y; i++) 
	{
		out << "x" << i  <<"\t";
	}
	out<<"f"<<"\n";

	for (int i = 0; i < n; i++) {
		int* t = dec2bin(i, y); // преведение чисел в бинарную систему
		for (int j = 0; j < y; j++) {
			out << t[j] << " \t";
		}
		out << f.back();
		f.pop_back();
		out << "\n";
	}
	return out.str();

}


std::string func_sdnf(std::vector<bool> f) 
{
	std::ostringstream out;
	int y = num_of_args(f) + 1;
	int n = f.size();
	for (int i = 0; i < n; i++) 
	{
		int r = f.back(); // берем значение функции
		f.pop_back(); // удаляем его из вектора
		if (r == 1) 
		{
			int* t = dec2bin(i, y); 
			out << "(";
			for (int j = 0; j < y; j++) // j номер х, цикл записывает один дизьюнкт в скобках
			{
				if (t[j] == 0) {
					if (j + 1 == y) {
						out << "x" << j << '\'';
					}
					else {
						out << "x" << j << '\'' << '&';
					}
				}
				if (t[j] == 1) {
					if (j + 1 == y) {
						out << "x" << j;
					}
					else {
						out << "x" << j << '&';
					}
				}
			}
			if (i + 1 == n) // если конец строки сднф, то пишем одну скобку
			{
				out << ")";
			}
			else 
			{
				out << ")v"; // если есть ещё значения, то пишем скобка + дизьюнкция
			}
		}
	}
	return out.str();
}

std::string func_sknf(std::vector<bool> f) 
{
	std::ostringstream out;
	int y = num_of_args(f) + 1;
	int n = f.size();
	for (int i = 0; i < n; i++) {
		int r = f.back();// берем значение функции
		f.pop_back();
		if (r == 0) 
		{
			int* t = dec2bin(i, y);// число в двоичной записи
			out << "(";
			for (int j = 0; j < y; j++) 
			{
				if (t[j] == 0) 
				{
					if (j + 1 == y) 
					{
						out << "x" << j << '\'';
					}
					else 
					{
						out << "x" << j << '\'' << 'v';
					}
				}
				if (t[j] == 1) 
				{
					if (j + 1 == y) 
					{
						out << "x";
						out << j;
					}
					else 
					{
						out << "x" << j << 'v';
					}
				}
			}
			if (i == n) 
			{
				out << ")";
			}
			else 
			{
				out << ")&";
			}
		}
	}
	return out.str();
}

int* dec2bin(int num, int size) // функция для перревода числа в бинарный вид
{

	int* bin = new int[size] {0};
	int* bin_r = new int[size];
	int j = 0;
	while (num)
	{

		bin[j] = (num % 2); // массив для 0 и 1 после деления на цело на 2 

		num /= 2;
		j++;
	}

	for (int i = 0; i < size; i++) 
	{
		bin_r[size - i - 1] = bin[i];
	}

	return bin_r;
}

std::string func_Zhegalkin(std::vector<bool> f)
{
	// не успел 
}
*/

#include <map>;
int roman_to_arab(std::string roman_number)
{
	std::map <char, int> roman_to_arab;
	roman_to_arab['I'] = 1; // словарь с ключами для мапа
	roman_to_arab['V'] = 5;
	roman_to_arab['X'] = 10;
	roman_to_arab['L'] = 50;
	roman_to_arab['C'] = 100;
	roman_to_arab['D'] = 500;
	roman_to_arab['M'] = 1000;

	int temp = 0;
	int result = 0;
	for (char c : roman_number) //переборка символов в строке с римскими
	{
		int n = roman_to_arab[c]; // текущая цифра из словаря
		if (n < temp) //если текущий символ меньше предыдущего, значит мы идём в меньшую сторону и просто плюсуем
		{
			result += temp;
			temp = n;
		}
		else if (n > temp)
		{
			if (temp == 0) //и если предыдущая равна 0 значит мы только начали перебирать
				temp = n;
			else //если нет, то ситуация с вычетом
			{
				result += n - temp;
				temp = 0;
			}
		}
		else if (n == temp) //сумма если предыдущий и текущий равны
		{
			result += temp + n;
			temp = 0;
		}
	}
	std::cout << result + temp << std::endl;
	return result + temp;
}


double Cnk(int N, int K)
{
	return ((N < K) ? 0 : ((K == 0) ? 1 : ((N - K + 1) / double(K) * Cnk(N, K - 1)))); // вычисление строки треугольника паскаля
}

std::vector<int> func_Pascal(int k) // вывод k строки треугольника паскаля
{
	for (int j = 0; j <= k; j++)
	{
		if (j == k)
		{
			for (int i = 0; i <= j; i++)
			{
				std::cout << Cnk(j, i) << " ";
			}
		}
	}
}

//на основе сета(уникального набора)
int func_substr_len(std::string input_str)
{
	int first = 0;
	int result = 0;
	std::set<char> charSet; //создаём set в котором будут храниться все символы подстроки

	for (int i = 0; i < input_str.size(); i++) //перебираем строку
	{
		if (charSet.find(input_str[i]) == charSet.end()) //если символа нет, значит добавляем
		{
			charSet.insert(input_str[i]);
		}
		else //если же есть, то
		{
			if (charSet.size() > result) //если размер подстроки больше размера предыдущей
			{
				result = charSet.size(); //записываем новое значение
			}
			charSet.clear();
			first++;
			i = first;
		}
	}
	std::cout << result << std::endl;
	return result;
}