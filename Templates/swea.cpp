// SWEA D? 번호 제목
// 핵심:

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

		cout << '#' << tc << '\n';
	}

	return 0;
}