#include "interpreter/value/SRI.h"

SRI::~SRI() {
	std::cout << "asdf\n";
}

Value* SRI::clone() {
	return nullptr;
}

int SRI::getType() {
	return ValueType::SRI;
}

Value* SRI::add(Value* that) {
	return nullptr;
}

SRI* SRI::toSRI() {
	return nullptr;
}

SRF* SRI::toSRF() {
	return nullptr;
}
