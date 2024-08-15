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
const int MW = 1e5+5;

int t, n = 12, dp[MW];
int w[] = {0, 1, 6, 36, 216, 1296, 7776, 46656, 9, 81, 729, 6561, 59049};

signed main() {
    hyper;
    cin >> t;
    rep1(j,0,t) dp[j] = INF;
    dp[0] = 0;
    rep1(i,1,n) rep1(j,0,t) {
        if(j-w[i] >= 0) dp[j] = min(dp[j], dp[j-w[i]]+1);
    }
    cout << dp[t];
}
