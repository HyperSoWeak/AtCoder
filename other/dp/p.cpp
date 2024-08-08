#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 1e5+5;

int n, dp[MN][2];
vector<int> e[MN];

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 1;
    if(u != 1 && e[u].size() == 1) return;
    for(int v: e[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
        dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
    }
}

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n-1) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1]) % MOD;
}
