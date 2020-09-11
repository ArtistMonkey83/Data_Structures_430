#include <iostream>
#include <fstream>

/*
______                _   _               _____           _     _______
|  ____|              | | (_)             |  __ \         | |   |__   __|
| |__ _   _ _ __   ___| |_ _  ___  _ __   | |__) | __ ___ | |_ ___ | |_   _ _ __   ___  ___
|  __| | | | '_ \ / __| __| |/ _ \| '_ \  |  ___/ '__/ _ \| __/ _ \| | | | | '_ \ / _ \/ __|
| |  | |_| | | | | (__| |_| | (_) | | | | | |   | | | (_) | || (_) | | |_| | |_) |  __/\__ \
|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_| |_|   |_|  \___/ \__\___/|_|\__, | .__/ \___||___/
                                                                      __/ | |
                                                                     |___/|_|
*/

struct node       // Declare a structure named node
{
 int data;       // With an integer variable named data
 node* next;     // And a pointer to a node named next
};


void yoliesProgramFooter();
void yoliesProgramHeader();
void displayExplanation();

char pop(node* &top);
void push(node* &top, char data);


using namespace std;

/*
__  __       _         ______                _   _
|  \/  |     (_)       |  ____|              | | (_)
| \  / | __ _ _ _ __   | |__ _   _ _ __   ___| |_ _  ___  _ __
| |\/| |/ _` | | '_ \  |  __| | | | '_ \ / __| __| |/ _ \| '_ \
| |  | | (_| | | | | | | |  | |_| | | | | (__| |_| | (_) | | | |
|_|  |_|\__,_|_|_| |_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|
*/

int main ()
{
 yoliesProgramHeader();
 displayExplanation();

 ifstream input("input.txt");      // Opening file to read in the same directory as this .cpp named input.txt
 int a,                            // Variables to hold lefthand, righthand operands
     b;
 char c;                           // As well as operator characters

 node *top = nullptr;

//cout << a << b << c << endl;

 while(input >> c )                          // While we have input from the file then...
 {
   if(isdigit(c)){ push(top,c - '0');}           // If the character is a digit push to the stack
   else {                                  // Else character is an operator, lower in precedence start popping!
     a = pop(top);                         // Assign the righthand operand to a
     b = pop(top);                         // Assign the lefthand operand to b
//cout << a << b << c << endl;
     switch(c)                             // Evaluate what operation needs to take place
     {
       case '+':   push(top, b + a);
                   //cout << pop(top) << endl;
                   break;
       case '-':   push(top, b - a);
                   //cout << pop(top) << endl;
                   break;
       case '*':   push(top, b * a);
                   //cout << pop(top) << endl;
                   break;
       case '/':   push(top, b / a);
                   //cout << pop(top) << endl;
                   break;
     }
   }
 }

 cout << "\n\n\t\t\t\tThe last calculation I read from the file is: " << b << " " << c << " " << a << " = " << int(pop(top))<< endl;

yoliesProgramFooter();
 return 0;
}

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
 cout << "\n\nThe purpose of this program is to test my ability to use the stack to evaluate a postfix\nexpression after reading it from a file. I will then print the results to the screen.\n\n";
}


void yoliesProgramHeader()
{
 cout << "\n\n\t\t\t\t\t\t************* YOLIE REYES **************\n";
 cout << "\t\t\t\t\t\t********** Postfix Assignment **********\n";
 cout << "\t\t\t\t\t\t************* 09-10-2020 ***************\n";
 cout << "\t\t\t\t\t\t************** CISP 430 ****************\n";
}


void yoliesProgramFooter()
{
 cout << "\n\n\t\t\t*********** Intended for Educational Purposes Only! ***********\n\n";
 cout << "\t\t\t\t\t**************** End of Program ****************\n\n\n\n";
}

char pop(node* &top)     // Pop something off of the stack to use (consume) passing the stack's top address by reference
{
 node* temp;            // Declaring a pointer to a node named temp
 int data;              // Declaring an int named data

 if(top)                // If there is a top node (something on stack) then... POP!
 {
   temp = top;          // Assign the address of top to temp
   top = top->next;     // The address of top gets re-assigned to the address of next node
   data = temp->data;   // The local 'data' variable initiallized with the starting value of top's data member
   delete temp;         // Delete the temporary node that held the value on the stack.
 }

 return data;           // Return the local variable data that holds the value that was on the stack
}

void push(node* &top, char data)      // Adding a node to the stack
{
 node* newNode = new node;           // Declaring a pointer to a node named newNode and dynamically allocating on stack
 newNode->data = data;               // Initializing the data member variable of newNode with the data we passed in
 newNode->next = top;                // The newNode's Next member variable is reassigned the address of top
 top = newNode;                      // The top of our stack now points to the address of the newly created node
}

/* how would we modularize adding a new node?
node * add(){                    // Function for adding a node
 node * temp = new node;        // Declaring a new pointer to a node named temp, dynamically allocating
 return temp;                   // Returning the pointer to this newly allocated space
}
*//*
       This is what I am doing
int main(){
 in >> s
 for (process every element in the array){
   if element operand
     convert char element to an integer and push on the stack
   else( element is an operator)
   {
     b= pop from stack
     a = pop from stack
     value = evaluate(a,b,operator)
     push value on the stack
   }
 }
 pop and display result
}
*/
