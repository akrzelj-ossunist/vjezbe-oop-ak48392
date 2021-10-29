
#include "Header.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    MyVector mv;
    mv.vector_new();

    int m;
    cout << "Unesi element,Ctrl+z (win) za kraj unosa" << endl;
    while (cin >> m)
        mv.vector_push_back(m);

    cout << "first element " << mv.vector_front() << endl;
    cout << "last element " << mv.vector_back() << endl;
    mv.print_vector();

    cout << "removing last element" << endl;
    mv.vector_pop_back();
    mv.print_vector();

    cout << "size " << mv.vector_size() << endl;
    cout << "capacity " << mv.capacity << endl;

    mv.vector_delete();
}
