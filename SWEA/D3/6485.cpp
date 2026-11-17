// SWEA D3 6485. 삼성시의 버스 노선

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Route
{
	int Above;
	int Below;
};

int main()
{
	//FILE* ignore = freopen("input.txt", "r", stdin);
	
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		cin >> N;

		std::vector<Route> busRoutes(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> busRoutes[i].Below >> busRoutes[i].Above;
		}

		int P;
		cin >> P;

		cout << '#' << tc << ' ';

		for (int i = 0; i < P; ++i)
		{
			int stop;
			cin >> stop;

			int cnt = 0;
			for (Route r : busRoutes)
			{
				if (stop >= r.Below && stop <= r.Above)
					cnt++;
			}
			cout << cnt << ' ';
		}
		cout << '\n';
	}

	return 0;
}