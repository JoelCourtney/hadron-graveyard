#pragma once

#include "ValueType.h"
#include <iostream>

struct SRI; struct SRF;

struct Value {
	virtual ~Value() {};
	virtual Value* clone() = 0;
	virtual int getType() = 0;
	
	// OPERATOR FUNCTIONS DO NOT CONSUME BY DEFAULT
	virtual Value* add(Value*) = 0;
	//virtual Value* subtract(Value*) = 0;
	//virtual Value* multiply(Value*) = 0;
	//virtual Value* divide(Value*) = 0;
	 //etc
	
};

struct Numeric: Value {
	virtual ~Numeric() {};
	// CONVERTER FUNCTIONS DO NOT CONSUME BY DEFAULT
	virtual SRI* toSRI() = 0;
	virtual SRF* toSRF() = 0;
};

#include "SRI.h"
#include "SRF.h"
