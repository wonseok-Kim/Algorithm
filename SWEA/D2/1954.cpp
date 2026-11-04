// SWEA D2 1954. 달팽이 숫자

#include <iostream>
#include <vector>

using namespace std;

void PrintArray2D(const vector<vector<int>>& arr2d)
{
	for (int i = 0; i < arr2d.size(); ++i)
	{
		for (int j = 0; j < arr2d[i].size(); ++j)
		{
			std::cout << arr2d[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int size;
		cin >> size;
		vector<vector<int>> arr2d(size);
		for (int i = 0; i < size; ++i)
		{
			arr2d[i].resize(size);
		}

		int curRow = 0;
		int curCol = 0;
		bool bPlusRow = true;
		bool bPlusCol = true;
		bool bDirHorizontal = true;

		for (int i = 1; i <= size * size; ++i)
		{
			arr2d[curRow][curCol] = i;

			if (bDirHorizontal)
			{
				(bPlusCol) ? (curCol++) : (curCol--);
				if (curCol < 0 || curCol >= size || arr2d[curRow][curCol] != 0)
				{
					(bPlusCol) ? (curCol--) : (curCol++);
					bPlusCol = !bPlusCol;
					bDirHorizontal = !bDirHorizontal;
					(bPlusRow) ? (curRow++) : (curRow--);
				}
			}
			else
			{
				(bPlusRow) ? (curRow++) : (curRow--);
				if (curRow < 0 || curRow >= size || arr2d[curRow][curCol] != 0)
				{
					(bPlusRow) ? (curRow--) : (curRow++);
					bPlusRow = !bPlusRow;
					bDirHorizontal = !bDirHorizontal;
					(bPlusCol) ? (curCol++) : (curCol--);
				}
			}
			//PrintArray2D(arr2d);
			//std::cout << '\n';
		}

		cout << '#' << tc << '\n';
		PrintArray2D(arr2d);
	}
	return 0;
}