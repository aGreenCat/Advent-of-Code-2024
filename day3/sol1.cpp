#include <bits/stdc++.h>
using namespace std;

int main() {
	int sumProducts = 0;

	int match = 0;
	int product = 1;

	char ch;
	while (cin >> ch) {
		if (ch == 'm') match = 1;
		else if (match == 1 && ch == 'u') match++;
		else if (match == 2 && ch == 'l') match++;
		else if (match == 3 && ch == '(') {
			match++;	
			
			int factor;
			if (cin >> factor) {
				match++;

				product *= factor;

			} else {
				match = -1;
				product = 1;
			}
		}
		else if (match == 5 && ch == ',') {
			match++;

			int factor;
			if (cin >> factor) {
				match++;
				
				product *= factor;
			} else {
				match = -1;
				product = 1;
			}
		}
		else if (match == 7 && ch == ')') {
			sumProducts += product;
			
			match = -1;
			product = 1;
		}
		else {
			match = 0;
			product = 1;
		}
	}
	
	cout << sumProducts << endl;
	
	return 0;
}
