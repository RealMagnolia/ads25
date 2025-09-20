#include <iostream>
using namespace std;

int abs(int n){
    return ((n < 0) ? n * (-1) : n);
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int k; cin >> k;
    int diff[n];
    for(int i = 0 ; i < n ; i++){
        diff[i] = abs(k - a[i]);
    }

    int m = 1e8, ind = 0;
    for(int i = 0 ; i < n ; i++){
        if(diff[i] < m) {
            m = diff[i];
            ind = i;
        }
    }
    cout << ind;
    return 0;
}