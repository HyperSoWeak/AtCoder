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
const int MN = 2e5+5;

int n, sz[MN], dpt[MN], ans[MN];
vector<int> e[MN];

void dfs(int u, int p) {
    if(u != 1) dpt[u] = dpt[p] + 1;
    sz[u] = 1;
    for(int v: e[u]) if(v != p) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p) {
    if(u != 1) ans[u] = ans[p] + sz[1] - 2 * sz[u];
    for(int v: e[u]) if(v != p) dfs2(v, u);
}

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n-1) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    rep1(i,1,n) ans[1] += dpt[i];
    dfs2(1, 0);
    rep1(i,1,n) cout << ans[i] << '\n';
}