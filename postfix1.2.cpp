#include <iostream>
#include <fstream>
#include <climits>

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

void yoliesProgramFooter();
void yoliesProgramHeader();
void displayExplanation();

using namespace std;

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
//cout << "hello I just got inside main! line 34\n";
yoliesProgramHeader();
displayExplanation();

fstream amoxtli("input.txt" , ios::in);      // Declaring an I/O fstream object(variable?) named amoxtli (Nahuatl for book),
                                             // linked to input.txt in the same directory as .cpp
                                             // amoxtli.open("input.txt"); opening the "book" to read from input.txt

//check to see if the previous operation of opening a "book" to read from worked if not exit
if (!amoxtli) { cout << "Could not open the file!"; yoliesProgramFooter(); return 0;}

char op [SHRT_MAX];    // Will hold the input.txt as single characters in an array that will be the <climits> max value for a short int.

int tlacualli = 0,     // The variable tlacualli (Nahuatl for food) to hold lefthand side operand
    octli = 0,         // The variable octli (Nahuatl for a tasty beverage) to hold righthandside operand
    tlapohualli = 0,   // The variable tlapohualli (Nahuatl for number) to hold the ASCII value for the operation symbol
    tlazolli = 0,      // The variable tlazolli (Nahuatl for waste) to hold the result of the computation
    i = 0,             // Will be used to iterate through characters of the input.txt file
    num_elements = 0;  // Will be used to keep track of elements read from input.txt


while (!amoxtli.eof()) // While we are not at the end of the "book"
{
  amoxtli >> op[i];    // Read into the character array op
  i++;                 // Increment interator counter
  num_elements++;      // Increment number of elements variable
}

if(num_elements == 2)       // If the number of elements exceeds one computation of two integers just print end of program, close the amoxtli fstream object
{
  tlacualli = (int)op[0];   // Initializing the left handside operand from char array op element being cast as an int
  octli = (int)op[1];       // Initializing the right handside operand from char array op element being cast as an int
  tlapohualli = (int)op[2]; // Saving the element in array that holds operation, casted as an int becomes "some number in Nahuatl"

  switch (tlapohualli)      // Checking "some number in Nahuatl" against ASCII values for +, -, *, / operations
  {
    case 42:                // Multiplication
            tlazolli = tlacualli * octli;
            break;
    case 43:                // Addition
            tlazolli = tlacualli + octli;
            break;
    case 45:                // Subtraction
            tlazolli = tlacualli - octli;
            break;
    case 47:                // Division
            tlazolli = tlacualli / octli;
            break;
    default: cout << "\nThe " << tlapohualli << " symbol does not represent a valid operation!\n";
             yoliesProgramFooter();
             amoxtli.close();
             return 0;
  }

//The results printed to the screen
cout << "\n\n\t\tThe calculation I read from the file is:\n";
cout << "\t\t" << tlacualli << " " << op[2] << " " << octli << " = " << tlazolli << endl;
}

yoliesProgramFooter();
amoxtli.close();

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
  cout << "\n\nThe purpose of this program is to test my ability to evaluate a postfix expression after reading it from a file then print the results to the screen.\n\n";
}


void yoliesProgramHeader()
{
  cout << "\n\n********* YOLIE REYES *********\n";
  cout << "********** Postfix Assignment **********\n";
  cout << "*********** 08-31-2020 ***********\n";
  cout << "********** CISP 430 **********\n";
}


void yoliesProgramFooter()
{
  cout << "\n\n\n**************** End of Program ****************\n\n\n\n";
}
