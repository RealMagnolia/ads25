#include <bits/stdc++.h>
using namespace std;

int main(){
    queue <int> b;
    queue <int> n;

    int moves = 1, limit = 1e6;
    for(int i = 0 ; i < 5 ; i++){
        int a;
        cin >> a;

        b.push(a);
    }

    for(int i = 0 ; i < 5 ; i++){
        int c;
        cin >> c;

        n.push(c);
    }

    while(moves <= limit){
        int boris = b.front();
        int nursik = n.front();
        b.pop(); 
        n.pop();
        if((boris == 0 && nursik == 9) || (boris == 9 && nursik == 0)){
            if(boris == 0){
                b.push(boris);
                b.push(nursik);
            }
            else if(nursik == 0){   
                n.push(boris);
                n.push(nursik);
            }
        }

        else if (boris > nursik){
            b.push(boris);
            b.push(nursik);
        }
        else if(nursik > boris){
            n.push(boris);
            n.push(nursik);
        }

        if(b.empty()){
            cout << "Nursik " << moves;
            break;
        }
        if(n.empty()) {
            cout << "Boris " << moves;
            break;
        }
        moves++;
    }
    if(moves > limit) cout << "blin nichya";
}
