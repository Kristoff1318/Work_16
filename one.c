#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

int count_caps(char * line) {
    char *place = line;
    int c = 0;

    while(*place != '\0') {
        if (*place >= 'A' && *place <= 'Z') c++;
        place++;
    }
    return c;
}

int main() {
    char line[256];
    int output;


    mkfifo("send_to_processor", 0644);
    mkfifo("receive_from_processor", 0644);

    while(1) {
        int pcon;

        pcon = open("send_to_processor", O_RDONLY);
        read(pcon, line, 256);
        close(pcon);

        output = count_caps(line);

        pcon = open("receive_from_processor", O_WRONLY);
        write(pcon, &output, sizeof(output));
        close(pcon);
    }

    return 0;
}
