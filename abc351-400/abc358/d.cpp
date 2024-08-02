#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 200005

signed main() {
    hyper;
    int n, m, a[MAXN], b[MAXN];
    cin >> n >> m;
    rep(i,0,n) cin >> a[i];
    rep(i,0,m) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int x=0, y=0, ans=0;
    while(y != m) {
        if(x == n) {
            cout << -1;
            return 0;
        }
        if(a[x] >= b[y]) ans += a[x], y++;
        x++;
    }
    cout << ans;
}