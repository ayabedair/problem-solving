#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

bool is_prime(ll n){
    if(n == 1) return 0;
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
    int n, k ; cin >> n >> k;
    vector<int>v;
    for(int i = 2 ; i <= n ; ++i)
        if(is_prime(i)) v.push_back(i);

    int cnt = 0;
    for(int i = 0 ; i < v.size() ; ++i){
        if(is_prime(v[i] + v[i + 1] + 1) && v[i] + v[i + 1] + 1 <= n)
            cnt++;
        if(cnt >= k) {cout << "YES"; return 0;}
    }
    cout << "NO";
    return 0;
}
