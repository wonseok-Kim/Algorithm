// SWEA D3 1240. [S/W 문제해결 응용] 1일차 - 단순 2진 암호코드

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string CODES[10] = {
	"0001101",
	"0011001",
	"0010011",
	"0111101",
	"0100011",
	"0110001",
	"0101111",
	"0111011",
	"0110111",
	"0001011"
};

int main()
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	std::cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N, M;
		std::cin >> N >> M;

		std::vector<std::string> screen(N);
		for (int i = 0; i < N; ++i)
			std::cin >> screen[i];

		int screenIdx;
		size_t idx;
		for (screenIdx = 0; screenIdx < N; ++screenIdx)
		{
			 idx = screen[screenIdx].find_last_of('1');
			if (idx != std::string::npos)
				break;
		}

		std::string org = screen[screenIdx].substr(idx - 55, 56);
		std::vector<int> decode(8);

		for (int i = 0; i < 8; ++i)
		{
			int startIdx = i * 7;
			std::string str = org.substr(startIdx, 7);
			for (int j = 0; j < 10; ++j)
			{
				if (str == CODES[j])
				{
					decode[i] = j;
					break;
				}
			}
		}

		int sumOdd = 0;
		int sumEven = 0;
		for (int i = 0; i < 8; ++i)
		{
			if (i & 1)
				sumOdd += decode[i];
			else
				sumEven += decode[i];
		}

		int answer = 0;
		if ((sumEven * 3 + sumOdd) % 10 == 0)
		{
			for (int i = 0; i < 8; ++i)
				answer += decode[i];
		}

		std::cout << '#' << tc << ' ' << answer << '\n';
	}


	return 0;
}

//0000000000000000000000000000000000000000000000000000000000000000000000
//0000011101101100010111011011000101100010001101001001101110110000000000
//0000011101101100010111011011000101100010001101001001101110110000000000
//0000011101101100010111011011000101100010001101001001101110110000000000
//0000011101101100010111011011000101100010001101001001101110110000000000
//0000011101101100010111011011000101100010001101001001101110110000000000
//0000011101101100010111011011000101100010001101001001101110110000000000
//0000011101101100010111011011000101100010001101001001101110110000000000
//0000000000000000000000000000000000000000000000000000000000000000000000
//0000000000000000000000000000000000000000000000000000000000000000000000
//
//1110110 1100010 1110110 1100010 1100010 0011010 0100110 111011