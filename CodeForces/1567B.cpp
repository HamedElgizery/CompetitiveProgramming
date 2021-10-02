#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 3e5+10;
int XORPRE[mxN];

void solve() {
	int A, B;
	cin >> A >> B;

	B ^= XORPRE[A-1];

	cout << A + (B > 0) + (A == B);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i < mxN; i++)
		XORPRE[i] = i ^ XORPRE[i-1];
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}