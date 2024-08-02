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
#define MAXN 105
#define MAXW 100005

int n, m, dp[MAXW], w[MAXN], v[MAXN];

signed main() {
    hyper;
    cin >> n >> m;
    rep1(i,1,n) cin >> w[i] >> v[i];
    rep1(i,1,n) {
        for(int j=m; j>=w[i]; --j) {
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout << dp[m];
}