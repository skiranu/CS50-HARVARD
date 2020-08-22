Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@skiranu 
me50
/
skiranu
Private
3
00
Code
Pull requests
Actions
Projects
Security
Insights
skiranu/readability.c
@skiranu
skiranu automated commit by check50 [check50=True]
Latest commit 2344216 4 minutes ago
 History
 1 contributor
74 lines (71 sloc)  2.08 KB
  
#include<stdio.h>
#include<cs50.h>
#include<string.h>
/*initial declaration of variables for count purposes*/
string s;
int count, wcount, scount, lcount, k, index = 0;
float avg_lcount, avg_scount = 0;
void colman(float a, float b);
/*function to count the letters,words,sentances in the string*/
void counts(string n)
{
    for (int i = 0; i < k; i++)
    {
        /*counting the number of words.*/
        if (s[i] == ' ')
        {
            count += 1;
        }
        /*Counting the special characters in sentance.*/
        if (s[i] == ',' || s[i] == '.' || s[i] == '!' || s[i] == '"' || s[i] == '-' || s[i] == '?')
        {
            wcount += 1;
        }
        /*Counting the number of sentances.*/
        if (s[i] == '.' || s[i] == '!' || s[i] == '?' || s[i] == ':')
        {
            scount += 1;
        }
    }
    /*spaces + 1 = number of words.*/
    wcount = count + 1;
    lcount = k - wcount - scount + 1;
    /*Avg number of letters per 100 words*/
    avg_lcount = (lcount * 100) / wcount;
    /*Avg number of sentences per 100 words*/
    avg_scount = (scount * 100) / wcount;
    /*printf("The number of avg_scount are:%f\n", avg_lcount);
    printf("The number of avg_scount are:%f\n", avg_scount);
    printf("The number of words are:%i\n", wcount);
    printf("The number of letters are:%i\n", lcount);
    printf("The number of sentances are:%i\n", scount);
    printf("The number of non-letters are:%i\n", wcount);*/
    colman(avg_lcount, avg_scount);
}
/*function to claculate the index from the average values.*/
void colman(float L, float S)
{
    index = 0.0588 * L - 0.296 * S - 15.8;
    /*Displaying custom output if Index is negative*/
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    /*Displaying custom output if Index is higher than 15*/
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}


int main(void)
{
    /*main function taking the input from user.*/
    s = get_string("Please enter the string:\n");
    k = strlen(s);
    /*first function call.*/
    counts(s);
}

© 2020 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
