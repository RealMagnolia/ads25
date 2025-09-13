#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n; cin >> n;
    queue <char> q;
    for(int i = 0 ; i < n ; i++){
        char c;
        cin >> c;
        q.push(c);
    }

    int ultK = 0, ultS = 0;
    while(q.size() > 1 && ultK + ultS < n){
        char c = q.front();
        q.pop();
        if(c == 'K'){
            if(ultS > 0) ultS--;
            else {
                ultK++;
                q.push('K');
            }
        }
        else {
            if(ultK > 0) ultK--;
            else {
                ultS++;
                q.push('S');
            }
        }
    }
    if(q.front() == 'K') cout << "KATSURAGI";
    else cout << "SAKAYANAGI";

    return 0;
}