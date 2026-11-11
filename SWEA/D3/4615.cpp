// SWEA D3 4615. 재미있는 오셀로 게임

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
//#include <list>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	Solution(int N, int M)
		: mBoard(N + 2, std::string(N + 2, 'O'))
		, mCount(M)
	{
		int x = N / 2;
		int y = x;

		mBoard[y][x] = 'W';
		mBoard[y + 1][x + 1] = 'W';
		mBoard[y][x + 1] = 'B';
		mBoard[y + 1][x] = 'B';

		std::fill(mBoard[0].begin(), mBoard[0].end(), '#');
		std::fill(mBoard.back().begin(), mBoard.back().end(), '#');
		for (int i = 0; i < N + 2; ++i)
		{
			mBoard[i].front() = '#';
			mBoard[i].back() = '#';
		}
	}

	void Run()
	{
		//print();

		for (int i = 0; i < mCount; ++i)
		{
			int x, y, c;
			cin >> x >> y >> c;

			char piece = (c == 1) ? 'B' : 'W';

			//cout << x << ", " << y << ", " << piece << '\n';
			setPiece(x, y, piece);
			//print();
		}

		countPieces();
	}

	int GetBlacks() { return mBlacks; }
	int GetWhites() { return mWhites; }

private:
	void print()
	{
		for (const auto& line : mBoard)
			cout << line << '\n';
		cout << '\n';
	}

	void setPiece(int x, int y, char piece)
	{
		mBoard[y][x] = piece;

		int i;
		for (i = 0; i < 8; ++i)
		{
			int xi = x;
			int yi = y;
			bool bFind = false;

			while (true)
			{
				xi += sDirX[i];
				yi += sDirY[i];

				if (mBoard[yi][xi] == piece)
				{
					bFind = true;
					break;
				}
				else if (mBoard[yi][xi] == '#' || mBoard[yi][xi] == 'O')
				{
					break;
				}
			}

			if (bFind)
			{
				do {
					xi -= sDirX[i];
					yi -= sDirY[i];
					mBoard[yi][xi] = piece;
				} while (!(xi == x && yi == y));
			}
		}
	}

	void countPieces()
	{
		for (int i = 1; i < mBoard.size() - 1; ++i)
		{
			const auto& line = mBoard[i];
			for (int j = 1; j < line.length() - 1; ++j)
			{
				if (line[j] == 'W')
					mWhites++;
				else if (line[j] == 'B')
					mBlacks++;
			}
		}
	}

private:
	static const int sDirX[];
	static const int sDirY[];

	std::vector<std::string> mBoard;
	int mCount;
	int mBlacks = 0;
	int mWhites = 0;
};

const int Solution::sDirX[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int Solution::sDirY[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int main(int argc, char** argv)
{
	FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N, M;
		cin >> N >> M;

		Solution s(N, M);
		s.Run();

		cout << '#' << tc << ' ' << s.GetBlacks() << ' ' << s.GetWhites() << '\n';
	}

	return 0;
}