/* Heap Asignment

Insert 10 values into a min-heap from a file. Display the data, level by level. Then delete 5 items. After each delete, display the heap, level by level.
*/

#include <iostream>
#include <climits>
#include <fstream>
#include <vector>

using namespace std;

//Function to swap two integers
void swap(int *x, int *y);

//Min-Heap class
class MinHeap
{

public:
    int *heapArr;                           //Pointer to an array that will hold our heap
    int capacity;                           //Max size of the heap
    int heapSize;                           //Current size of the heap

    MinHeap(int capacity);                  //Default constructor for a min-heap

    void MinHeapify(int );                  //Heapify the heap starting at provided node

    int parent(int i) { return (i-1)/2; }

    int left(int i) { return (2*i + 1); }   //Index of left child of node at index i

    int right(int i) { return (2*i + 2); }  //Index of right child of node at index i

    int extractMin();                       //Extract the root (minimum element)

    void decreaseKey(int i, int newVal);   //Decrease key value of key at index i to new_val

    int getMin() { return heapArr[0]; }     //Return the key at root (minimum key) from min heap

    void deleteKey(int i);                  //Delete a key stored at index i

    void insertKey(int k);                  //Insert a new key
};

/*
 ______                _   _
|  ____|              | | (_)
| |__ _   _ _ __   ___| |_ _  ___  _ __  ___
|  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| |  | |_| | | | | (__| |_| | (_) | | | \__ \
|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
*/
void displayExplanation()
{
 cout << "\n\nThe purpose of this program is to test my ability to implement a Min-Heap. \nI will populate the heap with ten items from a text file named input.txt, \nmaking sure the heap is a min-heap. I will display the date level by level.\nThen I will delete 5 items displaying the heap level by level as each item \nis deleted\n\n\n";
}

void yoliesProgramHeader()
{
 cout << "\n\n\t\t\t\t\t************* YOLIE REYES ***************\n";
 cout << "\t\t\t\t    ************ Heap Assignment ************\n";
 cout << "\t\t\t\t\t************* 12-06-2020 ****************\n";
 cout << "\t\t\t\t\t************** CISP 430 *****************\n";
}

void yoliesProgramFooter()
{
 cout << "\n\n\t\t\t*********** Intended for Educational Purposes Only! ***********\n\n";
 cout << "\t\t\t\t\t**************** End of Program ****************\n\n\n\n";
}

//Default Constructor, dynamically allocates a pointer to point to a location in memory (on the heap) the size of cap
MinHeap::MinHeap(int cap)
{
    heapSize = 0;           //Heap is going to be empty
    capacity = cap;         //Assign value passed as cap to capacity
    heapArr = new int[cap]; //Create a pointer to point to a location on the heap which can hold an array of integers cap long
}

//Inserts a new key, checks if min heap property is violated and swaps if need be,
void MinHeap::insertKey(int k)
{
    if (heapSize == capacity) { cout << "\nHeap Capacity reached cannot insert.\n"; return; } //Executed when heap is full!

    heapSize++;                //Increament the size of our heap by one
    int i = heapSize - 1;      //Set variable i to the last element in the heap
    heapArr[i] = k;            //Assign the value passed, to the last element on the heap

    while (i != 0 && heapArr[parent(i)] > heapArr[i])   //While the heap isn't empty, and the value at XXX is greater then the value we inserted
    {
        swap(&heapArr[i], &heapArr[parent(i)]);         //Call swap to switch values
        i = parent(i);                                  //Assign i to the pointer of the node that was greater, which triggered a swap
    }
}

/*
Decreases value of key at index i to newVal, assumming
newVal is smaller than harr[i].
*/
void MinHeap::decreaseKey(int i, int newVal)
{
    heapArr[i] = newVal;

    while (i != 0 && heapArr[parent(i)] > heapArr[i])
    {
        swap(&heapArr[i], &heapArr[parent(i)]);
        i = parent(i);
    }
}

/*
Removes minimum element from min heap, which is the root.
The root is always the lowest value in a min-heap
*/
int MinHeap::extractMin()
{
    //If the heap doesn't exist or is empty, return the max value of an integer
    if (heapSize <= 0) { return INT_MAX; }
    //If there is only one value in the heap decrement the size and return the only value.
    if (heapSize == 1) { heapSize--; return heapArr[0]; }

    // Store the minimum value, and remove it from heap
    int root = heapArr[0];             //Assign root to the value at element 0
    heapArr[0] = heapArr[heapSize-1];  //Assign the value of the last element to the first
    heapSize--;                        //Decrement the size of the heap
    MinHeapify(0);                     //Perform the heapify function on the first value in the array, which was the last

    return root;                       //Return the inital value at the beggining of the array.
}


/*
Deletes a key at index i, first reducing the value to minus
 infinite, then calls extractMin()
*/
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

/*
 A recursive method to heapify a subtree with the root at given index
This method assumes that the subtrees are already heapified
*/
void MinHeap::MinHeapify(int i)
{
    int l = left(i),
        r = right(i),
        smallest = i;

    if (l < heapSize && heapArr[l] < heapArr[i]) { smallest = l; }
    if (r < heapSize && heapArr[r] < heapArr[smallest]) { smallest = r; }
    if (smallest != i)
    {
        swap(&heapArr[i], &heapArr[smallest]);
        MinHeapify(smallest);
    }
}

//Function to swap two elements
void swap(int *y, int *r)
{
    int temp = *y;
    *y = *r;
    *r = temp;
}

void printArray(int *a,int n){
    for(int i = 0; i < n; i++) { cout << a[i] << " "; }
}



/*
 __  __       _         ______                _   _
|  \/  |     (_)       |  ____|              | | (_)
| \  / | __ _ _ _ __   | |__ _   _ _ __   ___| |_ _  ___  _ __
| |\/| |/ _` | | '_ \  |  __| | | | '_ \ / __| __| |/ _ \| '_ \
| |  | | (_| | | | | | | |  | |_| | | | | (__| |_| | (_) | | | |
|_|  |_|\__,_|_|_| |_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|
*/

int main()
{
yoliesProgramHeader();
displayExplanation();

    ifstream read("input.txt");

    vector<int> arr;

    while(read.good()){

        int temp;

        read>> temp;
        arr.push_back(5);
    }

    arr.push_back(2);
    arr.push_back(3);

    read.close();

    const int size = arr.size();

    MinHeap h(size);

    for (std::vector<int>::iterator it = arr.begin() ; it != arr.end() ;++it) { h.insertKey(*it); }

    printArray(h.heapArr, size);

    int count = 0;

    for (std::vector<int>::iterator it = arr.begin() ; it != arr.end() ;++it){

        if(count < 5) { h.deleteKey(*it); }
        count++;
    }

    printArray(h.heapArr, size);

yoliesProgramFooter();
    return 0;
}
