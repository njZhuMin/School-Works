#include <string>
#include <vector>
#include <iostream>

#include "longest.h"

using namespace std;
 
/**
 * For two strings: S[0...n-1], T[0...m-1]
 * Suppose C[i, j] means the lenght of longest common substring of two string that 
 *     end with S[i] and T[j], where 0 <= i < n, 0 <= j < m
 * We would know 
 *     C[i, j] = C[i-1, j-1] +1,    if S[i] == T[j];
 *             = 0                  if S[i] != T[j];
 *
 *     C[0, j] = 1,     if S[0] == T[j];
 *             = 0,     if S[0] != T[j];
 *     
 *     C[i, 0] = 1,     if S[i] == T[0];
 *             = 0,     if S[i] != T[0];
 *
 *
 * The final result is max(C[0...n-1, 0...m-1]);
 */

int longestCommonSubstring_n2_1(const string& str1, const string& str2) 
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
    
    int indices[] = {0, 0};
    int sizes[] = {size1, size2};
    
    // shift strings to find the longest common substring
    for (int index = 0; index < 2; ++index) 
    {
        indices[0] = 0;
        indices[1] = 0;
        
        // i is reference to the value in array
        int &i = indices[index]; 
        int size = sizes[index];
        
        // this is tricky to skip comparing strings both start with 0 for second loop
        i = index; 
        for (; i < size; ++i)
        {
            int m = indices[0];
            int n = indices[1];
            int length = 0;
            
            // with following check to reduce some more comparisons
            if (size1-m <= longest || size2-n <= longest) 
                break;
            
            while(m < size1 && n < size2)
            {
                ++comparisons;
                if (str1[m] != str2[n])
                {
                    length = 0;
                }
                else 
                {
                    ++length;
                    if (longest < length)
                    {
                        longest = length;
                        start1 = m-longest+1;
                        start2 = n-longest+1;
                    }
                }
                
                ++m;
                ++n;
            }
        }
    }
    
//    for (int i = 0; i < size1; ++i)
//    {
//        int m = i;
//        int n = 0;
//        int length = 0;
//        while(m < size1 && n < size2)
//        {
//            ++comparisons;
//            if (str1[m] != str2[n])
//            {
//                length = 0;
//            }
//            else 
//            {
//                ++length;
//                if (longest < length)
//                {
//                    longest = length;
//                    start1 = m-longest+1;
//                    start2 = n-longest+1;
//                }
//            }
//            
//            ++m;
//            ++n;
//        }
//    }
//
//    // shift string2 to find the longest common substring
//    for (int j = 1; j < size2; ++j)
//    {
//        int m = 0;
//        int n = j;
//        int length = 0;
//        while(m < size1 && n < size2)
//        {
//            ++comparisons;
//            if (str1[m] != str2[n])
//            {
//                length = 0;
//            }
//            else 
//            {
//                ++length;
//                if (longest < length)
//                {
//                    longest = length;
//                    start1 = m-longest+1;
//                    start2 = n-longest+1;
//                }
//            }
//            
//            ++m;
//            ++n;
//        }
//    }

#ifdef IDER_DEBUG
    cout<< "(first, second, comparisions) = (" << start1 << ", " << start2 << ", " << comparisons << ")" << endl;
#endif
    
    return longest;
}