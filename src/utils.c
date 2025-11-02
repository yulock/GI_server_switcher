#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define CONFIG_NAME "config.ini"
#define BACKUP_NAME "config.bak"
#define TEMP_NAME "config.tmp"

FILE *in, *out;
char ch;

void backup() {
    if ((in = fopen(CONFIG_NAME, "r")) == NULL) {
        fprintf(stderr, "Error: Could not open config.ini for reading.");
        return;
    }
    if ((out = fopen(BACKUP_NAME, "w")) == NULL) {
        fprintf(stderr, "Error: Could not open config.bak for writing.");
        fclose(in);
        return;
    }
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }
    if (fclose(in) != 0 || fclose(out) != 0) {
        fprintf(stderr, "Error: Could not close files properly.");
        return;
    }
    puts("Backup completed successfully.");
}

void restore() {
    if ((in = fopen(BACKUP_NAME, "r")) == NULL) {
        fprintf(stderr, "Error: Could not open config.bak for reading.");
        return;
    }
    if ((out = fopen(CONFIG_NAME, "w")) == NULL) {
        fprintf(stderr, "Error: Could not open config.ini for writing.");
        fclose(in);
        return;
    }
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }
    if (fclose(in) != 0 || fclose(out) != 0) {
        fprintf(stderr, "Error: Could not close files properly.");
        return;
    }

    puts("Restore completed successfully.");
}

void sw2OffiS() {
    char line[256];
    if ((in = fopen(CONFIG_NAME, "r")) == NULL) {
        fprintf(stderr, "Error: Could not open config.ini for reading.");
        return;
    }
    if ((out = fopen(TEMP_NAME, "w")) == NULL) {
        fprintf(stderr, "Error: Could not open temp.ini for writing.");
        fclose(in);
        return;
    }

    while (fgets(line, sizeof(line), in) != NULL) {
        if (strncmp(line, "game_biz=", 9) == 0) {
            fprintf(out, "game_biz=hk4e_cn\n");
        } 
        else if (strncmp(line, "channel=", 8) == 0) {
            fprintf(out, "channel=1\n");
        } 
        else {
            fputs(line, out);
        }
    }

    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error: Could not close files properly.");
        return;
    }

    if (remove(CONFIG_NAME) != 0 || rename(TEMP_NAME, CONFIG_NAME) != 0) {
        fprintf(stderr, "Error: Could not replace config.ini with updated version.");
        return;
    }

    puts("Switched to official server successfully.");
}

void sw2BiliS() {
    char line[256];
    if ((in = fopen(CONFIG_NAME, "r")) == NULL) {
        fprintf(stderr, "Error: Could not open config.ini for reading.");
        return;
    }
    if ((out = fopen(TEMP_NAME, "w")) == NULL) {
        fprintf(stderr, "Error: Could not open temp.ini for writing.");
        fclose(in);
        return;
    }

    while (fgets(line, sizeof(line), in) != NULL) {
        if (strncmp(line, "game_biz=", 9) == 0) {
            fprintf(out, "game_biz=hk4e_bilibili\n");
        } 
        else if (strncmp(line, "channel=", 8) == 0) {
            fprintf(out, "channel=14\n");
        } 
        else {
            fputs(line, out);
        }
    }

    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error: Could not close files properly.");
        return;
    }

    if (remove(CONFIG_NAME) != 0 || rename(TEMP_NAME, CONFIG_NAME) != 0) {
        fprintf(stderr, "Error: Could not replace config.ini with updated version.");
        return;
    }

    puts("Switched to bilibili server successfully.");
}

void exitProgram() {
    puts("Exiting...");
    exit(0);
}