#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

int main() {
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n % 2 != 0) n--;
        cout << gcd(n, (n / 2)) << ln;
    }
    return 0;
}
