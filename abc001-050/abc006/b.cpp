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

signed main() {
    hyper;
    int n, dp[1000005];
    dp[1] = dp[2] = 0, dp[3] = 1;
    cin >> n;
    rep1(i,4,n) dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]) % 10007;
    cout << dp[n];
}