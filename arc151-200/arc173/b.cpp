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
#define MAXN 305

int n, mx = 0;
pii a[MAXN];

bool check(pii x, pii y, pii z) {
    return ((x.se-y.se)*(x.fi-z.fi) == (x.se-z.se)*(x.fi-y.fi));
}

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) cin >> a[i].fi >> a[i].se;
    rep(i,0,n-2) rep(j,i+1,n-1) {
        int cnt = 2;
        rep(k,j+1,n) if(check(a[i],a[j],a[k])) cnt++;
        mx = max(mx, cnt);
    }
    cout << min(n/3, n-mx);
}