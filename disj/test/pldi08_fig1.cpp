#include "record.h"
#include <iostream>
using namespace std;
using namespace record;

int loopFunction(int _reserved_input_[]) {
	int x = _reserved_input_[0];
	int y = _reserved_input_[1];

	precondition(x < 0);

	while(1) {
		record_variable_int(x, y);
		
		if (x>=0) {
			record_branch(0);
			break;
		} else {
			record_branch(1);
			x=x+y; y++;
		} 
	}

	postcondition(y>=0);

	return 0;
}

int main(int argc, char** argv) {
	Context context("/home/lijiaying/Research/zilu/disj/tmp/pldi08_fig1.var", loopFunction, "loopFunction", NULL);
	context.addLearner("linear");
	return context.learn("/home/lijiaying/Research/zilu/disj/tmp/pldi08_fig1.cnt", "/home/lijiaying/Research/zilu/disj/tmp/pldi08_fig1.inv", "/home/lijiaying/Research/zilu/disj/test/pldi08_fig1.pc");
}

