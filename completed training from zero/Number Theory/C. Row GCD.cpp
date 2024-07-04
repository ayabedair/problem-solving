#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'


int main() {
    ll n, m; cin >> n >> m;

    vector<ll>a(n), b(m);
    for(int i = 0 ; i < n ; ++i) {cin >> a[i];}
    for(int i = 0 ; i < m ; ++i) {cin >> b[i];}

    sort(a.begin(), a.end());
    ll gc = 0;
    for(int j = 1 ; j < n ; ++j){
        gc = gcd(gc , a[j] - a[0]);
    }
    for(int i = 0 ; i < m ; ++i)
        cout << gcd(gc, a[0] + b[i]) << " ";

    return 0;
}
