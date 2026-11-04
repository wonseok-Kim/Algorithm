// SWEA D2 1940. 가랏! RC카!

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
//	FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		cin >> N;

		int curSpeed = 0;
		int inputSpeed;
		int distance = 0;

		for (int i = 0; i < N; ++i)
		{
			int choice;
			cin >> choice;

			switch (choice)
			{
			case 0:
				break;
			case 1:
			case 2:
				cin >> inputSpeed;
				(choice == 1) ? (curSpeed += inputSpeed) : (curSpeed -= inputSpeed);
				if (curSpeed < 0)
					curSpeed = 0;
				break;
			default:
				break;
			}

			distance += curSpeed;
		}

		cout << '#' << tc << ' ' << distance << '\n';
	}

	return 0;
}