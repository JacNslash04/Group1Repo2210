#include <stdio.h>
#include <time.h>

int main() {
    printf("This program will time how long you can hold your breath.\n");
    printf("Take a deep breath, then press the 'Enter' key.\n");
    printf("When you absolutely have to exhale, press the 'Enter' key again.\n");

    // Wait for the user to press 'Enter' to start the timer.
    printf("Press 'Enter' to start the timer.");
    getchar(); // Wait for Enter key press.

    time_t start_time = time(NULL);

    printf("Timer started. Hold your breath...\n");

    // Wait for the user to press 'Enter' to stop the timer.
    printf("Press 'Enter' to stop the timer.");
    getchar(); // Wait for Enter key press.

    time_t end_time = time(NULL);
    double duration = difftime(end_time, start_time);

    int minutes = (int)(duration / 60);
    int seconds = (int)(duration) % 60;

    printf("You held your breath for %d minutes and %d seconds!\n", minutes, seconds);

    return 0;
}