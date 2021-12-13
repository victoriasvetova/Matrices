#pragma once
#include "Pair.h"

template<typename T>
class tree_elem {
public:
    //элементы матрицы хранятся как листья бинарного дерева поиска
    //каждый из элементов - пара,первым элементом которой является пара индексов,
    //её второй элемент - значение,соответствующее этим индексам
    Pair<Pair<int,int>,T> indices_data;
    tree_elem *M_LEFT;
    tree_elem *M_RIGHT;

    tree_elem(const Pair<Pair<int,int>,T>& indices_) : indices_data(indices_){
        M_LEFT = NULL;
        M_RIGHT = NULL;
    }
    tree_elem(T key,tree_elem<T>* left,tree_elem<T>* right){//копиконструктор
        indices_data.second = key;
        M_LEFT = left;
        M_RIGHT = right;
    }

};

template<typename T>//перегрузка оператора вывода для удобства печати
std::ostream& operator << (std::ostream& out,tree_elem<T>& to_out){
    return out << to_out.indices_data << std::endl;
}