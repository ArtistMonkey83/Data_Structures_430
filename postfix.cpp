#include
/*
Read a postfix expression from an input file. Evaluate the postfix format and display the results.

precondition:
  the expression will be read from a file input.txt that contains a single line. There will be no spaces between the operands and the operators.

  the +-* / operators are allowed.normal rules of precedence apply

  no error checking

  the numbers will all be greater than 0 and less than 10(positive, single digit numbers)
*/

int main()
{
  //char to hold our values from input.txt
  char p = '!';
//opening the file to read
ifstream file;
file.opent("input.txt");

if (!file) { cout << "Could not open file!"}

while (file >> p)

return 0;
}
