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

namespace UF2 {

class UnionFind {

private:
    int *id;
    int count;

    int getRootId(int p)
    {
        while(id[p] != p)
            p = id[p];
        return p;
    }

public:
    UnionFind(int n)
    {
        id = new int[n];
        count = n;
        for(int i=0; i<n; i++)
        {
            id[i] = i;
        }
    }

    ~UnionFind()
    {
        delete[] id;
    }

    bool isConnected(int p, int q)
    {
        return getRootId(p) == getRootId(q);
    }

    void unionElements(int p, int q)
    {
        int p_root = getRootId(p);
        int q_root = getRootId(q);
        if(p_root == q_root)
            return;
        id[p_root] = q_root;
    }

};

}

namespace UF3 {

class UnionFind {

private:
    int *id;
    int count;
    int *sz;    //存储节点为根的子树的节点书（包括该根节点）

    int getRootId(int p)
    {
        while(id[p] != p)
            p = id[p];
        return p;
    }

public:
    UnionFind(int n)
    {
        id = new int[n];
        sz = new int[n];
        count = n;
        for(int i=0; i<n; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }

    ~UnionFind()
    {
        delete[] id;
        delete[] sz;
    }

    bool isConnected(int p, int q)
    {
        return getRootId(p) == getRootId(q);
    }

    void unionElements(int p, int q)
    {
        int p_root = getRootId(p);
        int q_root = getRootId(q);
        if(p_root == q_root)
            return;
        if(sz[p_root] < sz[q_root])
        {
            id[p_root] = q_root;
            sz[q_root] += sz[p_root];
            // sz[p_root] = 0;
        }
        else
        {
            id[q_root] = p_root;
            sz[p_root] += sz[q_root];
            // sz[q_root] = 0;
        }
    }

};

}

namespace UF4 {

class UnionFind {

private:
    int *id;
    int count;
    int *rank;  //存储以该节点为根的子树的层数

    int getRootId(int p)
    {
        while(id[p] != p)
            p = id[p];
        return p;
    }

public:
    UnionFind(int n)
    {
        id = new int[n];
        rank = new int[n];
        count = n;
        for(int i=0; i<n; i++)
        {
            id[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind()
    {
        delete[] id;
        delete[] rank;
    }

    bool isConnected(int p, int q)
    {
        return getRootId(p) == getRootId(q);
    }

    void unionElements(int p, int q)
    {
        int p_root = getRootId(p);
        int q_root = getRootId(q);
        if(p_root == q_root)
            return;
        if(rank[p_root] < rank[q_root])
        {
            id[p_root] = q_root;
            // rank[q_root] += rank[p_root];
            // sz[p_root] = 0;
        }
        else
        {
            id[q_root] = p_root;
            if(rank[q_root] == rank[p_root])
            {
                rank[p_root] += 1;
            }
            // rank[p_root] += rank[q_root];
            // sz[q_root] = 0;
        }
    }

};

}

namespace UF5 {

class UnionFind {

private:
    int *id;
    int count;
    int *rank;  //存储以该节点为根的子树的层数

    int getRootId(int p)
    {
        // while(id[p] != p)
        // {
        //     id[p] = id[id[p]];
        //     p = id[p];
        // }
        // return p;

        // 通过递归将树压缩至2层
        if(id[p] != p)
            id[p] = getRootId(id[p]);
        return id[p];
    }

public:
    UnionFind(int n)
    {
        id = new int[n];
        rank = new int[n];
        count = n;
        for(int i=0; i<n; i++)
        {
            id[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind()
    {
        delete[] id;
        delete[] rank;
    }

    bool isConnected(int p, int q)
    {
        return getRootId(p) == getRootId(q);
    }

    void unionElements(int p, int q)
    {
        int p_root = getRootId(p);
        int q_root = getRootId(q);
        if(p_root == q_root)
            return;
        if(rank[p_root] < rank[q_root])
        {
            id[p_root] = q_root;
            // rank[q_root] += rank[p_root];
            // sz[p_root] = 0;
        }
        else
        {
            id[q_root] = p_root;
            if(rank[q_root] == rank[p_root])
            {
                rank[p_root] += 1;
            }
            // rank[p_root] += rank[q_root];
            // sz[q_root] = 0;
        }
    }

};

}

#endif