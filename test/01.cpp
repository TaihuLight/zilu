#include "iif.h"
#include <iostream>
using namespace iif;

int loopFunction(int _reserved_input_[]) {
int x = _reserved_input_[0];
int y = _reserved_input_[1];

iif_assume(x==1 && y==1);
while(rand() % 8)
{
recordi(x, y);
x=x+y; y=x;
}
recordi(x, y);
iif_assert(y>=1);
return 0;
}

int main(int argc, char** argv)
 {
	iifround = atoi(argv[1]);
	initseed = atoi(argv[2]);
	iifContext context("/home/lijiaying/Research/GitHub/zilu/tmp/01.var", loopFunction, "loopFunction", "/home/lijiaying/Research/GitHub/zilu/tmp/01.ds");
	context.addLearner("conjunctive");
	return context.learn("/home/lijiaying/Research/GitHub/zilu/tmp/01.cnt", "/home/lijiaying/Research/GitHub/zilu/tmp/01");
}
