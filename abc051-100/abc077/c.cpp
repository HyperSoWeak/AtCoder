#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

#define MAXN 100005

int n, a[MAXN], b[MAXN], c[MAXN];
int x[MAXN], y[MAXN];

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) cin >> a[i];
    rep1(i,1,n) cin >> b[i];
    rep1(i,1,n) cin >> c[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    sort(c+1, c+n+1);
    a[0] = b[0] = c[0] = 0;
    a[n+1] = b[n+1] = c[n+1] = INF;
    int i = 1, j = 1;
    while(i <= n) {
        if(b[i] < c[j]) x[i++] = n + 1 - j;
        else j++;
    }
    i = 1, j = 1;
    while(i <= n) {
        if(b[i] <= a[j]) y[i++] = j - 1;
        else j++;
    }
    int ans = 0;
    rep1(i,1,n) ans += x[i] * y[i];
    cout << ans;
}
