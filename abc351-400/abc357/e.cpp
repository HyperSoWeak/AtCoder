#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
using namespace std;
#define MAXN 200005

int n, to[MAXN], indeg[MAXN] = {0}, cnt[MAXN];

signed main() {
    cin >> n;
    rep1(i,1,n) {
        cin >> to[i];
        indeg[to[i]]++;
        cnt[i] = 1;
    }
    queue<int> q;
    rep1(i,1,n) if(indeg[i] == 0) q.push(i);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        cnt[to[x]] += cnt[x];
        indeg[to[x]]--;
        if(indeg[to[x]] == 0) q.push(to[x]);
    }
    rep1(i,1,n) {
        if(indeg[i]) {
            int sum = cnt[i], head = i, x = to[i];
            while(x != head) {
                sum += cnt[x];
                x = to[x];
            }
            do {
                cnt[x] = sum;
                indeg[x] = 0;
                x = to[x];
            } while(x != head);
        }
    }
    int ans = 0;
    rep1(i,1,n) ans += cnt[i];
    cout << ans;
}