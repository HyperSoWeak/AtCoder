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

int n, a[3][MAXN], dp[3][MAXN];

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) rep(j,0,3) cin >> a[j][i];
    rep1(i,1,n) {
        dp[0][i] = max(dp[1][i-1]+a[1][i],dp[2][i-1]+a[2][i]);
        dp[1][i] = max(dp[0][i-1]+a[0][i],dp[2][i-1]+a[2][i]);
        dp[2][i] = max(dp[0][i-1]+a[0][i],dp[1][i-1]+a[1][i]);
    }
    cout << max(dp[0][n],max(dp[1][n],dp[2][n]));
}