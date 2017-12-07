#include <iostream>
#include "HashingCompare.hpp"

using namespace std;

int main()
{
    HashingCompare hc;
    // hc.compare();
    hc.hashL();
    hc.hashQ();
    hc.hashD();
    hc.printResult();
    return 0;
}
