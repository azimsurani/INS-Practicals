#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char plain1[10];
    cout<<"Enter plain text : ";
    cin>>plain1;
    int length = strlen(plain1);
    char key[26]={'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b'};
    char cipher1[length+1];
    for(int i=0;i<length;i++)
    {
        cipher1[i] = key[(plain1[i] - 97)];
    }
    cipher1[length]='\0';
    cout<<"Encrypted text is : "<<cipher1<<endl;
    char cipher2[10];
    cout<<"Enter text to decrypt : ";
    cin>>cipher2;
    length = strlen(cipher2);
    char plain2[length+1];
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(cipher2[i]==key[j])
            {
                plain2[i] = 97 + j;
            }
        }
    }
    plain2[length]='\0';
    cout<<"Decrypted text is : "<<plain2;
    return 0;
}
