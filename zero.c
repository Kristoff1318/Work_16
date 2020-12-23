#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    char line[256];
    int output;

    while(1) {
        int pcon;

        printf("Count caps: ");
        fgets(line, 256, stdin);
        pcon = open("send_to_processor", O_WRONLY);
        write(pcon, line, 4*strlen(line));
        close(pcon);

        pcon = open("receive_from_processor", O_RDONLY);
        read(pcon, &output, 256);
        close(pcon);

        printf("%d\n", output);
    }

    return 0;
}
