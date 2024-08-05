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
#define MAXN 3005

int n;
double p[MAXN], dp[MAXN][MAXN];

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) cin >> p[i];
    dp[0][0] = 1;
    rep1(i,1,n) {
        dp[i][0] = dp[i-1][0]*(1-p[i]);
        rep1(j,1,i) dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i]);
    }
    double sum = 0;
    for(int i=n; i>n-i; --i) sum += dp[n][i];
    cout << fixed << setprecision(10) << sum;
}