// SWEA D4 1249. [S/W 문제해결 응용] 4일차 - 보급로

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Point
{
	int X;
	int Y;
};

struct State
{
	int Cost;
	Point Pos;

	bool operator>(const State& s) const { return Cost > s.Cost; }
};

std::vector<std::string> field;
std::vector<std::vector<int>> bestCost;

static const Point DIRS[4] = { {1, 0}, {0, 1}, {-1, 0},  {0, -1} };

void dijkstra(Point point)
{
	std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
	pq.push({ 0, point });

	const int n = (int)field.size() - 2;
	int minCostToDest = INT_MAX;

	while (!pq.empty())
	{
		State state = pq.top();
		Point pos = state.Pos;
		pq.pop();

		if (state.Cost >= bestCost[pos.Y][pos.X])
			continue;
		bestCost[pos.Y][pos.X] = state.Cost;

		if (pos.Y == n && pos.X == n)
			minCostToDest = std::min(state.Cost, minCostToDest);

		for (Point dir : DIRS)
		{
			Point next = { pos.X + dir.X, pos.Y + dir.Y };
			if (field[next.Y][next.X] == '#' || bestCost[next.Y][next.X] != INT_MAX)
				continue;

			int nextCost = state.Cost + field[next.Y][next.X] - '0';
			if (nextCost >= minCostToDest)
				continue;

			pq.push({ nextCost, next });
		}
	}
}

int main()
{
	FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	std::cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		std::cin >> N;

		bestCost.assign(N + 2, std::vector<int>(N + 2, INT_MAX));
		field.resize(N + 2);
		field.front().resize(N + 2, '#');
		field.back().resize(N + 2, '#');

		for (int row = 1; row <= N; ++row)
		{
			auto& line = field[row];
			line.resize(N + 2);
			line.front() = '#';
			line.back() = '#';

			std::cin >> std::ws;
			std::cin.read(&line[1], N);
		}

		dijkstra({ 1, 1 });
		int minTime = bestCost[N][N];

		std::cout << '#' << tc << ' ' << minTime << '\n';
	}

	return 0;
}