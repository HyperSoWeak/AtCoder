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
using vi = vector<int>;
using mat = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 3e5+5;

int n, deg[MN];
vi g[MN];

bool cmp(int a, int b) { return deg[a] > deg[b]; }

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int ans = INF;
    rep1(c,1,n) {
        sort(g[c].begin(), g[c].end(), cmp);
        int x = 0;
        for(auto u: g[c]) {
            x++;
            int y = deg[u] - 1;
            ans = min(ans, n - (1 + x + x*y));
        }
    }
    cout << ans << '\n';
}
