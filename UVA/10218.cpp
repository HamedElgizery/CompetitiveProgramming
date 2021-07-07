#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

/*
	it can be seen that I can divide CC into two groups
	if CC % 2 == 0 "Even" so, I need to add the probabilities of 
	giving an Even number of candies to Men, which will be equal to probility of 
	giving 0 candies to men + giving 2 cadies to men...
	The probability of giving i candies to men = 
	(M/total)^i * (W/total)^(C-i) * nCr(n=C, r=i)
	We are multiplying by the nCr because there are multiple cases 
	where I can give Men i candies
	
*/



int M, W, C, total;

double Power(double x, int y) {
	double ret = 1;
	for (int i = 0; i < y; i++) {
		ret *= x;
	}
	return ret;
}

double nCr(int n, int r) {
	double ans = 1;
	for (int i = 0; i < n-r; i++) {
		ans *= (n-i);
		ans /= (i+1);
	}
	return ans;
}

void solve() {
	double prob = 0;
	total = M + W;

	for (int i = 0; i <= C; i+=2) 
		prob += Power(M*1.0/total, i)* Power(W*1.0/total, C-i) * nCr(C, i);

	cout << fixed << setprecision(7) << prob;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> M >> W >> C && (M+W)) {
		solve();
		cout << '\n';
	}
}
