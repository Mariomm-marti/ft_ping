#include "icmp.h"
#include "utils.h"
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

uint16_t icmp_get_id(void) { return getpid(); }

uint8_t *icmp_bytes(t_icmp icmp, uint8_t const *data, uint16_t *datalen) {
  uint8_t *bytes;
  uint16_t total_size;

  total_size = sizeof(icmp);
  if (datalen)
    total_size += *datalen;
  if (!(bytes = malloc(total_size)))
    terminate(1, "ft_ping: malloc failed");

  icmp.checksum = 0;
  icmp.sequence = htons(icmp.sequence);
  icmp.identifier = htons(icmp.identifier);
  icmp.time.tv_sec = htonl(icmp.time.tv_sec);
  icmp.time.tv_usec = htonl(icmp.time.tv_usec);

  memcpy(bytes, &icmp, sizeof(icmp));
  if (data && datalen)
    memcpy(bytes + sizeof(icmp), data, *datalen);
  if (datalen)
    *datalen = total_size;

  icmp.checksum = compute_checksum(bytes, total_size);
  memcpy(bytes, &icmp, sizeof(icmp));

  return bytes;
}

int icmp_from_bytes(t_icmp *icmp, uint8_t const *const bytes) {
  uint16_t const total_length = ntohs(*(uint16_t *)(bytes + 2));
  uint8_t const ip_header_length = *bytes & 0xf;

  if (!is_valid_checksum(bytes, total_length))
    return 1;
  // Shallow copying is the most efficient way of implementing it
  *icmp = *(t_icmp *)(bytes + WORDS_TO_BYTES(ip_header_length));
  icmp->sequence = ntohs(icmp->sequence);
  icmp->identifier = ntohs(icmp->identifier);
  icmp->time.tv_sec = ntohl(icmp->time.tv_sec);
  icmp->time.tv_usec = ntohl(icmp->time.tv_usec);
  return 0;
}

uint8_t icmp_ttl_from_bytes(uint8_t const *const bytes) {
  // 8 bytes into the packet (IP header) is the TTL
  return *(bytes + 8);
}

struct in_addr icmp_src_addr_from_bytes(uint8_t const *const bytes) {
  // 12 bytes into the packet is the source address
  return *(struct in_addr *)(bytes + 12);
}
