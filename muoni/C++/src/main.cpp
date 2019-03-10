#include <iostream>
#include "Values/Value.h"
#include "Values/NumericValue.h"
#include "Values/ValueFactory.h"
#include "Values/BigInt.h"
#include <complex>
#include <Eigen/Dense>
#include "Operations/BinaryOperation.h"
#include "Types/Type.h"
#include <cstdio>
#include <ctime>
#include "Dimensions/BaseDimension.h"
#include "Dimensions/CompositeDimension.h"
#include "Dimensions/DimensionalComponent.h"
#include "Dimensions/DerivedDimension.h"
#include "Dimensions/UnityDimension.h"
#include "Units/BaseUnit.h"
#include "Units/Unit.h"
#include "Units/DerivedUnit.h"
#include "Units/UnityBaseUnit.h"
#include "Units/UnityDerivedUnit.h"

void doStuffs() {
    BaseDimension distance("Distance");
    BaseDimension time("Time");
    UnityDimension angle("Angle");

    BaseUnit meter(&distance,"m");
    BaseUnit second(&time,"s");
    UnityBaseUnit radian(&angle,"rad");
    Unit* mps = Unit::divide(&meter,&second);
    std::cout << meter.toString() << std::endl;
    std::cout << second.toString() << std::endl;
    std::cout << mps->toString() << std::endl;

    std::vector<UnitComponent> v;
    v.emplace_back(&meter,1);

    DerivedUnit millimeter(&distance,"mm",v,0.001);
    std::cout << millimeter.toString() << std::endl;
    Unit* mmps = Unit::divide(&millimeter,&second);
    std::cout << mmps->toString() << std::endl;

    std::cout << Unit::areEquivalent(mmps,mps) << std::endl;

    v.clear();
    v.emplace_back(&radian,1);
    UnityDerivedUnit degree(&angle,"deg",v,3.14159265/180);

    double d = 10;
    d *= Unit::convert(mps,mmps);
    std::cout << d << std::endl;

    std::cout << radian.toString() << std::endl;
    double a = 3.14159265 / 4;
    a *= Unit::convert(&radian,&degree);
    std::cout << a << std::endl;

    Unit* asdf = Unit::multiply(&meter,&radian);
    std::cout << asdf->toString() << std::endl;
    std::cout << asdf->getDimension()->toString() << std::endl;

    delete mps;
    delete mmps;
}

int main() {
    std::cout << std::boolalpha;

    std::clock_t start = std::clock();

    doStuffs();

    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"Time: "<< duration << std::endl;
    return 0;
}