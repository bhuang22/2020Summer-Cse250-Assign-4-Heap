
#ifndef HEAP_H_
#define HEAP_H_
#include <iostream>
using namespace std;


namespace ubcse {

    template<typename dtype>
    class heap {

    public:
        /** TO DO:: default constructor
            perform new to reserve memory of size INITIAL_CAPACITY.
            set num_items = 0;
         */
        heap() {
            darray = new dtype[INITIAL_CAPACITY];
            sorted_array = new dtype[INITIAL_CAPACITY];
            num_items = 0;
            // write your code here
        };

        /** Create a heap from a given array */
        heap(dtype *other, size_t len) {
            // write your code here
            num_items = 0;
            darray = new dtype[INITIAL_CAPACITY];
            sorted_array = new dtype[INITIAL_CAPACITY];
            for (int i = 0; i < len; i++) {
                darray[i] = other[i];
                num_items++;
                heapify(i);

            }

        }        /** copy constructor
            copy another heap to this heap.
         */
        heap(const heap<dtype> &other) : num_items(other.num_items) {
            for (size_t i = 0; i < num_items; i++) {
                darray[i] = other.darray[i];
            }
            //write your code here
        };


        /** Accessor functions */

        /** returns the root of the heap */
        dtype &root();

        /** returns the left child of the given node. */
        size_t left(size_t index);


        /** returns the right child of the given node. */
        size_t right(size_t index);

        /** returns the parent of the given node. */
        size_t parent(size_t index);

        /** returns num_items of the array */
        size_t size();

        /** Core heap operations */

        /** perform heapify operation over the array. */
        void heapify(size_t index);

     //   void heapify1(size_t index);

        /** create a heap from the given input. */
        void build_heap();

        /** heap sort
          create a copy darray to sorted_array.
          then perform heapsort over sorted_array.
          */
        void heapsort();


        /* insert items into heap */
        void insert(const dtype &key);

        /* remove items from the heap*/
        void remove();

        /** print heap **/
        void print(std::string name);


    private:
        static const size_t INITIAL_CAPACITY;
        size_t num_items;   // size in heap
        dtype *darray; // pointer to the array in heap
        dtype *sorted_array;


    }; //end of class heap


    template<typename dtype>
    const size_t heap<dtype>::INITIAL_CAPACITY = 100;

/* TO DO : implement all the member functions here.
*/
    template<typename dtype>
    dtype &heap<dtype>::root() {
        return darray[0];
    }

    template<typename dtype>
    size_t heap<dtype>::left(size_t index) {
        size_t left = (2 * index) + 1;
        return left;
    }

    template<typename dtype>
    size_t heap<dtype>::right(size_t index) {
        size_t right = (2 * index) + 2;
        return right;
    }

    template<typename dtype>
    size_t heap<dtype>::parent(size_t index) {
        size_t parent = (index - 1) / 2;
        return parent;
    }

    template<typename dtype>
    size_t heap<dtype>::size() {
        return num_items;
    }

    template<typename dtype>
    void heap<dtype>::heapify(size_t index) {
        size_t parent = (index - 1) / 2;
        size_t largest = index;
        size_t left = (2 * index) + 1;
        size_t right = (2 * index) + 2;
        if (darray[parent] > 0) {
            if (darray[index] > darray[parent]) {
                swap(darray[index], darray[parent]);
                heapify(parent);
            }
        }

        if (left < num_items && darray[left] > darray[index]) largest = left;
        else
            largest = index;

        if (right < num_items && darray[right] > darray[index]) largest = right;

        if (largest != index) {
            swap(darray[index], darray[largest]);
            heapify(largest);
        }

    }

    /*
    template <typename dtype>
    void heap<dtype>::heapify1(size_t index){
        size_t largest=index;
        size_t left = (2*index)+1;
        size_t right =  (2*index)+2;

        if(left<num_items&&darray[left]>darray[index]) largest=left;
        else {
            largest = index;
        }

        if(right<num_items&&darray[right]>darray[index]) largest=right;

        if(largest!=index){
            swap(darray[index],darray[largest]);
            heapify(largest);
        }
    }
*/

    template<typename dtype>
    void heap<dtype>::build_heap() {
        for (int i = (num_items) / 2 +2; i >= 0; i--)
            heapify(i);
    }

    template<typename dtype>
    void heap<dtype>::heapsort() {
        for (size_t j = 0; j < num_items - 1; j++) {
            for (size_t k = j; k < num_items - 1; k++) {
                if(darray[j]>darray[k+1]) {
                    swap(darray[j],darray[k+1]);
            }
        }

        for (size_t i = 0; i < num_items; i++) {
            sorted_array[i] = darray[i];
        }
    }
}
    template <typename dtype>
    void  heap<dtype>::insert(const dtype& key){
        num_items+=1;
        darray[num_items-1]=key;
        if(num_items>1) heapify(num_items-1);
    }

    template <typename dtype>
    void heap<dtype>::remove(){
        size_t last = darray[num_items-1];
       darray[0]= last;
       num_items-=1;
       heapify(0);
    }

    template <typename dtype>
    void heap<dtype>:: print(std::string name) {
        cout<<name<<endl;
        for(int i=0;i< num_items;i++){
            cout<<darray[i];
            if(i==num_items-1) break;
            cout<<"," ;
        }
        cout<<endl;
    }

} //end of namespace


#endif