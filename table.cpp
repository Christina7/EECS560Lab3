#include "table.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;


table::table(){
	m=0;
	for (int i = 0; i < MAX_SIZE; i++){
		a[i].data = -1;
		a[i].flag = false;
	}
}

/*table::~table(){
	delete [] a;
	a = -1;
}*/

int table::hash(double x){
	int index = int(x) % m;
	int index2;
	int i = 0;
	if (isfull()){
		return m;
	}
	else{
		while (i < (m * 2)){
			index2 = int(index + pow(i, 2.0)) % m;
			if (a[index2].data == -1){
				return index2;
			}
			else{
				i++;
			}
		}
	}
	return m;
}

void table::insert(double x){
	int index = hash(x);
	if (index == m){
		cout << "Hash table full \n";
	}
	else if(contains(x)){
		cout << "Number already in list \n";
	}
	else{
		a[index].data = x;
	}
}

void table::remove(double x){
	int index = hash(x);
	if (contains(x)){
		a[index].data = -1; 
		a[index].flag = true;
	}
	else{
		cout << "Number not in table \n";
	}
}

void table::print(){//almost done need struct stuff
	for (int i = 0; i < m; i++){
		cout << i << ": " << a[i].data << " flag = ";
		if (a[i].flag){
			cout << "true";
		}
		else{
			cout << "false";
		}
		cout << endl;
	}
}



bool table::contains(double x){//done
	int index = int(x) % m;
	int index2;
	int i = 0;
	while (i < (m * 2)){/////////////////////////////////m *2 to <= m
		index2 = int(index + pow(i, 2.0)) % m;
		if ((a[index2].data == -1) && (a[index2].flag == false)){
			//if (a[index2].data == -1){
			return false;
		}
		else if ((a[index2].data == -1) && (a[index2].flag == true)){
			i++;
		}
		else if ((a[index2].data != -1) && (a[index2].data != x)){
			i++;
		}
		else if (a[index2].data == x){
			return true;
		}
	}

	return false;
}


bool table::isfull(){ //done
	for(int i=0; i < m; i++){
		if (a[i].data == -1){
			return false;
		}
	}
return true;
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
