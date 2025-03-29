// Vibe coded with github copilot
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void printFileSize(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            DIR *dir = opendir(path);
            if (dir != NULL) {
                struct dirent *entry;
                while ((entry = readdir(dir)) != NULL) {
                    if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                        char subPath[1024];
                        snprintf(subPath, sizeof(subPath), "%s/%s", path, entry->d_name);
                        printFileSize(subPath);
                    }
                }
                closedir(dir);
            }
        } else if (S_ISREG(st.st_mode)) {
            printf("%s - %lld %s - %o\n", path, st.st_size, st.st_size < 1024 ? "B" : st.st_size < 1048576 ? "KB" : st.st_size < 1073741824 ? "MB" : "GB", st.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    const char *directory = argv[1];
    printFileSize(directory);

    return 0;
}

