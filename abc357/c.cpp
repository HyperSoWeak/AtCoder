#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
using namespace std;

int n, pw[7] = {1,3,9,27,81,243,729};
bool a[729][729] = {{0}};

void gen(int x, int y, int sz) {
    if(sz == 3) {
        a[x+1][y+1] = 1;
        return;
    }
    if(sz == 1) return;
    rep(i,0,sz/3) rep(j,0,sz/3) {
        a[x+sz/3+i][y+sz/3+j] = 1;
    }
    rep(i,0,3) rep(j,0,3) {
        gen(x+i*sz/3, y+j*sz/3, sz/3);
    }
}

signed main() {
    cin >> n;
    gen(0,0,pw[n]);
    rep(i,0,pw[n]) {
        rep(j,0,pw[n]) {
            if(a[i][j]) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
}