#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque <int> a;
    char s;
    while(true){
        cin >> s;

        if(s == '+'){
            int n; cin >> n;
            a.push_front(n);
        }
        else if(s == '-'){
            int n; cin >> n;
            a.push_back(n);
        }

        else if(s == '*'){
            if(a.size() == 0) cout << "error\n";
            else{
                cout << a.front() + a.back() << endl;
                if(a.size() >= 2) {
                    a.pop_front(); a.pop_back();
                }
                else a.pop_front();
            }
        }
        else break;
    }

    return 0;
}