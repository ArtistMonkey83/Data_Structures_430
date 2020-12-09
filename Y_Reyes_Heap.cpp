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

    int parent(int i) { return (i-1)/2; }   //Parent index is computed as the floor of (nodeIndex-1)/2

    int left(int i) { return (2*i + 1); }   //Left child index is computed as 2*nodeIndex+1

    int right(int i) { return (2*i + 2); }  //Right child index is computed as 2*nodeIndex+2

    int extractMin();                       //Extract the root (minimum element)

    void decreaseKey(int i, int newVal);    //Decrease key value of key at index i to new_val

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
newVal is smaller than heapArr[i].
*/
void MinHeap::decreaseKey(int i, int newVal)
{
    cout <<"We made it inside the decreaseKey function\n";
    heapArr[i] = newVal;                                //The element in heapArr at index i is assigned to the max value of an integer
    cout << "heapArr[i] == "<< heapArr[i] << endl;
    while (i != 0 && heapArr[parent(i)] > heapArr[i])   //While we aren't at the first element and while the heapArr at parent index is > heapArr at i index swap!
    {
        swap(&heapArr[i], &heapArr[parent(i)]);         //Swap the newVal with the parent index to maintain min-Heap property
        i = parent(i);                                  //A parent index of a child node can be computed as (nodeIndex-1)/2
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

    //Return and remove minimum value in heapArr
    int root = heapArr[0];             //Assign root to the value at element 0, the smallest value in heapArr
    heapArr[0] = heapArr[heapSize-1];  //Assign the value of the last element to the first, to check min-heap property after removal
    heapSize--;                        //Decrement the size of the heap to reflect the removal of minimum value
    MinHeapify(0);                     //Perform the heapify function on the array using the root node index of 0, which holds the very last(max) value

    return root;                       //Return the initial value at the beggining of the array(smallest value that is now removed)
}


/*
Deletes a key at i, first reducing the value to minus
infinity, then calls extractMin() to find the min value
*/
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

/*
A recursive function to heapify a subtree with the root at index i
This function assumes that the subtrees are already heapified
*/
void MinHeap::MinHeapify(int i)
{
    int l = left(i),      //Compute the left child of the node at index i (2*nodeIndex+1)
        r = right(i),     //Compute the right child of the node at index i (2*nodeIndex+2)
        smallest = i;     //Variable to hold the smallest of the two values, also used in condition checking to execute a swap

    if (l < heapSize && heapArr[l] < heapArr[i]) { smallest = l; }            //If the left child is smaller than the parent assign l's index to smallest
    if (r < heapSize && heapArr[r] < heapArr[smallest]) { smallest = r; }     //If the right child is smaller than the parent assign r's index to the smallest

    if (smallest != i)   //This line executes if smallest is re-assigned in either preceeding if statements, and smallest is a valid element in heapArr
    {
        swap(&heapArr[i], &heapArr[smallest]);    //Swap the smallest of the two children of a parent node at index i
        MinHeapify(smallest);                     //Maintain the min-Heap property by checking if we violate it
    }
}

//Function to swap two elements
void swap(int *y, int *r)
{
    int temp = *y;        //Local temp integer variable to hold the value y's pointer is pointing to
    *y = *r;              //Assign the value r's pointer is pointing to, to y's pointer
    *r = temp;            //We are dereferencing the values of pointers in this function
}

//Function to print the array
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

    ifstream read("input.txt");     //Declaring ifstream object read, to read from the file input.txt
      int temp= INT_MAX;
    vector<int> populatedArray;     //A vector of integers named populatedArray, will hold what we read from input.txt
      //cout << "we made it here before the while loop\n";
      //cout << "the state of the eof bt is: "<< read.eof() << endl;
    while(read>>temp){             //While we are able to read from the input.txt file

        //int temp;                   //Declare a variable named temp to hold the values read from the file

        //read >> temp;                //Read into the temp variable an item from the file
        populatedArray.push_back(temp); //Use the push_back function to add the value read from file to our populatedArray
        //cout << " the value we just pused into the array is: " << populatedArray[temp] <<endl;
    }
    //cout << "the state of the eof bit  after while loop is: "<< read.eof() << endl;

    //populatedArray.push_back(2);
    //populatedArray.push_back(3);

    read.close();                  //Don't forget to close your file after reading from it!

    const int size = populatedArray.size();   //Assign the size variable to the size of the vector we just populated

    MinHeap heapersCreepers(size); //Create heapersCreepers setting the capacity to the value of size

    for  (std::vector<int>::iterator it = populatedArray.begin() ; it != populatedArray.end() ;++it) { heapersCreepers.insertKey(*it); }

    cout << "\n\n\t\t\tArray before removing 5 items: ";
    printArray(heapersCreepers.heapArr, size);

    int count = 0;

    for (std::vector<int>::iterator it = populatedArray.begin() ; it != populatedArray.end() ;++it){

        if(count < 5) { heapersCreepers.deleteKey(*it); }
        count++;
    }

    cout << "\n\n\t\t\tArray after removing 5 items: ";
    printArray(heapersCreepers.heapArr, size);

yoliesProgramFooter();
    return 0;
}
