#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv) {
    srand(time(0));

    if (argc != 2) {
        fprintf(stderr, "word_doer usage: ./word_doer \"str to print\"\n");
        exit(1);
    }

    size_t len = strlen(argv[1]);

    for (size_t i = 0; i < len; ++i) {
        for (uint32_t j = 0; j < 20; ++j){
            printf("\033[%i;3%im%c", rand() % 2, rand() % 8, (rand() % ('z' - 'a' + 1)) + 'a');
            fflush(stdout);
            usleep(100000 >> 1);
            printf("\b");
        }
        printf("\033[0;3%im%c", rand() % 8, argv[1][i]);
        fflush(stdout);
    }
    printf("\n");
}
