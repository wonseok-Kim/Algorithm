// SWEA D3 1860. 진기의 최고급 붕어빵

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//FILE* ignore = freopen("input.txt", "r", stdin);
	
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N, M, K;
		cin >> N >> M >> K;

		std::vector<int> arrivedSeconds(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> arrivedSeconds[i];
		}

		std::sort(arrivedSeconds.begin(), arrivedSeconds.end());

		int numBreadsGiven = 0;
		for (int s : arrivedSeconds)
		{
			int numBreadsMade = (s / M) * K - numBreadsGiven;
			if (numBreadsMade > 0)
				numBreadsGiven++;
			else
				break;
		}

		bool bPossible = false;
		if (numBreadsGiven == arrivedSeconds.size())
			bPossible = true;

		cout << '#' << tc << ' ' << (bPossible ? "Possible" : "Impossible") << '\n';
	}

	return 0;
}