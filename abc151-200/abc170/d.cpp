#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 200005
#define MAXA 1000005

int n, a[MAXN], ans = 0;
bool f[MAXA];

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    sort(a, a+n);
    rep(i,0,n) {
        if(!f[a[i]]) {
            if(i==n-1 || a[i]!=a[i+1]) ans++;
            for(int j=1; a[i]*j<MAXA; ++j) {
                f[a[i]*j] = 1;
            }
        }
    }
    cout << ans;
}