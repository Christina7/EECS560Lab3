#include "table.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;


table::table(){
	m=0;
}

/*table::~table(){
	delete [] a;
	a = NULL;
}*/

int table::hash(double x){
	int index = int(x) % m;
	return index;
}

void table::insert(double x){
	int index = hash(x);
	a[index].insert(x, a[index].getHead());
}

void table::remove(double x){
	bool isThere = find(x);
	int index = hash(x);
	if (isThere == true){
		a[index].erase(x, a[index].getHead());
	}
	else{
		cout << "Number not in table";
	}
}

void table::print(){//almost done need struct stuff
	for (int i = 0; i < m; i++){
		cout << i << ": " << a[i] << "flag = ";
		cout << endl;
	}
}

bool table::contains(double x){
	return true;
}

bool table::isfull(){ //done
	for(int i=0; i < m; i++){
		if (a[i] == NULL){
			return false;
		}
	}
return false;
}

void table::build(ifstream& file){ //done
	int item;
	file >> item;
	m = item;
	while (file >> item){
		insert(item);
	}
}

/*list*& table::getArray(){
	return a;
}*/
