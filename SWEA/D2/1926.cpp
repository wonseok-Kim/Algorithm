// SWEA D2 1926. 간단한 369게임

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int number = i;
		bool bClap = false;
		do
		{
			int unitDigit = number % 10;
			if (unitDigit == 3 || unitDigit == 6 || unitDigit == 9)
			{
				bClap = true;
				cout << '-';
			}
			number /= 10;
		} while (number != 0);

		if (!bClap)
			cout << i;
		cout << ' ';
	}

	return 0;
}