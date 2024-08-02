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

int n, X, Y, t;
bitset<20025> x, y;

signed main() {
    hyper;
    cin >> n >> X >> Y >> t;
    x[10010] = x[10010+t] = y[10010] = 1;
    rep(i,1,n) {
        cin >> t;
        if(i&1) y = (y>>t) | (y<<t);
        else x = (x>>t) | (x<<t);
    }
    if(x[10010+X] & y[10010+Y]) cout << "Yes\n";
    else cout << "No\n";
}