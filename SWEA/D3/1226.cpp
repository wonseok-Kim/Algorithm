// SWEA D3 1226. [S/W 문제해결 기본] 7일차 - 미로1

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

void PrintMaze(const char maze[][17])
{
	for (int i = 0; i < 16; ++i)
		cout << maze[i] << '\n';
	cout << '\n';
}

bool FindDest(char maze[][17], Point p)
{
	if (maze[p.y][p.x] == '3')
		return true;

	maze[p.y][p.x] = '1';
	//PrintMaze(maze);

	constexpr Point moves[4] = { {0, 1 }, {0, -1}, {1, 0}, {-1, 0} };
	for (int i = 0; i < 4; ++i)
	{
		Point next = { p.x + moves[i].x, p.y + moves[i].y };
		if (maze[next.y][next.x] != '1' && FindDest(maze, next))
			return true;
	}

	maze[p.y][p.x] = '0';
	return false;
}

int main(int argc, char** argv)
{
	FILE* ignore = freopen("input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; ++tc)
	{
		int num;
		cin >> num;

		Point startPos;
		char maz[16][17];
		for (int i = 0; i < 16; ++i)
		{
			for (int j = 0; j < 16; ++j)
			{
				cin >> maz[i][j];
				if (maz[i][j] == '2')
				{
					startPos = { i, j };
					maz[i][j] = '1';
				}
			}
			maz[i][16] = '\0';
		}
		
		cout << '#' << num <<  ' ' << (FindDest(maz, startPos) ? 1 : 0) << '\n';
	}

	return 0;
}