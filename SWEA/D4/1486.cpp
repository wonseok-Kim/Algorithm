// SWEA D4 1486. 장훈이의 높은 선반

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int N, B;
std::vector<int> heights;
std::vector<int> suffixSum;
int minSum;

void dfs(int startIdx, int sum)
{
	if (sum >= minSum)
		return;
	if (sum >= B)
	{
		minSum = std::min(minSum, sum);
		return;
	}

	for (int i = startIdx; i < N; ++i)
	{
		if (sum + suffixSum[i] < B)
			return;

		dfs(i + 1, sum + heights[i]);
	}
}

int main()
{
#ifdef _MSC_VER
	//FILE* ignore = freopen("input.txt", "r", stdin);
#endif

	int T;
	std::cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		std::cin >> N >> B;

		heights.resize(N);
		suffixSum.resize(N);
		minSum = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			std::cin >> heights[i];
		}

		suffixSum.back() = heights.back();
		for (int i = N - 1; i > 0; --i)
		{
			suffixSum[i - 1] = heights[i - 1] + suffixSum[i];
		}

		dfs(0, 0);

		int diff = minSum - B;
		std::cout << '#' << tc << ' ' << diff << '\n';
	}


	return 0;
}