#include "interpreter/value/Value.h"
#include "interpreter/value/ValueType.h"

Value* SRF::clone() {
	return nullptr;
}

SRF::SRF(double d): v(d) {}

SRF::~SRF() {
	std::cout << "zxcv\n";
}

int SRF::getType() {
	return ValueType::SRF;
}

Value* SRF::add(Value* that) {
	switch (that->getType()) {
		case ValueType::SRI: {
			SRI* sri = reinterpret_cast<SRI*>(that);
			SRF* s = new SRF((double) (sri->v) + v);
			std::cout<<s->v<<std::endl;
			return s;
		}
	}
	return nullptr;
}

SRI* SRF::toSRI() {
	return nullptr;
}

SRF* SRF::toSRF() {
	return nullptr;
}
