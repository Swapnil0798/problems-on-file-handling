#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

//read the data
int main()
{
  char Fname[20];
  char Data[10];
  
  int iret=0;
  int fd=0;     // file descripter

  printf("Enter file name to: ");
  scanf("%s",Fname);

  fd=open(Fname,O_RDWR | O_APPEND);
  
  if(fd==-1)
   {
     printf("Unable to opened a file\n");
     return -1; //failure
   }

    printf("File is succesfully opened with FD %d\n",fd);

    read(fd,Data,sizeof(Data));
    read(fd,Data,sizeof(Data));
    read(fd,Data,sizeof(Data));

    return 0;
  
}
