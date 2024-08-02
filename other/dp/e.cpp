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
    rr(dp,0x3f);
    dp[0] = 0;
    rep1(i,1,n) {
        for(int j=100000; j>=v[i]; --j) {
            dp[j] = min(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    for(int i=100000; i>=0; --i) {
        if(dp[i] <= m) {
            cout << i;
            return 0;
        }
    }
}