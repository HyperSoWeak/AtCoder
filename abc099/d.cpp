#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 1005

int n, m, w[3][MAXN], a[MAXN], ans = -INF, q[3];

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,n) rep(j,0,3) cin >> w[j][i];
    rep(t,0,8) {
        rep(j,0,3) q[j] = ((t>>j)&1)*2-1;
        rep(i,0,n) {
            a[i] = 0;
            rep(j,0,3) a[i] += w[j][i] * q[j];
        }
        sort(a, a+n, greater<int>());
        int sum = 0;
        rep(i,0,m) sum += a[i];
        ans = max(ans, sum);
    }
    cout << ans;
}