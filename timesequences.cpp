#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <queue>
#include <cstdlib>
#include "timer.h"
#include "sequence_class.h"

using namespace std;

int main(){
	Sequence seq1;
	Sequence seq2;
	Sequence seq3;
	Sequence seq4; 
	Timer t1("insertBack Timer");
	Timer t2("insert Timer");
	Timer t3("insert Timer");
	Timer t4("insert Timer");
	
	cout << "Timing insertBack and insert functions for 50000 insertions.\n\n";
	
	t1.start();
	for(int i = 0; i < 50000; i++){
		seq1.ensureCapacity(i);	
		seq1.insertBack(i);
	}
	t1.stop();
	
	cout << t1.getName() << " : " << t1 << endl;
	
	t2.start();
	for(int i = 0; i < 50000; i++){
		seq2.ensureCapacity(i);	
		seq2.insert(0, i);
	}
	t2.stop();
	
	cout << t2.getName() << " for the front : " << t2 << endl;
	
	t3.start();
	for(int i = 0; i < 50000; i++){
		seq3.ensureCapacity(i);	
		seq3.insert(seq3.getSize()/2, i);
	}
	t3.stop();
	
	cout << t3.getName() << " for the middle : " << t3 << endl;
	
	t4.start();
	for(int i = 0; i < 50000; i++){
		seq4.ensureCapacity(i);
		seq4.insert(rand()%(seq4.getSize()+1), i);
	}
	t4.stop();
	
	cout << t4.getName() << " for a random index : " << t4 << endl;
	
	return 0;
}
