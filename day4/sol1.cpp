#include <bits/stdc++.h>
using namespace std;

struct Change {
	int dc;
	int dr;
};

vector<Change> dirs = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

int countXMAS(const vector<vector<char>> &grid, int r, int c) {
	string target = "XMAS";
	int status = 0;

	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < dirs.size(); j++) {
			int key = pow(2, j);

			if ((status & key) == 0) {
				int nr = r + i*dirs[j].dr;
				int nc = c + i*dirs[j].dc;

				if (   nr < 0 || nr >= grid.size()
					|| nc < 0 || nc >= grid[0].size()
					|| grid[ nr ][ nc ] != target[i] ) {
					status |= key;
				}
			}
		}
	}

	int count = 0;
	for (int j = 0; j < dirs.size(); j++) {
		count += !(status & 1);
		status >>= 1;
	}
 
	return count;
}

int main() {
	vector<vector<char>> grid;

	string line;
	while (getline(cin, line)) {
		grid.push_back(vector<char>(line.begin(), line.end()));
	}

	int occurances = 0;

	for (int r = 0; r < grid.size(); r++) {
		for (int c = 0; c < grid[0].size(); c++) {
			if (grid[r][c] == 'X') {
				occurances += countXMAS(grid, r, c);
			}
		}
	}
	
	cout << occurances << endl;

	return 0;
}
