#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//create program to convert hex string into int
int convertHexToInt(char string[]);

int main()
{
    char str[] = "7DE"; //enter Hex number in UPPERCASE

    //perform convert function & print result
    printf("hex number: %d", convertHexToInt(str));

    return 0;
}

int convertHexToInt(char string[]) {
    int stringLength = strlen(string);  //stringLength represents length of Hex string
    int i = stringLength - 1;           //declare int i to be used in for loop for decimal sum calculation

    int currentNumber = 0;              //integer representation at each hex digit
    int decimalNumberSum = 0;           //sum of hex values in decimal
    int hexDigit = 0;                   //integer representation of hex base (0th place, 1st place etc.)

    for (i; i >= 0; i--) {

        //convert Hex digit into decimal number for alphabets
        if (string[i] >= 'A' && string[i] <= 'F') {
            currentNumber = string[i] - '0' - 7;
        }

        //convert Hex digit into decimal number for non-alphabets
        else {
            currentNumber = string[i] - '0';
        }

        //update decimal sum
        decimalNumberSum += currentNumber * pow(16.0,hexDigit);
        hexDigit++;                     //increment hexDigit (16 to the nth)
    }

    return decimalNumberSum;
}
