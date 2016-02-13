#include <ctime>
#include <string>
#include <iostream>

#include "longest.h"
using namespace std;

char getChar()
{
    int range = 'Y'-'X'+1;
    int start = 'X';
    return (char)(rand()%range+start);
}


int main(int argc, char const *argv[])
{
    // srand(time(null));
    int sizeLimit = 100;
    int cases = 10;
    while(--cases >= 0)
    {
        int size1 = rand()%sizeLimit;
        int size2 = rand()%sizeLimit;

        string str1 = string(size1, 'a');
        string str2 = string(size2, 'a');        
        for (int i = 0; i < size1; ++i)
            str1[i] = getChar();

        for (int i = 0; i < size2; ++i)
            str2[i] = getChar();      
        
//        string str1 = "YYYXXY";
//        string str2 = "X";
//        int size1 = str1.size();
//        int size2 = str2.size();


        cout << str1 << " (" << size1 << ")" << endl << str2  << " (" << size2 << ")"<< endl;
        cout << longestCommonSubstring_n3(str1, str2) << endl;
        cout << longestCommonSubstring_n2_n2(str1, str2) << endl;
        cout << longestCommonSubstring_n2_2n(str1, str2) << endl;
        cout << longestCommonSubstring_n2_1(str1, str2) << endl;
        
        cout<< endl;
    }

    return 0;
}

/** Sample Outputs:
 * (Since the test cases are randonmized, the result may not totally the same)
 */
// YXXXXXY (7)
// YXYXXYYYYXXYYYYXYYXXYYXXYXYYYYYYXYXYYXYXYYYXXXXXX (49)
// (first, second, comparisions) = (0, 42, 537)
// 6
// (first, second, comparisions) = (0, 42, 343)
// 6
// (first, second, comparisions) = (0, 42, 343)
// 6
// (first, second, comparisions) = (0, 42, 316)
// 6

// XXYXYYYXXYXYYYYXYXYYYXYYYYYXYX (30)
// XYY (3)
// (first, second, comparisions) = (3, 0, 127)
// 3
// (first, second, comparisions) = (3, 0, 90)
// 3
// (first, second, comparisions) = (3, 0, 90)
// 3
// (first, second, comparisions) = (3, 0, 12)
// 3

// XXYXXYYYXYXYYXXYYYYYXXYXXXYXXYXYXXXXYXXYYYXYYXYXYXXXYYXXXYYXYYXYXYXYXXXXXXXXXYXXXX (82)
// YYYYYXYYYXYYXXXYYYXXYYXXYXXXYYYYYYYYXXYXYYYYXYXYYXYX (52)
// (first, second, comparisions) = (5, 41, 7911)
// 9
// (first, second, comparisions) = (5, 41, 4264)
// 9
// (first, second, comparisions) = (5, 41, 4264)
// 9
// (first, second, comparisions) = (18, 20, 4183)
// 9

// X (1)
// XXYYYYYYXYYXYXXXYYXXXYYYYYYXYYYXYYXXYYYYXXXYXXXXXXXYXYXYXYYYYYYYYXYXYXXX (72)
// (first, second, comparisions) = (0, 0, 72)
// 1
// (first, second, comparisions) = (0, 0, 72)
// 1
// (first, second, comparisions) = (0, 0, 72)
// 1
// (first, second, comparisions) = (0, 0, 1)
// 1

//  (0)
// XYXXYYYXXXYYXXYYYYXXYYYXYYYXXXXXYYXXYXYXXXYY (44)
// 0
// 0
// 0
// 0

// YXXXYYYYYXYYY (13)
// YYYYYYYXYXYXXX (14)
// (first, second, comparisions) = (4, 2, 349)
// 7
// (first, second, comparisions) = (4, 2, 182)
// 7
// (first, second, comparisions) = (4, 2, 182)
// 7
// (first, second, comparisions) = (4, 2, 126)
// 7

// YYXXYXYXXYXYXXXXYXXYXYYXYYXXYXYY (32)
// XXYXYXXXXXYXXXYXYYYYXXXYYXYXYXYXXXYYYXXXYYYXXYXYYXXYYYYXYYYXXYXYYXYYXYYYY (73)
// (first, second, comparisions) = (16, 58, 4500)
// 11
// (first, second, comparisions) = (16, 58, 2336)
// 11
// (first, second, comparisions) = (16, 58, 2336)
// 11
// (first, second, comparisions) = (16, 58, 2225)
// 11

// XXXXXXXYXYXYYXYYXYYYXXXYYXYYXYYYYYXXXYXYYYYXXXYYXXYYYXYYYYXXYXYYXX (66)
// XXYXXYXXYXXXXYYYXXYXXYXYXXXXYYXYYXXXYYYXYXXYYYYYYYYXYYYY (56)
// (first, second, comparisions) = (20, 25, 7051)
// 9
// (first, second, comparisions) = (20, 25, 3696)
// 9
// (first, second, comparisions) = (20, 25, 3696)
// 9
// (first, second, comparisions) = (20, 25, 3615)
// 9

// XYXYXXYXXYYXYXYYYYXXYXXYYYYXYYYYYXXYXYYYYYXYYXXXYXXYXYYXYY (58)
// YXYYXXXYYXYYYXXYYXYXXYYXYYXXYXXXX (33)
// (first, second, comparisions) = (5, 17, 3651)
// 8
// (first, second, comparisions) = (5, 17, 1914)
// 8
// (first, second, comparisions) = (5, 17, 1914)
// 8
// (first, second, comparisions) = (41, 0, 1842)
// 8

// XYX (3)
// YYYXXYXXYYYYYYXXYYYXXYYYXYXYXYYXYXXYXXX (39)
// (first, second, comparisions) = (0, 4, 164)
// 3
// (first, second, comparisions) = (0, 4, 117)
// 3
// (first, second, comparisions) = (0, 4, 117)
// 3
// (first, second, comparisions) = (0, 4, 17)
// 3

