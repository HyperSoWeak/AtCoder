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

int n, t, a[45];
vector<int> v[2];

void dfs(int d, int sum, bool h) {
    if(sum > t) return;
    if(d == (h ? n : n/2)) {
        v[h].push_back(sum);
        return;
    }
    dfs(d+1, sum, h);
    dfs(d+1, sum+a[d], h);
}

signed main() {
    hyper;
    cin >> n >> t;
    rep(i,0,n) cin >> a[i];
    dfs(0,0,0); dfs(n/2,0,1);
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    int ans = 0;
    for(int x: v[0]) {
        int y = v[1][upper_bound(v[1].begin(), v[1].end(), t-x) - v[1].begin() - 1];
        ans = max(ans, x+y);
    }
    cout << ans;
}