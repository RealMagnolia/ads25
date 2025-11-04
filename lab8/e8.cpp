#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;
    vector <ll> p(n);
    for(int i = 0 ; i < n ; i++){
        cin >> p[i];
    }

    ll pow = 1;
    vector <ll> conv(n, 0);
    for(int i = 0 ; i < n ; i++){
        if(i == 0) {
            conv[i] = (p[i]/pow) + 97;
            pow *= 2;
        }
        else {
            conv[i] = ((p[i] - p[i-1])/pow) + 97;
            pow *= 2; 
        }
    }

    for(int i = 0 ; i < conv.size() ; i++){
        cout << (char)conv[i];
    }

    return 0;
}