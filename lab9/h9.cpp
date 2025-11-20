#include <iostream>
#include <vector>
using namespace std;

vector <int> pref(string &s){
    int n = s.size();
    vector <int> p(n, 0);
    int len = 0;

    for(int i = 1 ; i < n ;){
        if(s[i] == s[len]){
            len++;
            p[i] = len;
            i++;
        } else {
            if(len != 0) len = p[len - 1];
            else {
                p[i] = 0;
                i++;
            }
        }
    }
    return p;
}

vector <int> KMP(string &s, string &p){
    vector <int> pre = pref(p);
    vector <int> res;

    int i = 0, j = 0, n = s.size(), m = p.size();

    while(i < n){
        if(s[i] == p[i]){
            i++; j++;
        }

        if(j == m){
            res.push_back(i - m);
            j = pre[j - 1];
        } else if(i < n && s[i] != p[j]){
            if(j != 0) j = pre[j - 1];
            else i++;
        }
    }
    return res;
}

int main(){
    string s; cin >> s;
    int n = s.size(), ans = 0;
    vector <int> p = pref(s);

    if(n < 3){
        cout << 0;
        return 0;
    }

    for(int i = 1 ; i * 2 < n ; i++){
        int k = 2 * i - 1;
        int l = 2 * i;

        int pi = p[k], t = l - pi;

        if(i % t == 0) ans++;
    }

    cout << ans;
    return 0;
}