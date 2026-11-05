// SWEA D2 1946. 간단한 압축 풀기

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		cin >> N;

		cout << '#' << tc << '\n';

		int curWidth = 0;
		for (int i = 0; i < N; ++i)
		{
			char ch;
			int k;
			cin >> ch >> k;

			for (int j = 0; j < k; ++j)
			{
				cout << ch;
				curWidth++;
				if (curWidth == 10)
				{
					cout << '\n';
					curWidth = 0;
				}
			}
		}
		if (curWidth != 0)
			cout << '\n';
	}

	return 0;
}