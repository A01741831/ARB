#ifndef MyBST_H
#define MyBST_H

struct MyNodeBST
{
    int data;
    MyNodeBST *left, *right;

    MyNodeBST(int data, MyNodeBST *left, MyNodeBST *right){
        this->data=data;
        this->left=left;
        this->right=right;
    }

    MyNodeBST(int data){
        this->data=data;
        this->left=this->right=nullptr;
    }

    MyNodeBST(int data):MyNodeBST(data, nullptr,nullptr){}
};

class MyBST{
    private:
        int size; //
        MyNodeBST *root; //
        bool search(int data, MyNodeBST *current); //
        void preorder(MyNodeBST *current);
        void inorder(MyNodeBST *current);
        void postorder(MyNodeBST *current);
        int height(MyNodeBST* node);
    public:
        MyBST();
        int length(); //
        bool isEmpty(); //
        bool search(int data); //
        bool searchRec(int data,MyNodeBST *current); //
        bool searchRec(int data); //
        bool insert(int data); 
        bool remove(int data);
        void preorder();
        void inorder();
        void postorder();
        void level();
        void visit(int type);
        int height();
        void ancestors(int data);
        int whatLevelAmI(int data);
};


#endif