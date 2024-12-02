#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int>& report) {
	bool asc = true;

	for (int i = 1; i < report.size(); i++) {
		int change = report[i] - report[i-1];

		if (change > 3 || change < 1) {
			asc = false;
			break;
		}
	}

	bool dec = true;

	for (int i = 1; i < report.size(); i++) {
		int change = report[i] - report[i-1];

		if (change < -3 || change > -1) {
			dec = false;
			break;
		}
	}

	return asc ^ dec;
}

int main() {
	int safeReports = 0;

	string line;
	while (getline(cin, line)) {
		stringstream ss(line);

		vector<int> report;
		int level;
		while (ss >> level) report.push_back(level);
		
		if (isSafe(report)) {
			safeReports++;
		}
	}
	
	cout << safeReports << endl;
	
	return 0;
}
