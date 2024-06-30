#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 200005

struct Fenwick {
    vector<int> v;
    int size;
    Fenwick(int n) {
        v.resize(n+2, 0);
        size = n+1;
    }
    int lowbit(int x) { return x & (-x); }
    void modify(int pos, int x) {
        for(int i=pos; i<=size; i+=lowbit(i)) {
            v[i] += x;
        }
    }
    int query(int pos) {
        int sum = 0;
        for(int i=pos; i>0; i-=lowbit(i)) {
            sum += v[i];
        }
        return sum;
    }
    void radd(int l, int r, int x) {
        if(l>r) return;
        modify(l, x);
        modify(r+1, -x);
    }
};

int n, m, x;
Fenwick bit(MAXN);

signed main() {
    hyper;
    cin >> n >> m;
    rep1(i,1,n) {
        cin >> x;
        bit.radd(i, i, x);
    }
    while(m--) {
        cin >> x;
        x++;
        int q = bit.query(x);
        bit.radd(x, x, -q);
        bit.radd(1, n, q/n);
        q %= n;
        bit.radd(x+1, min(n, x+q), 1);
        q -= n-x;
        bit.radd(1, max(0ll, q), 1);
    }
    rep1(i,1,n) cout << bit.query(i) << ' ';
}
