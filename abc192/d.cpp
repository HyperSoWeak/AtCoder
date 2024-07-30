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

string x;
int m;

bool check(int n) {
    int a = 0;
    for(char c: x) {
        if(a > (2e18)/n) return 0; // overflow
        a = a*n + c-'0';
    }
    return (a <= m);
}

signed main() {
    hyper;
    cin >> x >> m;
    if(x.size() == 1) return cout << (x[0]-'0' <= m), 0;
    int mx = *max_element(x.begin(), x.end()) - '0';
    int l = mx, r = 1e18;
    while(l < r) {
        int m = (l+r+1) / 2;
        if(check(m)) l = m;
        else r = m-1;
    }
    cout << l - mx;
}
