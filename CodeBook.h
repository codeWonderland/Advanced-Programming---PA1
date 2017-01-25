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

#ifndef PA1_CODEBOOK_H
#define PA1_CODEBOOK_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

const int SIZE_OF_ARRAY = 2;
const int WORD_VECTOR_KEY = 0;
const int CODE_VECTOR_KEY = 1;
class CodeBook
{
private:
    std::vector<std::string> codeArray[SIZE_OF_ARRAY];
    int length;

public:
    void setWordList(std::vector<std::string> words)
    {
        codeArray[0] = words;
    }

    void setCodeList(std::vector<std::string> codes)
    {
        codeArray[1] = codes;
    }

    void setLength()
    {
        length = int(codeArray[0].size());
    }

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Purpose: This function will take in a string and search       *
     *      for it in the Code Book's code vector, if it is found    *
     *      then it will record the key for that code and use it to  *
     *      find the corresponding word in the parallel word vector. *
     * Pre: The function will take in a string                       *
     * Post: The function will either return the decrypted           *
     *      version of the code that was inputted or the code itself *
     *      if there is no decryption available in the Code Book     *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    std::string decrypt(std::string code)
    {
        for (int i = 0; i < this->length; i++)
        {
            if (code == codeArray[CODE_VECTOR_KEY][i])
            {
                return codeArray[WORD_VECTOR_KEY][i];
            }
        }
        return code;
    }

    /* * * * * * * * * * * * * * * * * * * * * * * * * *
     * Purpose: To take in a file that is determined   *
     *      by the user, decrypt that file in          *
     *      accordance with the CodeBook object        *
     *      and output the results in a separate       *
     *      file that is determined by the user.       *
     * Pre: There must already be a file to decrypt    *
     *      and there must be an instance of a         *
     *      CodeBook object to get the encryption      *
     *      code from                                  *
     * Post: This function will create or modify a     *
     *      file that the user determines, empty that  *
     *      file if it exists and then put the         *
     *      decrypted message in it.                   *
     * * * * * * * * * * * * * * * * * * * * * * * * * */
    void decryptFile(CodeBook&);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Purpose: This function will take in a string and search       *
     *      for it in the Code Book's word vector, if it is found    *
     *      then it will record the key for that word and use it to  *
     *      find the corresponding code in the parallel code vector. *
     * Pre: The function will take in a string                       *
     * Post: The function will either return the encrypted           *
     *      version of the word that was inputted or the word itself *
     *      if there is no encryption available in the Code Book     *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    std::string encrypt(std::string word)
    {
        for (int i = 0; i < this->length; i++)
        {
            if (word == codeArray[WORD_VECTOR_KEY][i])
            {
                return codeArray[CODE_VECTOR_KEY][i];
            }
        }
        return word;
    }

    /* * * * * * * * * * * * * * * * * * * * * * * * * *
     * Purpose: To take in a file that is determined   *
     *      by the user, encrypt that file in          *
     *      accordance with the CodeBook object        *
     *      and output the results in a separate       *
     *      file that is determined by the user.       *
     * Pre: There must already be a file to encrypt    *
     *      and there must be an instance of a         *
     *      CodeBook object to get the encryption      *
     *      code from                                  *
     * Post: This function will create or modify a     *
     *      file that the user determines, empty that  *
     *      file if it exists and then put the         *
     *      decrypted message in it.                   *
     * * * * * * * * * * * * * * * * * * * * * * * * * */
    void encryptFile(CodeBook&);

    /* * * * * * * * * * * * * * * * * * * * * * * *
     * Purpose: To take in a file that has a list  *
     *      of words and corresponding codes for   *
     *      encryption in the form of "word code"  *
     *      and populate a CodeBook object         *
     * Pre: There must be a file that the user can *
     *      reference to within the function       *
     * Post: This function creates a CodeBook      *
     * * * * * * * * * * * * * * * * * * * * * * * */
    void populateCodeBook(CodeBook&);
};

#endif //PA1_CODEBOOK_H
