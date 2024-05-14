#ifndef FT_PING_H_
#define FT_PING_H_
#pragma once

#include <arpa/inet.h>
#include <stdbool.h>

typedef uint64_t t_host_time;

/*
** The list of hosts that will be processed with its corresponding packet list
*/
typedef struct s_host {
  char const *host;
  in_addr_t ip;
  uint32_t transmitted;
  uint32_t received;
  t_host_time first_timestamp;
  t_host_time last_timestamp;
  t_host_time total_time_micro;
  t_host_time squared_total_time_micro;
  t_host_time min_time_micro;
  t_host_time max_time_micro;
  struct s_host *next;
} t_host;

/*
** Loaded settings for the ping execution
** All the fields are uint64_t as the socket will validate the correct range
*/
typedef struct s_settings {
  uint16_t flags;
  uint64_t count;
  uint64_t interval;
  uint64_t ttl;
  uint64_t tos;
  bool verbose;
  uint64_t timeout;
  uint64_t linger;
  bool flood;
  uint64_t preload;
  char *pattern;
} t_settings;

typedef struct s_ft_ping {
  t_settings settings;
  t_host *hosts;
} t_ft_ping;

void remove_all_hosts(void);
void add_host(char const *host);
void print_host_stats(t_host const *const host);
void main_loop(void);

#endif // !FT_PING_H_
