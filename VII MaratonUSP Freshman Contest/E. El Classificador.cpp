#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define ll long long

int main() {
    ll n, q; cin >> n >> q;
    vector<ll>v(n);
    for(ll i = 0 ; i < n ; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    while(q--){
        ll x; cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        if(it != v.end()){
            cout << *it << ln;
            v.erase(it);
        }
        else cout << -1 << ln;
    }


}
