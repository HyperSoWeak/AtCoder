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

void solve() {
    int a[6], p[6];
    rep1(i,1,5) cin >> a[i];
    rep1(i,1,5) cin >> p[i];
    int x = -(a[5]+a[5]+a[4]-a[2]-a[1]-a[1]);
    if(x <= 0) cout << 0 << '\n';
    else if(p[4]*2 <= p[5]) cout << p[4]*x << '\n';
    else if(p[5] <= p[4]) cout << (x+1)/2*p[5] << '\n';
    else cout << x/2*p[5] + x%2*p[4] << '\n';
}

signed main() {
    hyper;
    int t;
    cin >> t;
    while(t--) solve();
}