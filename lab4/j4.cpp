#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void shuffle(int l, int r, vector <int>&arr){
    if(l > r) return;
    int h = (l+r)/2;
    cout << arr[h] << " ";

    shuffle(l, h-1, arr);
    shuffle(h+1, r, arr);
}

int main(){
    int n; cin >> n;
    int size = pow(2, n);
    vector <int> arr(size-1);

    for(int i = 0 ; i < size-1 ; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    shuffle(0, size-2, arr);
    return 0;
}
