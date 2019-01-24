#pragma once

#include "Value.h"

struct SRF: Numeric {
	double v;

	SRF(double);
	~SRF();

	Value* clone();
	int getType();

	Value* add(Value*);

	SRI* toSRI();
	SRF* toSRF();
};
