#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

int main() {

    int t; cin >> t;
    int d;
    while(t--){
        cin >> d;
        cout << fixed << setprecision(9);
        if((d * d) - (4 * d) < 0) cout << "N\n";
        else{
            cout << "Y ";
            double a = (d + sqrt(d * d - 4 * d)) / 2;
            double b = d - a;
            cout << a << " " << b << "\n";
        }

    }

    return 0;
}
