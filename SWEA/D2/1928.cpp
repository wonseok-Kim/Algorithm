// SWEA D2 1928. Base64 Decoder
// 노트: MSB 개념을 몰라 buffer에 |= 연산을 왼쪽부터 채울지 오른쪽부터 채울지 헷갈렸음.

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	std::cin >> T;
	std::cin.get();

	char decodingTable[128] = { 0, };
	for (int i = 'A'; i <= 'Z'; ++i)
		decodingTable[i] = i - 'A';
	for (int i = 'a'; i <= 'z'; ++i)
		decodingTable[i] = 26 + i - 'a';
	for (int i = '0'; i <= '9'; ++i)
		decodingTable[i] = 52 + i - '0';
	decodingTable['+'] = 62;
	decodingTable['/'] = 63;


	for (int tc = 1; tc <= T; ++tc)
	{
		std::string line;
		std::getline(std::cin, line);

		std::cout << '#' << tc << ' ';
				
		for (int i = 0; i < line.size(); i += 4)
		{
			uint32_t buffer = 0;
			constexpr uint32_t mask = 0x3f;
			for (int j = 0; j < 4; ++j)
			{
				uint32_t tmp = decodingTable[line[i + j]];
				buffer |= (tmp << (6 * (3 - j)));
			}
			char* ptr = (char*)&buffer;
			std::cout << ptr[2] << ptr[1] << ptr[0];
		}

		std::cout << '\n';
	}

	return 0;
}