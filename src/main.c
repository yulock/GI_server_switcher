#include <stdio.h>
#include <stdlib.h>
#include "banner.h"
#include "utils.h"

int main(int argc, char * argv[]) {
    int choice;
    printBanner();
    printOption();

    
    while (1) {
        printf("Input your option: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                backup();
                break;
            case 2:
                restore();
                break;
            case 3:
                sw2OffiS();
                break;
            case 4:
                sw2BiliS();
                break;
            case 5:
                exitProgram();
            default:
                puts("Invalid option. Please try again.");
                break;
            }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

        return 0;
}