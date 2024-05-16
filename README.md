<div align='center'>

# ft_ping
#### Network diagnostic tool to check connectivity and measure response time.

[Foreword](#foreword) ~
[How to use it](#how-to-use-it)

</div>

## Foreword
This implementation of one of the most famous command line programs was done as
part of my specialisation and may contain minor bugs.

This implementation is based on the `inetutils-ping` utility, instead of
perchance the more adopted `iputils-ping`.

The biggest advantage of this implementation over `inetutil`'s is a more precise
round-trip-time calculation and a huge output speed, sometimes needed for a
precise stddev calculation. It also emits packets prioritising the interval over
the reception of one before sending the next one, which means that even when
a TTL problem or unreachable host exists, the debugging and the packet loss will
be quicker calculated (at the cost of the minimal precision that emitting packets
procedurally).

The calculated output over one second on `--flood` (or `--interval 0` as they are
equivalent) is 1800 packets per second.

```bash
$ ./ft_ping -w 5 --flood google.com
PING google.com (142.250.185.14): 44 data bytes
64 bytes from 142.250.185.14: icmp_seq=0 ttl=119 time=42.194ms
64 bytes from 142.250.185.14: icmp_seq=1 ttl=119 time=43.958ms
64 bytes from 142.250.185.14: icmp_seq=2 ttl=119 time=45.452ms
64 bytes from 142.250.185.14: icmp_seq=3 ttl=119 time=47.483ms
64 bytes from 142.250.185.14: icmp_seq=4 ttl=119 time=47.985ms
\[...\]
64 bytes from 142.250.185.14: icmp_seq=8938 ttl=119 time=44.431ms
64 bytes from 142.250.185.14: icmp_seq=8939 ttl=119 time=44.004ms
64 bytes from 142.250.185.14: icmp_seq=8940 ttl=119 time=43.720ms
64 bytes from 142.250.185.14: icmp_seq=8941 ttl=119 time=43.466ms
--- google.com ping statistics ---
9026 packets transmitted, 8942 packets received, 0% packet loss
round-trip min/avg/max/stddev = 15.686/28.577/67.269/9.460 ms
```

## How to use it
> `ft_ping` has been tested on Linux x86-64 Debian 12 with the compiler `gcc (Debian 12.2.0-14) 12.2.0`.

To use it, simply clone the repository and execute `make`. A binary `./ft_ping` should be generated.
A comprehensive list of the usage instructions can be found by using `./ft_ping --help`.
