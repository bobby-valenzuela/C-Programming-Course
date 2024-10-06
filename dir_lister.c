#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    // Cast pointers to dirent pointers
    const struct dirent *entryA = *(const struct dirent **)a;
    const struct dirent *entryB = *(const struct dirent **)b;
    return strcmp(entryA->d_name, entryB->d_name);
}

int main(int argc, char *argv[]) {
 
  int debug = 0;

  if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    const char *dirPath = argv[1];
    
    if ( debug) printf("[DEBUG] argv[1]: %s\n", dirPath);

    DIR *dir = opendir(dirPath);

    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    struct dirent *entry;
    struct dirent **entries = NULL;
    int count = 0;
    int capacity = 10;

    // Allocate initial memory for entries
    entries = malloc(capacity * sizeof(struct dirent *));
    if (entries == NULL) {
        perror("Unable to allocate memory");
        closedir(dir);
        return 1;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Reallocate memory if needed
        if (count >= capacity) {
            capacity *= 2;
            entries = realloc(entries, capacity * sizeof(struct dirent *));
            if (entries == NULL) {
                perror("Unable to reallocate memory");
                closedir(dir);
                return 1;
            }
        }
        // Allocate memory for the new entry and copy it
        entries[count] = malloc(sizeof(struct dirent) + strlen(entry->d_name) + 1);
        if (entries[count] == NULL) {
            perror("Unable to allocate memory for entry");
            closedir(dir);
            return 1;
        }
        memcpy(entries[count], entry, sizeof(struct dirent) + strlen(entry->d_name) + 1);
        count++;
    }

    closedir(dir);

    // Sort the entries alphabetically
    qsort(entries, count, sizeof(struct dirent *), compare);

    // Print the sorted entries
    printf("Contents of directory: %s\n", dirPath);
    for (int i = 0; i < count; i++) {
        printf("%s\n", entries[i]->d_name);
        free(entries[i]); // Free memory allocated for each entry
    }

    free(entries); // Free the array of pointers

    return 0;
}
