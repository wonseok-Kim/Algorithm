// SWEA D4 2819. 격자판의 숫자 이어 붙이기 

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

struct Point
{
	int X;
	int Y;
};

static const Point DIRS[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

std::vector<std::string> table(6, std::string(6, '#'));
std::set<std::string> comb;

void dfs(Point p, std::string& str)
{
	str.push_back(table[p.Y][p.X]);

	if (str.length() == 7)
	{
		comb.insert(str);
		str.pop_back();
		return;
	}

	for (Point dir : DIRS)
	{
		Point next = { p.X + dir.X, p.Y + dir.Y };
		if (table[next.Y][next.X] == '#')
			continue;
		
		dfs(next, str);
	}

	str.pop_back();
}

int main()
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	std::cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		comb.clear();

		for (int row = 1; row <= 4; ++row)
		{
			for (int col = 1; col <= 4; ++col)
			{
				std::cin >> table[row][col];
			}
		}

		std::string str;
		str.reserve(7);
		for (int row = 1; row <= 4; ++row)
		{
			for (int col = 1; col <= 4; ++col)
			{
				dfs({ col, row }, str);
			}
		}

		int answer = (int)comb.size();
		std::cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}
