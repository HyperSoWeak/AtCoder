#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

signed main() {
    hyper;
    int n, l, r;
    cin >> n >> l >> r;
    rep1(i,1,n) {
        if(i >= l && i <= r) cout << r + l - i << ' ';
        else cout << i << ' ';
    }
}