#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> X, Y;

    for(int i = 0 ; i < n ; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        X.push_back(x2); Y.push_back(y2);
    }
    int l = 0, r = 1e9;
    while(l <= r){
        int h = l + (r - l)/2, count = 0;
        for(int i = 0 ; i < X.size() ; i++){
            if(h >= X[i] && h >= Y[i]) count++;
        }

        if(count >= k) r = h - 1;
        else l = h + 1;
    }

    cout << r + 1;
    return 0;
}