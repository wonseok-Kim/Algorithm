// SWEA D3 1208. [S/W 문제해결 기본] 1일차 - Flatten

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; ++tc)
	{
		int dumpCount;
		cin >> dumpCount;

		int heightsOfBoxes[100];
		for (int i = 0; i < 100; ++i)
			cin >> heightsOfBoxes[i];
		std::sort(heightsOfBoxes, heightsOfBoxes + 100);

		int mid = (heightsOfBoxes[0] + heightsOfBoxes[99]) / 2;
		int idx = 99;
		for (; idx > 0; --idx)
			if (heightsOfBoxes[idx - 1] != heightsOfBoxes[idx])
				break;

		int minusCount = dumpCount;
		while (minusCount > 0)
		{
			for (int i = idx; i < 100; ++i)
			{
				--heightsOfBoxes[i];
				if (--minusCount == 0)
					goto PLUS_HEIGHT;
			}
			for (; idx > 0; --idx)
				if (heightsOfBoxes[idx - 1] != heightsOfBoxes[idx])
					break;
		}

	PLUS_HEIGHT:
		idx = 0;
		for (; idx < 99; ++idx)
			if (heightsOfBoxes[idx] != heightsOfBoxes[idx + 1])
				break;

		int plusCount = dumpCount;
		while (plusCount > 0)
		{
			for (int i = idx; i >= 0; --i)
			{
				++heightsOfBoxes[i];
				if (--plusCount == 0)
					goto PRINT_ANSWER;
			}
			for (; idx < 99; ++idx)
				if (heightsOfBoxes[idx] != heightsOfBoxes[idx + 1])
					break;			
		}

	PRINT_ANSWER:
		cout << '#' << tc << ' ' << (heightsOfBoxes[99] - heightsOfBoxes[0]) << '\n';
	}

	return 0;
}