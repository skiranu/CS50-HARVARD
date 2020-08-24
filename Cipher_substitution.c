#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*initial declaration global variables*/
int ci, len, c, z1, g = 0;
string str;
/*two char arrays for copying key and holding plain text*/
char m[26], a[26];
char h;
int a2;
void realsubstitutionLow(int l);
void realsubstitutionUpp(int l);
/*function checking duplicate letters of the key*/
void duplicate(string d)
{
    for (int s = 0; s < 26; s++)
    {   
        for (int s1 = s + 1; s1 < 27; s1++)
        {
            if (d[s] == d[s1])
            {
                printf("key contains duplicate.");
                exit(1);
            }
        }
    }
}
/*copying the key into an array(0-25 letters).*/
void subs1(string d)
{   
    printf("ciphertext: ");
    for (int i = 0; i < 26; i++)
    {
        a[i] = d[i];
    }
}
/* copying the plain text and assigning values from 0-25 as per the key*/
void subs2(string x)
{   
    g = strlen(x);
    for (z1 = 0; z1 < g; z1++)
    {
        /* checking if plain text is lower, cipher text should also be lower*/
        if (islower(x[z1]))
        {
            a2 = x[z1] - 97;
            /*assigining the plaintext and key*/
            realsubstitutionLow(a2);

        }
        /* checking if plain text is upper, cipher text should also be upper*/
        else if (isupper(x[z1]))
        {
            a2 = x[z1] - 65;
            /*assigining the plaintext and key*/
            realsubstitutionUpp(a2);
        }
        /*No action taken if the plain text contains special characters.*/
        else
        {
            printf("%c", x[z1]);
        }

    }
    printf("\n");

}
/*casting and substituting the key values to the plaintext*/
void realsubstitutionLow(int l)
{
    printf("%c", tolower(a[l]));
}
void realsubstitutionUpp(int l)
{
    printf("%c", toupper(a[l]));
}
/*main function taking the command line arguments.*/
int main(int argc, string argv[])
{
    /*checking if no arguments are provided at command line and printing msg.*/
    if (argc == 1 || argc > 2)
    {
        printf("./substitution key\n");
        exit(1);
    }
    /*converting the str from command line into int value for key.*/
    char *z = argv[1];
    int x = atoi(z);
    /*checks if input is alpha numeric and prints msg*/
    string d;
    d = argv[1];
    for (int j = 0; j < strlen(d); j++)
    {
        if (isdigit(d[j]))
        {
            printf("./substitution key");
            exit(1);
        }

    }
    /*checking if key is not 26 letters long*/
    len = strlen(d);
    if (len == 26)
    {
        printf("Input provided key length provided is\n: %i\n", len);
    }
    else
    {
        printf("Key must contain 26 characters.");
        exit(1);
    }
    /*calling duplicate funtion for checking key initially*/
    duplicate(d);
    /*getting plain text from the user.*/
    str = get_string("plaintext: \n");
    /*assigning the key to int array from 0-25.*/
    subs1(d);
    /*assigning the plain text to int array from 0-25.*/
    subs2(str);
}
