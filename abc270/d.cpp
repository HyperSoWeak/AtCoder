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

int n, k, a[105], dp[10005];

signed main() {
    hyper;
    cin >> n >> k;
    rep(i,0,k) cin >> a[i];
    rep1(i,1,n) {
        rep(j,0,k) {
            if(i < a[j]) continue;
            dp[i] = max(dp[i], i-dp[i-a[j]]);
        }
    }
    cout << dp[n];
}