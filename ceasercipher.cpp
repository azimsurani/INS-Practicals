#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char plain1[15];
    cout<<"Enter text to encrypt : "<<endl;
    cin>>plain1;
    int length = strlen(plain1);
    int key = 3;
    char cipher1[length+1];
    for(int i=0;i<length;i++)
    {
        char ch = plain1[i];
        if(ch>=65 && ch <=90)
        {
            if((ch+key)<91)
            {
                ch = ch + key;
            }
            else
            {
                ch = 64 + ((ch+key) % 90) ;
            }

        }
        if(ch>=97 && ch <=122)
        {
            if((ch+key)<123)
            {
                ch = ch + key;
            }
            else
            {
                ch = 96 + ((ch+key) % 122) ;
            }

        }
        cipher1[i] = ch;
    }
    cipher1[length]='\0';
    cout<<"Encrypted text is : " <<cipher1<<endl;
    char cipher2[15];
    cout<<"Enter cipher text to decrypt : "<<endl;
    cin>>cipher2;
    length = strlen(cipher2);
    char plain2[length+1];
    for(int i=0;i<length;i++)
    {
        char ch = cipher2[i];
        if(ch>=65 && ch <=90)
        {
            if((ch-key)>64)
            {
                ch = ch - key;
            }
            else
            {
                ch = 91 - (65 - (ch - key)) ;
            }

        }
        if(ch>=97 && ch <=122)
        {
            if((ch-key)>96)
            {
                ch = ch - key;
            }
            else
            {
                ch = 123 - (97 - (ch - key)) ;
            }

        }
        plain2[i] = ch;
    }
    plain2[length]='\0';
    cout<<"Decrypted text is : " <<plain2;
    return 0;
}
