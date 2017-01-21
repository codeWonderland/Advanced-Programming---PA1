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

#ifndef PA1_FUNCTIONS_H
#define PA1_FUNCTIONS_H

#include "CodeBook.h"
#include <fstream>
#include <iomanip>

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
void decryptFile();

/* * * * * * * * * * * * * * * * * * * * * * * * *
 * Purpose: To prompt the user and see if they   *
 *      want to encrypt a file, decrypt a        *
 *      file, or exit.                           *
 * Pre: No preconditions need to be met to run   *
 *      this process                             *
 * Post: This function will either call an       *
 *      encryption process a decryption process, *
 *      or exit the program.                     *
 * * * * * * * * * * * * * * * * * * * * * * * * */
void determineProcess();

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
void encryptFile();

/* * * * * * * * * * * * * * * * * * * * * * * *
 * Purpose: To take in a file that has a list  *
 *      of words and corresponding codes for   *
 *      encryption in the form of "word code"  *
 *      and populate a CodeBook object         *
 * Pre: There must be a file that the user can *
 *      reference to within the function       *
 * Post: This function creates a CodeBook      *
 * * * * * * * * * * * * * * * * * * * * * * * */
void populateCodeBook();

#endif //PA1_FUNCTIONS_H