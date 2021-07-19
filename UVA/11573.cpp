#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
	0/1 BFS
	https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/
*/

const int N = 1e3;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int grid[N][N];
int r, c;

bool valid(int rr, int cc) {
	return 0 <= rr && rr < r && 0 <= cc && cc < c;
}

int bfs(int rs, int cs, int rd, int cd) {
	vector<vector<int>> dist(r, vector<int>(c, 1e9));
	deque<pair<int, int>> dq;
	dist[rs][cs] = 0;
	dq.push_front({rs, cs});
	while(dq.size()) {
		rs = dq.front().first;
		cs = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 8; i++) {
			int nr = dr[i] + rs;
			int nc = dc[i] + cs;
			if (valid(nr, nc)) {
				if (dist[nr][nc] > dist[rs][cs] + (i != grid[rs][cs])) {
					dist[nr][nc] = dist[rs][cs] + (i != grid[rs][cs]);
					if (i == grid[rs][cs])
						dq.push_front({nr, nc});
					else
						dq.push_back({nr, nc});
				}
			}
		}
	}
	return dist[rd][cd];
}


void solve() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)  {
			char cc;
			cin >> cc;
			grid[i][j] = cc - '0';
		}
	}

	int n;
	cin >> n;
	while(n--) {
		int rs, cs, rd, cd;
		cin >> rs >> cs >> rd >> cd;
		--rs, --cs, --rd, --cd;
		cout << bfs(rs, cs, rd, cd) << endl;
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