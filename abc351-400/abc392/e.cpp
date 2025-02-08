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
const int MN = 2e5+5;

struct DSU {
    vector<int> p, sz;
    vector<vi> edges;
    DSU(int n) {
        p.resize(n+1);
        sz.resize(n+1, 1);
        edges.resize(n+1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x != y) {
            if(sz[x] < sz[y]) swap(x, y);
            p[y] = x;
            sz[x] += sz[y];
            edges[x].insert(edges[x].end(), edges[y].begin(), edges[y].end());
        }
    }
    void addEdge(int x, int y) {
        edges[find(x)].push_back(y);
    }
    vi& getEdges(int x) {
        return edges[find(x)];
    }
    bool same(int x, int y) { return find(x) == find(y); }
};

struct Ans {
    int x, y, z;
    Ans(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
};

signed main() {
    hyper;
    int n, m;
    pii edges[MN];
    cin >> n >> m;
    DSU dsu(n+1);
    rep1(i,1,m) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        if(dsu.same(a, b)) dsu.addEdge(a, i);
        else dsu.unite(a, b);
    }
    vector<Ans> ans;
    while(dsu.sz[dsu.find(1)] < n) {
        rep1(i,2,n) {
            if(!dsu.same(1, i)) {
                vi &e1 = dsu.getEdges(1), &e2 = dsu.getEdges(i);
                if(e1.size()) {
                    int x = e1.back();
                    e1.pop_back();
                    ans.emplace_back(x, edges[x].se, dsu.find(i));
                    dsu.unite(1, i);
                } else if(e2.size()) {
                    int x = e2.back();
                    e2.pop_back();
                    ans.emplace_back(x, edges[x].se, dsu.find(1));
                    dsu.unite(1, i);
                } else {
                    continue;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto &i: ans) cout << i.x << ' ' << i.y << ' ' << i.z << '\n';
}
