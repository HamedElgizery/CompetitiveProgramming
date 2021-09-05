#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e7+1;
ll D[mxN], ANS[mxN];

void solve() {
	int x;
	cin >> x;
	cout << ANS[x] << '\n';
}	

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 1; i < mxN; i++)
		for (int j = i; j < mxN; j += i)
			D[j] += i;
		
	memset(ANS, -1, sizeof ANS);
	for (int i = 1; i < mxN; i++)
		if (D[i] < mxN)
			if (!(~ANS[D[i]]))
				ANS[D[i]] = i;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
}