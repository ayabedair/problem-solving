#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(ll num){
    if(num<2) return 0;
    for(int i=2;i*i<=num;i++){
        if(num%i == 0) return 0;
    }
    return 1;
}
int main() {

    int t; cin>>t;
    while(t--)
    {
        ll x; cin>>x;
        int sq = sqrt(x);
        if((ll)sq*sq == x && isPrime(sq))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}