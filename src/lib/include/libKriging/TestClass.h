#ifndef LIBKRIGING_TESTCLASS_H
#define LIBKRIGING_TESTCLASS_H

#include <string>
#include "libKriging_exports.h"

class TestClass {
public:
    LIBKRIGING_EXPORT TestClass();
    LIBKRIGING_EXPORT std::string name();
    LIBKRIGING_EXPORT int f();
};

#endif //LIBKRIGING_TESTCLASS_H
