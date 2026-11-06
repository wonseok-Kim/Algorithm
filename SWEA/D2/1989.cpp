// SWEA D2 1989. 초심자의 회문 검사

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
		char word[11];
		cin >> word;

		bool bPalindrome = true;
		int len = (int)strlen(word);
		for (int i = 0; i < len / 2; ++i)
		{
			if (word[i] != word[len - 1 - i])
			{
				bPalindrome = false;
				break;
			}
		}

		cout << '#' << tc << ' ' << ((bPalindrome) ? 1 : 0) << '\n';
	}

	return 0;
}