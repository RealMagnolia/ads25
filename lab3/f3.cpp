#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> el;

    for(int i = 0 ; i < n ; i++){
        int t; cin >> t;
        el.push_back(t);
    }
    sort(el.begin() , el.end());

    vector <int> pow(n+1);
    pow[0] = 0;
    for(int i = 0 ; i < n ; i++) pow[i+1] = pow[i] + el[i];

    int p; cin >> p;
    for(int i = 0 ; i < p ; i++){
        int m; cin >> m;
        int l = 0 , r = el.size() - 1;
        while(l <= r){
            int h = l + (r - l)/2;
            if(m >= el[h])  l = h + 1;
            else r = h - 1;
        }

        int score = l;
        cout << score << " " << pow[score] << endl;
    }
    return 0;
}