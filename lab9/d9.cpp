#include <iostream>
#include <cctype>
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

int comb(string &s, string &p){
    string c = p + "#" + s;
    vector <int> pi = pref(c);

    int m = pi[pi.size() - 1];
    return m;
}

int main(){
    string s; cin >> s;
    s[0] = tolower(s[0]);
    int n; cin >> n;

    vector <string> p(n);
    vector <int> mt(n);
    int mx = 0;


    for(int i = 0 ; i < n ; i++){
        cin >> p[i];
        p[i][0] = tolower(p[i][0]);

        mt[i] = comb(s, p[i]);
        mx = max(mx, mt[i]);
    }

    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(mt[i] == mx && mx != 0) cnt++;
    } cout << cnt << endl;

    for(int i = 0 ; i < n ; i++){
        if(mt[i] == mx && mx != 0) {
            p[i][0] = toupper(p[i][0]);
            cout << p[i] << endl;
        }
    }
    return 0;
}