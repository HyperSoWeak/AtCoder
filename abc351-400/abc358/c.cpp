#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

signed main() {
    hyper;
    int n, m, a[10] = {0};
    string s;
    cin >> n >> m;
    rep(i,0,n) {
        cin >> s;
        for(char c: s) a[i] = a[i] * 2 + (c == 'o');
    }
    int ans = INF;
    rep(i,0,1<<n) {
        int sum = 0, cnt = 0;
        rep(j,0,n) {
            if((i>>j) & 1) {
                sum |= a[j];
                cnt++;
            }
        }
        if(sum == (1<<m)-1) ans = min(ans, cnt);
    }
    cout << ans;
}