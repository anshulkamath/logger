#ifndef LOG_H
#define LOG_H

#define FILE __FILE__
#define LINE __LINE__

#define RESET       "\x1b[0m"
#define INFO        "\x1b[0m"
#define WARNING     "\x1b[33m"
#define ERROR       "\x1b[31m"

#define info(...)  log_info(__FILE__, __LINE__, INFO, __VA_ARGS__)
#define warn(...)  log_warn(__FILE__, __LINE__, WARNING, __VA_ARGS__)
#define error(...) log_error(__FILE__, __LINE__, ERROR, __VA_ARGS__)
#define logger initialize_struct()

typedef void (*logType) (const char*, int, const char*, const char*, ...);

typedef struct logStruct {
    int initialized;
    logType log_info;
    logType log_warn;
    logType log_error;
} log_t;

log_t global_logger;

void print_var(const char* file, int line, const char* status, const char* fmt, ...);
log_t initialize_struct();

#endif