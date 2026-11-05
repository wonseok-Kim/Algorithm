// SWEA D3 1206. [S/W 문제해결 기본] 1일차 - View

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	FILE* ignore = freopen("input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; ++tc)
	{
		int N;
		cin >> N;

		std::vector<uint8_t> heights(N);
		for (int i = 0; i < N; ++i)
		{
			int height;
			cin >> height;
			heights[i] = (uint8_t)height;
		}

		int answer = 0;
		for (int i = 2; i < N - 2; ++i)
		{
			int leftTop = std::max(heights[i - 2], heights[i - 1]);
			int rightTop = std::max(heights[i + 1], heights[i + 2]);
			int aroundTop = std::max(leftTop, rightTop);

			int numRiverView = heights[i] - aroundTop;
			if (numRiverView > 0)
				answer += numRiverView;
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}