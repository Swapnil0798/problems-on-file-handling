#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int countcapital(char Fname[])
{
    int fd = 0;     // File descriptor
    int iRet = 0;
    char Data[1024];     // Mug
    int iSum = 0;
    int i=0;
    int icnt=0;

    fd = open(Fname,O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;  // Failure
    }

    while((iRet = read(fd,Data,sizeof(Data))) != 0)
    {
        for(i=0;i<iRet;i++)
        {
            if(Data[i]>='A'&& Data[i]<='Z')
            {
              icnt++;
            }
        }
        
    }

    close(fd);
    return icnt;
}

int main()
{
    char Fname[20];
    int iRet = 0;

    printf("Enter file name to open\n");
    scanf("%s",Fname);

    iRet = countcapital(Fname);
    printf("Number of capital character is : %d\n",iRet);

    return 0;
}