#include <iostream>
#include <stack>
#include <string>
using namespace std;

void check(string s){
    stack <char> st;
    for(int i = 0 ; i < s.size() ; i++){
        if(st.empty()) st.push(s[i]);
        else{
            if(s[i] == st.top()) st.pop();
            else st.push(s[i]);
        }
    }

    if(st.empty()) cout << "YES";
    else cout << "NO";
}
int main(){
    string s;
    cin >> s;

    check(s);
    return 0;
}