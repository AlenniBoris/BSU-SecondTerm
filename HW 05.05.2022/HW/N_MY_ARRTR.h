#ifndef HW_N_MY_ARRTR_H
#define HW_N_MY_ARRTR_H

class ABST
{
public:
    ABST()
    {
        arr = new int[capacity];
        for (int i = 0; i < capacity; ++i) arr[i] = -1;
    }

    ~ABST()
    {
        delete[] arr;
    }

    void insert(int x);
    void traverse();

private:
    void doInsert(int index, int x);
    void traverse(int index);
public:
    int* arr;
    int capacity = 100;
};

#endif //HW_N_MY_ARRTR_H
