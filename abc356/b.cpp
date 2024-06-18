#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

signed main() {
    hyper;
    int n, m, a[105], cnt[105] = {0};
    cin >> n >> m;
    rep(i,0,m) cin >> a[i];
    rep(i,0,n) {
        rep(j,0,m) {
            int x;
            cin >> x;
            cnt[j] += x;
        }
    }
    rep(i,0,m) {
        if(cnt[i] < a[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}