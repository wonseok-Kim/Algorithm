// SWEA D3 9229. 한빈이와 Spot Mart 

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> snacks;
int maxWeight;

int main()
{
	FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	std::cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N, M;
		std::cin >> N >> M;

		snacks.resize(N);
		for (int i = 0; i < N; ++i)
		{
			std::cin >> snacks[i];
		}

		std::sort(snacks.begin(), snacks.end());

		maxWeight = -1;

		int begin = 0;
		int end = N -1;
		while (begin < end)
		{
			int totalWeight = snacks[begin] + snacks[end];
			if (totalWeight > M)
			{
				end -= 1;
				continue;
			}

			if (totalWeight > maxWeight)
				maxWeight = totalWeight;
			begin += 1;
		}

		std::cout << '#' << tc << ' ' << maxWeight << '\n';
	}


	return 0;
}