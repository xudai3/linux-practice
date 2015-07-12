#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>

#define SHOWHOST

void showtime(long);
void show_info(struct utmp *);

int main()
{
    struct utmp current_record;
    int    utmpfd;
    int    reclen = sizeof(current_record);

    if((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1)
    {
        perror(UTMP_FILE);
        exit(1);
    }

    while(read(utmpfd, &current_record, reclen) == reclen)
        show_info(&current_record);
    
    close(utmpfd);

    return 0;
}

void show_info(struct utmp *utbufp)
{
    if(utbufp->ut_type != USER_PROCESS)
        return;

    printf("%-8.8s", utbufp->ut_name);
    printf(" ");
    printf("%-8.8s", utbufp->ut_line);
    printf(" ");
    showtime(utbufp->ut_time);

#ifdef SHOWHOST
    printf("(%s)", utbufp->ut_host);
#endif
    printf("\n");
}

void showtime(long timeval)
{
    char *cp;
    struct tm *ptmNow = localtime(&timeval);
    cp = ctime(&timeval);
    char ctmnow[128] = {0};
    strftime(ctmnow, sizeof(ctmnow), "%Y-%m-%d %H:%M:%S", ptmNow);
    printf("%16.16s", ctmnow);
}
