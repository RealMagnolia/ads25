#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long sum = 0;
class minHeap{
    public:
    vector <int> a;

    int parent(int i) {return (i-1)/2;}
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    int getMin() {return a[0];}

    void insert(int k){
        a.push_back(k);
        int ind = a.size()-1;

        while(ind > 0 && a[ind] < a[parent(ind)]){
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i){
        if(left(i) > a.size()-1) return;
        int j = left(i);

        if(right(i) < a.size() && a[right(i)] < a[left(i)]) j = right(i);
        if(a[i] > a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMin(){
        int root = getMin();
        swap(a[0], a[a.size()-1]);
        a.pop_back();
        if(a.size() > 0) heapify(0);
        return root;
    }

};

int main(){
    minHeap *heap = new minHeap;
    int n, x; 
    cin >> n >> x;

    while(n--){
        string q; cin >> q;
        if(q == "print"){
            cout << sum << endl;
        } else {
            int a; cin >> a;
            if(heap->a.size() < x){
                heap->insert(a);
                sum += a;
            } else{
                if(heap->getMin() < a){
                    int del = heap->extractMin();
                    sum -= del;
                    sum += a;
                    heap->insert(a);
                }
            }
        }
    }
    return 0;
}
