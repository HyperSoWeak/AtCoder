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
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 2e5+5;

struct Fenwick {
    vector<int> v;
    int sz;
    Fenwick(int n) {
        v.resize(n+1, 0);
        sz = n;
    }
    int lowbit(int x) { return x&-x; }
    void modify(int p, int x) {
        for(int i=p; i<=sz; i+=lowbit(i)) v[i] = max(v[i], x);
    }
    int query(int p) {
        int mx = -INF;
        for(int i=p; i>0; i-=lowbit(i)) mx = max(mx, v[i]);
        return mx;
    }
};

Fenwick bit(MN);

signed main() {
    hyper;
    int n;
    vi h(MN), a(MN);
    cin >> n;
    rep1(i,1,n) cin >> h[i];
    rep1(i,1,n) cin >> a[i];

    vi tmp(h), idx(MN);
    sort(tmp.begin()+1, tmp.begin()+1+n);
    rep1(i,1,n) idx[tmp[i]] = i;

    int ans = -INF;
    rep1(i,1,n) {
        int t = max(bit.query(idx[h[i]]-1), 0) + a[i];
        bit.modify(idx[h[i]], t);
        ans = max(ans, t);
    }
    cout << ans << '\n';
}
