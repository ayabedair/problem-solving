#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

//idea: range / n = #numbers divisable by n in this range
int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        ll x = k + (k / (n - 1));
        if(k % (n - 1) == 0)
            cout << x - 1 << ln;
        else
            cout << x << ln;
    
    }
    return 0;
}