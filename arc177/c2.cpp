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
    int x, y;
    Node(int x, int y): x(x), y(y) {}
};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void bfs(int sy, char clr) {
    rr(vis,0);
    dis[0][sy] = 0;
    vis[0][sy] = 1;
    deque<Node> q;
    q.emplace_back(0,sy);
    while(!q.empty()) {
        Node t = q.front(); q.pop_front();
        rep(i,0,4) {
            int x = t.x+dx[i];
            int y = t.y+dy[i];
            if(x<0 || y<0 || x>=n || y>=n) continue;
            if(!vis[x][y]) {
                dis[x][y] = dis[t.x][t.y] + (s[x][y]!=clr);
                if(s[x][y]!=clr) q.emplace_back(x,y);
                else q.emplace_front(x,y);
                vis[x][y] = 1;
            }
        }
    }
}

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) cin >> s[i];
    bfs(0, 'R');
    int ans = dis[n-1][n-1];
    bfs(n-1, 'B');
    cout << ans + dis[n-1][0];
}