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
#define D 8010

string s;
int x, y;
int a[D], b[D], la=0, lb=0;
bool dpx[D][2*D+1], dpy[D][2*D+1];
bitset<2*D+1> X, Y;

signed main() {
    hyper;
    cin >> s >> x >> y;
    bool xx = 1;
    int cnt = 0;
    for(char c: s) {
        if(c == 'F') {
            cnt++;
        }
        else {
            if(cnt) {
                if(xx) a[++la] = cnt;
                else b[++lb] = cnt;
            }
            xx = !xx;
            cnt = 0;
        }
    }
    if(cnt) {
        if(xx) a[++la] = cnt;
        else b[++lb] = cnt;
    }
    if(s[0]=='F') {
        X[D+a[1]] = 1;
        rep1(i,2,la) X = (X>>a[i]) | (X<<a[i]);
    }
    else {
        X[D] = 1;
        rep1(i,1,la) X = (X>>a[i]) | (X<<a[i]);
    }
    Y[D] = 1;
    rep1(i,1,lb) Y = (Y>>b[i]) | (Y<<b[i]);
    if(X[D+x] & Y[D+y]) cout << "Yes\n";
    else cout << "No\n";
}
