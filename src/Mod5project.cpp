//============================================================================
// Name        : Mod5project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to append user input to a file
void appendToFile(const string& filename) {
    ofstream fileOut;
    fileOut.open(filename, ios::app);  // Open the file in append mode

    if (!fileOut) {
        cerr << "Error opening file for appending: " << filename << endl;
        return;
    }

    string userInput;
    cout << "Enter text to append to the file: ";
    getline(cin, userInput);

    fileOut << userInput << endl;  // Append user input to the file
    fileOut.close();
}

// Function to reverse the contents of a file and write to a new file
void reverseFileContent(const string& inputFilename, const string& outputFilename) {
    ifstream fileIn(inputFilename);
    if (!fileIn) {
        cerr << "Error opening file for reading: " << inputFilename << endl;
        return;
    }

    // Read the file content into a string
    string fileContent((istreambuf_iterator<char>(fileIn)), istreambuf_iterator<char>());
    fileIn.close();

    // Reverse the file content
    reverse(fileContent.begin(), fileContent.end());

    ofstream fileOut(outputFilename);
    if (!fileOut) {
        cerr << "Error opening file for writing: " << outputFilename << endl;
        return;
    }

    // Write the reversed content to the new file
    fileOut << fileContent;
    fileOut.close();
}

int main() {
    const string inputFilename = "CSC450_CT5_mod5.txt";
    const string outputFilename = "CSC450-mod5-reverse.txt";

    // Append user input to the provided file
    appendToFile(inputFilename);

    // Reverse the contents of the file and write to a new file
    reverseFileContent(inputFilename, outputFilename);

    cout << "Operation completed. Check the files." << endl;

    return 0;
}
