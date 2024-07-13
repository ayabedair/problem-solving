#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define ll long long

int main() {
    int t; cin >> t;
    while(t--){
        ll k, g, n; cin >> k >> g >> n;

        if(((g + n) / k) % 2)
            cout << "Nathan\n";
        else
            cout << "Thiago\n";
    }


}
