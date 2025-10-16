#include <iostream>
#include <vector>
using namespace std;

int binaryS(vector <int> &a, int t){
    int l = 0, r = a.size()-1;
    while(l <= r){
        int h = l + (r-l)/2;
        if(a[h] == t) return h;
        if(a[h] > t) r = h-1;
        else l = h+1;
    }
    return -1;
}

void quick(vector <int> &a, int l, int r){
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

    if(l < j) quick(a, l, j);
    if(i < r) quick(a, i, r);
}

int main(){
    int n, m;
    cin >> n >> m;
    if(n == 0 || m == 0) return 0;
    
    vector <int> a1, a2;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        a1.push_back(x);
    }

    for(int i = 0 ; i < m ; i++){
        int x; cin >> x;
        a2.push_back(x);
    } 
    quick(a1, 0, n-1);
    quick(a2, 0, m-1);
    
    if(a1.size() > a2.size()){
        for(int i = 0 ; i < a2.size() ; i++){
            int f = binaryS(a1, a2[i]);
            if(f != -1){
                cout << a2[i] << " ";
                a1.erase(a1.begin()+f);
            }
        }
    } else{
        for(int i = 0 ; i < a1.size() ; i++){
            int f = binaryS(a2, a1[i]);
            if(f != -1){
                cout << a1[i] << " ";
                a2.erase(a2.begin()+f);
            }
        }
    }
    return 0;
}