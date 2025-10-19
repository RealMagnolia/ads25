#include <iostream>
#include <vector>
using namespace std;

bool check(string s1, string s2){
    return s1.size() <= s2.size();
}

void merge(vector <string> &a, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    vector <string> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    int i = 0 , j = 0, k = l;
    while(i < n1 && j < n2){
        if(check(L[i], R[j])){
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

void mergeS(vector <string> &a, int l, int r){
    if(l < r){
        int m = l + (r-l)/2;
        mergeS(a, l, m);
        mergeS(a, m+1, r);
        merge(a, l, m, r);
    }
}
int main(){
    int n; cin >> n;
    vector <vector <string>> a(n);
    for(int i = 0 ; i < n ; i++){
        while(true){
            string x; cin >> x;
            a[i].push_back(x);
            if(cin.peek() == '\n') break;
        }
    }

    for(int i = 0 ; i < n ; i++){
        mergeS(a[i], 0, a[i].size()-1);
        for(int j = 0 ; j < a[i].size() ; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
