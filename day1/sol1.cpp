#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int> left;
	priority_queue<int> right;

	int l, r;
	while (cin >> l >> r) {
		left.push(l);
		right.push(r);
	}

	int distance = 0;
	while (!left.empty()) {
		distance += abs(left.top() - right.top());
		
		left.pop();
		right.pop();
	}

	cout << distance << endl;

	return 0;
}
