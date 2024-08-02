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
#define MAXN 300005

int n;
pii a[MAXN];

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) cin >> a[i].fi;
    rep(i,0,n) cin >> a[i].se;
    sort(a, a+n);
    vector<int> ans;
    ans.push_back(a[0].se);
    rep(i,1,n) {
        if(a[i].se > ans.back()) ans.push_back(a[i].se);
        else {
            int t = lower_bound(ans.begin(), ans.end(), a[i].se) - ans.begin();
            ans[t] = a[i].se;
        }
    }
    cout << n + ans.size();
}