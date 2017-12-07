#include "HashingCompare.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

HashingCompare::HashingCompare(){
    srand (time(NULL));
    for(int i=0; i < 10000; i++){
        randomNumber[i] = rand();
    }
    for(int i=0; i < 10001; i++){
        hashingTableL[i] = -1;
        hashingTableQ[i] = -1;
        hashingTableD[i] = -1;
    }
    for(int i=0; i < 10; i++){
        linearConflict[i] = 0;
        quadraticConflict[i] = 0;
        doubleHashingConflict[i] = 0;
    }
    tableSize = 10001;
    numOfKeys = 0;
}

int HashingCompare::hashf1(int key){
    return key % tableSize;
}

int HashingCompare::hashf2(int key){
    return key % (tableSize - 1) + 1;
}

int HashingCompare::hashingLinear(int key){
    int index = 0;
    for(int i=0; i<tableSize; i++){
        index = (hashf1(key) + i) % tableSize;
        if(hashingTableL[index] != -1) continue;
        else{
            for(int j=numOfKeys/1000; j<10; j++){
                linearConflict[j] += i;
            }
            hashingTableL[index] = key;
            return index;
        }
    }
    return -1;
}

int HashingCompare::hashingQuadratic(int key){
    int index = 0;
    for(int i=0; i<(tableSize-1)/2; i++){
        // index = (hashf1(key) + i/2 + i * i /2) % tableSize;
        // index = (hashf1(key) + i + i * i) % tableSize;
        index = (hashf1(key) + i * i) % tableSize;
        if(hashingTableQ[index] != -1) continue;
        else{
            for(int j=numOfKeys/1000; j<10; j++){
                quadraticConflict[j] += i;
            }
            hashingTableQ[index] = key;
            return index;
        }
    }
    return -1;
}

int HashingCompare::hashingDouble(int key){
    int index = 0;
    for(int i=0; i<tableSize; i++){
        index = (hashf1(key) + i * hashf2(key)) % tableSize;
        if(hashingTableD[index] != -1) continue;
        else{
            for(int j=numOfKeys/1000; j<10; j++){
                doubleHashingConflict[j] += i;
            }
            hashingTableD[index] = key;
            return index;
        }
    }
    return -1;
}

void HashingCompare::hashL(){
    int indexL = 0;
    runTimeL = clock();
    for(int i=0; i<tableSize-1; i++){
        ++numOfKeys;
        indexL = hashingLinear(randomNumber[i]);
        if(indexL == -1) std::cout<< "Failed to insert " << randomNumber[i] << " using linear probing." << std::endl;
    }
    runTimeL = clock() - runTimeL;
    numOfKeys = 0;
}

void HashingCompare::hashQ(){
    int indexQ = 0;
    runTimeQ = clock();
    for(int i=0; i<tableSize-1; i++){
        ++numOfKeys;
        indexQ = hashingQuadratic(randomNumber[i]);
        if(indexQ == -1) std::cout<< "Failed to insert item " << i + 1 << ": " << randomNumber[i] << " using quadratic probing." << std::endl;
    }
    runTimeQ = clock() - runTimeQ;
    numOfKeys = 0;
}

void HashingCompare::hashD(){
    int indexD = 0;
    runTimeD = clock();
    for(int i=0; i<tableSize-1; i++){
        ++numOfKeys;
        indexD = hashingDouble(randomNumber[i]);
        if(indexD == -1) std::cout<< "Failed to insert item " << i + 1 << ": " << randomNumber[i] << " using double hashing." << std::endl;
    }
    runTimeD = clock() - runTimeD;
    numOfKeys = 0;
}

//void HashingCompare::compare(){
//    int indexL = 0;
//    int indexQ = 0;
//    int indexD = 0;
//    for(int i=0; i<tableSize-1; i++){
//        ++numOfKeys;
//        indexL = hashingLinear(randomNumber[i]);
//        if(indexL == -1) std::cout<< "Failed to insert " << randomNumber[i] << " using linear probing." << std::endl;
//        indexQ = hashingQuadratic(randomNumber[i]);
//        if(indexQ == -1) std::cout<< "Failed to insert " << randomNumber[i] << " using quadratic probing." << std::endl;
//        indexD = hashingDouble(randomNumber[i]);
//        if(indexD == -1) std::cout<< "Failed to insert " << randomNumber[i] << " using double hashing." << std::endl;
//    }
//}

void HashingCompare::printResult(){
    std::cout << std::endl;
    printf("%-9s|","Size");
    for(int i=0; i<10; i++){
        printf("%10d|",(i + 1) * 1000);
    }
    printf("%12s","Run Time");
    std::cout << std::endl;

    printf("%-9s|","Linear");
    for(int i=0; i<10; i++){
        printf("%10d|",linearConflict[i]);
    }
    printf("%9.3f s", (float)runTimeL/CLOCKS_PER_SEC);
    std::cout << std::endl;

    printf("%-9s|","Quadratic");
    for(int i=0; i<10; i++){
        printf("%10d|",quadraticConflict[i]);
    }
    printf("%9.3f s", (float)runTimeQ/CLOCKS_PER_SEC);
    std::cout << std::endl;

    printf("%-9s|","Double");
    for(int i=0; i<10; i++){
        printf("%10d|",doubleHashingConflict[i]);
    }
    printf("%9.3f s", (float)runTimeD/CLOCKS_PER_SEC);
    std::cout << std::endl;
}
