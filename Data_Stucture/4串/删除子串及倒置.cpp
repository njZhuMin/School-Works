#include <iostream>
#include <cstring>

using namespace std;

//declaration
void delStr( char *src, char *dst);
void reserverSentence(const char* sentence, int len, char sep);
void reserverSentences(const char* sentences, int len);

int main()
{
	char s1[20] = "Are you kidding?";
	char s2[5] = "you";
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	char s3[20] = "Are you kidding?";
    reserverSentences(s3, strlen(s3));
	//cout << "s:" << s3;
	cout << endl;
	delStr(s1,s2);
	cout << s1 << endl;
	return 0;
}

void reserverSentence(const char* sentence, int len, char sep)
{
    int *index_mark = new int[len]();
    int word_num = 1;
    index_mark[0] = -1;
    for(int i = 0; i < len; i++)
    {
        if(sentence[i] == ' ')
        {
            index_mark[word_num] = i;
            word_num++;
        }
    }
 
    char * word;
    int word_start, word_len;
    index_mark[word_num] = len;
    word_num++;
    for(int i = word_num - 1; i > 0; i--)
    {
        word_start = index_mark[i - 1] + 1;
        word_len = index_mark[i] - word_start;
        word = new char[word_len + 1]();
        memcpy(word, sentence + word_start, word_len);
        cout << word << endl;
        if(i != 1)
        {
            cout<<" ";
        }
        delete[] word;
    }
    cout << sep << endl;
    delete[] index_mark;
}
 
void reserverSentences(const char* sentences, int len)
{
    int old_pos = -1;
    for(int i = 0; i < len; i++)
    {
        if(sentences[i] == '.' || sentences[i] == '?' || sentences[i] == '!')
        {
            reserverSentence(sentences + old_pos + 1, i - old_pos - 1, sentences[i]);
            old_pos = i;
        }        
    }
}

void delStr(char* src, char* dst)
{
    char* p = src;
    char* q = dst;
    int dstLen;

    dstLen = strlen(dst);

    while( *src != '\0' )
    {
        if( *q == '\0' )
        {
            p -= dstLen;
            q = dst;//Q重新指向删除的字符
            continue;
        }
        else if ( *src != *q )
        {
            q = dst;
        }
        else
        {
            ++q;
        }
        *p++ = *src++;//每次都用src来刷新p,如果p指针往回dstLen长度,匹配到的字符串会被覆盖掉
    }
    *p = '\0';
}
