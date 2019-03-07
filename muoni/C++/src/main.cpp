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

void doStuffs() {
    BaseDimension distance("Distance"), time("Time");
    std::cout << distance.toString() << std::endl;
    std::cout << time.toString() << std::endl;
    std::vector<DimensionalComponent> v;
    v.emplace_back(&distance,1);
    v.emplace_back(&time,-2);
    CompositeDimension accel(v);
    std::cout << accel.toString() << std::endl;
    DerivedDimension otherAccel("Acceleration",v);
    std::cout << otherAccel.toString() << std::endl;
    std::cout << Dimension::areEquivalent(&accel,&otherAccel) << std::endl;
    BaseDimension mass("Mass");
    v.emplace_back(&mass,1);
    DerivedDimension force("Force",v);
    std::cout << force.toString() << std::endl;
    std::cout << accel.toString() << std::endl;
    CompositeDimension otherForce(v);
    std::cout << otherForce.toString() << std::endl;
    v.clear();
    v.emplace_back(&otherAccel,1);
    v.emplace_back(&mass,1);
    CompositeDimension thirdForce(v);
    std::cout << std::endl << std::endl << thirdForce.toString() << std::endl;
}

int main() {
    std::cout << std::boolalpha;

    std::clock_t start = std::clock();

    doStuffs();

    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"Time: "<< duration << std::endl;
    return 0;
}