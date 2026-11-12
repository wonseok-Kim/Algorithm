// SWEA D3 2814. 최장 경로

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
//#include <list>
//#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	Solution(int N, int M)
		: mEdges(N + 1, std::vector<bool>(N + 1, false))
		, mNodeCount(N)
	{
		for (int i = 0; i < M; ++i)
		{
			int x, y;
			cin >> x >> y;

			mEdges[y][x] = true;
			mEdges[x][y] = true;
		}
	}

	int Run()
	{
		return getLongestRoute();
	}

private:
	int getLongestRoute()
	{
		int maxLevel = 1;
		std::vector<bool> usedNodes(mNodeCount + 1, false);
		for (int i = 1; i <= mNodeCount; ++i)
		{
			getLongestRouteHelper(usedNodes, i, 1, &maxLevel);
		}

		return maxLevel;
	}

	void getLongestRouteHelper(std::vector<bool>& usedNodes, int curNode, int curLevel, int *outMaxLevel)
	{
		usedNodes[curNode] = true;

		for (int i = 1; i <= mNodeCount; ++i)
		{
			if (mEdges[curNode][i] && !usedNodes[i])
			{
				getLongestRouteHelper(usedNodes, i, curLevel + 1, outMaxLevel);
			}
		}
		usedNodes[curNode] = false;
		*outMaxLevel = std::max(curLevel, *outMaxLevel);
	}

private:
	std::vector<std::vector<bool>> mEdges;
	int mNodeCount;
};


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
		int answer = s.Run();


		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}