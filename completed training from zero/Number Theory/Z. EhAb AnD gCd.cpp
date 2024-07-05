#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

/*
 * assume a = 1
 * gcd(1, b) = 1
 * lcm(1, b) = b
 * so, 1 + b = x
 * b = x - 1
 * */

int main() {
    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        cout << 1 << " " << x - 1 << ln;
    }
    return 0;
}
