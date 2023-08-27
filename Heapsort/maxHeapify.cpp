#include<iostream>
using namespace std;

class Heap {
    int heapSize;
    int* arr;

    Heap(int heapSize) {
        this->heapSize = heapSize;
        this->arr = new int[heapSize]; 
    }

    void maxHeapify (int index);
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

int main() {

}