#include "Header.h"
#include <iostream>
#include <vector>
#include <fstream>

int num_of_args(std::vector <bool> f)
{
	int n, s;
	n = f.size();
	s = pow(2, n);
	return s;
}

std::vector <bool> read_from_file(std::string file_name, std::vector<bool> f)
{
	bool buf;
	std::ifstream file(file_name);
	if (file.is_open()) // ввод с файла где каждая строка через пробел имеет значения Фамилия Имя Возраст
	{
		int i = 0;
		while (!file.eof())
		{

			
			f.push_back(i);
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

std::string table(std::vector<bool> f)
{

}

std::string func_sdnf(std::vector<bool> f)
{

}

std::string func_schf(std::vector<bool> f)
{

}

std::string func_Zhegalkin(std::vector<bool> f)
{

}
