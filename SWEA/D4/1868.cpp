// SWEA D4 1868. 파핑파핑 지뢰찾기

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>

struct Point
{
	int X;
	int Y;
};

static const Point sDir[8] = { {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1} };

std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << '(' << p.X << ", " << p.Y << ')';
	return out;
}

void print(const std::vector<std::string>& board)
{
	//for (auto& line : board)
	//{
	//	std::cout << line << '\n';
	//}
	//std::cout << '\n';
}

void printStack(const std::stack<Point>& stk)
{
	//const auto& container = stk._Get_container();

	//std::cout << "stack: ";
	//for (Point p : container)
	//{
	//	std::cout << p << ", ";
	//}
	//std::cout << '\n';
}

int dfs(std::vector<std::string>& board, Point p)
{
	std::stack<Point> stk;
	stk.push(p);

	int cnt = 0;
	while (!stk.empty())
	{
		Point pt = stk.top();
		stk.pop();
		cnt += 1;
		
		int numMinesAround = 0;
		for (Point d : sDir)
		{
			Point next;
			next.X = pt.X + d.X;
			next.Y = pt.Y + d.Y;

			if (board[next.Y][next.X] == '*')
			{
				numMinesAround += 1;
			}
		}
		board[pt.Y][pt.X] = '0' + numMinesAround;

		if (numMinesAround > 0)
			continue;

		for (Point d : sDir)
		{
			Point next;
			next.X = pt.X + d.X;
			next.Y = pt.Y + d.Y;

			if (board[next.Y][next.X] == '.')
			{
				board[next.Y][next.X] = '-';
				stk.push(next);
			}
		}
	}

	return cnt;
}

int main()
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	std::cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		std::cin >> N;

		int numBooms = 0;
		std::vector<std::string> board(N + 2);

		board.front().resize(N + 2, '#');
		board.back().resize(N + 2, '#');
		for (int i = 1; i <= N; ++i)
		{
			board[i].resize(N + 2);
			board[i].front() = '#';
			std::cin >> &board[i][1];
			board[i].back() = '#';

			numBooms += (int)std::count(board[i].begin(), board[i].end(), '*');
		}

		//print(board);
		int answer = 0;
		int numExposed = 0;
		for (int row = 1; row <= N; ++row)
		{
			for (int col = 1; col <= N; ++col)
			{
				if (board[row][col] == '.')
				{
					bool bMineAround = false;
					for (Point d : sDir)
					{
						int nextRow = row + d.Y;
						int nextCol = col + d.X;
						if (board[nextRow][nextCol] == '*')
						{
							bMineAround = true;
							break;
						}
					}
					if (bMineAround)
						continue;

					numExposed += dfs(board, { col, row });
					answer += 1;
					//print(board);
					//__debugbreak();
				}
			}
		}
		answer += (N*N) - numExposed - numBooms;

		std::cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}