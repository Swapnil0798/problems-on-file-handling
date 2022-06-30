#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

// O_RDONLY read
//O_WRONLY write
//O_RDWR  READ+WRITE
int main()
{
  char Fname[20];
 
  int fd=0;     // file descripter

  printf("Enter file name to: ");
  scanf("%s",Fname);

  fd=open(Fname,O_RDONLY);
  
  if(fd==-1)
   {
     printf("Unable to opened a file\n");
     return -1; //failure
   }

    printf("File is succesfully opened FD %d\n",fd);

   
    return 0;
  
}