#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 100005

int n, dp[MAXN];
pii a[MAXN];

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) {
        int x, r;
        cin >> x >> r;
        a[i].fi = x + r, a[i].se = x - r;
    }
    sort(a, a+n);
    int ans = 1, r = a[0].fi;
    rep(i,0,n) {
        if(r <= a[i].se) r = a[i].fi, ans++;
    }
    cout << ans;
}