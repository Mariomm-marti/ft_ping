#ifndef UTILS_H_
#define UTILS_H_
#pragma once

#include "ft_ping.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

uint16_t compute_checksum(void const *bytes, size_t const number);
bool is_valid_checksum(void const *bytes, size_t const number);
t_host_time get_time_micro(void);
t_host_time get_timeval_micro(struct timeval time);
void terminate(int status_code, char *message);

#endif // !UTILS_H_
