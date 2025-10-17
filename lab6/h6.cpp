#include <iostream>
#include <vector>
using namespace std;

char binS(vector <char> a, char c){
    int l = 0, r = a.size()-1;
    char ans = 'A';
    while(l <= r){
        int h = l + (r-l)/2;
        if(c < a[h]){
            r = h-1;
            ans = a[h];
        } else l = h+1;
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector <char> a;

    for(int i = 0 ; i < n ; i++){
        char c; cin >> c;
        a.push_back(c);
    }
    char c; cin >> c;
    char ans = binS(a, c);

    if(ans == 'A') cout << a[0];
    else cout << ans;
    return 0;
}