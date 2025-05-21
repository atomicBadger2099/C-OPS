// Compile with: gcc -std=gnu99 open_url.c -o open_url

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char url[256];       // Buffer for user input
    char command[512];   // Buffer for system command

    printf("Enter a URL to open in Firefox: ");
    if (fgets(url, sizeof(url), stdin) == NULL) {
        fprintf(stderr, "Error reading URL input.\n");
        return 1;
    }

    // Remove trailing newline from URL
    size_t len = strlen(url);
    if (len > 0 && url[len - 1] == '\n') {
        url[len - 1] = '\0';
    }

    // Format the shell command with stderr suppressed
    int written = snprintf(command, sizeof(command), "firefox '%s' 2>/dev/null &", url);
    if (written < 0 || (size_t)written >= sizeof(command)) {
        fprintf(stderr, "Error: URL too long or formatting failed.\n");
        return 1;
    }

    // Execute the system command
    int ret = system(command);
    if (ret == -1) {
        perror("Error executing system command");
        return 1;
    } else if (WIFEXITED(ret) && WEXITSTATUS(ret) != 0) {
        fprintf(stderr, "Firefox command failed with exit status %d\n", WEXITSTATUS(ret));
        return 1;
    }

    printf("Firefox launched with URL: %s\n", url);
    return 0;
}
