#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;

	vector<int> A(N), ZER, NEG; 
	vector<bool> exist(N, 1);

	int i = 0;
	for (auto& a : A) {
		cin >> a;
		if (!a)
			ZER.push_back(i);
		if (a < 0)
			NEG.push_back(i);
		i++;
	}


	vector<pair<int, int>> ans;
	for (int i = 1; i < ZER.size(); i++) {
		ans.push_back({ZER[i], ZER[0]});
		exist[ZER[i]] = 0;
	}

	if (NEG.size()&1) {
		int mx = NEG[0];
		for (auto it : NEG) {
			if (A[mx] < A[it])
				mx = max(mx, it);
		}
		if (ZER.size()) 
			ans.push_back({mx, ZER[0]});
		else 
			ans.push_back({mx, -1});
		exist[mx] = 0;
	}

	if (ZER.size() && ZER.size() + (NEG.size()&1) < N) {
		ans.push_back({ZER[0], -1});
		exist[ZER[0]] = 0;
	}

	set<int> ind;
	for (int i = 0; i < N; i++)
		if (exist[i])
			ind.insert(i);

	int I = *ind.begin();
	bool first = 1;
	for (auto it : ind) {
		if (first) {
			first = 0;
			continue;
		}
		ans.push_back({I, it});
		I = it;
	}


	for (auto it : ans) {
		if (~it.second)
			cout << 1 << ' ' << it.first+1 << ' ' << it.second+1 << endl;
		else
			cout << 2 << ' ' << it.first+1 << endl;
	}
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