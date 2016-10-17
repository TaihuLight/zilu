#include "iif.h"
#include <iostream>
using namespace iif;

int loopFunction(int _reserved_input_[]) {
int i = _reserved_input_[0];

iif_assume( i < 10 && i > -10);
while( i * i < 100)
{
recordi(i);
 i = i + 1;
}
recordi(i);
iif_assert( i == 10);
return 0;
}

int main(int argc, char** argv)
 {
iifContext context("/home/parallels/Research/GitHub/ZILU/tmp/zilu_poly3.var", loopFunction, "loopFunction", "/home/parallels/Research/GitHub/ZILU/tmp/zilu_poly3.ds");
context.addLearner("poly");
return context.learn("/home/parallels/Research/GitHub/ZILU/tmp/zilu_poly3.cnt", "/home/parallels/Research/GitHub/ZILU/tmp/zilu_poly3");
}