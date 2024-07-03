#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

#define loop(n)          for(ll i = 0; i < (n); i++)
#define lp(x, s, e)      for(ll x = (s); x < (e); x++)
#define loopj(n)         for(ll j = 0; j < (n); j++)
#define space " "



int main() {
    int n; cin >> n;
    vector<int>v(n);
    loop(n) cin >> v[i];
    sort(v.begin(), v.end());

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        auto it = upper_bound(v.begin(), v.end(), x);
        cout << it - v.begin() << ln;
    }



    return 0;
}
