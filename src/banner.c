#include <stdio.h>
#include "banner.h"

void printBanner() {
    puts("===========================================");
    puts("|            GI server switcher           |");
    puts("|              Simple version             |");
    puts("===========================================");
}

void printOption() {
    puts("|         Enter the serial num            |");
    puts("|          1. backup                      |");
    puts("|          2. restore                     |");
    puts("|          3. Switch to official server   |");
    puts("|          4. Switch to bilibili server   |");
    puts("|          5. exit                        |");
    puts("===========================================");
}
