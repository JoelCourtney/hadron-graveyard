#include <iostream>
#include "interpreter/Interpreter.h"
#include "error/Error.h"
#include "interpreter/value/Value.h"

int main() {
	int v = ValueType::SRI;
	SRI i;
	i.v = 5;
	Value* asdf = &i;
	SRF f(4.5);
	Value* zxcv = &f;
	Value* r = zxcv->add(asdf);
	std::cout << reinterpret_cast<SRF*>(r)->v << std::endl;
	delete r;
};
