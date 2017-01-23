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

//Declare Global Variables
CodeBook myCodeBook;

void decryptFile()
{
    //Declare Variables
    std::string fileNameIn, fileNameOut, lines, currentWord;
    std::ifstream inputFile;
    std::ofstream outputFile;
    bool noInput = true;

    //Test to see if input file exists
    while (noInput)
    {

        noInput = false;

        //Get File Name:
        std::cout << std::setw(80);
        std::cout << "What is the name of the Input File:";
        std::cin >> fileNameIn;
        std::cout << std::endl;

        //Open File for Input
        inputFile.open(fileNameIn);

        //In the event of failure, the while statement is triggered
        if (inputFile.fail())
        {
            std::cout << std::setw(80);
            std::cout << "Couldn't open file";
            noInput = true;
        }
        else
        {
            std::cout << std::setw(80);
            std::cout << "File Opened Successfully!" << std::endl;
        }
    }

    //Get output file name
    std::cout << std::setw(80);
    std::cout << "What is the name of the Output File:";
    std::cin >> fileNameOut;
    std::cout << std::endl;

    //Open output file
    outputFile.open(fileNameOut);

    while (!inputFile.eof())
    {
        getline(inputFile, lines);
        currentWord = "";

        //Parsing through the lines character by character looking for whitespace
        //If any is found then we know that we have hit another word
        for (int h = 0; h < lines.length(); h++)
        {
            if (lines[h] != ' ')
            {
                currentWord += lines[h];
            }
            else
            {
                outputFile << myCodeBook.decrypt(currentWord) << " ";
                currentWord = "";
            }
        }

        outputFile << myCodeBook.decrypt(currentWord) << " ";
        currentWord = "";

        outputFile << std::endl;
    }
    inputFile.close();
}

void determineProcess()
{

    //Declare Variables
    bool continueOperations;
    int userChoice;
    char userInputForContinue;

    do
    {
        //Determine the path the user wants to take
        std::cout << std::setw(80) << "Welcome! I can provide three functions:" << std::endl
                  << std::setw(80) << "1. Encrypt" << std::endl
                  << std::setw(80) << "2. Decrypt" << std::endl
                  << std::setw(80) << "3. Exit" << std::endl
                  << std::setw(80) << "What would you like to do:";
        std::cin >> userChoice;

        switch(userChoice)
        {
            case 1:
                encryptFile();
                break;
            case 2:
                decryptFile();
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

void encryptFile()
{
    //Declare Variables
    std::string fileNameIn, fileNameOut, lines, currentWord;
    std::ifstream inputFile;
    std::ofstream outputFile;
    bool noInput = true;

    //Test to see if input file exists
    while (noInput)
    {

        noInput = false;

        //Get File Name:
        std::cout << std::setw(80);
        std::cout << "What is the name of the Input File:";
        std::cin >> fileNameIn;
        std::cout << std::endl;

        //Open File for Input
        inputFile.open(fileNameIn);

        //In the event of failure, the while statement is triggered
        if (inputFile.fail())
        {
            std::cout << std::setw(80);
            std::cout << "Couldn't open file";
            noInput = true;
        }
        else
        {
            std::cout << std::setw(80);
            std::cout << "File Opened Successfully!" << std::endl;
        }
    }

    //Get output file name
    std::cout << std::setw(80);
    std::cout << "What is the name of the Output File:";
    std::cin >> fileNameOut;
    std::cout << std::endl;

    //Open output file
    outputFile.open(fileNameOut);

    while (!inputFile.eof())
    {
        getline(inputFile, lines);
        currentWord = "";

        //Parsing through the lines character by character looking for whitespace
        //If any is found then we know that we have hit another word
        for (int h = 0; h < lines.length(); h++)
        {
            if (lines[h] != ' ')
            {
                currentWord += lines[h];
            }
            else
            {
                outputFile << myCodeBook.encrypt(currentWord) << " ";
                currentWord = "";
            }
        }

        outputFile << myCodeBook.encrypt(currentWord) << " ";
        currentWord = "";

        outputFile << std::endl;
    }
    inputFile.close();
}

void populateCodeBook()
{
    //Declare Variables
    std::vector<std::string> wordSet, codeSet;
    std::string filenameIn, lines, phrase;
    std::ifstream inputFile;
    bool noInput = true;
    int counter = 0;

    //Test to see if the codebook file exists
    while (noInput)
    {

        noInput = false;

        //Get File Name:
        std::cout << std::setw(80);
        std::cout << "What is the name of the CodeBook file:";
        std::cin >> filenameIn;

        //Open File for Input
        inputFile.open(filenameIn);

        //In the event of failure, the while statement is triggered
        if (inputFile.fail())
        {
            std::cout << std::setw(80);
            std::cout << "Couldn't Open File!" << std::endl;
            noInput = true;
        }

        else
        {
            std::cout << std::setw(80);
            std::cout << "File Opened Successfully" << std::endl << std::endl;
        }

    }

    //Parsing through the file, line by line
    while (!inputFile.eof())
    {
        getline(inputFile, lines);
        phrase = "";

        //Parsing through the lines character by character looking for whitespace
        //If any is found then we know that we have hit another word
        for (int h = 0; h < lines.length(); h++)
        {
            if (lines[h] != ' ' && !inputFile.eof())
            {
                phrase += lines[h];
            }
            else
            {
                wordSet.push_back(phrase);
                phrase = "";
            }
        }

        if (phrase != "")
        {
            codeSet.push_back(phrase);
        }
        counter++;
    }
    inputFile.close();

    //Using collected data to populate our Code List
    myCodeBook.setCodeList(codeSet);
    myCodeBook.setWordList(wordSet);
    myCodeBook.setLength();

    std::cout << std::setw(80);
    std::cout << "CodeBook Populated Successfully!" << std::endl;
}