#include <bits/stdc++.h>
using namespace std;

bool isAsc(int a, int b) {
	return b-a > 0 && b-a <= 3; 
}

bool checkAsc(const vector<int>& report, int curr, bool skip) {
	if (curr >= report.size()-1) return true;
	if (curr >= report.size()-2 && !skip) return true;

	bool safe = false;

	if (isAsc(report[curr], report[curr+1])) {
		if (checkAsc(report, curr+1, skip)) return true;
	}
	
	if (curr < report.size()-2 && !skip && isAsc(report[curr], report[curr+2])) {
		if (checkAsc(report, curr+2, true)) return true;
	}

	return false;
}

bool isSafe(const vector<int>& report) {
	return checkAsc(report, 0, false) || checkAsc(report, 1, true);
}

int main() {
	int safeReports = 0;

	string line;
	while (getline(cin, line)) {
		stringstream ss(line);

		vector<int> report;
		vector<int> neg_report;
		int level;
		while (ss >> level) {
			report.push_back(level);
			neg_report.push_back(-level);
		};

		if (isSafe(report) || isSafe(neg_report)) {
			safeReports++;
		}
	}
	
	cout << safeReports << endl;
	
	return 0;
}
