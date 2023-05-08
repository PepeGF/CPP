#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    char* folder_prefix = "CPP";
    char folder_name[10];
    char path[20];
    int i;

    for (i = 1; i <= 9; i++) {
        sprintf(folder_name, "%s%02d", folder_prefix, i);
        sprintf(path, "./%s", folder_name);
        if (mkdir(path, 0777) == -1) {
            fprintf(stderr, "Error: no se pudo crear la carpeta %s\n", folder_name);
            exit(1);
        } else {
            printf("Carpeta creada: %s\n", folder_name);
        }
    }

    return 0;
}
