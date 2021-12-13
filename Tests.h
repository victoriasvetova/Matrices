#include "BinaryTree.h"
void TestAll(){
    int M = 3;
    int N = 3;
    int K = 3;

    bin_tree<int> a(M,K);
    bin_tree<int> b(K,N);

    a.insert({1,1},1);
    a.insert({2,2},2);
    a.insert({3,3},3);


    b.insert({1,3},1);
    b.insert({2,2},2);
    b.insert({3,1},3);

    bin_tree<int> sum = a + b;
    bin_tree<int> diff = a - b;
    bin_tree<int> multiplication = a * b;

    bool sum_flag = true;
    if(sum.get({1,1}) != 1 || sum.get({1,3}) != 1 ||
    sum.get({2,2}) != 4 || sum.get({3,1}) != 3 ||
    sum.get({3,3}) != 3)
        sum_flag = false;

    bool diff_flag = true;
    if(diff.get({1,1}) != 1 || diff.get({1,3}) != -1 ||
    diff.get({3,1}) != -3 || diff.get({3,3}) != 3)
        diff_flag = false;

    bool mult_flag = true;
    if(multiplication.get({1,3}) != 1 || multiplication.get({2,2}) != 4 || multiplication.get({3,1}) != 9)
        mult_flag = false;

    if(!sum_flag)
        std::cerr << "Sum ERROR !";

    if(!diff_flag)
        std::cerr << "Diff ERROR !";

    if(!mult_flag)
        std::cerr << "Mult ERROR !";

    if(!sum_flag || !diff_flag || !mult_flag)
        std::exit(0);

    std::cerr << "ALL TESTS IS OK !\n";
}