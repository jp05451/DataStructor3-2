#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 500000

using namespace std;

class Data
{
public:
    int data;
    int pos;
    bool operator>(const Data &b) { return data > b.data; }
    bool operator<(const Data &b) { return data < b.data; }
    bool operator>=(const Data &b) { return data >= b.data; }
    bool operator<=(const Data &b) { return data <= b.data; }
    bool operator==(const Data &b) { return data == b.data; }
    Data() {}
    Data(int d, int p)
    {
        data = d;
        pos = p;
    }
    Data(int d)
    {
        data = d;
    }
};

class permutedSequence
{
public:
    permutedSequence(int size) { this->size = size; }
    void sort()
    {
        int cursor = -1;
        for (int i = 0; i < size - 1; i++)
        {
            if (value[i] > value[i + 1] && cursor == -1)
            {
                cursor = i + 1;
            }
            if (cursor != -1)
            {
                dataList[i - cursor] = value[i];
            }
        }
        dataList[size - cursor - 1] = value[size - 1];
        for (int i = 0; i < cursor && cursor != -1; i++)
        {
            dataList[i + size - cursor] = value[i];
        }
    }
    int search(int input)
    {
        //Data *result;
        //result = find(dataList, dataList + size - 1, input);
        int result;
        result = Find(input);

        //if (result != dataList + size - 1)
        //return result->pos;
        if (result != -1)
            return dataList[result].pos;
        return -1;
    }

    int Find(int input)
    {
        int begin = 0;
        int end = size;
        int cursor = (begin + end) / 2;
        while (end >= begin)
        {
            if (input == dataList[cursor].data)
            {

                return cursor;
            }
            if (input > dataList[cursor].data)
            {
                begin = cursor + 1;
            }
            else
            {
                end = cursor - 1;
            }
            cursor = (begin + end) / 2;
        }
        return -1;
    }

    int size = 0;
    Data value[MAX];
    Data dataList[MAX];
};

int main()
{
    int times;
    cin >> times;
    permutedSequence P(times);
    for (int i = 0; i < times; i++)
    {
        cin >> P.value[i].data;
        P.value[i].pos = i;
    }
    P.sort();
    cin >> times;
    for (int i = 0; i < times; i++)
    {
        int target;
        cin >> target;

        cout << P.search(target) << endl;
    }
}