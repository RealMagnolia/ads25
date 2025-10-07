#include <iostream>
#include <vector>
using namespace std;

class maxHeap{
    public:
    vector <int> a;

    int parent(int i) {return (i-1)/2;}
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    int getMax() {return a[0];}

    void insert(int k){
        a.push_back(k);
        int ind = a.size()-1;

        while(ind > 0 && a[ind] > a[parent(ind)]){
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i){
        if(left(i) > a.size()-1) return;
        int j = left(i);

        if(right(i) < a.size() && a[right(i)] > a[left(i)]) j = right(i);
        if(a[i] < a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMax(){
        int root = getMax();
        swap(a[0], a[a.size()-1]);
        a.pop_back();
        if(a.size() > 0) heapify(0);
        return root;
    }

    int smash(int root){
        while(a.size() > 1){
            int max1 = extractMax(), max2 = extractMax();
            int diff = max1-max2;
            insert(diff);
        }
        return a[0];
    }
};

int main(){
    maxHeap *heap = new maxHeap;
    int n; cin >> n;

    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        heap->insert(a);
    }
    int root = 0;
    cout << heap->smash(root);
    return 0;
}
