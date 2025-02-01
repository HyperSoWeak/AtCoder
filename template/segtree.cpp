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

struct Segtree {
    vector<int> t, lz;
    int sz;
    Segtree(int n) {
        t.resize(4*n, 0);
        lz.resize(4*n, 0);
        sz = n;
    }
    void push(int v, int l, int r) {
        if(lz[v]) {
            t[v] += lz[v];
            if(l != r) {
                lz[2*v] += lz[v];
                lz[2*v+1] += lz[v];
            }
            lz[v] = 0;
        }
    }
    void modify(int v, int l, int r, int ql, int qr, int x) {
        push(v, l, r);
        if(ql > r || qr < l) return;
        if(ql <= l && r <= qr) {
            lz[v] += x;
            push(v, l, r);
            return;
        }
        int m = (l+r)/2;
        modify(2*v, l, m, ql, qr, x);
        modify(2*v+1, m+1, r, ql, qr, x);
        t[v] = max(t[2*v], t[2*v+1]);
    }
    int query(int v, int l, int r, int ql, int qr) {
        push(v, l, r);
        if(ql > r || qr < l) return -INF;
        if(ql <= l && r <= qr) return t[v];
        int m = (l+r)/2;
        return max(query(2*v, l, m, ql, qr), query(2*v+1, m+1, r, ql, qr));
    }
    void modify(int l, int r, int x) { modify(1, 1, sz, l, r, x); }
    int query(int l, int r) { return query(1, 1, sz, l, r); }
};

signed main() {
    hyper;

}
