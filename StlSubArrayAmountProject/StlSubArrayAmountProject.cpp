#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename Iterator>
void ContainerInit(Iterator begin, Iterator end);
template <typename Iterator>
void ContainerPrint(Iterator begin, Iterator end);

double PowerBinReq(double x, int n);
double PowerBinLoop(double x, int n);

int main()
{
    int size = 5;
    vector<int> array(2 * size);
    ContainerInit(array.begin(), array.end());
    ContainerPrint(array.begin(), array.end());

    /*
    int iMax = 0;
    int amountMax = array[0];
    for (int i = 0; i < size + 1; i++)
    {
        int amount = 0;
        for (int j = i; j < j + size; j++)
            amount += array[j];
        if (amount > amountMax)
        {
            iMax = i;
            amountMax = amount;
        }
    }
    */

    int iMax = 0;
    int amountMax = 0;
    for (int i = iMax; i < size; i++)
        amountMax += array[i];

    int amountCurr = amountMax;
    for (int i = 1; i < size + 1; i++)
    {
        int amount = amountCurr - array[i - 1] + array[i + size - 1];
        if(amount > amountMax)
        {
            iMax = i;
            amountMax = amount;
        }
        amountCurr = amount;
    }

}

template <typename Iterator>
void ContainerInit(Iterator begin, Iterator end)
{
    generate(begin, end, []()
        {
            return rand() % 100;
        });
}

template <typename Iterator>
void ContainerPrint(Iterator begin, Iterator end)
{
    for_each(begin, end, [](auto item)
        {
            cout << item << " ";
        });
    cout << "\n";
}

double PowerBinReq(double x, int n)
{
    if (!n)
        return 1;
    if (n % 2)
        return PowerBinReq(x, n - 1) * x;
    else
    {
        int p = PowerBinReq(x, n / 2);
        return p * p;
    }
}

double PowerBinLoop(double x, int n)
{
    int power{ 1 };
    while (n)
    {
        if (n & 1)
            power *= x;
        power *= power;
        n >>= 1;
    }
    return power;
}