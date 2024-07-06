#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

int main() {
    int t; cin >> t;
    while(t--){
        ll a, b, k; cin >> a >> b >> k;
        if(a == b && a != 1) cout << "YES\n";
        else if(a == b && a == 1) cout << "NO\n";
        else{
            ll odds = 0;
            if((b & 1) || (a & 1)) odds++;
            odds += (b - a) / 2;
            if(odds > k) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}
