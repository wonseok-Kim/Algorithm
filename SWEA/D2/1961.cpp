// SWEA D2 1961. 숫자 배열 회전

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int size;
		cin >> size;

		vector<vector<int>> array2d(size);
		for (int i = 0; i < size; ++i)
		{
			array2d[i].resize(size);
			for (int j = 0; j < size; ++j)
			{
				cin >> array2d[i][j];
			}
		}

		cout << '#' << tc << '\n';
		for (int i = 0; i < size; ++i)
		{
			for (int j = size - 1; j >= 0; --j)
				cout << array2d[j][i];
			cout << ' ';

			for (int j = size - 1; j >= 0; --j)
				cout << array2d[size - i - 1][j];
			cout << ' ';

			for (int j = 0; j < size; ++j)
				cout << array2d[j][size - i - 1];
			cout << '\n';
		}
	}
	return 0;
}