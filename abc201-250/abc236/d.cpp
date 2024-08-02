#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

int n, a[20][20], ans = 0;
bool used[20];

void solve(int d, int sum) {
    if(d == n) {
        ans = max(ans, sum);
        return;
    }
    int x = 1;
    while(used[x]) x++;
    used[x] = 1;
    rep1(y,x+1,n*2) {
        if(used[y]) continue;
        used[y] = 1;
        solve(d+1, sum ^ a[x][y]);
        used[y] = 0;
    }
    used[x] = 0;
}

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n*2-1) rep1(j,i+1,n*2) cin >> a[i][j];
    solve(0, 0);
    cout << ans;
}