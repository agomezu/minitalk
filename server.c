#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig)
{
    static char character = 0;
    static int bits_received = 0;

    character |= (sig == SIGUSR2) << bits_received;
    bits_received++;
    if (bits_received == 8) {
        if (character == '\0')
            write(1, "\n", 1);
        else
            write(1, &character, 1);
        character = 0;
        bits_received = 0;
    }
}

int main(void)
{
    printf("Server running with PID: %d\n", getpid());

    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    while (1)
        pause();

    return 0;
}

