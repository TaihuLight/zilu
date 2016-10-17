#include "iif.h"
#include <iostream>
using namespace iif;

int loopFunction(int _reserved_input_[]) {
int x = _reserved_input_[0];

iif_assume((x>=0) && (x<=50));
while(rand() % 8)
{
recordi(x);
 if (x>50) x++;
		if (x == 0) {
			x ++;
		} else x--;
}
recordi(x);
iif_assert((x>=0) && (x<=50));
return 0;
}

int main(int argc, char** argv)
 {
iifContext context("/home/parallels/Research/GitHub/ZILU/tmp/zilu_poly1.var", loopFunction, "loopFunction", "/home/parallels/Research/GitHub/ZILU/tmp/zilu_poly1.ds");
context.addLearner("poly");
context.addLearner("conjunctive");
return context.learn("/home/parallels/Research/GitHub/ZILU/tmp/zilu_poly1.cnt", "/home/parallels/Research/GitHub/ZILU/tmp/zilu_poly1");
}