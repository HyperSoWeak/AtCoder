#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 100005

int n, m, l, x, y, ans = 0;
pii a[MAXN], b[MAXN];
struct pair_hash {
    inline size_t operator() (const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
unordered_set<pii, pair_hash> st, used;
struct cmp {
    bool operator() (pii u, pii v) {
        return a[u.fi].fi+b[u.se].fi < a[v.fi].fi+b[v.se].fi;
    }
};
priority_queue<pii, vector<pii>, cmp> pq;

signed main() {
    hyper;
    cin >> n >> m >> l;
    rep1(i,1,n) cin >> a[i].fi, a[i].se = i;
    rep1(i,1,m) cin >> b[i].fi, b[i].se = i;
    rep(i,0,l) {
        cin >> x >> y;
        st.emplace(x,y);
    }
    sort(a+1, a+n+1, greater<pii>());
    sort(b+1, b+m+1, greater<pii>());
    pq.emplace(1,1);
    for(;;) {
        pii t = pq.top(); pq.pop();
        if(!st.count(make_pair(a[t.fi].se,b[t.se].se))) {
            cout << a[t.fi].fi + b[t.se].fi;
            return 0;
        }
        pii x = {t.fi+1, t.se};
        pii y = {t.fi, t.se+1};
        if(!used.count(x)) {
            used.insert(x);
            pq.push(x);
        }
        if(!used.count(y)) {
            used.insert(y);
            pq.push(y);
        }
    }
}