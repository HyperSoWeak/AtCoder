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
#define MOD 1000000007

int n, m, dp[100005], x;

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,m) {
        cin >> x;
        dp[x] = -1;
    }
    dp[0] = 1;
    dp[1]++;
    rep1(i,2,n) {
        if(dp[i] == -1) dp[i] = 0;
        else dp[i] = (dp[i-1]+dp[i-2]) % MOD;
    }
    cout << dp[n];
}