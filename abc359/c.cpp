#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

int sx, sy, tx, ty;

signed main() {
    hyper;
    cin >> sx >> sy >> tx >> ty;
    if(sx > tx) {
        swap(sx, tx);
        swap(sy, ty);
    }
    int dx = abs(sx-tx), dy = abs(sy-ty);
    cout << dy + max(0ll, (dx-(dy+((sx+sy)%2==0))+1)/2);
}