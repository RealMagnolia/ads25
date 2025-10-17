#include <iostream>
using namespace std;

void quick(int l, int r, int* a){
    int p = a[(l+r)/2];
    int i = l, j = r;

    while(i < j){
        while(a[i] > p) i++;
        while(a[j] < p) j--;

        if(i <= j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if(l < j) quick(l, j, a);
    if(i < r) quick(i, r, a);
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m], a1[m][n];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j]; 
        }
    }

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            a1[i][j] = a[j][i];
        }
    }

    for(int i = 0 ; i < m ; i++){
        quick(0, n-1, a1[i]);
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << a1[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}