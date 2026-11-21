// SWEA D4 7465. 창용 마을 무리의 개수

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <stack>

std::vector<int> parent;

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec)
{
	for (int i = 1; i < vec.size(); ++i)
		out << i << ' ';
	out << '\n';
	for (int i = 1; i < vec.size(); ++i)
		out << vec[i] << ' ';
	return out;
}

int find(int x)
{
	if (parent[x] == x)
		return x;

	int ret = find(parent[x]);
	parent[x] = ret;
	return ret;
}

int main()
{
	//FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	std::cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N, M;
		std::cin >> N >> M;

		parent.resize(N + 1);
		for (int i = 1; i <= N; ++i)
			parent[i] = i;

		for (int i = 0; i < M; ++i)
		{
			int a, b;
			std::cin >> a >> b;
			//std::cout << "input: " << a << ", " << b << '\n';

			int rootA = find(a);
			int rootB = find(b);
			parent[rootB] = rootA;
			
			//std::cout << parent << "\n\n";
			continue;
		}

		int answer = 0;
		for (int i = 1; i <= N; ++i)
			if (parent[i] == i)
				answer += 1;

		std::cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}
