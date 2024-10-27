#include "threads/thread.h"
//#include <stdio.h>
#include <stdint.h>

#define F (1 << 14) //16384

typedef int FixedP;


FixedP convToFixed(int num);

int convToInt(FixedP f);

int roundConvToInt(FixedP f);

// a+b
FixedP fixedAdd(FixedP a, FixedP b);

// a-b;
FixedP fixedSub(FixedP a, FixedP b);

// fixed point plus int, a+b
FixedP fixedAddInt(FixedP a, int b);

// fixed oint subtrct int, a-b
FixedP fixedSubInt(FixedP a, int b);

// Fixed point multiplication, a*b
FixedP fixedMull (FixedP a, FixedP b);

// Fixed point division, a/b
FixedP fixedDiv (FixedP a, FixedP b);

// Fixed devided by int, a/b
FixedP fixedDivInt (FixedP a, int b);

// Fixed mutilplied by int, a*b
FixedP fixedMulInt (FixedP a, int b);
