#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define max max<int>
#define min min<int>
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 405

int n, a[MAXN], dp[MAXN][MAXN], ps[MAXN];

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) {
        cin >> a[i];
        dp[i][i] = 0;
        ps[i] = ps[i-1] + a[i];
    }
    rep1(len,2,n) rep1(i,1,n-len+1) {
        int j = i + len - 1;
        dp[i][j] = INF;
        rep(k,i,j) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+ps[j]-ps[i-1]);
    }
    cout << dp[1][n];
}
