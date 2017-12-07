#ifndef HASHINGCOMPARE_HPP_INCLUDED
#define HASHINGCOMPARE_HPP_INCLUDED
#include <time.h>

class HashingCompare{
    private:
        int randomNumber[10000];
        // hashing table for different conflict resolution methods
        int hashingTableL[10001];
        int hashingTableQ[10001];
        int hashingTableD[10001];
        //////////////////////////////////////////////////////////
        // hold the conflict number for the 10 tests
        int linearConflict[10];
        int quadraticConflict[10];
        int doubleHashingConflict[10];
        /////////////////////////////////////////////
        int tableSize;
        int numOfKeys;
        time_t runTimeL, runTimeQ, runTimeD;


    public:
        HashingCompare();
        int hashf1(int);
        int hashf2(int);
        int hashingLinear(int);
        int hashingQuadratic(int);
        int hashingDouble(int);
        void printResult();
        void hashL();
        void hashQ();
        void hashD();
//        void compare();
};

#endif // HASHINGCOMPARE_HPP_INCLUDED
