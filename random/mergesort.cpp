#include <iostream>
#include <vector>

using namespace std;

void Merge(int *a, int i, int mid, int j)
{
    int p = i;
    int q = mid + 1;
    int size = j - i + 1;
    int merged[size];

    for (int k = 0; k < size; k++)
    {
        if (p > mid && q <= j)
        {
            merged[k] = a[q];
            q++;
        }
        else if (q > j)
        {
            merged[k] = a[p];
            p++;
        }
        else
        {
            if (a[p] < a[q])
            {
                merged[k] = a[p++];
            }
            else
            {
                merged[k] = a[q++];
            }
        }
    }

    for (int k = 0; k < size; k++)
    {
        a[i + k] = merged[k];
    }
}

void MergeSort(int *a, int i, int j)
{
    if (i == j)
        return;
    int mid = (i + j) / 2;
    MergeSort(a, i, mid);
    MergeSort(a, mid + 1, j);
    Merge(a, i, mid, j);
}

int main()
{
    int a[7] = {10, 23, 45, 23, 43, 28, 65};

    for (int i = 0; i < 7; i++)
    {
        std::cout << a[i] << ' ';
    }
    cout << '\n';

    MergeSort(a, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        std::cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}
