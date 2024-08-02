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
#define MAXN 200005

int n, a[MAXN], b[MAXN];
int dp[MAXN][2][2];

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) cin >> a[i];    
    rep1(i,1,n) cin >> b[i];    
    dp[1][0][0] = a[1], dp[1][1][1] = 0;
    dp[1][0][1] = dp[1][1][0] = INF;
    rep(t,0,2) rep1(i,2,n) {
        dp[i][0][t] = min(dp[i-1][0][t]+b[i-1], dp[i-1][1][t]) + a[i];
        dp[i][1][t] = min(dp[i-1][0][t], dp[i-1][1][t]+b[i-1]);
    }
    int ans = INF;
    rep(i,0,2) rep(j,0,2) ans = min(ans, dp[n][i][j]+(i==j?b[n]:0));
    cout << ans;
}