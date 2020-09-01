#include<iostream>

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

yoliesProgramFooter();
yoliesProgramHeader();
displayExplanation();

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

yoliesProgramHeader();
displayExplanation();

iostream amoxtli;             //declaring an input/output stream variable named amoxtli (Nahuatl for book)
amoxtli.open("input.txt");    //opening the "book" to read from input.txt

//check to see if the previous operation of opening a "book" to read from worked if not exit
if (!amoxtli) { cout << "Could not open the file!"; return 0;}

char op = ' ';        // The variable op to hold the operation symbol from input.txt
int tlacualli = 0,    // The variable tlacualli (Nahuatl for food) to hold lefthand side operand
    octli = 0,        // The variable octli (Nahuatl for a tasty beverage) to hold righthandside operand
    tlapohualli = 0,  // The variable tlapohualli (Nahuatl for number) to hold the ASCII value for the operation symbol
    tlazolli = 0;     // The variable tlazolli (Nahuatl for waste) to hold the result of the computation

//while reading from the amoxtli "book" into locally declared variables
//cast the operator as an int and perform calculation with correct precedence
while (amoxtli >> tlacualli >> octli >> op)
{
  tlapohualli = (int)op; // Saving the casted int as "some number in Nahuatl"
  switch (tlapohualli)  // Checking "some number in Nahuatl" against ASCII values for +, -, *, / operations
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
            break;
    default: cout << "\nThe " tlapohualli << " symbol does not represent a valid operation!\n"
             yoliesProgramFooter();
             return 0;
}

cout << "\n\n\t\tThe calculation I read from the file is:\n";
cout << "\t\t" << tlacualli << " " << op << " " << octli << " = " << tlazolli << endl;

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
