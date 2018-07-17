#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char key[5][5]={{'p','l','a','y','f'},{'i','r','b','c','d'},{'e','g','h','k','m'},{'n','o','q','s','t'},{'u','v','w','x','z'}};
    char plain1[20];
    cout<<"Enter plain1 text : ";
    cin>>plain1;
    int length = strlen(plain1);
    for(int i=0;i<length-1;i++)
    {
        if(plain1[i]=='j')
            plain1[i]='i';
        if(plain1[i]==plain1[i+1])
        {
            for(int j=length+i;j>i+1;j--)
            {
                plain1[j]=plain1[j-1];
            }
            plain1[i+1]='x';
            plain1[length+i+1]='\0';
        }
    }

    length = strlen(plain1);
    if(length%2 == 1)
    {
        plain1[length] = 'x';
        plain1[length+1] = '\0';
    }
    length = strlen(plain1);
    char cipher1[length+1];
    for(int i=0;i<length;i=i+2)
    {
        int row1,col1;
        int row2,col2;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(plain1[i]==key[j][k])
                {
                    row1=j;
                    col1=k;
                }
                if(plain1[i+1]==key[j][k])
                {
                    row2=j;
                    col2=k;
                }
            }
        }
        if(row1==row2)
        {
            cipher1[i]=key[row1][(col1+1)%5];
            cipher1[i+1]=key[row2][(col2+1)%5];
            continue;
        }
        else if(col1==col2)
        {
            cipher1[i]=key[(row1+1)%5][col1];
            cipher1[i+1]=key[(row2+1)%5][col2];
            continue;
        }
        else
        {
            cipher1[i]=key[row1][col2];
            cipher1[i+1]=key[row2][col1];
        }
    }
    cipher1[length]='\0';
    cout<<"Encrypted text is : "<<cipher1<<endl;

    char cipher2[20];
    cout<<"Enter text to decrypt : ";
    cin>>cipher2;
    length = strlen(cipher2);
    char plain2[length+1];
    for(int i=0;i<length;i=i+2)
    {
        int row1,col1;
        int row2,col2;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(cipher2[i]==key[j][k])
                {
                    row1=j;
                    col1=k;
                }
                if(cipher2[i+1]==key[j][k])
                {
                    row2=j;
                    col2=k;
                }
            }
        }
        if(row1==row2)
        {
            plain2[i]=key[row1][(col1-1+5)%5];
            plain2[i+1]=key[row2][(col2-1+5)%5];
            continue;
        }
        else if(col1==col2)
        {
            plain2[i]=key[(row1-1+5)%5][col1];
            plain2[i+1]=key[(row2-1+5)%5][col2];
            continue;
        }
        else
        {
            plain2[i]=key[row1][col2];
            plain2[i+1]=key[row2][col1];
        }
    }
    plain2[length]='\0';
    for(int i=1;i<length;i++)
    {
        if(plain2[i]=='x')
        {
            if(plain2[i-1]==plain2[i+1])
            {
                for(int j=i;j<length;j++)
                    plain2[j]=plain2[j+1];
                length--;
            }
        }
    }
    if(plain2[length-1]=='x')
        plain2[length-1]='\0';
    cout<<"Decrypted text is : " <<plain2;
    return 0;
}
