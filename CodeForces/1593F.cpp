#include <bits/stdc++.h>

using namespace std;

const int mxN = 40;
int D[mxN], dp[mxN][mxN][mxN][mxN];
int N, A, B;

bool fun(int idx, int a, int b, int take) {
   if (idx == N) {
        if (!a && !b && !take) return 1;
        else return 0;
   }

    int &ret = dp[idx][a][b][take];
    if (~ret) return (ret == -2 ? 0 : 1);
    ret = -2;

    //take red
    if (take > 0) {
        bool c1 = fun(idx+1, (a * 10 + D[idx]) % A, b, take-1);
        if (c1) return ret = 0, 1;
    }
    //take black
    if ((N-idx)-take > 0) { 
        bool c2 = fun(idx+1, a, (b * 10 + D[idx]) % B, take);
        if (c2) return ret = 1, 1;
    }

    return 0;
}

void build(int idx, int a, int b, int take) {
    if (idx == N)
        return;
    if (dp[idx][a][b][take] == 0) {
        cout << "R";
        build(idx+1, (a * 10 + D[idx]) % A, b, take-1);
    }
    else {
        cout << "B";
        build(idx+1, a, (b * 10 + D[idx]) % B, take);
    }
}

void solve() {
    cin >> N >> A >> B;

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        D[i] = c - '0';
    }

    memset(dp, -1, sizeof dp);

    for (int i = 1; i < N; i++) 
        fun(0, 0, 0, i);

    int best = 1e9;
    for (int i = 1; i < N; i++) {
        if (dp[0][0][0][i] > -1)
            if (abs((N - best) - best) > abs((N - i) - i))
                best = i;
    }
    if (best >= 1e9)
        return void(cout << -1);
    build(0, 0, 0, best);
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
      cout << '\n';
    }
    return 0;
}