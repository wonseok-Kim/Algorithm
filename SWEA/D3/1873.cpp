// SWEA D3 1873. 상호의 배틀필드

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point
{
	int x;
	int y;
};

void PrintMap(const std::vector<std::string>& map)
{
	for (const auto& line : map)
	{
		cout << line << '\n';
	}
}

void Print( std::vector<std::string>& map)
{
	for (int i =1; i < map.size() - 1; ++i)
	{
		map[i].back() = '\0';
		cout << &map[i][1] << '\n';
	}
}

bool GetBreakableWallPos(const std::vector<std::string>& map, Point curPos, Point move, Point* outWallPos)
{
	while (true)
	{
		curPos.x += move.x;
		curPos.y += move.y;

		char ch = map[curPos.y][curPos.x];
		if (ch == '@' || ch == '#')
			return false;
		else if (ch == '*')
		{
			*outWallPos = curPos;
			return true;
		}
	}
}

int main(int argc, char** argv)
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	std::string impassable = "*#-@";
	std::string commands = "UDLR";
	std::string tanks = "^v<>";
	Point moves[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
	Point curPos;
	int curState;

	for (int tc = 1; tc <= T; ++tc)
	{
		int H, W;
		cin >> H >> W;

		std::vector<std::string> gameMap(H + 2, std::string(W + 2, '@'));
		for (int i = 1; i <= H; ++i)
		{
			for (int j = 1; j <= W; ++j)
			{
				cin >> gameMap[i][j];
				size_t idx = tanks.find(gameMap[i][j]);
				if (idx != std::string::npos)
				{
					curPos = { j, i };
					curState = (int)idx;
				}
			}
		}

		//PrintMap(gameMap);

		int N;
		cin >> N;

		for (int i = 0; i < N; ++i)
		{
			char command;
			cin >> command;

			switch (command)
			{
			case 'U':
			case 'D':
			case 'L':
			case 'R':
			{
				curState = (int)commands.find(command);
				Point next = { curPos.x + moves[curState].x, curPos.y + moves[curState].y };
				size_t idx = impassable.find(gameMap[next.y][next.x]);
				if (idx == std::string::npos)
				{
					gameMap[curPos.y][curPos.x] = '.';
					curPos = next;
				}
				gameMap[curPos.y][curPos.x] = tanks[curState];
			}
			break;
			case 'S':
			{
				Point wallPos;
				if (GetBreakableWallPos(gameMap, curPos, moves[curState], &wallPos))
				{
					gameMap[wallPos.y][wallPos.x] = '.';
				}
			}
			break;
			default:
				//__debugbreak();
				break;
			}

			//cout << command << '\n';
			//PrintMap(gameMap);
		}

		cout << '#' << tc << ' ';
		Print(gameMap);
	}

	return 0;
}