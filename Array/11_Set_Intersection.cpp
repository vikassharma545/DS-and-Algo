#include <iostream>
using namespace std;

class Set_Operations
{
public:
    int *array;
    int size;
    int length;

    Set_Operations(int size)
    {
        array = new int[size];
        this->size = size;
    }

    void Display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    Set_Operations *Intersection_unsorted(Set_Operations s1, Set_Operations s2)
    {
        Set_Operations *s3 = new Set_Operations(s1.size + s2.size);

        int k = 0;

        for (int i = 0; i < s1.length; i++)
        {
            int check = 0;
            for (int j = 0; j < s2.length; j++)
                if (s1.array[i] == s2.array[j])
                    check = 1;

            if (check)
                s3->array[k++] = s1.array[i];
        }

        s3->length = k;

        return s3;
    }

    Set_Operations *Intersection_Sorted(Set_Operations s1, Set_Operations s2)
    {
        int i = 0, j = 0, k = 0;

        Set_Operations *s4 = new Set_Operations(s1.size + s2.size);

        while (i < s1.length && j < s2.length)
        {
            if (s1.array[i] < s2.array[j])
                i++;
            else if (s1.array[i] > s2.array[j])
                j++;
            else
            {
                s4->array[k++] = s1.array[i++];
                j++;
            }
        }

        s4->length = k;
        return s4;
    }
};

int main()
{
      Set_Operations s1(10), s2(10), *s3;

    s1.array[0] = 3;
    s1.array[1] = 4;
    s1.array[2] = 5;
    s1.array[3] = 6;
    s1.array[4] = 10;
    s1.length = 5;

    s2.array[0] = 2;
    s2.array[1] = 4;
    s2.array[2] = 5;
    s2.array[3] = 7;
    s2.array[4] = 12;
    s2.length = 5;

    s1.Display();
    s2.Display();
    s3 = s1.Intersection_unsorted(s1, s2);
    s3->Display();

    return 0;
}