#pragma once
#include <tuple>

template<typename M,typename N>
class Pair {
public:
    //значащие поля объявлены константными и публичными для того,чтобы у пользователя не было возможности их изменить
    //(кроме как при создании объекта) - READONLY доступ
    const M first;
    const N second;

    //использованы списки инициализации
    Pair():first(M()),second(N()){}
    Pair(M first_, N second_) : first(first_), second(second_) {}
};

bool operator > (const Pair<int,int>& lhs,const Pair<int,int>& rhs){
    return std::make_tuple(lhs.first,lhs.second) > std::make_tuple(rhs.first,rhs.second);
}

bool operator != (const Pair<int,int>& lhs,const Pair<int,int>& rhs){
    return std::make_tuple(lhs.first,lhs.second) != std::make_tuple(rhs.first,rhs.second);
}

template<typename M,typename N>
std::ostream& operator << (std::ostream& ostream,const Pair<M,N>& pair){
    return ostream << "[ " << pair.first << ", " << pair.second << " ]";
}