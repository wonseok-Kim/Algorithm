// SWEA D3 2806. N-Queen
// 핵심: 처음에는 모든 (x, y)에 Queen을 놓아 보면서 brute force로 진행하려고 했음. 
//	하지만 Queen이 놓인 행과 열은 다시 쓸 수 없으므로, N개를 모두 놓으려면 행마다 Queen이 하나씩 들어가야 함. 
//	따라서 행을 기준으로 잡고 각 행에서 어느 열에 놓을지만 결정하면 된다는 사실을 깨달음. (행과 열을 바꿔도 마찬가지임.)

#define _CRT_SECURE_NO_WARNINGS

//#include <algorithm>
#include <cstdlib>
#include <iostream>
//#include <list>
//#include <string>
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
	{ 
		mQueenCoords.reserve(N);
	}

	int Run()
	{
		findNQueen(0);
		return mCnt;
	}

private:
	void findNQueen(int curX)
	{
		int n = (int)mQueenCoords.capacity();
		if (curX == n)
		{
			mCnt++;
			return;
		}

		for (int y = 0; y < n; ++y)
		{
			bool bAttacked = false;
			for (auto p : mQueenCoords)
			{
				if (p.Y == y || (std::abs(p.X - curX) == std::abs(p.Y - y)))
				{
					bAttacked = true;
					break;
				}
			}
			if (bAttacked)
				continue;
					   
			mQueenCoords.push_back({ curX, y });
			findNQueen(curX + 1);
			mQueenCoords.pop_back();
		}
	}
	

private:
	std::vector<Point> mQueenCoords;
	int mCnt = 0;
};


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