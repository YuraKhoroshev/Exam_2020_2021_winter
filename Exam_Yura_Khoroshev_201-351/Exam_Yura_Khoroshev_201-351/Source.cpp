#include "Header.h"
#include <iostream> 
#include <vector>
#include <fstream>
#include <sstream>
#include <set> 

/*
int num_of_args(std::vector <bool> f) // ���������� ���������� ����������
{
	int n, s;
	n = f.size();
	s = pow(2, n);
	return s;
}

std::vector <bool> read_from_file(std::string file_name, std::vector<bool> f) // ���� �� �����
{
	std::string buf;
	bool bufb;
	std::ifstream file(file_name);
	if (file.is_open()) // ���� � ����� 
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


std::string table(std::vector<bool> f) // ������� ������� ����� ������� � �������� �������, ��� ������� ����������
{
	std::ostringstream out; // ������ ��� ����������
	int y = num_of_args(f); 
	int n = f.size(); 
	for (int i = 0; i < y; i++) 
	{
		out << "x" << i  <<"\t";
	}
	out<<"f"<<"\n";

	for (int i = 0; i < n; i++) {
		int* t = dec2bin(i, y); // ���������� ����� � �������� �������
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
		int r = f.back(); // ����� �������� �������
		f.pop_back(); // ������� ��� �� �������
		if (r == 1) 
		{
			int* t = dec2bin(i, y); 
			out << "(";
			for (int j = 0; j < y; j++) // j ����� �, ���� ���������� ���� �������� � �������
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
			if (i + 1 == n) // ���� ����� ������ ����, �� ����� ���� ������
			{
				out << ")";
			}
			else 
			{
				out << ")v"; // ���� ���� ��� ��������, �� ����� ������ + ����������
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
		int r = f.back();// ����� �������� �������
		f.pop_back();
		if (r == 0) 
		{
			int* t = dec2bin(i, y);// ����� � �������� ������
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

int* dec2bin(int num, int size) // ������� ��� ��������� ����� � �������� ���
{

	int* bin = new int[size] {0};
	int* bin_r = new int[size];
	int j = 0;
	while (num)
	{

		bin[j] = (num % 2); // ������ ��� 0 � 1 ����� ������� �� ���� �� 2 

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
	// �� ����� 
}
*/

#include <map>;
int roman_to_arab(std::string roman_number)
{
	std::map <char, int> roman_to_arab;
	roman_to_arab['I'] = 1; // ������� � ������� ��� ����
	roman_to_arab['V'] = 5;
	roman_to_arab['X'] = 10;
	roman_to_arab['L'] = 50;
	roman_to_arab['C'] = 100;
	roman_to_arab['D'] = 500;
	roman_to_arab['M'] = 1000;

	int temp = 0;
	int result = 0;
	for (char c : roman_number) //��������� �������� � ������ � ��������
	{
		int n = roman_to_arab[c]; // ������� ����� �� �������
		if (n < temp) //���� ������� ������ ������ �����������, ������ �� ��� � ������� ������� � ������ �������
		{
			result += temp;
			temp = n;
		}
		else if (n > temp)
		{
			if (temp == 0) //� ���� ���������� ����� 0 ������ �� ������ ������ ����������
				temp = n;
			else //���� ���, �� �������� � �������
			{
				result += n - temp;
				temp = 0;
			}
		}
		else if (n == temp) //����� ���� ���������� � ������� �����
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
	return ((N < K) ? 0 : ((K == 0) ? 1 : ((N - K + 1) / double(K) * Cnk(N, K - 1)))); // ���������� ������ ������������ �������
}

std::vector<int> func_Pascal(int k) // ����� k ������ ������������ �������
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

//�� ������ ����(����������� ������)
int func_substr_len(std::string input_str)
{
	int first = 0;
	int result = 0;
	std::set<char> charSet; //������ set � ������� ����� ��������� ��� ������� ���������

	for (int i = 0; i < input_str.size(); i++) //���������� ������
	{
		if (charSet.find(input_str[i]) == charSet.end()) //���� ������� ���, ������ ���������
		{
			charSet.insert(input_str[i]);
		}
		else //���� �� ����, ��
		{
			if (charSet.size() > result) //���� ������ ��������� ������ ������� ����������
			{
				result = charSet.size(); //���������� ����� ��������
			}
			charSet.clear();
			first++;
			i = first;
		}
	}
	std::cout << result << std::endl;
	return result;
}