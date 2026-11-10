// SWEA D3 6808. 규영이와 인영이의 카드게임

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

struct CardHistory
{
	bool used[9] = { false, };
};

class Solution
{
public:
	void Run()
	{
		bool drawedCards[19] = { false, };
		for (int i = 0; i < 9; ++i)
		{
			cin >> mOppCards[i];
			drawedCards[mOppCards[i]] = true;
		}

		int idx = 0;
		for (int i = 1; i < 19; ++i)
		{
			if (!drawedCards[i])
				mMyCards[idx++] = i;
		}

		playAllCases();
	}

	int GetWins() { return mWins; }
	int GetLoses() { return mLoses; }

private:
	void playAllCases()
	{
		CardHistory history;
		playAllCasesHelper(history, 0, 0, 0);
	}

	void playAllCasesHelper(CardHistory& history, int turns, int myScore, int oppScore)
	{
		if (turns == 9)
		{
			if (myScore > oppScore)
				mWins++;
			else if (myScore < oppScore)
				mLoses++;
			return;
		}

		for (int i = 0; i < 9; ++i)
		{
			if (history.used[i])
				continue;

			int turnScore = mOppCards[turns] + mMyCards[i];
			int newMyScore = myScore;
			int newOppScore = oppScore;

			if (mMyCards[i] > mOppCards[turns])
				newMyScore += turnScore;
			else
				newOppScore += turnScore;

			history.used[i] = true;
			playAllCasesHelper(history, turns + 1, newMyScore, newOppScore);
			history.used[i] = false;
		}
	}

private:
	int mOppCards[9];
	int mMyCards[9];
	int mWins = 0;
	int mLoses = 0;
};

int main(int argc, char** argv)
{
	FILE* ignore = freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		Solution s;
		s.Run();

		cout << '#' << tc << ' ' << s.GetLoses() << ' ' << s.GetWins() << '\n';
	}

	return 0;
}