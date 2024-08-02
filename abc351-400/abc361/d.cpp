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

int n;
string s, t;
unordered_map<string, int> dis;
queue<string> q;

signed main() {
    hyper;
    cin >> n >> s >> t;
    s += "..", t += "..";
    dis[s] = 0;
    q.push(s);
    while(!q.empty()) {
        string u = q.front(); q.pop();
        if(u == t) return cout << dis[t], 0;
        int x = 0;
        while(u[x] != '.') x++;
        rep1(i,0,n) if(i+1 < x || i > x+1) {
            string v = u;
            swap(v[i], v[x]);
            swap(v[i+1], v[x+1]);
            if(dis.find(v) != dis.end()) continue;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
    cout << "-1";
}
