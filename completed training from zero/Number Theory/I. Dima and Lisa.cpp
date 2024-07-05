#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

bool is_prime(ll n){
    if(n < 4) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 2 ; i * i <= n ; ++i){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main() {
    ll n; cin >> n;
    if(is_prime(n)) cout << 1 << ln << n;
    else{
        if(is_prime(n - 2)) cout << 2 << ln << 2 << " " << n - 2;
        else{
            cout << 3 << ln << 3 << " ";
            n -= 3;
            for(int i = 3; i < n ; ++i){
                if(is_prime(i) && is_prime(n - i)) {
                    cout << i << " " << n - i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
