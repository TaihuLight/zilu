#include "iif.h"
#include <iostream>
using namespace iif;

int loopFunction(int _reserved_input_[]) {
int i = _reserved_input_[0];
int k = _reserved_input_[1];
int n = _reserved_input_[2];

iif_assume( (i==0) && (k==0) && (n>0));
while(i < n)
{
recordi(i, k, n);
i++;k++;
}
recordi(i, k, n);
iif_assert( (i == k) && (k == n));
return 0;
}

int main(int argc, char** argv)
 {
	iifround = atoi(argv[1]);
	initseed = atoi(argv[2]);
	iifContext context("/home/lijiaying/Research/GitHub/zilu/tmp/down_true_1.var", loopFunction, "loopFunction", "/home/lijiaying/Research/GitHub/zilu/tmp/down_true_1.ds");
	context.addLearner("conjunctive");
	return context.learn("/home/lijiaying/Research/GitHub/zilu/tmp/down_true_1.cnt", "/home/lijiaying/Research/GitHub/zilu/tmp/down_true_1");
}
