// 
// histogram.h
//
//

#ifndef _histogram_h
#define _histogram_h

#include <string>
#include "Vector.h"


void printHistogram(Vector<std::string> &asterisk, Vector<int> &interval);

void initializeVectors(Vector<int> &data, Vector<std::string> &asterisk, Vector<int> &interval);

void getHistSpecs(int &mmaximumHistValue, int &mminimumHistValue, int &histRangeSize);



#endif