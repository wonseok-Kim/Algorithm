// SWEA D3 2817. 부분 수열의 합

#define _CRT_SECURE_NO_WARNINGS

//#include <algorithm>
//#include <cstdlib>
#include <iostream>
//#include <list>
//#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	Solution(int N, int K)
		: mArr(N)
		, mUsedIdx(N, false)
		, mK(K)
	{
		for (int i = 0; i < N; ++i)
			cin >> mArr[i];
	}

	int Run()
	{
		count(0, 0);

		return mCnt;
	}

private:
	void count(int curSum, int curIdx)
	{
		if (curSum > mK)
			return;
		if (curSum == mK)
		{
			mCnt++;
			return;
		}

		for (int i = curIdx; i < mArr.size(); ++i)
		{
			if (mUsedIdx[i])
				continue;

			mUsedIdx[i] = true;
			count(curSum + mArr[i], i);
			mUsedIdx[i] = false;
		}
	}

private:
	std::vector<int> mArr;
	std::vector<bool> mUsedIdx;
	int mK;
	int mCnt = 0;
};


int main(int argc, char** argv)
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N, K;
		cin >> N >> K;

		Solution s(N, K);
		int answer = s.Run();

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}