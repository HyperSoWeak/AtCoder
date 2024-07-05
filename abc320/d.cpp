#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 200005

struct Info {
    int p, x, y;
    Info(int p, int x, int y):
        p(p), x(x), y(y) {}
};
int n, m;
vector<Info> g[MAXN];
bool vis[MAXN];
pii ans[MAXN];

void solve(int x) {
    if(vis[x]) return;
    vis[x] = 1;
    for(Info e: g[x]) {
        ans[e.p] = mp(ans[x].fi+e.x, ans[x].se+e.y);
        solve(e.p);
    }
}

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,m) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        g[a].emplace_back(b, x, y);
        g[b].emplace_back(a, -x, -y);
    }
    solve(1);
    rep1(i,1,n) {
        if(!vis[i]) cout << "undecidable\n";
        else cout << ans[i].fi << ' ' << ans[i].se << '\n';
    }
}