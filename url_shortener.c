#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 200
#define SHORT_URL_LENGTH 10

typedef struct {
    char long_url[MAX_URL_LENGTH];
    char short_url[SHORT_URL_LENGTH];
} URLMapping;

void generate_short_url(char* long_url, char* short_url) {
    // Generate a short URL based on the long URL (implementation logic here)
    // You can use hash functions or other algorithms to generate a unique short URL
    // For simplicity, this example uses a random string for demonstration purposes
    strcpy(short_url, "abc123");
}

void redirect_to_original_url(char* short_url, URLMapping* mappings, int num_mappings) {
    int i;
    for (i = 0; i < num_mappings; i++) {
        if (strcmp(short_url, mappings[i].short_url) == 0) {
            printf("Redirecting to the original URL: %s\n", mappings[i].long_url);
            return;
        }
    }
    printf("Short URL not found.\n");
}

int main() {
    URLMapping mappings[10]; // Assume a fixed number of URL mappings

    int num_mappings = 0;
    char long_url[MAX_URL_LENGTH];

    while (1) {
        printf("\n--- URL Shortening Program ---\n");
        printf("1. Generate Short URL\n");
        printf("2. Redirect Short URL\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from the input buffer

        switch (choice) {
            case 1:
                printf("Enter the long URL: ");
                fgets(long_url, sizeof(long_url), stdin);
                long_url[strcspn(long_url, "\n")] = '\0'; // Remove trailing newline character

                if (num_mappings < sizeof(mappings) / sizeof(mappings[0])) {
                    URLMapping mapping;
                    strcpy(mapping.long_url, long_url);
                    generate_short_url(long_url, mapping.short_url);
                    mappings[num_mappings++] = mapping;
                    printf("Short URL generated: %s\n", mapping.short_url);
                } else {
                    printf("Maximum number of URL mappings reached.\n");
                }
                break;

            case 2:
                if (num_mappings > 0) {
                    char short_url[SHORT_URL_LENGTH];
                    printf("Enter the short URL: ");
                    fgets(short_url, sizeof(short_url), stdin);
                    short_url[strcspn(short_url, "\n")] = '\0'; // Remove trailing newline character

                    redirect_to_original_url(short_url, mappings, num_mappings);
                } else {
                    printf("No URL mappings found.\n");
                }
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
