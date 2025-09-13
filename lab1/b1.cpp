#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int main(){
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        v.push_back(t);
    }
    for(int i = 0; i < v.size(); i++){
        bool found = false;
        for(int j = i - 1; j >= 0; j--){
            if(v[i] >= v[j]) {
                cout << v[j] << ' ';
                found = true;
                break;
            }
        }
        if(!found) cout << -1 << ' ';
    }
}