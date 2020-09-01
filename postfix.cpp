#include<iostream>
/*
Read a postfix expression from an input file. Evaluate the postfix format and display the results.

precondition:
  the expression will be read from a file input.txt that contains a single line. There will be no spaces between the operands and the operators.

  the +-* / operators are allowed.normal rules of precedence apply

  no error checking

  the numbers will all be greater than 0 and less than 10(positive, single digit numbers)
*/
using namespace std;

int main()
{

iostream amoxtli;             //declaring an input/output stream variable named amoxtli (Nahuatl for book)
amoxtli.open("input.txt");    //opening the book to read from input.txt

//check to see if the previous operation of opening a file to read from worked if not exit
if (!file) { cout << "Could not open file!"; return 0;}

char op = ' ';        //char op to hold the operation symbol from input.txt
int tlacualli = 0,    // The variable tlacualli (Nahuatl for food) to hold lefthand side operand
    octli = 0,        // The variable octli (Nahuatl for a tasty beverage) to hold righthandside operand
    tlapohualli = 0,  // The variable tlapohualli (Nahuatl for number) to hold the ASCII value for the operation symbol
    tlazolli = 0;     // The variable tlazolli (Nahuatl for waste) to hold the result of the computation

//while reading from file into locally declared variables
//check the operator and perform operation in correct precedence
while (file >> tlacualli >> octli >> op)
{
  tlapohualli = (int)op; //casting 'op' as an int to perform correct operation and saving it as "some number in Nahuatl"
  switch (tlapohualli)
    case 42:
            tlazolli = tlacualli * octli;
            break;
    case 43:
            tlazolli = tlacualli + octli;
            break;
    case 45:
            tlazolli = tlacualli - octli;
            break:
    case 47:
            tlazolli = tlacualli / octli;
}
cout << "\n\n\t\tThe calculation I read from the file is:\n";
cout << "\t\t" << tlacualli << " " << op << " " << octli << " = " << tlazolli << endl;

return 0;
}
