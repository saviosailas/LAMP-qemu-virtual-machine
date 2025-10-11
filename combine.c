#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024 * 1024  // 1 MB buffer

void combine_chunks(const char *output_filename) {
    FILE *out = fopen(output_filename, "wb");
    if (!out) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(out);
        exit(EXIT_FAILURE);
    }

    int chunk_index = 0;
    while (1) {
        char chunk_name[256];
        snprintf(chunk_name, sizeof(chunk_name), "chunk_%d", chunk_index);

        FILE *chunk = fopen(chunk_name, "rb");
        if (!chunk) {
            // Stop when chunk doesn't exist
            if (chunk_index == 0) {
                fprintf(stderr, "No chunk files found (e.g., chunk_0).\n");
            } else {
                printf("Finished combining %d chunks into '%s'.\n", chunk_index, output_filename);
            }
            break;
        }

        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, chunk)) > 0) {
            fwrite(buffer, 1, bytes_read, out);
        }

        fclose(chunk);
        printf("Merged %s\n", chunk_name);
        chunk_index++;
    }

    free(buffer);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    combine_chunks(argv[1]);
    return EXIT_SUCCESS;
}

