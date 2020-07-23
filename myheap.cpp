#include <iostream>
#include "heap.h"

int main(){
    ubcse::heap<int> h1;
    h1.print("h1");
    h1.insert(8);
    h1.print("h1");
    h1.insert(16);
    h1.print("h1");
    h1.insert(5);
    h1.print("h1");
    h1.insert(25);
    h1.print("h1");
    h1.remove();
    h1.print("h1");

    int a[4] = {2,4,6,7};
    ubcse::heap<int> h2(a, 4);
    h2.print("h2");
    h2.heapsort();
    h2.print("h2");
} //end of main
