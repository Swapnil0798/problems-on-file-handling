#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

//write the data;
int main()
{
  char Fname[20];
  char Data[10];
  
  int iret=0;
  int fd=0;     // file descripter

  printf("Enter file name open to: ");
  scanf("%s",Fname);

  fd=open(Fname,O_RDWR );
  
  if(fd==-1)
   {
     printf("Unable to opened a file\n");
     return -1; //failure
   }

    printf("File is succesfully opened with FD %d\n",fd);
     
     while((iret=read(fd,Data,sizeof(Data))) != 0)
     {
       write(1,Data,iret);
     }
    close(fd);
    return 0;
  
}
