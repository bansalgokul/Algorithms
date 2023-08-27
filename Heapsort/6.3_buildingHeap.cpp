#include<iostream>
using namespace std;

class Heap {
    public: 
    int heapSize;
    int* arr;

    Heap(int heapSize, int * arr) {
        this->heapSize = heapSize;
        this->arr = arr; 
    }

    void maxHeapify (int index);
    void buildHeap ();
};

int parent(int index) {
    return (index-1)/2;
}
int leftChild (int index) {
    return (2 * index) + 1;
}
int rightChild (int index) {
    return (2 * index) + 2;
}

void Heap :: maxHeapify(int index){
    int l = leftChild(index);
    int r = rightChild(index);

    int largest = index;

    if(l < this->heapSize && this->arr[l] > this->arr[largest]){
        largest = l;
    }
    if(r < this->heapSize && this->arr[r] > this->arr[largest]){
        largest = r;
    }

    if(largest != index) {
        int temp = this->arr[largest];
        this->arr[largest] = this->arr[index];
        this->arr[index] = temp;

        this->maxHeapify(largest);
    }

    return;
}

void Heap :: buildHeap () {
    for(int i = (this->heapSize-1)/2; i >= 0; i--){
        this->maxHeapify(i);
    }
}


int main() {
    int * arr = new int[5];

    for(int i = 0; i < 5; i++){ 
        cin >> arr[i];
    }

    Heap* newHeap = new Heap(5, arr);
    newHeap->buildHeap();

    for(int i = 0; i < 5; i++){ 
        cout << arr[i] << " ";
    }

    cout << endl;
}