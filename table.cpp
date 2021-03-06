#include "table.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;


table::table(){ //initialize all entries to -1 and false
	m=0;
	for (int i = 0; i < MAX_SIZE; i++){
		a[i].data = -1;
		a[i].flag = false;
	}
}

//finds index to place x
int table::hash(double x){
	int index = int(x) % m;
	int index2;
	int i = 0;
	if (isfull()){	//check if full
		return m;	
	}
	else{
		while (i < m ){	//quadratic probing
			index2 = int(index + pow(i, 2.0)) % m;
			if (a[index2].data == -1){ //found empty spot
				return index2;
			}
			else{
				i++; //check new spot
			}
		}
	}
	return m;
}

//adds x to table
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

//removes x from table
void table::remove(double x){
	int index;
	if (contains(x)){	//checks if in table
		index = find(x);	//finds index
		a[index].data = -1; 
		a[index].flag = true;
	}
	else{
		cout << "Number not in table \n";
	}
}

//print table
void table::print(){
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

//finds index of x
int table::find(double x){//just like contains except returns the index
	int index = int(x) % m;
	int index2;
	int i = 0;
	while (i <= m ){
		index2 = int(index + pow(i, 2.0)) % m;
		if ((a[index2].data == -1) && (a[index2].flag == false)){
			return m;
		}
		else if ((a[index2].data == -1) && (a[index2].flag == true)){
			i++;
		}
		else if ((a[index2].data != -1) && (a[index2].data != x)){
			i++;
		}
		else if (a[index2].data == x){
			return index2;
		}
	}

	return false;
}

//sees if x is in table
bool table::contains(double x){
	int index = int(x) % m;
	int index2;
	int i = 0;
	while (i <= m ){
		index2 = int(index + pow(i, 2.0)) % m;
		if ((a[index2].data == -1) && (a[index2].flag == false)){	//empty bucket never filled 
			return false;
		}
		else if ((a[index2].data == -1) && (a[index2].flag == true)){	//empty bucket once filled
			i++;
		}
		else if ((a[index2].data != -1) && (a[index2].data != x)){	//filled bucket not x
			i++;
		}
		else if (a[index2].data == x){	//filled bucket x
			return true;
		}
	}

	return false;
}

//sees if table is full
bool table::isfull(){ 
	for(int i=0; i < m; i++){
		if (a[i].data == -1){
			return false;
		}
	}
return true;
}

//builds table
void table::build(ifstream& file){ 
	int item;
	file >> item;
	m = item;
	while (file >> item){
		insert(item);
	}
}

