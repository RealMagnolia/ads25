#include <iostream>
#include <vector>
using namespace std;

int bins(vector <int> &a, int t){
    int l = 0, r = a.size()-1;
    
    while (l <= r){
        int h = l + (r-l)/2;
        if(a[h] == t) return h;
        if(a[h] > t) r = h-1;
        else l = h+1;
    }
    return -1;
}

void merge(vector <int> &a, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector <int> L(n1), R(n2);
    for(int i = 0 ; i < n1 ; i++) L[i] = a[l+i];
    for(int j = 0 ; j < n2 ; j++) R[j] = a[m+1+j];

    int i = 0 , j = 0 , k = l;
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
    while (j < n2){
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
    int n, m;
    cin >> n >> m;
    if(n == 0 || m == 0) return 0;

    vector <int> v1, v2;
    for(int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        v1.push_back(x);
    }
    
    for(int i = 0 ; i < m ; i++) {
        int x; cin >> x;
        v2.push_back(x);
    }
    mergeS(v1, 0, n-1);
    mergeS(v2, 0, m-1);

    if(v1.size() > v2.size()){
        for(int i = 0 ; i < v2.size() ; i++){
            int f = bins(v1, v2[i]);
            if(f != -1){
                cout << v2[i] << " ";
                v1.erase(v1.begin()+f); 
            }
        }
    } else{
        for(int i = 0 ; i < v1.size() ; i++){
            int f = bins(v2, v1[i]);
            if(f != -1){
                cout << v1[i] << " ";
                v2.erase(v2.begin()+f); 
            }
        }
    }
    return 0;
}