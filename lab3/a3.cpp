#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t; cin >> t;
    vector <int> el;

    for(int i = 0 ; i < t ; i++){
        int a; cin >> a;
        el.push_back(a);
    }

    int n, m;
    cin >> n >> m;
    vector<vector <int>> sn(n, vector <int> (m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> sn[i][j];
        }
    }

    for(int j = 0 ; j < el.size() ; j++){
        int tar = el[j];
        bool find = false;

        for(int j = 0 ; j < n && !find ; j++){
            int l = 0 , r = m - 1;

            if(j%2 == 0){
                while(l <= r){
                    int h = l + (r - l)/2;
                    if(sn[j][h] == tar){
                        cout << j << " " << h << endl;
                        find = true;
                        break;
                    } else if(sn[j][h] < tar) r = h - 1;
                    else l = h + 1;
                }
            }

            else{
                while(l <= r){
                    int h = l + (r - l)/2;
                    if(sn[j][h] == tar){
                        cout << j << " " << h << endl;
                        find = true;
                        break;
                    } else if(sn[j][h] < tar) l = h + 1;
                    else r = h - 1;
                }
            }
        } 
        if(find == false) cout << "-1\n";
    }
    return 0;
}