#include "MyBST.h"

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

}

bool MyBST::remove(int data){
    
}