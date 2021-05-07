//#define MAX_STR_LENGTH 5000
//#define MAX_WORDS 10
//#define MAX_WORD_LENGTH 20

#include <string.h>
/*
* 
* words counts the numbwe of words 
* in the sentence
* 
*/ 
int wordCount(const char* sentence)
{
    int count = 0, i, len;
    char lastC="";
    len = strlen(sentence);
    if (len > 0)
    {
        lastC = sentence[0];
    }
    for (i = 0; i <= len; i++)
    {
        if ((sentence[i] == ' ' || sentence[i] == '\0') && lastC != ' ')
        {
            count++;
        }
        lastC = sentence[i];
    }
    return count;
}
/*
*
* geetString replaces scanf_s in order
* to accept carriage returns without
* user input.
*
*/
int getString(char* buf)
{
    int index = 0;
    int ch = 0, numWords = 0;
    //char  buf[81];

    buf[0] = (char)(0);

    //printf("Enter some text: ");
    ch = getchar();
    if (ch == 10 || ch == EOF) {
        return 0;
    }
    else
    {
        do
        {
            buf[index] = (char)ch;
            index++;
        } while (index < 80 && ((ch = getchar()) != '\n' && ch != EOF));
        if (index < 80)
            buf[index] = (char)(0);
        else
            buf[80] = (char)(0);
        //printf("You entered %s using %i chars.", buf, index);
        numWords = wordCount(buf);
        return numWords;
    }
}
