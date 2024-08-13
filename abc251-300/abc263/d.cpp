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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 2e5+5;

int n, l, r, a[MN], dpl[MN], dpr[MN];

signed main() {
    hyper;
    cin >> n >> l >> r;
    rep1(i,1,n) cin >> a[i];
    rep1(i,1,n) {
        dpl[i] = min(dpl[i-1]+a[i], l*i);
        dpr[i] = min(dpr[i-1]+a[n-i+1], r*i);
    }
    int ans = INF;
    rep1(i,0,n) ans = min(ans, dpl[i]+dpr[n-i]);
    cout << ans;
}