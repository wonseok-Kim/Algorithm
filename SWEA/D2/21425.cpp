// SWEA D2 21425. +=
// 핵심:

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		unsigned int A, B, N;
		cin >> A >> B >> N;

		if (A > B)
			std::swap(A, B);

		unsigned int num = 0;
		while (true)
		{
			A += B;
			++num;
			if (A > N)
				break;
			B += A;
			++num;
			if (B > N)
				break;
		}

		cout << num << '\n';
	}
	return 0;
}