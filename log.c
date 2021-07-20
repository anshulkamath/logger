#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include "log.h"

void print_var(const char* file, int line, const char* status, const char* fmt, ...) {
    time_t rawtime;
    time(&rawtime);
    struct tm* timeinfo = gmtime(&rawtime);
    
    int hours = timeinfo->tm_hour;
    int mins = timeinfo->tm_min;
    int secs = timeinfo->tm_sec;

    printf("%s[%02d:%02d:%02d] %s:%d %s", status, hours, mins, secs, file, line, RESET);
    
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

log_t initialize_struct() {
    if (global_logger.initialized) {
        return global_logger;
    }

    global_logger.initialized = 1;
    global_logger.log_info = print_var;
    global_logger.log_warn = print_var;
    global_logger.log_error = print_var;

    return global_logger;
}
