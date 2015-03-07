#ifndef SEQUENCE_CLASS_H
#define SEQUENCE_CLASS_H

typedef int EType;

class Sequence {
	
	friend std::ostream &operator<<(std::ostream &os, const Sequence &sequence) {
		os << '{';
		for (int i = 0; i < sequence.size; i++)
			os << sequence.arr[i] << (i < sequence.size -1 ? ", " : "");
		os << "}";
		return os;
	}

	private :
		int size, capacity;
		EType *arr;

	public :
		Sequence();

		EType get(int index);
		void set(int index, const EType &Element);
	   	void insertBack(const EType &Element);
		EType removeBack();
		void insert(int index, const EType &Element);
		EType remove(int index);
		EType &front();
		EType &back();
		int find(const EType &Element);
		bool search(const EType &Element);
		void sort();
		int getSize() {return size;}
		int getCapacity() {return capacity;}
		void expand();
		void shrink();
};

#endif
