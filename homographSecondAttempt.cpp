/**********************************************************************
* Program:
*   Lab 05, Homographs
*   Brother Helfrich, CS 470
*
* Authors:
*   Osvaldo Carrillo Lira
*   Aaron Eiche
*   Zach Heiner
*   Collin Steel
*   John Tanner
*   Jordon Thompson
*
* Summary:
*   This program prompts the user for 2 file patha. It then compares the
*	the user's input to determines if the two file paths are Homographs
*   of Non-Homographs. The program also contains a canonize function
*   which transforms the file path into a standard "canonized" file path.
 ************************************************************************/

#define WINDOWS
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string getWorkingDirectory();
string handleUserInput( string path );
string promptUser( string path );
string toLowerCase( string path );

int main()
{
    // Variable to hold menu option choice
    int menuOption = 0;

    do {

        // Obtain the working directory of the user
        string workingDIR = getWorkingDirectory();
        cout << "Current working directory is: " << workingDIR << "\n";

        // Create a string variable to hold filepath
        string filepath1 = "";
        string filepath2 = "";

        cout << "Please choose from the following menu items:\n";
        cout << "1. Compare File Paths For Homograph Attacks\n";
        cout << "2. Test Canonization Function\n";
        cout << "3. Exit Program\n";
        cout << "Menu Selection: ";
        cin >> menuOption;

        // Menu option logic
        if (menuOption == 1) {
            // Prompt user for file paths
            filepath1 = handleUserInput( filepath1 );
            filepath2 = handleUserInput( filepath2 );
        }
        else if (menuOption == 2) {
            // Prompt user for file path
            filepath1 = handleUserInput( filepath1 );
        }

    } while ( menuOption != 3 );

    return 0;
}

/**************************************************
 * GET WORKING DIRECTORY
 * This function returns the working directory
 * of the user.
 * ************************************************/
string getWorkingDirectory() {
    char buff[ FILENAME_MAX ];
    GetCurrentDir( buff, FILENAME_MAX );
    string current_working_dir( buff );
    return current_working_dir;
}

/**************************************************
 * HANDLE USER INPUT
 *
 * ************************************************/
string handleUserInput( string path ) {
    promptUser( path );
    toLowerCase( path );
    return path;
}

/**************************************************
 * PROMPT USER
 * This function will prompt the user for a filepath
 * and return a string
 * ************************************************/
string promptUser( string path ) {
    // Prompt the user for a filepath
    cout << "Enter a filepath: ";

    // Save user input into the variable
    cin >> path;

    // Return user input
    return path;
}


/**************************************************
 * TO LOWER CASE
 * This function will tranform the filepath to a
 * lower case version of the path.
 * ************************************************/
string toLowerCase( string path ) {
    // Transform each character in the path to lower case
    transform( path.begin(), path.end(), path.begin(), [](unsigned char letter ) {
        return tolower( letter );
        } );
    return path;
}