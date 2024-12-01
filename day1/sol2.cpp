#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> left;
	unordered_map<int, int> counts;

	int l, r;
	while (cin >> l >> r) {
		left.push_back(l);
		counts[r] += 1;
	}

	int similarity = 0;

	for (int i = 0; i < left.size(); i++) {
		similarity += counts[left[i]] * left[i];
	}

	cout << similarity << endl;

	return 0;
}
