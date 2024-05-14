#include "ft_ping.h"
#include "parser.h"
#include "utils.h"
#include <signal.h>

t_ft_ping ping;
bool terminate_received;

void handle_sigint(int signal) {
  if (signal != SIGINT)
    return;
  terminate_received = true;
}

int main(int argc, char **argv) {
  if (signal(SIGINT, handle_sigint) == SIG_ERR)
    terminate(1, "ft_ping: error whilst registering signals...");
  load_arguments(argc, argv);
  main_loop();
  terminate(0, NULL);
}
