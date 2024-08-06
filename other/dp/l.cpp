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

int n, a[MAXN], dp[MAXN][MAXN];

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for(int l=n; l>=1; --l) {
        rep1(r,l+1,n) {
            dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    }
    cout << dp[1][n];
}
