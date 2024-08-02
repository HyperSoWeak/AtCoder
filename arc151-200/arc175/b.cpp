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

int n, a, b, st, x, y;
string s;

signed main() {
    hyper;
    cin >> n >> a >> b >> s;
    rep(i,0,2*n) {
        if(s[i] == '(') st++;
        else if(st > 0) st--;
        else x++, st++;
    }
    y = st / 2;
    if(2*b > a) cout << min(x,y)*a + abs(x-y)*b;
    else cout << (x+y)*b;
}