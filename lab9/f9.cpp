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

int KMP_count(string &t, string &p){
    string s = p + "#" + t;
    int n = s.size() , m = p.size();

    int count = 0;
    vector <int> pi = pref(s);
    for(int i = 0 ; i < n ; i++){
        if(pi[i] == m){
            count++;
        }
    }
    return count;
}

void KMP(string &t, string &p){
    string s = p + "#" + t;
    int n = s.size() , m = p.size();

    vector <int> pi = pref(s);
    for(int i = 0 ; i < n ; i++){
        if(pi[i] == m){
            int pos = i - m * 2;
            cout << pos + 1 << " ";
        }
    }
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    cout << KMP_count(s1, s2) << endl;
    KMP(s1, s2);
    return 0;
}