#ifndef LIBNAME_TESTS_HELPERS_TESTSRSC_H
#define LIBNAME_TESTS_HELPERS_TESTSRSC_H

#include <string>

class TestsRsc
{

public:
    static std::string getPathExternalRsc(const std::string &filename);
};

#endif // LIBNAME_TESTS_HELPERS_TESTSRSC_H