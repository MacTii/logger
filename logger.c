#include "log.h"

int main(int argc, char *argv[]) {

    printf("PID: %d\n", getpid());

    if (init_logger(LOG_FILENAME) != 0) {
        return EXIT_FAILURE;
    }

    // application code here
    log_message(STANDARD, "Application started");

    while(1)
    {
        if (set_log(1, "Example message for log severity MIN") == 2) {
            close_logger();
            return EXIT_SUCCESS;
        }
        if (set_log(2, "Example message for log severity STANDARD") == 2)
        {
            close_logger();
            return EXIT_SUCCESS;
        }
        if (set_log(3, "Example message for log severity MAX") == 2) {
            close_logger();
            return EXIT_SUCCESS;
        }
        sleep(3);
    }

    return 0;
}