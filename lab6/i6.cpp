#include <iostream>
#include <string>
#include <vector> 
using namespace std;

string a;
void quick(int l, int r){
    int p = a[(l+r)/2];
    int i = l, j = r;

    while(i < j){
        while(a[i] < p) i++;
        while(a[j] > p) j--;

        if(i <= j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if(l < j) quick(l, j);
    if(i < r) quick(i, r);
}

int main(){
    cin >> a;
    int n = a.size();
    quick(0, n-1);
    for(char c : a){
        cout << c;
    }
    return 0;
}