
#include "Header.h"
#include <iostream>
#include <iomanip>

using namespace std;

void MyVector::vector_new(size_t sz)
{
    size = 0;
    capacity = 1;
    arr = new int[capacity];
}
void MyVector::vector_delete()
{
    delete[] arr;
}
void MyVector::vector_push_back(int n)
{
    if (size == capacity)
    {
        capacity += 1;
        int* arr1 = new int[capacity];
        for (int i = 0; i < capacity; i++)
            arr1[i] = arr[i];
        delete[] arr;
        arr = arr1;
    }
    arr[size] = n;
    size++;
}
void MyVector::vector_pop_back()
{
    size -= 1;
}
int& MyVector::vector_front()
{
    return arr[0];
}
int& MyVector::vector_back()
{
    return arr[size - 1];
}
size_t MyVector::vector_size()
{
    return size;
}


void MyVector::print_vector()
{
    for (size_t i = 0; i < vector_size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}