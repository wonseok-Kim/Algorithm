// SWEA D4 1238. [S/W 문제해결 기본] 10일차 - Contact

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution
{
public:
	int Run()
	{
		int inputCount;
		int start;
		cin >> inputCount >> start;

		inputCount /= 2;
		for (int i = 0; i < inputCount; ++i)
		{
			int from, to;
			cin >> from >> to;

			lists[from].push_back(to);
		}

		std::vector<int> cur;
		std::vector<int> prev;
		for (int node : lists[start])
		{
			cur.push_back(node);
			alreadyCalled[node] = true;
		}

		while (!cur.empty())
		{
			std::swap(prev, cur);
			cur.clear();

			for (int idx : prev)
			{
				for (int node : lists[idx])
				{
					if (!alreadyCalled[node])
					{
						cur.push_back(node);
						alreadyCalled[node] = true;
					}
				}
			}
		}
		
		auto iter = std::max_element(prev.begin(), prev.end());
		return *iter;
	}

private:
	bool alreadyCalled[101] = { false, };
	std::list<int> lists[101];
	int maxLast;
};

int main(int argc, char** argv)
{
	FILE* ignore = freopen("input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; ++tc)
	{
		Solution s;
		int answer = s.Run();

		cout << '#' << tc <<  ' ' << answer << '\n';
	}

	return 0;
}