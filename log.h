#ifndef SCR_LOGGER_LOG_H
#define SCR_LOGGER_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdatomic.h>
#include <pthread.h>

enum log_level_t {MIN = 1, STANDARD, MAX};

#define LOG_FILENAME "application.log"

volatile static sig_atomic_t flag_signo_1 = 0;
volatile static sig_atomic_t flag_signo_2 = 0;
volatile static sig_atomic_t flag_signo_3 = 0;

volatile static sig_atomic_t logger_enabled = 1;
volatile static sig_atomic_t logger_severity_lvl = MIN;

static pthread_mutex_t logger_file_mutex;
static pthread_mutex_t logger_dump_file_mutex;

atomic_int sig_ch;

void handler_signo_1(int signo, siginfo_t *info, void *other);

void handler_signo_2(int signo, siginfo_t *info, void *other);

void handler_signo_3(int signo, siginfo_t *info, void *other);

void dump_state_handler();

void* log_loop(void* arg);

void log_message(enum log_level_t message_level, char *message);

void log_enable_handler();

int set_log(unsigned int sv, const char *s);

void log_level_handler();

int init_logger();

void close_logger();

#endif //SCR_LOGGER_LOG_H
