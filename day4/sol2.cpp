#include <bits/stdc++.h>
using namespace std;

bool isX_MAS(const vector<vector<char>> &grid, int r, int c) {
	if (grid[r][c] != 'A') return false;

	vector<char> corners = { grid[r+1][c+1], grid[r-1][c+1], grid[r-1][c-1], grid[r+1][c-1] };
	for (char ch : corners) if (ch == 'X' || ch == 'A') return false;

	if (corners[0] == corners[2] || corners[1] == corners[3]) return false;

	return true;
}

int main() {
	vector<vector<char>> grid;

	string line;
	while (getline(cin, line)) {
		grid.push_back(vector<char>(line.begin(), line.end()));
	}

	int occurances = 0;

	for (int r = 1; r < grid.size()-1; r++) {
		for (int c = 1; c < grid[0].size()-1; c++) {
			occurances += isX_MAS(grid, r, c);
		}
	}
	
	cout << occurances << endl;

	return 0;
}
