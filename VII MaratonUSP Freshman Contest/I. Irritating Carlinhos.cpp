#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int main() {
    int tx, ty, cx, cy; cin >> tx >> ty >> cx >> cy;
    string t; cin >> t;
    string c; cin >> c;

    if(tx == cx && ty == cy){
        cout << "Rodou!";
        return 0;
    }
    for(int i = 0 ; i < t.size() ; ++i){
        switch (t[i]) {
            case 'U' :
                ty++;
                break;
            case 'D' :
                ty--;
                break;
            case 'R' :
                tx++;
                break;
            case 'L' :
                tx--;
                break;
            default:
                break;
        }
        if(tx == cx && ty == cy) {
            cout << "Rodou!";
            return 0;
        }

        switch (c[i]) {
            case 'U' :
                cy++;
                break;
            case 'D' :
                cy--;
                break;
            case 'R' :
                cx++;
                break;
            case 'L' :
                cx--;
                break;
            default:
                break;
        }
        if(tx == cx && ty == cy){
            cout << "Rodou!";
            return 0;
        }

    }
    cout << "Quase!";
    return 0;
}