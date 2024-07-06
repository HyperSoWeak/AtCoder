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
#define MAXN 505

int n, dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
string s[MAXN];
struct Node {
    int x, y, d;
    Node(int x, int y, int d): x(x), y(y), d(d) {}
    friend bool operator<(const Node a, const Node b) {
        return a.d > b.d;
    }
};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void dijk(int sy, char clr) {
    rr(vis,0);
    rr(dis,0x3f);
    dis[0][sy] = 0;
    priority_queue<Node> pq;
    pq.emplace(0,sy,0);
    while(!pq.empty()) {
        Node t = pq.top(); pq.pop();
        vis[t.x][t.y] = 1;
        rep(i,0,4) {
            int x = t.x+dx[i];
            int y = t.y+dy[i];
            if(x<0 || y<0 || x>=n || y>=n) continue;
            if(vis[x][y]) continue;
            int d = dis[t.x][t.y] + (s[x][y]!=clr);
            if(d < dis[x][y]) {
                dis[x][y] = d;
                pq.emplace(x,y,d);
            }
        }
    }
}

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) cin >> s[i];
    dijk(0, 'R');
    int ans = dis[n-1][n-1];
    dijk(n-1, 'B');
    cout << ans + dis[n-1][0];
}