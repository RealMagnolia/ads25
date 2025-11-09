#include <iostream>
#include <vector>
using namespace std;

vector <int> pref(string &s){
    int n = s.size();
    vector <int> p(n);
    p[0] = 0;

    for(int i = 1 ; i < n ; i++){
        int j = p[i-1];

        while(j > 0 && s[i] != s[j]){
            j = p[j-1];
        }

        if(s[i] == s[j]) j++;
        p[i] = j;
    }

    return p;
}

bool KMP (string &t, string &p){
    string s = p + "#" + t;

    int n = s.size(), m = p.size();

    vector <int> pi = pref(s);
    
    for(int i = 0 ; i < n ; i++){
        if(pi[i] == m){
            int pos = i - 2 * m;
            return true;
        }
    }

    return false;
}

int main(){
    string s1, s2, temp;
    cin >> s1 >> s2;

    temp += s1;
    int count = 0;

    while(s1.size() < s2.size()){
        s1 += temp;
        count++;
    } bool flag = KMP(s1, s2);

    for(int i = 0 ; i < 2 ; i++){
        if(flag){
            cout << count + 1;
            break;
        }
        count++;
        s1 += temp;
        flag = KMP(s1,s2);
    }
    
    if(flag == false) cout << -1;
    return 0;
}