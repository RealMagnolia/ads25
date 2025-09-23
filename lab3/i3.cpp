#include <iostream>
#include <vector>
using namespace std;

bool find(int a, vector <int> v){
    for(int i = 0 ; i < v.size() ; i++){
        int l = 0 , r = v.size() - 1;
        while(l <= r){
            int h = (l+r)/2;
            if(v[h] == a) return true;
            else if(v[h] < a) l = h+1;
            else r = r-1; 
        }
    }
    return false;
}

int main(){
    int n, x; cin >> n;
    vector <int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }

    cin >> x;
    if(find(x, v)) cout << "Yes";
    else cout << "No";
    return 0;
}