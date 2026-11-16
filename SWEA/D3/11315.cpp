// SWEA D3 11315. 오목 판정

#define _CRT_SECURE_NO_WARNINGS

//#include <algorithm>
//#include <cstdlib>
#include <iostream>
//#include <list>
#include <string>
#include <vector>

using namespace std;

struct Point
{
	int X;
	int Y;
};

class Solution
{
public:
	Solution(int N)
		: mBoard(N)
	{
		for (int i = 0; i < N; ++i)
		{
			cin >> mBoard[i];
		}
	}

	bool Run()
	{
		bool bAnswer;
		for (int row = 0; row < mBoard.size(); ++row)
		{
			for (int col = 0; col < mBoard.size(); ++col)
			{
				if (mBoard[row][col] != 'o')
					continue;

				for (Point dir : sDir)
				{
					bAnswer = check5stones({ col + dir.X, row + dir.Y }, dir, 1);
					if (bAnswer)
					{
						goto RETURN_ANSWER;
					}
				}
			}
		}

	RETURN_ANSWER:
		return bAnswer;
	}

private:
	bool check5stones(Point p, Point dir, int numStones)
	{
		int n = (int)mBoard.size();
		if (p.Y < 0 || p.Y >= n || p.X < 0 || p.X >= n)
			return false;

		if (mBoard[p.Y][p.X] == '.')
			return false;

		if (numStones == 4 && mBoard[p.Y][p.X] == 'o')
			return true;

		Point next = { p.X + dir.X, p.Y + dir.Y };
		return check5stones(next, dir, numStones + 1);
	}

	void print()
	{
		for (const auto& line : mBoard)
			cout << line << '\n';
		cout << '\n';
	}

private:
	static const Point sDir[8];

	std::vector<std::string> mBoard;
};

const Point Solution::sDir[8] = { {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1} };


int main(int argc, char** argv)
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		cin >> N;

		Solution s(N);
		bool answer = s.Run();

		cout << '#' << tc << ' ' << (answer ? "YES" : "NO") << '\n';
	}

	return 0;
}