#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void) {
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(srv, (struct sockaddr *)&addr, sizeof(addr));
    listen(srv, 8);

    char buf[64];
    while (1) {
        int fd = accept(srv, NULL, NULL);
        if (fd < 0) continue;

        recv(fd, buf, 4096, 0);   /* buffer overflow: up to 4096 bytes into 64-byte buf */
        printf("%s\n", buf);
        send(fd, "ok\n", 3, 0);
        close(fd);
    }
    return 0;
}
