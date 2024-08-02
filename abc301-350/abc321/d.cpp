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
#define MAXN 200005

int n, m, p, a[MAXN], b[MAXN], ps[MAXN];

signed main() {
    hyper;
    cin >> n >> m >> p;
    rep(i,0,n) cin >> a[i];
    rep(i,0,m) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    ps[0] = 0;
    rep(i,0,m) ps[i+1] = ps[i] + b[i];
    int ans = 0;
    rep(i,0,n) {
        int x = lower_bound(b, b+m, p-a[i]) - b;
        ans += (m-x)*p + ps[x] + a[i]*x;
    }
    cout << ans;
}