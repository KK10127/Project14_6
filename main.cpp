/*
 * CHAPTER 14, PROJECT 6
 * CS 151
 * Tu 5:30-9:20 with Porto
 * Programmer: Jay Montoya
 *
 *
 * PROBLEM STATEMENT:
 *      Write a recursive boollean function names isMember. The function should accept three paramters: an array of
 *      integers, an integer indicating the number of elements in the array, and an integer value to be searched for.
 *      The function should return true if the value is found in the array or false if the value is not found.
 *      Demonstate the use of the function in a program that asks the user to enter an array of numbers and a value to
 *      be searched for.
 *
 * ALGORITHM for main():
 *
 * ALGORITHM for containsValue():
 *
 */
#include <iostream>
using namespace std;

// function prototype
bool isMember(int * arrayPtr, int size, int target);

// main method
int main() {

    // declare variables
    int size;
    int currentVal;
    int target;

    // greeting
    cout << "\nWelcome to the demo for project 6!" << endl;

    // prompt for number of values
    cout << "\nHow many values do you wish to enter? ";
    cin >> size;

    // build array based on size
    int values[size];

    // enter members
    for (int i = 0; i < size; i++) {
        cout << "\tEnter value #" << (i + 1) << ": ";
        cin >> currentVal;
        *(values + i) = currentVal;
    }

    // enter value to be searched for
    cout << "\nEnter the number you wish to search for: ";
    cin >> target;

    // call the function with the array, size, and target value
    // output the result
    isMember(values, size, target)
        ? cout << "\nThe value is found in the list!" << endl
        : cout << "The value was not found in the list!" << endl;

    // end program
    return 0;
}

/*
 * This function will recursively determine whether an array of integers contains the target value.
 * PRE-CONDITION:
 *      - the function is given a pointer to a fully initialized array of integers
 *      - the function is given the size of the above array
 *      - the function is given the target integer.
 * POST-CONTITION:
 *      - the function returns a boolean representing whether or not the target is contained within the array of values.
 */
bool isMember(int * arrayPtr, int size, int target) {
    // get the current search index
    int searchIndex = size - 1;

    // cases
    if (*(arrayPtr + searchIndex) == target) {
        // stopping case! We found it!
        return true;
    } else if (searchIndex == 0) {
        // second stopping case! we reached the end!
        return false;
    } else {
        // continue searching going from front to back all the way to index 0.
        return isMember(arrayPtr, (size - 1), target);
    }
}
