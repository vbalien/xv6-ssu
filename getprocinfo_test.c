#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "processInfo.h"

int number_of_digits(int n)
{
  int count = 0;

  if (n == 0) return 1;
  while(n != 0)
  {
    n = n/10;
    ++count;
  }
  return count;
}

void print_pad(int n, int pad)
{
  int start;
  printf(0, "%d", n);
  for (start = number_of_digits(n);start < pad;++start)
    printf(0, " ");
}

int main(void)
{
  int maxpid = get_max_pid();
  int pid;
  struct processInfo info;

  printf(0, "PID     PPID    SIZE    Number of Context Switch\n");
  for (pid=1;pid<=maxpid;++pid) {
    if (get_proc_info(pid, &info) < 0)
      continue;
    print_pad(pid, 8);
    print_pad(info.ppid, 8);
    print_pad(info.psize, 8);
    print_pad(info.numberContextSwitches, 8);
    printf(0, "\n");
  }
  exit();
}
