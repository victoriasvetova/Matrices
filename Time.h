#include <time.h>
#include <fstream>
#include "BinaryTree.h"

void Test(){
    int Size = 100;

    std::fstream out;//инициализация потока вывода
    out.open("Difference.txt");
    std::srand(0);

    for (int i = 1; i <= 10; i += 1) {

        int* data1 = new int[i * i];
        for (int j = 0; j < i * i; ++j) {
            data1[i] = rand() % 1000;
        }

        bin_tree<int> a(Size,Size);
        int index = 0;
        for (int j = 0; j < i * i; ++j) {
            for (int k = 0; k < i * i; ++k) {
                a.insert({rand() % Size,rand() % Size},data1[index]);//случайное заполнение
                ++index;
                if(index >= i * i)//в случае,если все элементы из data1 использованы,заполнение повторяется с начала
                    index = 0;
            }
        }

        bin_tree<int> b(Size,Size);
        index = 0;
        for (int j = 0; j < i * i; ++j) {
            for (int k = 0; k < i * i; ++k) {
                b.insert({rand() % Size,rand() % Size},data1[index]);
                ++index;
                if(index >= i * i)
                    index = 0;
            }
        }

        unsigned int start = clock();
        bin_tree<int> c = a - b;
        unsigned int finish = clock();
        out << finish - start << ' ';

    }
}