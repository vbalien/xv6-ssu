#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
  int pcount = get_num_proc(&pcount);
  printf(0, "Total Number of Active Processes: %d\n", pcount);
  exit();
}
