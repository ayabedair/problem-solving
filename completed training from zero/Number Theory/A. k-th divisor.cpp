#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'


int main() {
    ll n, k; cin >> n >> k;
    k--;
    vector<ll>v;

    for(ll i = 1; i * i <= n ; ++i){
        if(n % i == 0) {
            v.push_back(i);
            if (i * i != n)
                v.push_back(n / i);
        }
    }

    sort(v.begin(), v.end());
    k < v.size()? cout << v[k] : cout << -1;



    return 0;
}
