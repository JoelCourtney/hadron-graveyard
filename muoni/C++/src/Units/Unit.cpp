//
// Created by Joel Courtney on 2019-03-04.
//

#include <Units/Unit.h>

#include "Units/Unit.h"

Unit::Unit(Dimension* d) : dimension(d) {}

Dimension* Unit::getDimension() const {
    return dimension;
}
