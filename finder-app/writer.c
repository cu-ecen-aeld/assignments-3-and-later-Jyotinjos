#include <syslog.h>
#include <errno.h>
#include<stdio.h>

int main(int argc, char* argv[]){

    openlog("writer",LOG_CONS | LOG_PID | LOG_PERROR | LOG_ODELAY, LOG_USER);
    if(argc < 3 )
    {
        fprintf(stderr, "Invalid number of arguments! \nFirst argument is file directory, \nSecond is the write string");
        syslog(LOG_ERR, "INVALID Number of arguments!: %d", argc);
        closelog();
        return 1;
    }    // Body

    const char* writestr = argv[2];
    const char* writefile = argv[1];

    if(!writefile) {
		//print that you need a file
		syslog(LOG_ERR, "Missing a file to write to.\n");
		return 1;
	}
	if(!writestr) {
		//print that you need a string to write
		syslog(LOG_ERR, "Missing a string to write to the file.\n");
		return 1;
	}

    FILE *fWriteFile = fopen(writefile, "w");
    if(fWriteFile == NULL)
    {
        syslog(LOG_ERR, "Error opening the file: %s", writefile);
        closelog();
        return 1;    
    }
    // fprintf(fWriteFile,"%s", writestr);
    int result = fputs(writestr, fWriteFile);
    //error checking
	if(result == EOF) {
		syslog(LOG_ERR, "%m\n");
        closelog();
		return 1;
	}

    fclose(fWriteFile);

    syslog(LOG_DEBUG, "Usage: Write to file: %s is successful", writefile);
    closelog();

    return 0;


}