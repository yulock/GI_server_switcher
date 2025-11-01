#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int ch;
    FILE *fp1;
    unsigned long count = 0;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("Can not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }


    while ((ch = getc(fp1)) != EOF) {
        putc(ch, stdout);
        count ++;
    }

    fclose(fp1);
    printf("File %s has %lu characters\n", argv[1], count);

    return 0;
}