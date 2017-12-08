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
        // int hashingTableD2[10001];
        //////////////////////////////////////////////////////////
        // hold the conflict number for the 10 tests
        int linearConflict[10];
        int quadraticConflict[10];
        int doubleHashingConflict[10];
        /////////////////////////////////////////////
        int tableSize;
        int numOfKeys; // Number of keys inserted
        time_t runTimeL, runTimeQ, runTimeD; // Track running time for different methods


    public:
        HashingCompare(); // Constructor
        int hashf1(int); // Primary hashing method
        int hashf2(int); // Secondary hashing method for double hashing
        int hashingLinear(int); // Linear probing
        int hashingQuadratic(int); // Quadratic probing
        int hashingDouble(int); // Double hashing
        int hashingDouble2(int);
        void printResult(); // Print the compare result
        void hashL(); // Hash 10000 keys using linear probing
        void hashQ(); // Hash 10000 keys using quadratic probing
        void hashD(); // Hash 10000 keys using double hashing
        void hashD2();
        void compare(); // Run the 3 methods to compare
};

#endif // HASHINGCOMPARE_HPP_INCLUDED
