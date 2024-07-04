#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

vector<int>v;
void prime_fact(ll n){
    for(int i = 2 ; i * i <= n ; ++i){
        while(n % i == 0){
            v.push_back(i);
            n /= i;
        }
    }
    if(n != 1)
        v.push_back(n);
}


int main() {
    ll n, k; cin >> n >> k;

    prime_fact(n);
    if(v.size() >= k){
        ll prod = 1;
        for(int i = 0 ; i < k - 1 && i < v.size(); ++i){
            cout << v[i] << " ";
            prod *= v[i];
        }
        cout << n / prod;
    }else
        cout << -1;



    return 0;
}
