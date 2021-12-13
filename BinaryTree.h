#pragma once
#include <iostream>
#include "TreeElem.h"

template<typename T>
class bin_tree {
private:
    tree_elem<T> *ROOT;
    int SIZE;

    void Print_Recursive(tree_elem<T>* curr){
        if(curr){
            Print_Recursive(curr->M_LEFT);
            std::cout << curr->indices_data << std::endl;
            Print_Recursive(curr->M_RIGHT);
        }
    }

public:
    const int ROWS;
    const int COLUMNS;

    bin_tree() : ROWS(0),COLUMNS(0){
        ROOT = nullptr;
        SIZE = 0;
    }

    bin_tree(int m,int n) : ROWS(m),COLUMNS(n){
        ROOT = nullptr;
        SIZE = 0;
    }

    bin_tree(const Pair<int,int>& indices,int data,int m,int n) : ROWS(m),COLUMNS(n){
        ROOT = new tree_elem<T>({indices,data});
        SIZE = 1;
    }

    int get_size() { return SIZE; }

    T get(const Pair<int,int>& indices) const{

        tree_elem<T>* curr = ROOT;
        while (curr){
            if(curr->indices_data.first != indices){
                if(curr->indices_data.first > indices){
                    curr = curr->M_LEFT;
                } else
                    curr = curr->M_RIGHT;
            }else
                return curr->indices_data.second;
        }
        return T();
    }

    bool find(const Pair<int,int>& indices) {

        tree_elem<T> *curr = ROOT;
        while (curr && curr->indices_data.first != indices) {
            if (curr->indices_data.first > indices)
                curr = curr->M_LEFT;
            else
                curr = curr->M_RIGHT;
        }
        return (bool) curr;
    }

    void insert(const Pair<int,int>& indices,int data) {
        if (ROOT == nullptr) {
            ROOT = new tree_elem<T>({indices,data});
            SIZE = 1;
        } else {
            tree_elem<T> *curr = ROOT;
            while (curr && curr->indices_data.first != indices) {
                if (curr->indices_data.first > indices) {
                    if (curr->M_LEFT)
                        curr = curr->M_LEFT;
                    else {
                        curr->M_LEFT = new tree_elem<T>({indices,data});
                        SIZE++;
                        return;
                    }
                } else {
                    if (curr->M_RIGHT)
                        curr = curr->M_RIGHT;
                    else {
                        curr->M_RIGHT = new tree_elem<T>({indices,data});
                        SIZE++;
                        return;
                    }
                }
            }
        }
    }
    
    void Print(){
        tree_elem<T>* curr = ROOT;
        Print_Recursive(curr);
    }

    T& operator [](const Pair<int,int>& indices){
        return this->get(indices);
    }

    bin_tree<T> operator *(bin_tree<T>& matrix){

        int M = this->ROWS;
        int K = this->COLUMNS;
        int N = matrix.COLUMNS;

        if(K != matrix.ROWS)
            return bin_tree<T>();

        bin_tree<T> res(M,N);
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                T tmp = T();
                for (int k = 1; k <= K; ++k) {
                    if(this->find({i,k}) && matrix.find({k,j}))
                        tmp += this->get({i,k}) * matrix.get({k,j});
                }
                if(tmp != T())
                    res.insert({i,j},tmp);
            }
        }
        return res;
    }

    bin_tree<T> operator +(bin_tree<T>& matrix){
        if(matrix.COLUMNS != this->COLUMNS || matrix.ROWS != this->ROWS)
            return bin_tree<T>();
        int M = matrix.ROWS;
        int N = matrix.COLUMNS;
        bin_tree<T> res(M,N);
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                T tmp = this->get({i,j}) + matrix.get({i,j});
                if(tmp != T())
                    res.insert({i,j},tmp);
            }
        }
        return res;
    }

    bin_tree<T> operator -(bin_tree<T>& matrix){
        if(matrix.COLUMNS != this->COLUMNS || matrix.ROWS != this->ROWS)
            return bin_tree<T>();
        int M = matrix.ROWS;
        int N = matrix.COLUMNS;
        bin_tree<T> res(M,N);
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                T tmp = this->get({i,j}) - matrix.get({i,j});
                if(tmp != T())
                    res.insert({i,j},tmp);
            }
        }
        return res;
    }
};