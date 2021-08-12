#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e6+10;
int N, A[mxN], ans;

void solve() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	multiset<int> mst;
	for (int i = 0; i < N; i++) {
		int j = i+1;
		auto it = mst.upper_bound(A[i]);
		while(j < N && (A[j] >= A[j-1]) && (it == mst.end() || *it >= A[j]))
			j++;
		for (int ii = i; ii < j; ii++)
			mst.insert(A[ii]);
		i = j-1;
		ans++;
	}
	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}