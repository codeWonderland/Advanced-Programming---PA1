/*
Author: Alice Easter
        Class: CSI 240-05
        Assignment: PA 1
Date Assigned: 01/19/17
        Due Date: 01/26/17 12:29 PM
Description:
        Input a file, encrypt and / or decrypt said file by the standards of a codebook, and export that file
Certification of Authenticity:
        I certify that this is entirely my own work, except where I have given
        fully-documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
        may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic
- staff; and/or Communicate a copy of this assignment to a plagiarism checking
- service (which may then retain a copy of this assignment on its database for the
- purpose of future plagiarism checking)
*/

#include "functions.h"
#include "CodeBook.h"

//Declare Global Variables
CodeBook myCodeBook;

void determineProcess()
{

    //Declare Variables
    bool continueOperations;
    int userChoice;
    char userInputForContinue;

    myCodeBook.populateCodeBook(myCodeBook);

    do
    {
        //Determine the path the user wants to take
        std::cout << std::setw(80) << "Welcome! I can provide three functions:" << std::endl
                  << std::setw(80) << "1. Encrypt" << std::endl
                  << std::setw(80) << "2. Decrypt" << std::endl
                  << std::setw(80) << "3. Exit   " << std::endl
                  << std::setw(80) << "What would you like to do:";
        std::cin >> userChoice;

        switch(userChoice)
        {
            case 1:
                myCodeBook.encryptFile(myCodeBook);
                break;
            case 2:
                myCodeBook.decryptFile(myCodeBook);
                break;
            case 3:
                std::cout << std::setw(80) << "Have a nice day!";
                exit(0);
            default:
                std::cout << std::setw(80) << "Sorry! That is not a valid answer,"
                << " let's try this again." << std::endl;
                determineProcess();
                break;
        }

        //Determine whether or not the user wants to continue
        std::cout << std::setw(80) <<"Your translation was a success!" << std::endl
                  << std::setw(80) << "Would you like to process another file? (Y or N):";
        std::cin >> userInputForContinue;

        if (toupper(userInputForContinue) == 'Y')
        {
            continueOperations = true;
        }
        else
        {
            continueOperations = false;
        }
    }
    while (continueOperations);

    std::cout << std::setw(80) << "Have a nice day!";
    exit(0);
}