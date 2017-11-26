#ifndef UNION_FIND_TEST_HELPER_H
#define UNION_FIND_TEST_HELPER_H
#include "union_find.h"
#include <iostream>
#include <ctime>

namespace UnionFindTestHelper {

void testQuick(int n)
{
    UF1::UnionFind uf1 = UF1::UnionFind(n);
    srand(time(NULL));

    time_t start_time = clock();

    for(int i=0; i<n; i++)
    {
        int p = rand() % n;
        int q = rand() % n;
        uf1.unionElements(p, q);
    }

    for(int i=0; i<n; i++)
    {
        int p = rand() % n;
        int q = rand() % n;
        uf1.isConnected(p, q);
    }

    time_t end_time = clock();
    std::cout<< n << " ops union and check connection, costs "<< (end_time - start_time) / (double)CLOCKS_PER_SEC << " s."<<std::endl;
    
}

}

#endif