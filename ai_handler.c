// ai_handler.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ai_handler.h"

void get_ai_response(const char *prompt, char *response_buffer, int buffer_size) {
    // Construct shell command to run ai_helper.py
    char command[1024];
    snprintf(command, sizeof(command),
             "python3 ai_helper.py \"%s\" 2>/dev/null", prompt);

    // Open pipe to read Python script output
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        snprintf(response_buffer, buffer_size, "Error: Failed to run ai_helper.py.");
        return;
    }

    // Read the response into buffer
    char line[256];
    response_buffer[0] = '\0'; // Clear buffer

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strlen(response_buffer) + strlen(line) < buffer_size - 1) {
            strcat(response_buffer, line);
        } else {
            break;  // Prevent overflow
        }
    }

    pclose(fp);
}
