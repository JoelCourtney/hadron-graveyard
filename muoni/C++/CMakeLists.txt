cmake_minimum_required(VERSION 3.13)
project(C__)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR}/inc/Grammar /usr/local/include/eigen3 /usr/local/include/antlr4-runtime)

FILE(GLOB GRAMMAR_FILES inc/Grammar/*.h src/Grammar/*.cpp)

link_directories(/usr/local/lib)

add_executable(muon src/main.cpp ${GRAMMAR_FILES} inc/Data/Primitive.h inc/Data/DataFactory.h inc/Data/Numeric.h inc/Data/Scalar.h inc/Data/Matrix.h inc/Data/Float.h src/Data/Float.cpp src/Data/DataFactory.cpp inc/Data/Int.h src/Data/Int.cpp inc/Data/String.h src/Data/String.cpp src/Data/Numeric.cpp src/Data/Scalar.cpp src/Data/Matrix.cpp src/Data/Primitive.cpp inc/Data/Bool.h src/Data/Bool.cpp inc/Data/ComplexInt.h src/Data/ComplexInt.cpp inc/Data/ComplexFloat.h src/Data/ComplexFloat.cpp inc/Data/BigIntBackend.h src/Data/BigInt.cpp inc/Data/Null.h src/Data/Null.cpp inc/Data/IntMatrix.h src/Data/IntMatrix.cpp inc/Data/FloatMatrix.h src/Data/FloatMatrix.cpp inc/Units/Unit.h inc/Units/BaseUnit.h inc/Units/CompositeUnit.h src/Units/Unit.cpp inc/Units/DerivedUnit.h inc/Dimensions/Dimension.h src/Dimensions/Dimension.cpp inc/Units/Conversion.h inc/Dimensions/BaseDimension.h inc/Dimensions/CompositeDimension.h src/Dimensions/BaseDimension.cpp src/Dimensions/CompositeDimension.cpp inc/Dimensions/DerivedDimension.h src/Dimensions/DerivedDimension.cpp inc/Dimensions/DimensionalComponent.h src/Dimensions/DimensionalComponent.cpp inc/Units/UnitComponent.h src/Units/BaseUnit.cpp src/Units/UnitComponent.cpp inc/Dimensions/NamedDimension.h src/Dimensions/NamedDimension.cpp inc/Units/NamedUnit.h src/Units/NamedUnit.cpp src/Units/DerivedUnit.cpp inc/Dimensions/UnityDimension.h src/Dimensions/UnityDimension.cpp inc/Units/UnityDerivedUnit.h src/Units/UnityDerivedUnit.cpp src/Units/CompositeUnit.cpp inc/Units/UnityBaseUnit.h src/Units/UnityBaseUnit.cpp inc/CodeReaders/CodeReader.h inc/CodeReaders/FileCodeReader.h inc/CodeReaders/CommandLineCodeReader.h src/CodeReaders/FileCodeReader.cpp src/CodeReaders/CodeReader.cpp src/CodeReaders/CommandLineCodeReader.cpp inc/Errors/Error.h inc/Environment/Scope.h src/Environment/Scope.cpp inc/Interpreter/MuonInterpreter.h src/Interpreter/MuonInterpreter.cpp inc/Environment/Environment.h src/Environment/Environment.cpp inc/Environment/ExplicitScope.h inc/Environment/ImplicitScope.h inc/Environment/FileScope.h src/Environment/ExplicitScope.cpp inc/Environment/FullScope.h src/Environment/FullScope.cpp src/Environment/FileScope.cpp inc/Errors/SyntaxError.h inc/Errors/RuntimeError.h inc/Errors/TypeError.h inc/Errors/VarlNotFoundError.h inc/Errors/CannotDeferError.h src/Errors/VarlNotFoundError.cpp src/Errors/Error.cpp src/Interpreter/MuonLiterals.cpp src/Interpreter/MuonLValues.cpp src/Interpreter/MuonBinaryOperations.cpp src/Interpreter/MuonUnaryOperations.cpp inc/Data/Type.h inc/Errors/InvalidOperationError.h inc/Data/BigInt.h inc/Errors/InvalidConversionError.h inc/Errors/NotImplementedError.h src/Errors/NotImplementedError.cpp inc/Errors/CannotAssignError.h src/Interpreter/MuonAtoms.cpp inc/Data/List.h src/Data/List.cpp inc/Data/Data.h src/Data/Data.cpp src/Interpreter/MuonControls.cpp src/Environment/ImplicitScope.cpp)

target_link_libraries(muon libantlr4-runtime.a)
