#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (auto& a : A) cin >> a;
	for (auto& b : B) cin >> b;

	vector<int> add, sub;
	for (int i = 0; i < N; i++) {
		while(A[i] > B[i]) {
			A[i]--;
			sub.push_back(i);
		}
		while(A[i] < B[i]) {
			A[i]++;
			add.push_back(i);
		}
	}

	if (add.size() != sub.size()) return void(cout << -1 << endl);

	cout << add.size() << endl;
	for (int i = 0; i < add.size(); i++) {
		cout << sub[i]+1 << ' ' << add[i]+1 << '\n';
	}
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
	while(t--) {
		solve();
	}
}