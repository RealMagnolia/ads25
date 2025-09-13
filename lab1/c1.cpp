#include <bits/stdc++.h>
using namespace std;

void check(string a, string b){
    stack <char> s1;
    stack <char> t1;

    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] >= 'a' && a[i] <= 'z'){
            s1.push(a[i]);
        }
        else s1.pop();
    }

    for(int i = 0 ; i < b.size() ; i++){
        if(b[i] >= 'a' && b[i] <= 'z'){
            t1.push(b[i]);
        }
        else t1.pop();
    }

    if(s1 == t1) cout << "Yes";
    else cout << "No";

}

int main(){
    string s, t;
    cin >> s >> t;

    check(s, t);
    return 0;
}