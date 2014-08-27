//
//  filelib.h
//  5_02
//
//  Created by Ben Mills on 10/30/13.
//
// Stanford's "filelib.h" is not happy on my x_64 computer :(
// So I made my own.
//

#ifndef _filelib_h
#define _filelib_h

#include <fstream>
#include <string>


/*
 * Function: promptUserForFile
 * Usage: string filename = promptUserForFile(stream, prompt);
 * -----------------------------------------------------------
 * Asks the user for the name of a file.  The file is opened using
 * the reference parameter <code>stream</code>, and the function
 * returns the name of the file.  If the requested file cannot be
 * opened, the user is given additional chances to enter a valid file.
 * The optional <code>prompt</code> argument provides an input prompt
 * for the user.
 */

std::string promptUserForFile(std::ifstream & stream, std::string prompt = "");
std::string promptUserForFile(std::ofstream & stream, std::string prompt = "");






#endif
