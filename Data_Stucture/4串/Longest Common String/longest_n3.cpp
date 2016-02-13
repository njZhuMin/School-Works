#include <string>
 
#include <iostream>

#include "longest.h"

using namespace std;

int longestCommonSubstring_n3(const string& str1, const string& str2) 
{   
    size_t size1 = str1.size();
    size_t size2 = str2.size();
    if (size1 == 0 || size2 == 0) return 0;

    // the start position of substring in original string
    int start1 = -1;
    int start2 = -1;
    // the longest length of common substring 
    int longest = 0; 

    // record how many comparisons the solution did;
    // it can be used to know which algorithm is better
    int comparisons = 0;

    for (int i = 0; i < size1; ++i)
    {
        for (int j = 0; j < size2; ++j)
        {
            // find longest length of prefix 
            int length = 0;
            int m = i;
            int n = j;
            while(m < size1 && n < size2)
            {
                ++comparisons;
                if (str1[m] != str2[n]) break;
                
                ++length;
                ++m;
                ++n;
            }

            if (longest < length)
            {
                longest = length;
                start1 = i;
                start2 = j;
            }
        }
    }
#ifdef IDER_DEBUG
    cout<< "(first, second, comparisions) = (" << start1 << ", " << start2 << ", " << comparisons << ")" << endl;
#endif
    return longest;
}