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
    vector<int> p, sz, col, cnt;
    DSU(int n) {
        p.resize(n+1);
        col.resize(n+1);
        sz.resize(n+1, 1);
        cnt.resize(n+1, 1);
        iota(p.begin(), p.end(), 0);
        iota(col.begin(), col.end(), 0);
    }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x != y) {
            if(x > y) swap(x, y);
            p[y] = x;
            sz[x] += sz[y];
        }
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void paint(int x, int c) {
        int y = find(x);
        int size = sz[y];
        cnt[col[y]] -= size;
        col[y] = c;
        cnt[col[y]] += size;
        if(col[find(y-1)] == col[y]) unite(y-1, y);
        if(col[find(y+size)] == col[y]) unite(y, y+size);
    }
    int get(int c) { return cnt[c]; }
};

signed main() {
    hyper;
    int n, q;
    cin >> n >> q;
    DSU dsu(n+5);
    while(q--) {
        int t, x, c;
        cin >> t;
        if(t == 1) {
            cin >> x >> c;
            dsu.paint(x, c);
        } else {
            cin >> c;
            cout << dsu.get(c) << '\n';
        }
    }
}
