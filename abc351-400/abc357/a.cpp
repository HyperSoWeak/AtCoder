#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
using namespace std;

int main() {
    int n, m, a, cnt=0;
    cin >> n >> m;
    rep(i,0,n) {
        cin >> a;
        if(m >= a) {
            m -= a;
            cnt++;
        } else break;
    }
    cout << cnt;
}