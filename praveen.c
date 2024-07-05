#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256  // Maximum length of a line to read

void grep(FILE *file, const char *pattern) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, pattern)) {
            printf("%s", line);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <pattern> <file>\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[1];
    const char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    grep(file, pattern);

    fclose(file);
    return 0;
}

