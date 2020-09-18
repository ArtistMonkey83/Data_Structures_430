#include <iostream>     // Include directive for cin/cout
#include <fstream>      // Include directive for processing input/output files
#include <string>       // Include directive for using string class

using namespace std;    // so I don't have to type things like std::cout

struct node       //Declare a structure named node
{
  string data;    // With a string named data
  node* prev;     // And pointers to nodes named prev and next
  node* next;
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
 cout << "\n\nThe purpose of this program is to test my ability to read a list of names from a .txt file into a doubly linked list. I will delete a name if the word delete preceedes it, traverse the names in ascending and descending order, as well as write the contents into the file output.txt\n\n";
}

void yoliesProgramHeader()
{
 cout << "\n\n\t\t\t\t\t************* YOLIE REYES ***************\n";
 cout << "\t\t\t\t    ***** Doubly-Linked List Assignment *****\n";
 cout << "\t\t\t\t\t************* 09-17-2020 ****************\n";
 cout << "\t\t\t\t\t************** CISP 430 *****************\n";
}

void yoliesProgramFooter()
{
 cout << "\n\n\t\t\t*********** Intended for Educational Purposes Only! ***********\n\n";
 cout << "\t\t\t\t\t**************** End of Program ****************\n\n\n\n";
}

void traverseForward(node* head)     // Function to move forward through doubly-linked list
{
// Declaring an ofstream object named output and linking it with the file output.txt contained in the same directory as this file
  ofstream output("output.txt");

  while (head)                      // While we have a valid pointer to a node
  {
    output << head->data << endl;   // Save to the file the data at that address
    cout << "\t\t\t\t\t\t\t\t\t\t" << head->data << endl;     // Print to the user/screen the data we saved
    head = head->next;              // Advance to the next node by pointing head to the address at head->next
  }

  output.close();                   // Close the file when you are finished reading all data values from the list
}

void traverseReverse(node* head)    // Reverse traverse is similar to forwards, start with tail and use prev instead of next pointer!
{
// Declaring an ofstream object named output and linking it with the file output.txt contained in the same directory as this file
  ofstream output("output.txt", ios::app);

  node* tail = head;                // Pointer to a node named tail, that holds the address we passed

  while (tail->next != nullptr) {tail = tail->next;}    // While we have items in the list, advance to the next node

  while (tail)                      // While we still have a vaild address
  {
    output << tail->data << endl;   // Save to the file the data at that address
    cout << "\t\t\t\t\t\t\t\t\t\t" << tail->data << endl;     // Print to the user/screen the data we saved
    tail = tail->prev;              // Retreat to the prev node by pointing tail to the address at tail->prev
  }

  output.close();                   // Close the file when you are finished read all data values from the list
}

void sortInsert(node* &head, string data)       // Function passes the address of a node and a string
{
  node* newNode = new node;                     // Declare a new node and
  newNode->data = data;                         // Assign it's member data to the data passed

  if (head == nullptr)                          // If the address is null the list is empty
  {
    newNode->prev = nullptr;                    // Set the prev
    newNode->next = nullptr;                    // and next pointers to null
    head = newNode;                             // assign the address of the node passed to function to the address of
  }                                             // node just created
  else if (head->data > newNode->data)          // If the data at the begging of the list is greater then the data
  {                                             // we just passed into function, then we put it in front of list for ascending order
    newNode->prev = nullptr;                    // Because its the first in the list we set the prev pointer to null
    newNode->next = head;                       // Because we are replacing the front of the list we point next to what was the head
    newNode->next->prev = newNode;              // We need to update the previous head nodes prev pointer from null to the newNode
    head = newNode;                             // Update the head to point to the address of the newNode since it is in the front now
  }
  else                                          // If we make it here the list wasn't empty and
  {                                             // the data was greater then the head node's data
    node* current = head;                       // Make a pointer to a node and assign it the address we passed

// While the current address' next pointer points to something
// And the data that comes after the current node's data is
// Less than the data we passed. Set the current address to the address
// of the next node to continue checking for the spot to insert newNode's data
// If we make it into this while loop the data we passed into function was greater then the head->data but less then the head->next->data
    while (current->next != nullptr && current->next->data < newNode->data)
    {current = current->next;}        // so we advance to the next node to prep for insertion just before it

    newNode->next = current->next;    // Set newNode's next pointer to the next pointer of the node we just advanced to in previous step
                                      // If the address we just advanced to has a succeeding node then our data
                                      // Belongs right before it
    if (current->next != nullptr) {newNode->next->prev = newNode;}

    current->next = newNode;          // If we make it here then that means the list wasn't empty,
    newNode->prev = current;          // and the data was greater than anything present so put it at the end of the list
  }                                   // current->next pointer is set the the newNode we created,previously null(end of list)
}                                     // newNode->prev pointer is set to address of current, which is the value in ascending
                                      // order right before the value passed into the funtion intiially.

void Delete(node* &head, string data)       // Function for deleting a node, takes an adress and the value to look for
{
  if (head == nullptr) {return;}            // If the list is empty the adress of head will be null, nothing to delete return.

  if (head->data == data)                   // If the data we passed is equal to the data of the node we passed
  {
    node* temp = head;                      // Allocate a new pointer to a node named temps to hold the address we passed
    head = head->next;                      // Set head pointer to the node that comes after the address we passed
    head->prev = nullptr;                   // Set the prev pointer to null because we want to delete the value that came before
    delete temp;                            // Delete the node we created to temporarily hold the address of the node we passed in
    return;                                 // Return to the calling function
  }

// If we make it here the list was populated, and we didn't find the value to delete at the address we passed
  node* curr = head;        // Create a pointer to a node to hold the current position starting with the addres we passed
  node* prev = nullptr;     // Create a pointer to a node to hold the previous position,
                            // starting @ null because we don't have any idea what came before the address we just passed
// While we aren't in an empty list and the data we are trying to delete is not at the current position
  while (curr != nullptr && curr->data != data)
  {
    prev = curr;            // Set the prev pointer to hold the position we are currently at
    curr = curr->next;      // Advance to the next node to check and see if that location holds the data we want to delete
  }

  if (curr == nullptr) {return;}    // If the current pointer points to nullptr we didn't find the data in our list

  prev->next = curr->next;          // This will point prev->next to the value that comes after current

// We only make it here if the list was populated, data not found @ the address we passed in and we haven't reached the end
  if (curr->next != nullptr) {curr->next->prev = prev;}   // If there are still values in the list point the previous pointer
                                                          // to address we just left, and then delete our current position
  delete curr;                                            // deleting ensures we don't have a memory leak
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

  ifstream input("input.txt");      // Declaring an ifstream object named input, linked to the file input.txt in the same directory as this file
  string data;                      // Declaring a string to hold the data from the file

  node* head = nullptr;             // Create a new pointer to a node named head, initialized to nullptr (its empty)

  while (input >> data)             // While we are reading input from our file into the string variable we created named data
  {
    if (data == "delete")           // If we come across the word delete
    {
      input >> data;                // We know the next input should be the value(name) we want to delete of the name we will be deleting
      cout << "\t\t\tWe detected delete before " << data << ", we will delete this entry\n";
      Delete(head, data);           // Deleting the data located at the adress of head. If head value is null we will return
    }
    else {sortInsert(head, data);}  // Insert this node in ascending order, if head is null the list is empty
  }

  // cout << "Ascending order of the file:\n ";
  traverseForward(head);            // traverseForward through a doubly-linked list and print the data
  cout << "\t\t\t===========================================================\n";          // Seperation symbols between acending and descending outputs
  traverseReverse(head);            // traverseReverse through a doubly-linked list and print the data

  input.close();                    // Don't forget to close your file!

  yoliesProgramFooter();
  return 0;
}
