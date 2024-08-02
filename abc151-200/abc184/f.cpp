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
vector<int> p, q;

int search(int k) {
    int l = 0, r = q.size() - 1;
    while(l < r) {
        int m = (l+r+1) / 2;
        if(q[m] <= k) l = m;
        else r = m-1;
    }
    return q[l];
}

signed main() {
    hyper;
    cin >> n >> t;
    rep(i,0,n) cin >> a[i];
    rep(i,0,1<<(n/2)) {
        int sum = 0;
        rep(j,0,n/2) if(i&(1<<j)) sum += a[j];
        if(sum <= t) p.push_back(sum);
    }
    rep(i,0,1<<(n-n/2)) {
        int sum = 0;
        rep(j,0,n-n/2) if(i&(1<<j)) sum += a[n/2+j];
        if(sum <= t) q.push_back(sum);
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    int ans = 0;
    for(int x: p) {
        int y = search(t-x);
        ans = max(ans, x+y);
    }
    cout << ans;
}