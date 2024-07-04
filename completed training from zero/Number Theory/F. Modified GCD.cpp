#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

vector<ll>v;
void fact(ll n){
    for(int i = 1; i * i <= n ; ++i){
        if(n % i == 0) {
            v.push_back(i);
            if (i * i != n)
                v.push_back(n / i);
        }
    }
}

int main() {
    ll a, b; cin >> a >> b;
    ll g = gcd(a, b);
    fact(g);

    sort(v.begin(), v.end());
    ll n; cin >> n;
    while(n--){
        ll x, y; cin >> x >> y;
        bool f = 0;
        for(int i = v.size() - 1 ; i >= 0 ; --i) {
            if (v[i] >= x && v[i] <= y)
            {
                cout << v[i] << ln;
                f = 1;
            }
            if(f) break;
        }
        if(!f) cout << -1 << ln;
    }

    return 0;
}
