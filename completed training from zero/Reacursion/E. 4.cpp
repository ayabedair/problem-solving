#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

int main()
{
    ll n; cin >> n;
    for(int i = 0 ; i < 100 ; ++i){
        for(int j =  0; j < 1000 ; ++j){
            ll res = n - (1234567 * i) - (123456 * j);
            if(res < 0) break;
            if(res % 1234 == 0) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}
