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

int n, k, a[105];
bool dp[100005];

signed main() {
    hyper;
    cin >> n >> k;
    rep(i,0,n) cin >> a[i];
    rep1(i,1,k) rep(j,0,n) {
        if(i-a[j] >= 0 && !dp[i-a[j]]) dp[i] = 1;
    }
    cout << (dp[k] ? "First" : "Second");
}