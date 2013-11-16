// 
// histogram.h
//
//

#ifndef _histogram_h
#define _histogram_h

#include <string>
#include "Vector.h"
#include "simpio.h"

using namespace std;


void printHistogram(Vector<std::string> &asterisk, Vector<int> &interval) {
    
    for (int i = 0; i < interval.size(); i++) {
        std::cout << interval[i] << " : " << asterisk[i] << std::endl;
    }
}

void getHistSpecs(int &maximumHistValue, int &minimumHistValue, int &histRangeSize) {
    maximumHistValue = getInteger("Enter a maximum: ");
    minimumHistValue = getInteger("Enter a minimum: ");
    histRangeSize = getInteger("Enter an interval size: ");
}


void initializeVectors(Vector<int> &data, Vector<std::string> &asterisk, Vector<int> &interval) {
    int minimumHistValue = 0;
    int maximumHistValue = 0;
    int histRangeSize = 1; // so as not to divide by 0
    getHistSpecs(maximumHistValue, minimumHistValue, histRangeSize);
    int intervalCount = (maximumHistValue - minimumHistValue) / histRangeSize;
    
    // Initializing interval:
    for (int i = 0; i <= intervalCount; i++) {
        interval.add(minimumHistValue + (histRangeSize * i));
    }
    
    //initialize asterisk
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < interval.size(); j++) {
            asterisk.add("");
            if (data[i] >= interval[j] && data[i] < interval[j] + histRangeSize) {
                asterisk[j] += '*';
                break;
            }
        }
    }
}
    


#endif