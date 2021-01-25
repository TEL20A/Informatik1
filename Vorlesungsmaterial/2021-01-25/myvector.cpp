#include <iostream>
#include <vector>
using namespace std;

struct MyVector {
  int currentSize;
  int maxSize;
  char * data;

  MyVector()
  {
    currentSize = 0;
    maxSize = 4;
    data = new char[maxSize];
  }

  void push_back(char neuer_wert)
  {
    data[currentSize] = neuer_wert;
    currentSize++;
  }

};

int main() {

  vector<int> v1;
  v1.push_back(42);
  v1.push_back(23);
  v1.push_back(38);

  for (int el : v1)
  {
    cout << el << endl;
  }

  MyVector v2;
  cout << v2.currentSize << endl;
  cout << v2.maxSize << endl;
  cout << v2.data << endl;
  v2.push_back('a');
  v2.push_back('b');
  v2.push_back('b');

  for (int i = 0; i<v2.currentSize; i++)
  {
    cout << v2.data[i] << endl;
  }
  return 0;
}















