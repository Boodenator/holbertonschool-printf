#include "main.h"

int print_percent(void)
{
    return write(1, "%", 1);
}
