// Name: Twarit Waikar
// Enrollment number: 17114074

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<int, std::string> map;

std::string add(long n)
{
	if(n == 0)
	{
		map[n] = "0";
	}
	else if(n == 1)
	{
		map[n] = "1";
	}
	else
	{
		map[n] = map[n - 1] + map[n - 2];
	}

	return map[n];
}

bool replace(std::string& str, const std::string& from, const std::string& to)
{
	size_t start_pos = str.find(from);

	if(start_pos == std::string::npos)
	{
		return false;
	}

	str.replace(start_pos, from.length(), to);

	return true;
}

long long replaceAll(std::string& str, const std::string& from, const std::string& to)
{
	if(from.empty())
	{
		return 0;
	}

	size_t start_pos = 0;
	long long i = 0;

	while((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		i++;
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}

	return i;
}

int mainA1_2()
{
	int T = 0;
	std::cin >> T;

	int t = 0;
	while(t++ < T)
	{
		int N = 0;
		std::cin >> N;

		std::string P;
		std::cin.ignore();
		getline(std::cin, P);

		for(long i = 0; i < N + 1; ++i)
		{
			add(i);
		}

		std::cout << "Case " << t << ": " << replaceAll(map[N], P, "") << std::endl;
		std::cin.get();
	}

	return 0;
}
