#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void send_character(int pid, char character)
{
    for (int i = 0; i < 8; i++) {
        int bit = (character >> i) & 1;
        if (bit == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        write(2, "Usage: ./client <PID> <message>\n", 32);
        return 1;
    }
    int pid = atoi(argv[1]);
    char *message = argv[2];

    for (int i = 0; message[i]; i++)
        send_character(pid, message[i]);
    send_character(pid, '\0');

    return 0;
}

