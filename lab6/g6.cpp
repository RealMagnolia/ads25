#include <iostream>
#include <map>
using namespace std;

int main(){
    int n; cin >> n;
    map <string, string> nick;

    for(int i = 0 ; i < n ; i++){
        string f, l;
        cin >> f >> l;

        if(nick.size() == 0) nick[f] = l;
        else{
            bool flag = false;
            map <string, string>::iterator it;
            for(it = nick.begin() ; it != nick.end() ; it++){
                if(it->second == f){
                    flag = true;
                    nick[it->first] = l;
                }
            }
            if(flag == false) nick[f] = l;
        }
    }

    map <string, string>::iterator it;
    cout << nick.size() << endl;
    for(it = nick.begin() ; it != nick.end() ; it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}