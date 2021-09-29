
#include "systemc.h"
#include "simple_bus_test.h"

int sc_main(int, char **)
{
  simple_bus_test top("top");

  sc_start(10000, SC_MS);

  return 0;
}
