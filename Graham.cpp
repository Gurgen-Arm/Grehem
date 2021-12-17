#include "Graham.h"

int Graham::Lowest_point(hull* value, const int n)
{
    int k = 0;
    for (int i = 1; i < n; i++)
    {

        if (value[i].y < value->y)
        {

            k = i;
        }

    }
    

    return k;
}

void Graham::Angle(vector<double>& ps2, hull* point, const int n)
{
    ps2.resize(n);
    int j = Lowest_point(point, n);
    for (int i = 0; i < n; i++)
        ps2[i] = atan2(point[i].y - point[j].y, point[i].x - point[j].x) * 180 / PI;

    /*for (int i = 0; i < n; i++)
        cout << ps2[i] << endl;*/
}

double Graham::result(const hull& p1, const hull& p2, const hull& p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

bool Graham::leftTurn(const hull& a, const hull& b, const hull& c)
{
    return result(a, b, c) > 0;
}

void Graham::Stack(vector<double>& ang, hull* point)
{
    stack<int>S;
    S.push(0);
    S.push(1);

    for (int c = 2; c < ang.size(); c++)
    {
        int a, b;
        do
        {
            b = S.top();
            S.pop();
            a = S.top();
        }

        while (!leftTurn(point[a], point[b], point[c]));

        S.push(b);
        S.push(c);
    }

    cout << endl;
    while (!S.empty())
    {
        
        cout << point[S.top()].x << " " << point[S.top()].y<< endl;
        S.pop();
    }
}

void merge::Merge(vector<double>& a, double* mas_0, double* mas_1, double* mas_2, double* mas_3, double* mas_4, const int n)
{
    for (int i = 0; i < (int)(n / 5); i++)
    {
        a[i] = mas_0[i];
        a[i + (int)(n / 5)] = mas_1[i];
        a[i + 2 * (int)(n / 5)] = mas_2[i];
        a[i + 3 * (int)(n / 5)] = mas_3[i];
    }
    for (int i = 0, j = 4 * (int)(n / 5); i < (n - 4 * (int)(n / 5)) && j < n; i++, j++)
    {
        a[j] = mas_4[i];
    }
}

void merge::Sort(double* mas, hull* b, const int n, int start, int end)
{
    for (int i = 0, starti = start; (i < n) && (starti < end); i++, starti++)
    {
        for (int j = 0, startj = start; (j < n) && (startj < end); j++, startj++)
        {
            if (mas[j] > mas[i])
            {
                swap(mas[i], mas[j]);
                swap(b[starti], b[startj]);
            }
        }
    }
}

void merge::check(vector<double>& a, hull* b, double* mas_0, double* mas_1, double* mas_2, double* mas_3, double* mas_4, const int n)
{
    for (int i = 0; i < (int)(n / 5); i++)
    {

        if (mas_0[i] > mas_1[i])
        {
            swap(mas_0[i], mas_1[i]);
            swap(b[i], b[(int)(n / 5) + i]);
            Sort(mas_0, b, (int)(n / 5), 0, (int)(n / 5));
            Sort(mas_1, b, (int)(n / 5), (int)(n / 5), 2 * (int)(n / 5));

        }
        if (mas_0[i] > mas_2[i])
        {
            swap(mas_0[i], mas_2[i]);
            swap(b[i], b[2 * (int)(n / 5) + i]);
            Sort(mas_0, b, (int)(n / 5), 0, (int)(n / 5));
            Sort(mas_2, b, (int)(n / 5), 2 * (int)(n / 5), 3 * (int)(n / 5));
        }
        if (mas_0[i] > mas_3[i])
        {
            swap(mas_0[i], mas_3[i]);
            swap(b[i], b[3 * (int)(n / 5) + i]);
            Sort(mas_0, b, (int)(n / 5), 0, (int)(n / 5));
            Sort(mas_3, b, (int)(n / 5), 3 * (int)(n / 5), 4 * (int)(n / 5));

        }
        if (mas_0[i] > mas_4[i])
        {
            swap(mas_0[i], mas_4[i]);
            swap(b[i], b[4 * (int)(n / 5) + i]);
            Sort(mas_0, b, (int)(n / 5), 0, (int)(n / 5));
            Sort(mas_4, b, n - 4 * (int)(n / 5), 4 * (int)(n / 5), n);
        }

        //
        if (mas_1[i] > mas_2[i])
        {
            swap(mas_1[i], mas_2[i]);
            swap(b[(int)(n / 5) + i], b[2 * (int)(n / 5) + i]);
            Sort(mas_1, b, (int)(n / 5), (int)(n / 5), 2 * (int)(n / 5));
            Sort(mas_2, b, (int)(n / 5), 2 * (int)(n / 5), 3 * (int)(n / 5));
        }
        if (mas_1[i] > mas_3[i])
        {
            swap(mas_1[i], mas_3[i]);
            swap(b[(int)(n / 5) + i], b[3 * (int)(n / 5) + i]);
            Sort(mas_1, b, (int)(n / 5), (int)(n / 5), 2 * (int)(n / 5));
            Sort(mas_3, b, (int)(n / 5), 3 * (int)(n / 5), 4 * (int)(n / 5));
        }
        if (mas_1[i] > mas_4[i])
        {
            swap(mas_1[i], mas_4[i]);
            swap(b[(int)(n / 5) + i], b[4 * (int)(n / 5) + i]);
            Sort(mas_1, b, (int)(n / 5), (int)(n / 5), 2 * (int)(n / 5));
            Sort(mas_4, b, n - 4 * (int)(n / 5), 4 * (int)(n / 5), n);
        }

        //
        if (mas_2[i] > mas_3[i])
        {
            swap(mas_2[i], mas_3[i]);
            swap(b[2 * (int)(n / 5) + i], b[3 * (int)(n / 5) + i]);
            Sort(mas_2, b, (int)(n / 5), 2 * (int)(n / 5), 3 * (int)(n / 5));
            Sort(mas_3, b, (int)(n / 5), 3 * (int)(n / 5), 4 * (int)(n / 5));
        }
        if (mas_2[i] > mas_4[i])
        {
            swap(mas_2[i], mas_4[i]);
            swap(b[2 * (int)(n / 5) + i], b[4 * (int)(n / 5) + i]);
            Sort(mas_2, b, (int)(n / 5), 2 * (int)(n / 5), 3 * (int)(n / 5));
            Sort(mas_4, b, n - 4 * (int)(n / 5), 4 * (int)(n / 5), n);
        }


        //
        if (mas_3[i] > mas_4[i])
        {
            swap(mas_3[i], mas_4[i]);
            swap(b[3 * (int)(n / 5) + i], b[4 * (int)(n / 5) + i]);
            Sort(mas_3, b, (int)(n / 5), 3 * (int)(n / 5), 4 * (int)(n / 5));
            Sort(mas_4, b, n - 4 * (int)(n / 5), 4 * (int)(n / 5), n);
        }

    }


    for (int i = 0; i < 250; i++)
    {
        if (mas_1[0] < mas_0[(int)(n / 5) - 1])
        {
            swap(mas_1[0], mas_0[(int)(n / 5) - 1]);
            swap(b[(int)(n / 5)], b[(int)(n / 5) - 1]);
            Sort(mas_0, b, (int)(n / 5), 0, (int)(n / 5));
            Sort(mas_1, b, (int)(n / 5), (int)(n / 5), 2 * (int)(n / 5));
        }
        //
        if (mas_1[0] > mas_2[0])
        {
            swap(mas_1[0], mas_2[0]);
            swap(b[(int)(n / 5)], b[2 * (int)(n / 5)]);
            Sort(mas_1, b, (int)(n / 5), (int)(n / 5), 2 * (int)(n / 5));
            Sort(mas_2, b, (int)(n / 5), 2 * (int)(n / 5), 3 * (int)(n / 5));
        }
        //
        if (mas_2[0] < mas_1[(int)(n / 5) - 1])
        {
            swap(mas_2[0], mas_1[(int)(n / 5) - 1]);
            swap(b[2 * (int)(n / 5)], b[2 * (int)(n / 5) - 1]);
            Sort(mas_1, b, (int)(n / 5), (int)(n / 5), 2 * (int)(n / 5));
            Sort(mas_2, b, (int)(n / 5), 2 * (int)(n / 5), 3 * (int)(n / 5));
        }
        //
        if (mas_2[0] > mas_3[0])
        {
            swap(mas_2[0], mas_3[0]);
            swap(b[2 * (int)(n / 5)], b[3 * (int)(n / 5)]);
            Sort(mas_2, b, (int)(n / 5), 2 * (int)(n / 5), 3 * (int)(n / 5));
            Sort(mas_3, b, (int)(n / 5), 3 * (int)(n / 5), 4 * (int)(n / 5));
        }
        //
        if (mas_3[0] < mas_2[(int)(n / 5) - 1])
        {
            swap(mas_3[0], mas_2[(int)(n / 5) - 1]);
            swap(b[3 * (int)(n / 5)], b[3 * (int)(n / 5) - 1]);
            Sort(mas_2, b, (int)(n / 5), 2 * (int)(n / 5), 3 * (int)(n / 5));
            Sort(mas_3, b, (int)(n / 5), 3 * (int)(n / 5), 4 * (int)(n / 5));
        }
        //
        if (mas_3[0] > mas_4[0])
        {
            swap(mas_3[0], mas_4[0]);
            swap(b[3 * (int)(n / 5)], b[4 * (int)(n / 5)]);
            Sort(mas_3, b, (int)(n / 5), 3 * (int)(n / 5), 4 * (int)(n / 5));
            Sort(mas_4, b, n - 4 * (int)(n / 5), 4 * (int)(n / 5), n);
        }
        //
        if (mas_4[0] < mas_3[(int)(n / 5) - 1])
        {
            swap(mas_4[0], mas_3[(int)(n / 5) - 1]);
            swap(b[4 * (int)(n / 5)], b[4 * (int)(n / 5) - 1]);
            Sort(mas_3, b, (int)(n / 5), 3 * (int)(n / 5), 4 * (int)(n / 5));
            Sort(mas_4, b, n - 4 * (int)(n / 5), 4 * (int)(n / 5), n);
        }
    }

}

void merge::Merge_Sort(vector<double>& a, hull* b, const int n)
{
    if (n % 5 == 0)
    {
        double* mas_0 = new double[n / 5];
        double* mas_1 = new double[n / 5];
        double* mas_2 = new double[n / 5];
        double* mas_3 = new double[n / 5];
        double* mas_4 = new double[n / 5];
        for (int i = 0; i < n / 5; i++)
        {
            mas_0[i] = a[i];
            mas_1[i] = a[i + n / 5];
            mas_2[i] = a[i + 2 * n / 5];
            mas_3[i] = a[i + 3 * n / 5];
            mas_4[i] = a[i + 4 * n / 5];

        }
        Sort(mas_0, b, n / 5, 0, n / 5);
        Sort(mas_1, b, n / 5, n / 5, 2 * n / 5);
        Sort(mas_2, b, n / 5, 2 * n / 5, 3 * n / 5);
        Sort(mas_3, b, n / 5, 3 * n / 5, 4 * n / 5);
        Sort(mas_4, b, n / 5, 4 * n / 5, n);

        check(a, b, mas_0, mas_1, mas_2, mas_3, mas_4, n);
        Merge(a, mas_0, mas_1, mas_2, mas_3, mas_4, n);
        /*for (int i = 0; i < n; i++)
            cout << a[i] << endl;*/

    }
    else
    {
        double* mas_0 = new double[(int)(n / 5)];
        double* mas_1 = new double[(int)(n / 5)];
        double* mas_2 = new double[(int)(n / 5)];
        double* mas_3 = new double[(int)(n / 5)];
        double* mas_4 = new double[n - 4 * (int)(n / 5)];
        for (int i = 0; i < (int)(n / 5); i++)
        {
            mas_0[i] = a[i];
            mas_1[i] = a[i + (int)(n / 5)];
            mas_2[i] = a[i + 2 * (int)(n / 5)];
            mas_3[i] = a[i + 3 * (int)(n / 5)];
        }
        for (int i = 0, j = 4 * (int)(n / 5); i < n - 4 * (int)(n / 5); i++, j++)
        {

            mas_4[i] = a[j];
        }
        Sort(mas_0, b, (int)(n / 5), 0, (int)(n / 5));
        Sort(mas_1, b, (int)(n / 5), (int)(n / 5), 2 * (int)(n / 5));
        Sort(mas_2, b, (int)(n / 5), 2 * (int)(n / 5), 3 * (int)(n / 5));
        Sort(mas_3, b, (int)(n / 5), 3 * (int)(n / 5), 4 * (int)(n / 5));
        Sort(mas_4, b, n - 4 * (int)(n / 5), 4 * (int)(n / 5), n);
        check(a, b, mas_0, mas_1, mas_2, mas_3, mas_4, n);
        cout << endl;
        Merge(a, mas_0, mas_1, mas_2, mas_3, mas_4, n);
        /*for (int i = 0; i < n; i++)
            cout << a[i] << endl;*/
        
    }
}

merge::merge()
{
    const int N = 1000;
    
    hull* b = new hull[N];
    for (int i = 0; i < N; i++)
    {
        b[i].x = rand() % 1000;
        b[i].y = rand() % 1000;
    }

    Angle(a, b, N);
    unsigned int start_time = clock();
    Merge_Sort(a, b, N);
   
    unsigned int end_time = clock(); // конечное врем€
    unsigned int search_time = end_time - start_time;
    cout << "Merge Sort Time: " << search_time << endl;
    Stack(a, b);
    delete[] b;
}



void heap::heapify(vector<double>& arr, hull* b, int n, int i)
{
    int largest = i;
    
    int l = 3 * i + 1; // левый = 3*i + 1
    int c = 3 * i + 2;// центральный = 3*i + 2
    int r = 3 * i + 3; // правый = 3*i + 3

    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (c < n && arr[c] > arr[largest])
        largest = c;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // ≈сли самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        swap(b[i], b[largest]);
        
        heapify(arr, b, n, largest);
    }
}

void heap::heapSort(vector<double>& arr, hull* b, int n)
{
    
    for (int i = n / 3 - 1; i >= 0; i--)
        heapify(arr, b, n, i);


   
    for (int i = n - 1; i >= 0; i--)
    {
       

        swap(arr[0], arr[i]);
        swap(b[0], b[i]);

        
        heapify(arr, b, i, 0);
    }
}
heap::heap()
{
    const int N = 1000;

    hull* b = new hull[N];
    for (int i = 0; i < N; i++)
    {
        b[i].x = rand() % 1000;
        b[i].y = rand() % 1000;
    }
    
    Angle(a, b, N);
    unsigned int start_time = clock();
    heapSort(a, b, N);
    unsigned int end_time = clock(); // конечное врем€
    unsigned int search_time = end_time - start_time;
    cout <<"Heap Sort Time: "<< search_time << endl;
    Stack(a, b);
    delete[] b;
}





