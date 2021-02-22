
#include <iostream>
#include "dynArraySortSearch.hpp"

using std::cout, std::endl;

int main() {
    int arraySize, *numArray, userInt;
    const int MIN_ARRAY_SIZE = 10, MAX_ARRAY_SIZE = 20;

    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    //Get size of array from user
    std::cout << "What size array would you like to create?(10-20)" << std::endl;
    arraySize = getInt(MIN_ARRAY_SIZE, MAX_ARRAY_SIZE);

    // Create and fill array with size given by user
    numArray = createArray(arraySize);

    // Start loop to allow the user to search for as many numbers as they like
    do {
        // Display the array
        displayArray(numArray, arraySize);

        //Get integer from user to search for
        std::cout << "Enter any integer to search the array for it:" << std::endl;
        userInt = getInt(MIN_NUMBER_SIZE, MAX_NUMBER_SIZE);

        //Search array for userInt and report
        if(binSearch(numArray, arraySize, userInt))
        {
            cout << "Found! The array contains your integer!" << endl;
        }
        else
        {
            cout << "DOH! Not found! The array does not contain your integer!" << endl;
        }

    } while(stillSearching());
    // Delete dynamically allocated memory
    delete [] numArray;
    std::cout << "OK bye!" << endl;
    return 0;
}
