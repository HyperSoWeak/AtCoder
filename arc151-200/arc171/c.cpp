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
const int MOD = 998244353;
const int MAXN = 3005;

int n, dp[MAXN][MAXN][2], t[MAXN][2], sum[MAXN][2];
vector<int> g[MAXN];

void dfs(int u, int p) {
    dp[u][0][0] = 1;
    dp[u][1][1] = (u != 1);
    int deg = (u != 1);
    for(int v: g[u]) {
        if(v == p) continue;
        dfs(v, u);
        deg++;
        rep1(k,0,deg) {
            t[k][0] = dp[u][k][0];
            t[k][1] = dp[u][k][1];
        }
        rep1(k,0,deg) {
            dp[u][k][0] = t[k][0] * sum[v][0];
            dp[u][k][1] = t[k][1] * sum[v][0];
            if(k != 0) {
                dp[u][k][0] += t[k-1][0] * sum[v][1] * k;
                dp[u][k][1] += t[k-1][1] * sum[v][1] * k;
            }
            dp[u][k][0] %= MOD;
            dp[u][k][1] %= MOD;
        }
    }
    rep1(k,0,deg) {
        sum[u][0] += dp[u][k][0];
        sum[u][1] += dp[u][k][1];
    }
    sum[u][0] %= MOD;
    sum[u][1] %= MOD;
}

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n-1) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    cout << sum[1][0];
}
