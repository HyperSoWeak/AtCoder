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

struct Data {
    int value;
    int a, b, c;
    Data(int value, int a, int b, int c):
        value(value), a(a), b(b), c(c) {}
    bool operator<(const Data& d) const {
        return value < d.value;
    }
};

int n, k;
int a[MN], b[MN], c[MN];
priority_queue<Data> pq;
set<tuple<int,int,int>> s;

void push(int x, int y, int z) {
    if(s.count({x,y,z})) return;
    if(x >= n || y >= n || z >= n) return;
    s.emplace(x,y,z);
    pq.emplace(a[x]*b[y]+b[y]*c[z]+c[z]*a[x],x,y,z);
}

signed main() {
    hyper;
    cin >> n >> k;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];
    rep(i,0,n) cin >> c[i];
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
    sort(c,c+n,greater<int>());
    push(0,0,0);
    rep(i,0,k-1) {
        auto [v, ai, bi, ci] = pq.top(); pq.pop();
        push(ai+1,bi,ci);
        push(ai,bi+1,ci);
        push(ai,bi,ci+1);
    }
    cout << pq.top().value << '\n';
}
