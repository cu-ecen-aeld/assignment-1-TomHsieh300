#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    openlog(NULL, 0, LOG_USER);
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments %d\n", argc);

        return 1;
    } else {
        int fd;

        char *dictionary = argv[1];
        char *write_string = argv[2];
        ssize_t size = strlen(write_string);
   
        fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd == -1) {
            syslog(LOG_ERR, "%s\n", strerror(errno));
            return 1;
        } else {
            syslog(LOG_DEBUG, "Writing %s to %s\n", write_string, dictionary);
            write(fd, write_string, size);
            close(fd);
            return 0;

        }

    }

    return 0;
}
