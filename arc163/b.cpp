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

int n, m, a[MAXN], ans = INF;

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,n) cin >> a[i];
    sort(a+2, a+n);
    rep(i,2,n-m+1) ans = min(ans, max(0ll,a[0]-a[i]) + max(0ll,a[i+m-1]-a[1]));
    cout << ans;
}
