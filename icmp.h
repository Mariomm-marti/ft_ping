#ifndef ICMP_H_
#define ICMP_H_
#include <netinet/in.h>
#pragma once

#include "ft_ping.h"
#include <netdb.h>
#include <sys/time.h>

#define WORDS_TO_BYTES(words) (words * 4)
#define DATA_SIZE 20
#define FULL_DATA_SIZE DATA_SIZE + (int)sizeof(struct s_icmp)
#define ICMP_ECHO 8
#define ICMP_ECHO_REPLY 0
#define ICMP_NOT_REACHABLE 3
#define ICMP_TTL_EXCEED 11

typedef struct __attribute__((__packed__)) s_icmp {
  uint8_t type;
  uint8_t code;
  uint16_t checksum;
  uint16_t identifier;
  uint16_t sequence;
  struct timeval time;
} t_icmp;

/*
 * ID for the ICMP packets
 */
uint16_t icmp_get_id(void);

/*
 * Converts _icmp_ and _data_ to a byte array with the correct fields in
 * network format. Whilst the return value is the byte array, the resulting
 * size of the operation will be placed in _datalen_ if not NULL.
 *
 * When _datalen_ is not NULL but _data_ is, or the sizes do not match, the
 * behaviour is undefined.
 */
uint8_t *icmp_bytes(t_icmp icmp, uint8_t const *data, uint16_t *datalen);

/*
 * Converts a sequence of _bytes_ of length _len_ to a t_icmp. A verify
 * of the checksum is done and, if failed, returns 1.
 *
 * The _bytes_ are assumed to be received from a raw socket, so an initial
 * IP header is expected, which will be used to understand the structure
 * of the received information.
 *
 * All fields will be automatically converted to host format and network
 * format will be assumed.
 */
int icmp_from_bytes(t_icmp *icmp, uint8_t const *const bytes);

/*
 * Extracts from a sequence of _bytes_ the TTL.
 *
 * The _bytes_ are assumed to be received from a raw socket, so an initial
 * IP header is expected, which will be used to extract the TTL.
 */
uint8_t icmp_ttl_from_bytes(uint8_t const *const bytes);

/*
 * Extracts from a sequence of _bytes_ the timestamp in t_host_time format.
 *
 * The _bytes_ are assumed to be received from a raw socket, so an initial
 * IP header is expected, which will be used to extract the timestamp.
 */
t_host_time icmp_timestamp_from_bytes(uint8_t const *const bytes);

/*
 * Extracts from a sequence of _bytes_ the source address.
 *
 * The _bytes_ are assumed to be received from a raw socket, so an initial
 * IP header is expected, which will be used to extract the source addr.
 */
struct in_addr icmp_src_addr_from_bytes(uint8_t const *const bytes);

#endif // !ICMP_H_
