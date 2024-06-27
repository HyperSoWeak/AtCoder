#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 505

int h, w, a[MAXN][MAXN];
struct Move {
    int x1, y1, x2, y2;
    Move(int x1, int y1, int x2, int y2):
        x1(x1), y1(y1), x2(x2), y2(y2) {}
};
vector<Move> v;

signed main() {
    hyper;
    cin >> h >> w;
    rep1(i,1,h) rep1(j,1,w) cin >> a[i][j];
    rep1(i,1,h) {
        rep1(j,1,w-1) {
            if(a[i][j] & 1) {
                v.emplace_back(i, j, i, j+1);
                a[i][j]--;
                a[i][j+1]++;
            }
        }
    }
    rep1(i,1,h-1) {
        if(a[i][w] & 1) {
            v.emplace_back(i, w, i+1, w);
            a[i][w]--;
            a[i+1][w]++;
        }
    }
    cout << v.size() << '\n';
    for(Move e: v) {
        cout << e.x1 << ' ' << e.y1 << ' ';
        cout << e.x2 << ' ' << e.y2 << '\n';
    }
}