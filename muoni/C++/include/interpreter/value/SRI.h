#pragma once

#include "Value.h"

struct SRI: Numeric {
	int v;

	~SRI();

	Value* clone();
	int getType();

	Value* add(Value*);

	SRI* toSRI();
	SRF* toSRF();
};
