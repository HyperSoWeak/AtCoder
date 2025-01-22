#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using mat = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e5+5;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

signed main() {
    hyper;
    int h, w;
    string s[55];
    cin >> h >> w;
    rep(i,0,h) cin >> s[i];
    rep(i,0,h) rep(j,0,w) {
        if(s[i][j] == '#') continue;
        int cnt = 0;
        rep(k,0,8) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if(s[ni][nj] == '#') ++cnt;
        }
        s[i][j] = cnt + '0';
    }
    rep(i,0,h) cout << s[i] << '\n';
}
