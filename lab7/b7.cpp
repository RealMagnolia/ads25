#include <iostream>
#include <vector>
using namespace std;

void merge(vector <int> &a, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector <int> L(n1), R(n2);
    for(int i = 0 ; i < n1 ; i++) L[i] = a[l+i];
    for(int j = 0 ; j < n2 ; j++) R[j] = a[m+1+j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        } else{
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        a[k] = L[i];
        i++; k++;
    }
    while(j < n2){
        a[k] = R[j];
        j++; k++;
    }
}

void mergeS(vector <int> &a, int l, int r){
    if(l < r){
        int m = l + (r-l)/2;
        
        mergeS(a, l, m);
        mergeS(a, m+1, r);

        merge(a, l, m, r);
    }
}

int main(){
    vector <int> inter;

    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        inter.push_back(x);
    }

    int m; cin >> m;
    for(int i = 0 ; i < m ; i++){
        int x; cin >> x;
        inter.push_back(x);
    }
    mergeS(inter, 0, inter.size()-1);
    
    for(int i = 0 ; i < inter.size() ; i++){
        cout << inter[i] << " ";
    }

    return 0;
}