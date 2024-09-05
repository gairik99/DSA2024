#include <bits/stdc++.h>
using namespace std;

/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};*/

// Function to extract minimum value in heap and then to store
// next minimum value at first index.
int MinHeap::extractMin()
{
    // Your code here
    if (heap_size <= 0)
        return -1;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    // storing value of leaf node at first index.
    harr[0] = harr[heap_size - 1];
    harr[heap_size - 1] = 0;
    heap_size--;

    // calling heapify function for the first index.
    MinHeapify(0);

    return root;
}

// Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    // Your code here
    if (i < heap_size)
    {
        // decreasing value at ith index to minimum integer value.
        decreaseKey(i, INT_MIN);
        // extracting the minimum value from heap.
        extractMin();
    }
}

// Function to insert a value in Heap.
void MinHeap::insertKey(int k)
{
    // Your code here
    heap_size++;
    int i = heap_size - 1;
    // inserting the value at leaf node.
    harr[i] = k;

    while (i != 0 && harr[parent(i)] > harr[i])
    {
        // swapping values of ith index with its parent node
        // if value at parent node is greater.
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}