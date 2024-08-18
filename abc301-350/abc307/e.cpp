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
const int MN = 1e6+5;

int n, m, dp[MN][2];

signed main() {
    hyper;
    cin >> n >> m;
    dp[1][1] = m;
    rep1(i,2,n) {
        dp[i][0] = (dp[i-1][0]*(m-2) + dp[i-1][1]*(m-1)) % MOD;
        dp[i][1] = dp[i-1][0];
    }
    cout << dp[n][0];
}
