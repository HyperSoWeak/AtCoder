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

int vol2(int x1, int y1, int z1, int x2, int y2, int z2) {
    int ans = 1;
    ans *= max(0LL, min(x1+7, x2+7) - max(x1, x2));
    ans *= max(0LL, min(y1+7, y2+7) - max(y1, y2));
    ans *= max(0LL, min(z1+7, z2+7) - max(z1, z2));
    return ans;
}

int vol3(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3) {
    int ans = 1;
    ans *= max(0LL, min(min(x1+7, x2+7), x3+7) - max(max(x1, x2), x3));
    ans *= max(0LL, min(min(y1+7, y2+7), y3+7) - max(max(y1, y2), y3));
    ans *= max(0LL, min(min(z1+7, z2+7), z3+7) - max(max(z1, z2), z3));
    return ans;
}

signed main() {
    hyper;
    int V1, V2, V3;
    cin >> V1 >> V2 >> V3;
    rep1(x1,0,7) rep1(y1,0,7) rep1(z1,0,7) {
        rep1(x2,-1,7) rep1(y2,-1,7) rep1(z2,-1,7) {
            int v3 = vol3(0,0,0,x1,y1,z1,x2,y2,z2);
            if(v3 != V3) continue;
            int v2 = vol2(0,0,0,x1,y1,z1) + vol2(0,0,0,x2,y2,z2) + vol2(x1,y1,z1,x2,y2,z2) - v3 * 3;
            int v1 = 3 * 7 * 7 * 7 - v2 * 2 - v3 * 3;
            if(v1 != V1 || v2 != V2) continue;
            cout << "Yes\n0 0 0 ";
            cout << x1 << ' ' << y1 << ' ' << z1 << ' ';
            cout << x2 << ' ' << y2 << ' ' << z2 << ' ';
            return 0;
        }
    }
    cout << "No";
}