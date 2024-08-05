#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

int n, m;
struct Edge {
    int u, v, w;
} e[200005];
bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n,1) {
        rep(i,0,n) p[i] = i;
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
    }
    int same(int x, int y) {
        return find(x) == find(y);
    }
};

signed main() {
    hyper;
    cin >> n >> m;
    DSU d(n+1);
    rep(i,0,m) cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e, e+m, cmp);
    int ans = 0;
    rep(i,0,m) {
        auto[u,v,w] = e[i];
        if(!d.same(u,v)) d.unite(u,v);
        else if(w > 0) ans += w;
    }
    cout << ans;
}