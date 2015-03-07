#include <iostream>
#include <sstream>
#include <queue>

#include "sequence_class.h"

Sequence::Sequence() : size(0), capacity(100) {arr = new EType[capacity];}

EType Sequence::get(const int index) {
	if(index > size || index < 0){
		std::cerr << "Desired index is out of bounds.\n";
		return -1;
	}
	else
		return arr[index];
}

void Sequence::set(int index, const EType &Element) {
	if(index > size || index < 0){
		std::cerr << "Desired index is out of bounds.\n";
		return;
	}
	else
		arr[index] = Element;
}

void Sequence::insertBack(const EType &Element){   
	if(size >= capacity) {
		expand();
		arr[size] = Element;
		size++;
	}
	else {
		arr[size] = Element;
		size++;
	}
}

EType Sequence::removeBack(){
	if(size == 0){
		std::cerr << "Nothing to remove.\n";
		return -1;
	}
	else {
		EType temp = arr[size-1];
		size--;
		if(size <= (capacity/2)-5)
			shrink();
		return temp;
	}

}

void Sequence::insert(int index, const EType &Element){
	if(size >= capacity) {
		expand();
		for(int i = size; i > index; i--){
			arr[i] = arr[i-1];
		}
		arr[index] = Element;
		size++;
	}
	else {
		for(int i = size; i > index; i--){
			arr[i] = arr[i-1];
		}
		arr[index] = Element;
		size++;
	}
}

EType Sequence::remove(int index){
	if(size == 0){
		std::cerr << "Nothing to remove.\n";
		return -1;
	}
	else {
		EType removed = arr[index];
		size--;
		for(int j = index; j < size; j++){
			arr[j] = arr[j+1];
		}
		if(size <= (capacity/2)-5)
			shrink();
		return removed;
	}
	
}

EType &Sequence::front(){
	   static EType ref1 = arr[0];
	   return ref1;
}

EType &Sequence::back(){
	   static EType ref2 = arr[size-1];
	   return ref2;
}

EType Sequence::find(const EType &Element){
	for(int i = 0; i < size; i++){
		   if(Element == arr[i]){
				 return i;
		   }
	}
	return -1;
}

bool Sequence::search(const EType &Element){
	return (find(Element) != -1) ? true : false;
}

void Sequence::sort(){
	std::priority_queue<EType> pq;

	for(int i = 0; i < size; i++){
		   pq.push(arr[i]);
	}

	for(int i = size-1; i >= 0; i--){
		   arr[i] = pq.top();
		   pq.pop();
	}
}

void Sequence::expand() {
	EType *temp = new EType[2*capacity];
	for (int i = 0; i < capacity; i++)
		temp[i] = arr[i];
	delete [] arr;
	arr = temp;
	capacity*=2;
}

void Sequence::shrink() {
	EType *temp = new EType[capacity/2];
	for(int i = 0; i < (capacity/2)-5; i++)
		temp[i] = arr[i];
	delete [] arr;
	arr = temp;
	capacity/=2;
}

