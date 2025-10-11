#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE_MB 95
#define CHUNK_SIZE_BYTES (CHUNK_SIZE_MB * 1024 * 1024)

void split_file(const char *filename) {
    FILE *src = fopen(filename, "rb");
    if (!src) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    unsigned char *buffer = (unsigned char *)malloc(CHUNK_SIZE_BYTES);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(src);
        exit(EXIT_FAILURE);
    }

    int chunk_index = 0;
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, CHUNK_SIZE_BYTES, src)) > 0) {
        char chunk_name[256];
        snprintf(chunk_name, sizeof(chunk_name), "chunk_%d", chunk_index);
        
        FILE *chunk = fopen(chunk_name, "wb");
        if (!chunk) {
            perror("Error creating chunk file");
            free(buffer);
            fclose(src);
            exit(EXIT_FAILURE);
        }

        fwrite(buffer, 1, bytes_read, chunk);
        fclose(chunk);
        printf("Created %s (%zu bytes)\n", chunk_name, bytes_read);
        chunk_index++;
    }

    free(buffer);
    fclose(src);
    printf("File splitting complete. %d chunks created.\n", chunk_index);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    split_file(argv[1]);
    return EXIT_SUCCESS;
}

