#include "utils.h"
#include "ft_ping.h"
#include <argp.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

uint16_t compute_checksum(void const *bytes, size_t const number) {
  uint16_t const *words = bytes;

  uint32_t checksum;
  uint16_t current_word;

  checksum = 0;
  for (size_t i = 0; i < number / 2; i++) {
    current_word = *(words + i);
#ifndef __BIG_ENDIAN
    current_word = ((current_word & 0xFF) << 8) | ((current_word >> 8) & 0xFF);
#endif
    checksum += current_word;
  }
  while (checksum > 0xffff)
    checksum = (checksum & 0xffff) + (checksum >> 16);
  return ~checksum;
}

bool is_valid_checksum(void const *bytes, size_t const number) {
  return compute_checksum(bytes, number) == 0x0;
}

t_host_time get_time_micro(void) {
  struct timeval now;

  gettimeofday(&now, NULL);
  return now.tv_sec * 1000000 + now.tv_usec;
}

t_host_time get_timeval_micro(struct timeval time) {
  return time.tv_sec * 1000000 + time.tv_usec;
}

void terminate(int status_code, char *message) {
  remove_all_hosts();
  if (message)
    puts(message);
  exit(status_code);
}
