
#include <iostream>
#include <limits>
#include <iomanip>

#include "dynArraySortSearch.hpp"

using std::cin;
using std::cout;
using std::endl;

void resetStream();
bool validateCharacterInput(char, const char [], int);
int randInRange(int);

int getInt(int min, int max)
{
    int userInput, validatedInput;
    bool validInput;
    do {
        cin >> userInput;
        // Validate input
        if( !cin.fail() && userInput >= min && userInput <= max ) {
            validInput = true;
            validatedInput = userInput;
        }
        else {
            validInput = false;
            cout << "Invalid input detected. Try again" << endl;
            resetStream();
        }
    } while(!validInput);

    return validatedInput;
}

const int * createArray(int arraySize)
{
    //Create array of given size full of zeroes
    auto *numArray = new int[arraySize] {0};
    int key, value;
    for(int i = 0; i < arraySize; i++) {
        // Create random number
        key = randInRange(MAX_NUMBER_SIZE);
        // Find correct location
        value = i;
        while(value > 0 && *(numArray + value - 1) > key) {
            *(numArray + value) = *(numArray + value - 1);
            value--;
        }
        *(numArray + value) = key;   //insert in right place
    }

    return numArray;
}

void displayArray(const int * array, int arraySize)
{
    const int STREAM_WIDTH = 4, LINE_ITEMS = 5;
    for (int i = 0; i < arraySize; ++i) {
        // Set width of output stream
        cout << std::setw(STREAM_WIDTH);
        // Display value
        cout << *(array + i);
        if((i + 1) % LINE_ITEMS == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}

bool binSearch(const int * numArray, int size, int value)
{
    int min = 0;
    int max = size - 1;
    bool found = false;

    while (max >= min && !found)
    {
        int mid = (min + max) / 2;
        if ( *(numArray + mid) == value ) {
            found = true;
        }
        else if ( *(numArray + mid) > value ) {
            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }
    return found;
}

bool stillSearching()
{
    const char ACCEPTABLE_INPUT[2] {'Y', 'N'};
    char userInput;
    bool searchAgain, validInput;
    cout << "Would you like to search for another number? (y/n)" << endl;
    do {
        cin >> userInput;
        // Uppercase the input to allow lower and uppercase entries
        userInput = static_cast<char>(toupper(userInput));
        // Validate input 
        if(!cin.fail() && validateCharacterInput(userInput, ACCEPTABLE_INPUT, 2)){
            validInput = true;
        }
        else {
            cout << "Invalid input detected. Enter y/n." << endl;
            resetStream();
            validInput = false;
        }
    } while(!validInput);
    if(userInput == 'Y'){
        searchAgain = true;
    }
    else {
        searchAgain = false;
    }

    return searchAgain;
}

bool validateCharacterInput(char input, const char validInputs[], int validInputsLength)
{
    bool validInput = false;
    // Validate input if it is found in the array of valid inputs
    for (int i = 0; i < validInputsLength; ++i) {
        if(validInputs[i] == input) {
            validInput = true;
        }
    }
    return validInput;
}

//https://stackoverflow.com/questions/7887941/random-number-from-9-to-9-in-c
int randInRange(int max)
{
    // Returns random integer between argument max and -max
    return rand() % (max * 2 +1) + (-max);
}

void resetStream()
{
    const long large = std::numeric_limits<std::streamsize>::max();
    const char endLine = '\n';
    // Clear input and errors
    cin.clear();
    // Flush the buffer
    cin.ignore(large,endLine);
}
