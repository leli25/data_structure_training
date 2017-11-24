#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "FileOps.h"
#include "SequenceST.h"


using namespace std;

template<typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;
        
        //Constructor
        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left= NULL;
            this->right = NULL;
        }
    };
    
    Node* root;
    int count;
public:
    BST(){
        root = NULL;
        count = 0;
    }
    
    ~BST(){
        //TODO
        __deleteTree(root);
    }
    
    int size(){
        return count;
    }
    
    bool isEmpty(){
        return count == 0;
    }
    
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }
    
    //Non reversion
    void insertNonReversion(Key key, Value value){
        if(isEmpty){
            root = new Node(key, value);
            return;
        }
        Node *p = root;
        while(p != NULL){
            if(p->key == key){
                p->value = value;
                return;
            }
            else if(p->key > key){
                if(p->left == NULL)
                    break;
                else
                    p = p->left;
            }
            else{
                if(p->right == NULL)
                    break;
                else
                    p = p->right;
            }
        }
        if(p->key > key)
            p->left = new Node(key, value);
        else
            p->right = new Node(key, value);
    }
    
    bool contain(Key key){
        return __contain(root, key);
    }
    
    Value* search(Key key){
        return __search(root, key);
    }
    
    void levelOrder(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            //visit node
            cout<<node->key<<endl;
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
    }
    
    Key minimum(){
        Node* minNode = __minimum(root);
        return minNode->key;
    }
    
    Key maximun() {
        Node* maxNode = __maximum(root);
        return maxNode->key;
    }
    
    void removeMin() {
        if(root != NULL)
            root = __removeMin(root);
    }
    
    void removeMax() {
        if(root != NULL)
            root = __removeMax(root);
    }
    
private:
    Node* insert(Node *node, Key key, Value value){
        if(node == NULL){
            count++;
            return new Node(key, value);
        }
        if(node->key == key){
            node->value = value;
            //return node;
        }
        else if(node->key > key){
            node->left = insert(node->left, key, value);
        }
        else{
            node->right = insert(node->right, key, value);
        }
        
        return node;
            
    }
    bool __contain(Node *node, Key key){
        if(node == NULL)
            return false;
        if(node->key ==  key)
            return true;
        else if(node->key > key)
            return __contain(node->left, key);
        else
            return __contain(node->right, key);
    }
    Value* __search(Node *node, Key key){
        if(node == NULL)
            return NULL;
        if(node->key == key)
            return &(node->value);
        else if(node->key > key)
            return __search(node->left, key);
        else
            return __search(node->right, key);
    }
    
    void __deleteTree(Node *node){
        if(node == NULL)
            return;
        __deleteTree(node->left);
        __deleteTree(node->right);
        delete node;
        count--;
    }
    
    Node* __minimum(Node *node){
        if(node->left == NULL)
            return node;
        else
            return __minimum(node->left);
    }
    
    Node* __maximum(Node *node){
        if(node->right == NULL)
            return node;
        else
            return __maximum(node->right);
    }
    
    Node* __removeMin(Node* node) {
        if(node->left == NULL) {
            Node* rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }
    
    Node* __removeMax(Node* node) {
        if(node->right == NULL) {
            Node* leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }
    
};


int main()
{
    string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // 测试 BST
        time_t startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }
        // 输出圣经中god一词出现的频率
        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;
        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        // 测试顺序查找表 SST
        startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }

    return 0;
}