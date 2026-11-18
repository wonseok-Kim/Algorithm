// SWEA D3 1220. [S/W 문제해결 기본] 5일차 - Magnetic

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

void print(const std::vector<int>& v)
{
	for (int e : v)
	{
		std::cout << e << ' ';
	}
	std::cout << '\n';
}

int main()
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; ++tc)
	{
		int size;
		std::cin >> size;

		std::vector<std::vector<int>> table(size, std::vector<int>(size + 2));
		for (int i = 1; i <= size; ++i)
			for (int j = 0; j < size; ++j)
				std::cin >> table[j][i];

		int answer = 0;
		for (int i = 0; i < size; ++i)
		{
			auto& row = table[i];
			bool bMoved;
			//print(row);
			do
			{
				bMoved = false;
				for (int j = 1; j <= size; ++j)
				{
					if (row[j] == 1 && row[j + 1] == 0)
					{
						row[j] = 0;
						row[j + 1] = 1;
						bMoved = true;

					}
					else if (row[j] == 2 && row[j - 1] == 0)
					{
						row[j] = 0;
						row[j - 1] = 2;
						bMoved = true;
					}
/*
					if (bMoved)
						print(row);*/
				}
			} while (bMoved);

			bool b1 = false;
			for (int j = 1; j <= size; ++j)
			{
				if (!b1 && row[j] == 1)
				{
					b1 = true;					
				}
				else if (b1 && row[j] == 2)
				{
					answer += 1;
					b1 = false;
				}
			}
		}

		std::cout << '#' << tc << ' ' << answer << '\n';
	}


	return 0;
}