#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	queue<int> q;
	priority_queue<int, vector<int>, greater<int>> pq;
	int Q;
	cin >> Q;
	while(Q--) {
		int type, x;
		cin >> type;
		if (type == 1) {
			cin >> x;
			q.push(x);
		}
		else if (type == 2) {
			if (!pq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else {
			while(!q.empty()) {
				pq.push(q.front());
				q.pop();
			}
		}
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