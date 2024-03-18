#include <iostream>
using namespace std;
struct Dynamic{
  int *data;
  int size;
  int capacity;

  Dynamic(): data(nullptr) , size(0)  , capacity(0) {}
  ~Dynamic() {delete[] data;}
  void resize(int Newcapacity){
    int *new_data =new int[Newcapacity];
    for(int i=0;i<size;i++){
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = Newcapacity;
  }
  void insert_back(int value){
    if(size == capacity){
      resize(capacity*2);
    }
    data[size] = value;
  }
  void insert(int value, int ind){
    if(size == capacity){
      resize(capacity*2);
    }
    for(int i=size;i>ind;i--){
      data[i] = data[i-1];
    }data[ind] = value;
  }
};
int main() {
  Dynamic d;
  d.resize(10);
  cout << d.capacity << endl;
  d.resize(20);
  cout << d.capacity << endl;
}