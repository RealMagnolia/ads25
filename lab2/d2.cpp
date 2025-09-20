#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    map <int, int> mode;
    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        mode[a]++;
    }
    
    int m = 0;
    map <int, int>::iterator it;
    for(it = mode.begin() ; it != mode.end() ; it++){
        if(it->second > m) m = it->second;
    }

    vector <int> md;
    for(it = mode.begin() ; it != mode.end() ; it++){
        if(it->second == m) md.push_back(it->first);
    }
    sort(md.begin(), md.end());
    reverse(md.begin(), md.end());

    for(int i = 0 ; i < md.size() ; i++){
        cout << md[i] << " ";
    }
    return 0;
}