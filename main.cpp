#include "MyVector.h"
#include <iostream>
using namespace std;

int main() 
{
    MyVector<int> v = MyVector<int>(8);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.printVector();
    v.pop_back();
    v.printVector();
    v.pop_back(2);
    v.printVector();
    cout << "The 2nd element is " << v[1] << endl;
    v.clear();
    cout << "Vector is empty -> " << boolalpha << v.empty() << endl;
}