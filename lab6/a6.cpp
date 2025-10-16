#include <iostream>
#include <string>
#include <vector>
using namespace std;

char a[100005];
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
    if(r > i) quick(i, r);
}

int main(){
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    quick(0, n-1);

    vector <char> v, c;
    for(int i = 0 ; i < n ; i++){
        string s = "aeiou";
        if(s.find(a[i]) != string::npos) v.push_back(a[i]);  
        else c.push_back(a[i]);
    }

    for(int i = 0 ; i < v.size() ; i++) cout << v[i];
    for(int i = 0 ; i < c.size() ; i++) cout << c[i];
    return 0;

}