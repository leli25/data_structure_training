#include "unionFindTestHelper.h"

using namespace std;

int main()
{
    int n = 1000000;
    //UnionFindTestHelper::testQuick(n);
    // UnionFindTestHelper::testQuickImproved(n);
    UnionFindTestHelper::testQuickImproved1(n);
    UnionFindTestHelper::testQuickImproved2(n);

    return 0;
}