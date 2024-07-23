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

int q, c, x;
priority_queue<int, vector<int>, greater<int>> pq;
queue<int> qq;

signed main() {
    hyper;
    cin >> q;
    while(q--) {
        cin >> c;
        if(c == 1) {
            cin >> x;
            qq.push(x);
        }
        else if(c == 2) {
            if(!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else {
                cout << qq.front() << '\n';
                qq.pop();
            }
        }
        else {
            while(!qq.empty()) {
                pq.push(qq.front());
                qq.pop();
            }
        }
    }
}