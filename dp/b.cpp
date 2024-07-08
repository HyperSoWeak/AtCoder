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

int n, k, h[100005], dp[100005];

signed main() {
    hyper;
    rr(dp,0x3f);
    cin >> n >> k;
    rep1(i,1,n) cin >> h[i];
    dp[1] = 0;
    rep1(i,2,n) rep1(j,1,k) {
        if(i-j >= 0) dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
    }
    cout << dp[n];
}