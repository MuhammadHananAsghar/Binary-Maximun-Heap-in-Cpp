// CREATED BY MUHAMMAD HANAN ASGHAR
// PYTHONIST
#include <iostream>
using namespace std;
class BinaryMaximumHeap{
  private:
  int *heap;
  int heapSize;
  int arraySize;
  int getParent(int index){
    return (index - 1) / 2;
  }
  int getRight(int index){
    return (2 * index) + 2;
  }
  int getLeft(int index){
    return (2 * index) + 1;
  }
  void swap(int i,int j){
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
  }
  bool hasLeft(int index){
    return getLeft(index) < heapSize;
  }
  bool hasRight(int index){
    return getRight(index) < heapSize;
  }
  public:
  BinaryMaximumHeap(int size){
    heap = new int[size];
    arraySize  = size;
    heapSize = 0;
  }
  void heapifyUp(int index){
    if(index!=0){
      int parent = getParent(index);
      if(heap[parent] < heap[index]){
        swap(parent,index);
        heapifyUp(parent);
      }
    }
 }
  
  void Insert(int data){
    if(heapSize == arraySize){
      cout<<"Data Structure Overflow"<<endl;
      return;
    }else{
      heapSize++;
      heap[heapSize - 1] = data;
      cout<<endl<<"Data Added - "<<data<<endl;
      heapifyUp(heapSize - 1);
    }
  }
  void Display(){
    for(int i = 0;i<heapSize;i++){
      cout<<heap[i]<<" - ";
    }
  }
  void heapifyDown(int index){
    int leftSide = getLeft(index);
    int rightSide = getRight(index);
    int min = index;
    if(heap[leftSide] > heap[min] && hasLeft(index)){
      min = leftSide;
    }
    if(heap[rightSide] > heap[min] && hasRight(index)){
      min = rightSide;
    }
    if(min != index){
      swap(index,min);
      heapifyDown(min);
    }
  }
  int Remove(){
    if(heapSize == 0){
      return -1;
    }else{
      int root = heap[0];
      heap[0] = heap[heapSize - 1];
      heapSize--;
      if(heapSize > 1){
        heapifyDown(0);
      }
      return root;
    }
  }
};

int main() {
  BinaryMaximumHeap heap(10);
  heap.Insert(23);
  heap.Insert(25);
  heap.Insert(235);
  heap.Insert(80);
  heap.Display();
  cout<<endl;
  heap.Remove();
  heap.Display();
}
