#include <iostream>
#include <vector>
using namespace std;

bool comp(vector <int> &a, vector <int> &b){
    long long sum1 = 0 , sum2 = 0;
    for(int i = 0 ; i < a.size() ; i++) sum1 += a[i];
    for(int i = 0 ; i < b.size() ; i++) sum2 += b[i];

    if(sum1 != sum2) return sum1 > sum2;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] != b[i]) return a[i] < b[i];
    }

    return false;
}

void merge(vector <vector<int>> &a, int l, int m, int r){
    vector <vector <int>> temp;
    int i = l, j = m+1;
    
    while(i <= m && j <= r){
        if(comp(a[i], a[j])){
            temp.push_back(a[i]);
            i++;
        } else{
            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for(int i = l ; i <= r ; i++){
        a[i] = temp[i-l];
    }
}

void mergeS(vector <vector<int>>&a, int l, int r){
    if(l >= r) return;
    int m = l + (r-l)/2;

    mergeS(a, l, m);
    mergeS(a, m+1, r);
    merge(a, l, m, r);
}

int main(){
    int n, m;
    cin >> n >> m;

    vector <vector <int>> a(n, vector <int> (m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }

    mergeS(a, 0, n-1);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}