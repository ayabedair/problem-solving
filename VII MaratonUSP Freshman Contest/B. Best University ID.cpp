#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int N = 10005;
bitset<N> notPrime;
vector<ll> prime;

void getPrime() {
    for (ll i = 2; i < N; ++i) {
        if (!notPrime[i]) {
            prime.push_back(i);
            for (ll j = i * 2; j < N; j += i) {
                notPrime[j] = true;
            }
        }
    }
}

ll max_prime(ll x) {
    ll t = 0;
    for (int i = 0 ; i < prime.size() ; ++i) {
        if(x % prime[i] != 0) continue;
        t = prime[i];
        while(x % prime[i] == 0)
            x /= prime[i];
        if (x == 1) break;
    }
    return max(t, x);
}

int main() {
    int n; cin >> n;
    getPrime();
    ll mx = 0;
    string res;
    while(n--){
        string s; cin >> s;
        ll id; cin >> id;
        ll t = max_prime(id);
        if(t > mx) {
            res = s;
            mx = t;
        }
    }
    cout << res;
    return 0;
}


