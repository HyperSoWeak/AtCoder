#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

struct Node {
    int x, y, step;
    Node(int x, int y, int step):
        x(x), y(y), step(step) {}
};
int n, m, a[405][405];
queue<Node> q;

void update(int x, int y, int step) {
    if(y>=1 && y<=n && a[x][y]==-1) {
        a[x][y] = step;
        q.emplace(x, y, step);
    }
}

signed main() {
    hyper;
    cin >> n >> m;
    int mq = sqrt(m);
    rr(a,-1);
    a[1][1] = 0;
    q.emplace(1,1,0);
    while(!q.empty()) {
        Node t = q.front(); q.pop();
        rep1(i,max(1ll,t.x-mq),min(n,t.x+mq)) {
            int d = m - (i-t.x) * (i-t.x);
            int dq = sqrt(d);
            if(dq*dq != d) continue;
            update(i, t.y+dq, t.step+1);
            update(i, t.y-dq, t.step+1);
        }
    }
    rep1(i,1,n) rep1(j,1,n) cout << a[i][j] << " \n"[j==n];
}