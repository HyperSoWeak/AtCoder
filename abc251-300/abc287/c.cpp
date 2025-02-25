#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int int64_t
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define all(a) a.begin(),a.end()
#define sz(a) (signed)a.size()
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e5+5;

struct DSU {
    vector<int> p, sz;
    DSU(int n) {
        p.resize(n+1);
        sz.resize(n+1, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x != y) {
            if(sz[x] < sz[y]) swap(x, y);
            p[y] = x;
            sz[x] += sz[y];
        }
    }
    bool same(int x, int y) { return find(x) == find(y); }
};

int n, m;
int cnt[MN];

signed main() {
    hyper;
    cin >> n >> m;
    DSU dsu(n);
    int p = n;
    rep(i,0,m) {
        int u, v;
        cin >> u >> v;
        ++cnt[u], ++cnt[v];
        if(!dsu.same(u, v)) {
            dsu.unite(u, v);
            --p;
        }
    }
    bool f = 1;
    rep1(i,1,n) if(cnt[i] > 2) f = 0;
    if(p == 1 && m == n-1 && f) cout << "Yes\n";
    else cout << "No\n";
}
