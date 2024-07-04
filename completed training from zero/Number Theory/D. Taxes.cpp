#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

bool is_prime(ll n){
    if(n < 4) return 1;
    if(n % 2 == 0) return 0;
    else{
        for(int i = 3 ; i * i <= n ; ++i){
            if(n % i == 0) return 0;
        }
    }
    return 1;
}

int main() {
    ll n; cin >> n;

    if(is_prime(n)) cout << 1;
    else if(n % 2 == 0) cout << 2;
    else{
        if(is_prime(n - 2)) cout << 2;
        else cout << 3;
    }


    return 0;
}
