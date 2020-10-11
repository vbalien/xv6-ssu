#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
  int pid = get_max_pid();
  printf(0, "Maximum PID: %d\n", pid);
  exit();
}
