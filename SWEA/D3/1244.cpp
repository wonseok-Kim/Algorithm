// SWEA D3 1244. [S/W 문제해결 응용] 2일차 - 최대 상금

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void GetMaxPrize(std::string& strNumber, int startIdx, int numSwap, int* outMaxPrize, int* outRemainingSwaps)
{
	int number = std::stol(strNumber);
	if (number >= *outMaxPrize && numSwap < *outMaxPrize)
	{
		*outRemainingSwaps = numSwap;
		*outMaxPrize = number;
	}

	if (numSwap == 0)
		return;
	
	for (int i = startIdx; i < strNumber.length(); ++i)
	{
		for (int j = i + 1; j < strNumber.length(); ++j)
		{
			std::swap(strNumber[i], strNumber[j]);
			GetMaxPrize(strNumber, i + 1, numSwap - 1, outMaxPrize, outRemainingSwaps);
			std::swap(strNumber[i], strNumber[j]);
		}
	}
}

int main(int argc, char** argv)
{
	FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int numSwap;
		std::string strNumber;
		cin >> strNumber >> numSwap;

		int maxPrize = std::stol(strNumber);
		int remainingSwaps = numSwap;
		GetMaxPrize(strNumber, 0, numSwap, &maxPrize, &remainingSwaps);

		if (remainingSwaps & 1)
		{
			auto str = std::to_string(maxPrize);
			std::swap(str[str.length() - 2], str[str.length() - 1]);
			maxPrize = std::stol(str);
		}

		cout << '#' << tc << ' ' << maxPrize << '\n';
	}

	return 0;
}