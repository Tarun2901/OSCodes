#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
 
int main()
{
        	int n,fd;
        	char buff[200];
 
        	// read()
        	printf("Enter text to write in the file: ");
        	n = read(0, buff, 50);
 
    // open()
        	fd = open("file.txt",O_CREAT | O_RDWR, 0777);
 
        	// write()
        	write(fd, buff, n);
 
        	// close();
        	close(fd);
 
// append()
printf("Enter text to append: ");
n = read(0, buff, 50);
fd = open("file.txt", O_RDWR | O_APPEND);
write(fd, buff, 50);
close(fd);
        	return 0;
}
