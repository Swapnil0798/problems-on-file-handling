#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
// 0777
//Read:4
//Write:2
//Execute:1    0     7      7    7
//permision: octal_owner_group_other

int main()
{
  char Fname[20];
  char Data[100];
  int iret=0;

  int fd=0;     // file descripter

  printf("Enter file name: ");
  scanf("%s",Fname);

 printf("Enter the data that we want to write\n");
 scanf(" %[^'\n']s",Data);
  fd=creat(Fname,0777);
  
  if(fd==-1)
   {
     printf("Unable to create a file\n");
     return -1; //failure
   }

    printf("File is succesfully created FD %d\n",fd);

    iret=write(fd,Data,strlen(Data));

    printf("%d bytes succefully return in the file \n",iret);
   
    return 0;
  
}