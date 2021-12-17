#pragma once
#include <iostream>
#include<vector>
#include <ctime>
#include<stack>
#include<cmath>
using namespace std;
const double PI = 3.14159265;
struct hull
{
	double x;
	double y;
};
class Graham
{
public:
	
	
	vector<double>a;

	
	int Lowest_point(hull* value, const int n);
	void Angle(vector<double>& ps2, hull* point, const int n);
	double result(const hull& p1, const hull& p2, const hull& p3);
	bool leftTurn(const hull& a, const hull& b, const hull& c);
	void Stack(vector<double>& ang, hull* point);
	
};
class merge:public Graham
{
public:
	void Merge(vector<double>& a, double* mas_0, double* mas_1, double* mas_2, double* mas_3, double* mas_4, const int n);
	void Sort(double* mas, hull* b, const int n, int start, int end);
	void check(vector<double>& a, hull* b, double* mas_0, double* mas_1, double* mas_2, double* mas_3, double* mas_4, const int n);
	void Merge_Sort(vector<double>& a, hull* b, const int n);
	merge();
	
};
class heap:public Graham
{
public:
	void heapify(vector <double>& arr, hull* b, const int n, int i);
	void heapSort(vector <double>& arr, hull* b, const int n);
	heap();
	
};
