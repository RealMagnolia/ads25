#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n; cin >> n;
    string name;
    deque <string> names;
    while(n--){
        cin >> name;
        if(!names.empty() && name == names.back()) continue;
        names.push_back(name);
    }
    cout << "All in all: " << names.size() << endl;
    cout << "Students:" << endl;
    while(!names.empty()){
        cout << names.back() << endl; names.pop_back();
    }
    return 0;
}