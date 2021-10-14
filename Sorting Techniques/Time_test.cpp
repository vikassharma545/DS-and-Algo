//  May be your pc will hang :-)
// for calculating approx actual time very very large time function run (billions times) at different time intervals (more then hour) 
// at different temperature and take average of all

#include <iostream>
#include <algorithm>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

void Print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Bubble_Sort(int array[], int size)
{
    int flag;

    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}

void Insertion_Sort(int array[], int size)
{
    int i, j, x;
    for (i = 1; i < size; i++)
    {
        j = i - 1;
        x = array[i];
        while (j > -1 && array[j] > x)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = x;
    }
}

void Selection_Sort(int array[], int size)
{
    int i, j, k;
    for (i = 0; i < size - 1; i++)
    {
        for (j = k = i; j < size; j++)
        {
            if (array[j] < array[k])
                k = j;
        }

        swap(array[i], array[k]);
    }
}

int Partitioning(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low;
    int j = high;

    do
    {
        do
        {
            i++;
        } while (array[i] <= pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
            swap(array[i], array[j]);

    } while (i < j);

    swap(array[low], array[j]);

    return j;
}

void Quick_sort(int array[], int low, int high)
{
    int j;

    if (low < high)
    {
        j = Partitioning(array, low, high);
        Quick_sort(array, low, j);
        Quick_sort(array, j + 1, high);
    }
}

void Merge(int Array[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int *B = new int[high + 1];

    while (i <= mid && j <= high)
    {
        if (Array[i] < Array[j])
            B[k++] = Array[i++];

        else
            B[k++] = Array[j++];
    }

    for (; i <= mid; i++)
        B[k++] = Array[i];

    for (; j <= high; j++)
        B[k++] = Array[j];

    for (int m = low; m <= high; m++)
        Array[m] = B[m];

    delete[] B;
}

void Iterative_Merge_Sort(int Array[], int n)
{
    int p, l, h, mid, i;

    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(Array, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(Array, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
        Merge(Array, 0, p / 2 - 1, n - 1);
}

void Recursive_Merge_Sort(int Array[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;

        Recursive_Merge_Sort(Array, low, mid);
        Recursive_Merge_Sort(Array, mid + 1, high);
        Merge(Array, low, mid, high);
    }
}

void Count_Sort(int Array[], int size)
{
    int max = *max_element(Array, Array + size);
    int *arr = new int[max + 1];

    for (int i = 0; i < size; i++)
        arr[Array[i]]++;

    int i = 0, j = 0;

    while (i < max + 1)
    {
        while (arr[i] > 0)
        {
            Array[j++] = i;
            arr[i]--;
        }
        i++;
    }

    delete[] arr;
}

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        this->next = NULL;
    }
};

class Bucket_Bin
{
public:
    Node **Bins;
    int max;
    Bucket_Bin(int Array[], int size)
    {
        this->max = *max_element(Array, Array + size);
        this->Bins = new Node *[this->max + 1];
    }

    void Insert(int x)
    {
        Node *temp = new Node;
        temp->data = x;

        if (this->Bins[x] == NULL)
            this->Bins[x] = temp;

        else
        {
            Node *p = this->Bins[x];

            while (p->next != NULL)
                p = p->next;

            p->next = temp;
        }
    }

    int Delete(int x)
    {
        Node *p = this->Bins[x];
        this->Bins[x] = this->Bins[x]->next;
        int r = p->data;
        delete p;
        return r;
    }
};

void Bin_Sort(int Array[], int size)
{
    Bucket_Bin *b = new Bucket_Bin(Array, size);

    for (int i = 0; i < size; i++)
        b->Insert(Array[i]);

    int i = 0, j = 0;

    while (i < b->max + 1)
    {
        while (b->Bins[i] != NULL)
        {
            Array[j++] = b->Delete(i);
        }
        i++;
    }

    delete b;
}

class Bucket
{
public:
    Node **Bins;
    int passes;

    Bucket(int Array[], int size)
    {
        int x = *max_element(Array, Array + size);
        int count = 0;
        while (x != 0)
        {
            x = x / 10;
            count++;
        }

        this->passes = count;
        this->Bins = new Node *[10];
    }

    void Insert(int index, int x)
    {
        Node *temp = new Node;
        temp->data = x;

        if (this->Bins[index] == NULL)
            this->Bins[index] = temp;

        else
        {
            Node *p = this->Bins[index];

            while (p->next != NULL)
                p = p->next;

            p->next = temp;
        }
    }

    int Delete(int index)
    {
        Node *p = this->Bins[index];
        this->Bins[index] = this->Bins[index]->next;
        int r = p->data;
        delete p;
        return r;
    }
};

void Radix_Sort(int Array[], int size)
{
    Bucket *b = new Bucket(Array, size);
    int x;

    for (int i = 0; i <= b->passes; i++)
    {
        for (int j = 0; j < size; j++)
        {
            x = (int)(Array[j] / pow(10, i)) % 10;
            b->Insert(x, Array[j]);
        }

        int k = 0, l = 0;

        while (k < 10)
        {
            while (b->Bins[k] != NULL)
            {
                Array[l++] = b->Delete(k);
            }
            k++;
        }
    }

    delete b;
}

auto get_time(int arr[], int size, void (*func)(int[], int))
{
    long int i = 0;
    double sum = 0;
    while (i < 10000000)
    {
        auto start = high_resolution_clock::now();
        func(arr, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        sum = sum + duration.count();
        i++;
    }
    cout << (double)sum / 10000000 << " nanoseconds" << endl;
}

auto get_time_r(int arr[], int size, void (*func)(int[], int, int))
{
    long int i = 0;
    double sum = 0;
    while (i < 10000000)
    {
        auto start = high_resolution_clock::now();
        func(arr, 0, size - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        sum = sum + duration.count();
        i++;
    }
    cout << (double)sum / 10000000 << " nanoseconds" << endl;
}

int *array(int x, int size)
{
    int *p = new int[size];

    if (x == 1)
    {
        for (int i = 0; i < size; i++)
            p[i] = i + 1;
    }
    else if (x == 2)
    {
        for (int i = size, j = 0; j < size; i--, j++)
            p[j] = i;
    }
    else if (x == 3)
    {
        int j;
        for (int i = 0; i < size; i++)
        {
            j = i;
            p[i] = j + 2;
            i++;
            p[i] = j + 1;
        }
    }

    return p;
}
int main()
{
    int size = 20;
    // 1 for sorted array
    // 2 for reverse sorted array
    // 3 for average array
    int Case = 2;
    int *arr = array(Case, size);


    cout << "Array = ";
    Print(arr, size);
    cout<<endl;


    cout << "Bubble Sort          : ";
    get_time(arr, size, &Bubble_Sort);


    arr = array(Case, size);
    cout << "Insertion Sort       : ";
    get_time(arr, size, &Insertion_Sort);
    

    arr = array(Case, size);
    cout << "Selection Sort       : ";
    get_time(arr, size, &Selection_Sort);


    arr = array(Case, size);
    cout << "Quick Sort           : ";
    get_time_r(arr, size, &Quick_sort);


    arr = array(Case, size);
    cout << "Merge recursive Sort : ";
    get_time_r(arr, size, &Recursive_Merge_Sort);


    arr = array(Case, size);
    cout << "Merge iterative Sort : ";
    get_time(arr, size, &Iterative_Merge_Sort);


    arr = array(Case, size);
    cout << "count Sort           : ";
    get_time(arr, size, &Count_Sort);

    // cout << "Bucket/Bin Sort      : ";
    // get_time(arr, size,&Bin_Sort);

    // cout << "Radix Sort           : ";
    // get_time(arr, size,&Radix_Sort);

    cout << "After sorting " << endl;
    Print(arr, size);

    return 0;
}