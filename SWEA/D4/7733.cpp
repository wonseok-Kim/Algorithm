// SWEA D4 7733. 치즈 도둑

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <list>
#include <random>
#include <set>
#include <stack>
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
		: mCheese(N, std::vector<int>(N))
		, mEatenCheese(N, std::vector<bool>(N, false))
		, mVisited(N * N, false)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> mCheese[i][j];
				mUsed[mCheese[i][j]] = true;
			}
		}
	}

	int Run()
	{
		int totalCheese = (int)mCheese.size() * (int)mCheese.size();
		int remainCheese = totalCheese;

		int maxNumAreas = 1;
		int days = 0;
		for (int i = 1; i <= 100; ++i)
		{
			if (!mUsed[i])
				continue;

			//cout << "EAT " << i << '\n';
			remainCheese -= eatCheese(i);
			if (remainCheese == 0)
				break;

			int numAreas = countArea();
			maxNumAreas = std::max(maxNumAreas, numAreas);
		}

		return maxNumAreas;
	}

private:
	int eatCheese(int value)
	{
		int eatenAmount = 0;
		for (int row = 0; row < mCheese.size(); ++row)
		{
			const auto& vec = mCheese[row];
			for (int col = 0; col < vec.size(); ++col)
			{
				if (vec[col] == value)
				{
					mEatenCheese[row][col] = true;
					eatenAmount++;
				}
			}
		}
		return eatenAmount;
	}

	int bfs(Point p)
	{
		std::stack<Point> stk;
		stk.push(p);

		int n = (int)mCheese.size();
		int idx = p.Y * n + p.X;
		mVisited[idx] = true;

		int cnt = 0;
		while (!stk.empty())
		{
			Point pt = stk.top();
			stk.pop();
			cnt++;

			for (Point dir : sDir)
			{
				Point next;
				next.X = pt.X + dir.X;
				next.Y = pt.Y + dir.Y;
				if (next.X < 0 || next.X >= n || next.Y < 0 || next.Y >= n)
					continue;

				int nextIdx = next.Y * n + next.X;
				if (nextIdx < 0 || nextIdx >= mVisited.size())
					continue;

				if (mVisited[nextIdx] || mEatenCheese[next.Y][next.X])
					continue;

				mVisited[nextIdx] = true;
				stk.push(next);
			}
		}
		return cnt;
	}

	int countArea()
	{
		std::fill(mVisited.begin(), mVisited.end(), false);

		int n = (int)mCheese.size();
		int cnt = 0;
		for (int row = 0; row < n; ++row)
		{
			for (int col = 0; col < n; ++col)
			{
				if (mEatenCheese[row][col])
					continue;

				int idx = row * n + col;
				if (mVisited[idx])
					continue;

				bfs({ col, row });
				cnt++;
			}
		}

		return cnt;
	}

	void printCheese()
	{
		for (const auto& vec : mCheese)
		{
			for (int v : vec)
			{
				cout << v << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}

	void printVisited()
	{
		int n = (int)mCheese.size();
		for (int row = 0; row < n; ++row)
		{
			for (int col = 0; col < n; ++col)
			{
				if (mEatenCheese[row][col])
				{
					cout << "# ";
					continue;
				}
				int idx = row * n + col;
				if (mVisited[idx])
				{
					cout << "X ";
					continue;
				}
				cout << "O ";				
			}
			cout << '\n';
		}
		cout << '\n';
	}

private:
	static const Point sDir[4];

	bool mUsed[101] = { false, };
	std::vector<std::vector<int>> mCheese;
	std::vector<std::vector<bool>> mEatenCheese;
	std::vector<bool> mVisited;
};

const Point Solution::sDir[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

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
		int answer = s.Run();

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}