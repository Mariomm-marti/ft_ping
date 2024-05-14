#ifndef PARSER_H_
#define PARSER_H_
#pragma once

#define IS_COUNT_SET(x) (x & 0x1)
#define IS_INTERVAL_SET(x) (x & (0x1 << 1))
#define IS_TTL_SET(x) (x & (0x1 << 2))
#define IS_TOS_SET(x) (x & (0x1 << 3))
#define IS_VERBOSE_SET(x) (x & (0x1 << 4))
#define IS_TIMEOUT_SET(x) (x & (0x1 << 5))
#define IS_LINGER_SET(x) (x & (0x1 << 6))
#define IS_FLOOD_SET(x) (x & (0x1 << 7))
#define IS_PRELOAD_SET(x) (x & (0x1 << 8))
#define IS_PATTERN_SET(x) (x & (0x1 << 9))
#define SET_COUNT_FLAG(x) (x | 0x1)
#define SET_INTERVAL_FLAG(x) (x | (0x1 << 1))
#define SET_TTL_FLAG(x) (x | (0x1 << 2))
#define SET_TOS_FLAG(x) (x | (0x1 << 3))
#define SET_VERBOSE_FLAG(x) (x | (0x1 << 4))
#define SET_TIMEOUT_FLAG(x) (x | (0x1 << 5))
#define SET_LINGER_FLAG(x) (x | (0x1 << 6))
#define SET_FLOOD_FLAG(x) (x | (0x1 << 7))
#define SET_PRELOAD_FLAG(x) (x | (0x1 << 8))
#define SET_PATTERN_FLAG(x) (x | (0x1 << 9))

void load_arguments(int argc, char **argv);

#endif // !PARSER_H_
