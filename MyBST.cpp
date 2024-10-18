#include "MyBST.h"
#include <queue>
#include <iostream>

MyBST::MyBST() {
    this->root=nullptr;
    this->size=0;
}

int MyBST::length(){
    return this->size;
}

bool MyBST::isEmpty(){
    return this->size==0;
}

bool MyBST::search(int data){
    MyNodeBST *current=this->root;
    while(current!=nullptr){
        if(current->data==data){
            return true;
        }else if(data<current->data){
            current=current->left;
        }else{
            current=current->right;
            //current=data<current->data?current->left:current->right;
        }
    }
    return false;
}

bool MyBST::searchRec(int data, MyNodeBST *current){
    if(current==nullptr){
        return false;
    }else if(data==current->data){
        return true;
    }else if(data<current->data){
        return searchRec(data,current->left);
    }else{
        return searchRec(data,current->right);
    }
}

bool MyBST::searchRec(int data){
    return this->searchRec(data,this->root);
}

bool MyBST::insert(int data){
    MyNodeBST *newNode=new MyNodeBST(data);
    if(newNode==nullptr){
        return false;
    }
    if(this->root==nullptr){
        this->root=newNode;
        this->size++;
        return true;
    }
    MyNodeBST *current=this->root;
    MyNodeBST *parent=nullptr;
    while(current!=nullptr){
        parent=current;
        if(data<current->data){
            current=current->left;
        }else if(data>current->data){
            current=current->right;
        }else{
            delete newNode;
            return false;
        }
    }
    if(data<parent->data){
        parent->left=newNode;
    }else{
        parent->right=newNode;
    }
    this->size++;
    return true;
}

bool MyBST::remove(int data){
    MyNodeBST *current=this->root;
    MyNodeBST *parent=nullptr;
    while(current!=nullptr){
        if(data<current->data){
            parent=current;
            current=current->left;
        }else if(data>current->data){
            parent=current;
            current=current->right;
        }else{
            break;
        }
    }
    if(current==nullptr){
        return false;
    }
    if(current->left==nullptr && current->right==nullptr){
        if(parent==nullptr){
            this->root=nullptr;
        }else if(parent->left==current){
            parent->left=nullptr;
        }else{
            parent->right=nullptr;
        }
        delete current;
    }else if(current->left!=nullptr && current->right==nullptr){
        if(parent==nullptr){
            this->root=current->left;
        }else if(parent->left==current){
            parent->left=current->left;
        }else{
            parent->right=current->left;
        }
        delete current;
    }else if(current->left==nullptr && current->right!=nullptr){
        if(parent==nullptr){
            this->root=current->right;
        }else if(parent->left==current){
            parent->left=current->right;
        }else{
            parent->right=current->right;
        }
        delete current;
    }else{
        MyNodeBST *successor=current->right;
        parent=current;
        while(successor->left!=nullptr){
            parent=successor;
            successor=successor->left;
        }
        current->data=successor->data;
        if(parent->left==successor){
            parent->left=successor->right;
        }else{
            parent->right=successor->right;
        }
        delete successor;
    }
    this->size--;
    return true;
}

void MyBST::preorder(MyNodeBST* current) {
    if (current == nullptr) {
        return;
    }
    std::cout << current->data << ",";
    preorder(current->left);
    preorder(current->right);
}

void MyBST::preorder() {
    this->preorder(this->root);
    std::cout << std::endl;
}

void MyBST::inorder(MyNodeBST* current) {
    if (current == nullptr) {
        return;
    }
    inorder(current->left);
    std::cout << current->data << ",";
    inorder(current->right);
}

void MyBST::inorder() {
    this->inorder(this->root);
    std::cout << std::endl;
}

void MyBST::postorder(MyNodeBST* current) {
    if (current == nullptr) {
        return;
    }
    postorder(current->left);
    postorder(current->right);
    std::cout << current->data << ",";
}

void MyBST::postorder() {
    this->postorder(this->root);
    std::cout << std::endl;
}

void MyBST::level() {
    if (this->root == nullptr) {
        return;
    }
    std::queue<MyNodeBST*> q;
    q.push(this->root);
    while (!q.empty()) {
        MyNodeBST* current = q.front();
        q.pop();
        std::cout << current->data << ",";
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    std::cout << std::endl;
}

void MyBST::visit(int type) {
    switch (type) {
        case 1:
            this->preorder();
            break;
        case 2:
            this->inorder();
            break;
        case 3:
            this->postorder();
            break;
        case 4:
            this->level();
            break;
        default:
            std::cout << "Invalid option" << std::endl;
    }
}

int MyBST::height(MyNodeBST* node) {
    if (node == nullptr) {
        return -1;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

int MyBST::height() {
    return height(this->root);
}

void MyBST::ancestors(int data) {
    std::vector<int> ancestors;
    MyNodeBST* current = this->root;
    while (current != nullptr) {
        if (current->data == data) {
            break;
        }
        ancestors.push_back(current->data);
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current != nullptr) {
        for (size_t i = 0; i < ancestors.size(); i++) {
            std::cout << ancestors[i];
            if (i != ancestors.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << std::endl;
    }
}

int MyBST::whatLevelAmI(int data) {
    MyNodeBST* current = this->root;
    int level = 0;
    while (current != nullptr) {
        if (current->data == data) {
            return level;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
        level++;
    }
    return -1;
}