#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e6;
bool isPrime[mxN];
int cum[mxN];

bool isSimilar(int n) {
	return isPrime[n] && (n&1) && isPrime[(n+1)/2];
}

void sieve() {
	for (int i = 0; i < mxN; i++)
		isPrime[i] = 1;

	isPrime[0] = isPrime[1] = 0;

	for (int i = 4; i < mxN; i+=2)
		isPrime[i] = 0;

	for (ll i = 3; i < mxN; i+=2) {
		if (isPrime[i]) {
			for (ll j = i * i; j < mxN; j+=i)
				isPrime[j] = 0;
		}
	}

	for (int i = 1; i < mxN; i++) {
		cum[i] = cum[i-1] + isSimilar(i);
	}
}

void solve() {
	int Q;
	cin >> Q;

	while(Q--) {
		int l, r;
		cin >> l >> r;
		cout << cum[r] - cum[l-1] << '\n'; 
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	solve();
}