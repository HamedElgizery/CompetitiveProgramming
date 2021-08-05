#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mxN = 1e5+10;

void solve() {
	int N;
	cin >> N;
	vector<int> A(N), AS(N), freqA(mxN, 0), freqAS(mxN, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		AS[i] = A[i];
	}

	sort(AS.begin(), AS.end());

	for (int i = 0; i < N; i+=2) {
		freqA[A[i]]++;
		freqAS[AS[i]]++;
	}

	bool ans = 1;
	for (int i = 0; i < mxN; i++) {
		ans &= (freqA[i] == freqAS[i]);
	}
	cout << (ans ? "YES" : "NO") << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
}