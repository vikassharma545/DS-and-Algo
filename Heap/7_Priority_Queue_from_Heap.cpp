// Heap is best suitable data structure for priority queue
// insertion time => log(n)
// deletion time => log(n)

// Priority queue => pop function always pop the the element of higher priority

// here we implement a priority queue in which element is itself a priority using max heap
// heigher the value have higher the priority

#include <bits/stdc++.h>
using namespace std;

class Priority_queue
{
private:
    vector<int> vec;

public:
    void push(int key)
    {
        // Insert key at the end
        auto i = vec.size();
        vec.emplace_back(key);

        // Rearrange elements: O(log n)
        while (i > 0 && key > vec[i % 2 == 0 ? (i / 2) - 1 : i / 2])
        {
            vec[i] = vec[i % 2 == 0 ? (i / 2) - 1 : i / 2];
            i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
        }
        vec[i] = key;
    }


    int pop() 
    {
        auto size = vec.size();
        int x, i, j;
        x = vec[0];
        vec[0] = vec[size - 1];
        i = 0;
        j = 1;

        while (j < size)
        {
            if (vec[j + 1] > vec[j])
                j = j + 1;

            if (vec[i] < vec[j])
            {
                swap(vec[i], vec[j]);
                i = j;
                j = (j * 2) + 1;
            }
            else
                break;
        }
        vec.pop_back();
        return x;
    }

    void Display()
    {
        for (auto i = vec.begin(); i < vec.end(); i++)
            cout << *i << " ";
    }
};

int main()
{
    Priority_queue p;

    for (int i = 0; i < 10; i++)
    {
        int k;
        cin >> k;
        p.push(k);
    }

    p.Display();
    cout << endl;

    cout << "pop = " << p.pop() << endl;
    p.Display();
}