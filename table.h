#ifndef TABLE_H
#define TABLE_H

#include "list.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 101;

class table{
private:
	double a[MAX_SIZE];
	int m;

public:
	table();
	//~table();
	int hash(double x);
	void insert(double x);
	void remove(double x);
	void print();
	bool contains(double x);
	bool isfull();
	void build(ifstream& file);
	// getArray();

};



#endif
