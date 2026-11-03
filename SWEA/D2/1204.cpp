// SWEA D2 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기
// 핵심: 

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int numTestcase;
		std::cin >> numTestcase;

		int answer = 0;
		int arrScore[101] = { 0, };

		for (int i = 0; i < 1000; ++i)
		{
			int score;
			std::cin >> score;
			++arrScore[score];
		}

		int freq = 0;
		for (int i = 0; i < 101; ++i)
		{
			if (arrScore[i] >= freq)
			{
				answer = i;
				freq = arrScore[i];
			}
		}

		cout << '#' << numTestcase << ' ' << answer << '\n';
	}

	return 0;
}