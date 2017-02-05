#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

const char* secret = "INFORMATIONISTHERESOLUTIONOFUNCERTAINTY";

bool check_secret(char *provided) {
    size_t secret_len = strlen(secret);
    size_t provided_len = strlen(provided);

    for (size_t i=0; i < secret_len; i++) {
        if (i >= provided_len) {
            return false;
        }

        char s = secret[i];
        char p = provided[i];

        if (s != p) {
            return false;
        }

        usleep(100);
    }

    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./server secret\n");
        return 1;
    }

    if (check_secret(argv[1])) {
        printf("You know the secret!\n");
        return 0;
    } else {
        printf("Sorry, try again\n");
        return 1;
    }
}
