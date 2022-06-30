#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

//open the file and write the data into the file
int main()
{
  char Fname[20];
  char Data[100];
  
  int iret=0;
  int fd=0;     // file descripter

  printf("Enter file name to: ");
  scanf("%s",Fname);

  fd=open(Fname,O_RDWR);
  
  if(fd==-1)
   {
     printf("Unable to opened a file\n");
     return -1; //failure
   }

    printf("File is succesfully opened with FD %d\n",fd);

    printf("Enter the data that we want to write:\n");
    scanf(" %[^'/n']s",Data);
    
    iret=write(fd,Data,strlen(Data));

    printf("%d byetes gets succefully return in the file",iret);

   
    return 0;
  
}