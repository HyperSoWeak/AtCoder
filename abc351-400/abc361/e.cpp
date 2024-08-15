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

int n, dpt[MN], c, sum = 0;
vector<pii> e[MN];

void dfs(int u, int p) {
    for(auto [v,w]: e[u]) if(v != p) {
        dpt[v] = dpt[u] + w;
        if(dpt[v] > dpt[c]) c = v;
        dfs(v, u);
    }
}

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n-1) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].emplace_back(b,c);
        e[b].emplace_back(a,c);
        sum += c;
    }
    dfs(1, 0);
    dpt[c] = 0; dfs(c, 0);
    cout << 2 * sum - dpt[c];
}
