// SWEA D3 5215. 햄버거 다이어트

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
//#include <list>
//#include <string>
#include <vector>

using namespace std;

struct Food
{
	int Score;
	int Cal;
};

class Solution
{
public:
	Solution(int N, int L)
		: mFoods(N)
		, mLimitCal(L)
	{}

	int Run()
	{
		for (int i = 0; i < mFoods.size(); ++i)
		{
			cin >> mFoods[i].Score >> mFoods[i].Cal;
		}

		std::vector<bool> usedFoods(mFoods.size());
		int maxScore = 0;
		findCombination(usedFoods, 0, 0, 0, &maxScore);

		return maxScore;
	}

private:
	void findCombination(std::vector<bool>& usedFoods, int curIdx, int curScore, int curCal, int* outMaxScore)
	{
		if (curIdx == mFoods.size())
		{
			*outMaxScore = std::max(*outMaxScore, curScore);
			return;
		}

		for (int repeat = curIdx; repeat < mFoods.size(); ++repeat)
		{
			usedFoods[repeat] = true;
			int newScore = curScore + mFoods[repeat].Score;
			int newCal = curCal + mFoods[repeat].Cal;

			if (newCal > mLimitCal)
			{
				*outMaxScore = std::max(*outMaxScore, curScore);
				continue;
			}

			findCombination(usedFoods, repeat + 1, newScore, newCal, outMaxScore);
			usedFoods[repeat] = false;
		}
	}

private:
	std::vector<Food> mFoods;
	int mLimitCal;
};


int main(int argc, char** argv)
{
	FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N, L;
		cin >> N >> L;

		Solution s(N, L);
		int answer = s.Run();

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}