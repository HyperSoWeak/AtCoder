#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 200005

int n, x;
struct Board {
    int h, ps, idx;
    Board(int h, int ps, int idx):
        h(h), ps(ps), idx(idx) {}
};
stack<Board> q;

signed main() {
    hyper;
    cin >> n;
    q.emplace(INF, 0, 0);
    rep1(i,1,n) {
        cin >> x;
        while(q.top().h <= x) q.pop();
        int sum = q.top().ps + (i-q.top().idx) * x;
        q.emplace(x, sum, i);
        cout << sum+1 << ' ';
    }
}