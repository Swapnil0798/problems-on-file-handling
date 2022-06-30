//accept file name and 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void displaydata(char Fname[])
{
    int fd=0;
    
    char Data[10];
    int iret=0;

    fd=open(Fname,O_RDWR );
  
   if(fd==-1)
   {
     printf("Unable to opened a file\n");
     return ; //failure
   }

    printf("File is succesfully opened with FD %d\n",fd);
     
     while((iret=read(fd,Data,sizeof(Data))) != 0)
     {
       write(1,Data,iret);
     }
    close(fd);
}
//write the data;
int main()
{
  char Fname[20];
       // file descripter

  printf("Enter file name open to: ");
  scanf("%s",Fname);

  displaydata(Fname);
  
    return 0;
  
}
