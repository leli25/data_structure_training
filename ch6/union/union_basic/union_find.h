#ifndef UNION_FIND_H
#define UNION_FIND_H

namespace UF1 {

class UnionFind {
private:
    int count;
    int *id;
public:
    UnionFind(int n)
    {
        id = new int[n];
        count = n;
        for(int i=0; i<count; i++)
            id[i] = i;
    }

    bool isConnected(int p, int q)
    {
        return id[p] == id[q];
    }

    void unionElements(int p, int q)
    {
        int pId = id[p];
        int qId = id[q];
        if(pId == qId)
            return;
        for(int i=0; i<count; i++)
        {
            if(id[i] == pId)
            {
                id[i] = qId;
            }
        }
    }

    ~UnionFind()
    {
        delete[] id;
    }
};

}

#endif