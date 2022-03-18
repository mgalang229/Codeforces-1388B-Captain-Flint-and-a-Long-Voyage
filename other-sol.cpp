#include <bits/stdc++.h>
using namespace std;

void perform_test() {
	int n;
	cin >> n;
	// to get the max value, it is always optimal to choose either 8 or 9
	// because their binary notation length is 4 (which is the highest)
	// to determine the no. of 8 digits that will be used, we need to divide
	// the length (no. of binary digits to be removed later) by 4
	
	// there will be two cases:
	// if n is even, then the exactly n/4 digits will be replaced by 8 instead of using 9
	// if n is odd, then (n/4) + 1 digits will be replaced by 8 because the binary digit
	// which is placed in the ((n * 4) - n)-th position will be removed as well so instead
	// of using 9, it is valid to choose 8 to produce a smaller value
	
	// for the remaining digits, fill it using 9s
	string last = "";
	int k = n / 4;
	for(int i = 0; i < k; i++) {
		last += '8';
	}
	int r = n % 4;
	if(r != 0) {
		last += '8';
	}
	int rem = n - last.length();
	for(int i = 0; i < rem; i++) {
		last += '9';
	}
	reverse(last.begin(), last.end());
	cout << last << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		perform_test();
	}
	return 0;
}

