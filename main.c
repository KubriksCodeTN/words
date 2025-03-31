#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>

int main(void) {
    srand(time(0));

    int32_t i = 0;

    while (4) {
        for (uint32_t j = 0; j < 20; ++j){
            printf("\033[%i;3%im%c", rand() % 2, rand() % 8, (rand() % ('z' - 'a' + 1)) + 'a');
            fflush(stdout);
            usleep(100000 >> 1);
            printf("\b");
        }
        printf("\033[0;3%im%c", rand() % 8, (rand() % ('z' - 'a' + 1)) + 'a');
        fflush(stdout);
    }
}
