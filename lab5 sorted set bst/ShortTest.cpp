#include "ShortTest.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <assert.h>
#include <iostream>
using namespace std;

bool r2(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}


void testAll() {
    SortedSet s(r2);

    // Test adding elements
    assert(s.add(5) == true);
    assert(s.add(3) == true);
    assert(s.add(8) == true);
    assert(s.add(1) == true);
    assert(s.add(5) == false);  // Adding duplicate element
    assert(s.add(7) == true);
    cout<<"size: "<<s.size()<<endl;
    // Test searching for elements
    assert(s.search(5) == true);  // Existing element
    assert(s.search(2) == false); // Non-existing element
    assert(s.search(1) == true);
    cout<<"size: "<<s.size()<<endl;
    // Test removing elements
    assert(s.remove(3) == true);  // Existing element
    assert(s.remove(6) == false); // Non-existing element
    assert(s.remove(5) == true);  // Existing element
    assert(s.remove(1) == true);  // Existing element
    cout<<"size: "<<s.size()<<endl;
    // Verify the final state of the set
    assert(s.size() == 2);
    assert(s.search(3) == false);
    assert(s.search(5) == false);
    assert(s.search(8) == true);
    assert(s.search(1) == false);
    assert(s.search(7) == true);
    cout<<"size: "<<s.size()<<endl;





//	int vverif[5];
//	int iverif;
//	TComp e;
//
//	SortedSet s1(r2);
//	assert(s1.add(5) == true);
//    assert(s1.add(1) == true);
//    assert(s1.add(10) == true);
//
//	SortedSetIterator it1 = s1.iterator();
//	it1.first();
//	e = it1.getCurrent();
//	iverif = 0;
//	vverif[iverif++] = e;
//	it1.next();
//	while (it1.valid()) {
//		assert(e < it1.getCurrent());
//		e = it1.getCurrent();
//		vverif[iverif++] = e;
//		it1.next();
//	}
//	assert((vverif[0] == 1) && (vverif[1] == 5) && (vverif[2] == 10));
//
//
//	SortedSet s(r2);
//	assert(s.isEmpty() == true);
//	assert(s.size() == 0);
//    assert(s.add(5) == true);
//    assert(s.add(1) == true);
//    assert(s.add(10) == true);
//	assert(s.add(7) == true);
//	assert(s.add(1) == false);
//	assert(s.add(10) == false);
//	assert(s.add(-3) == true);
//	assert(s.size() == 5);
//	assert(s.search(10) == true);
//	assert(s.search(16) == false);
//	assert(s.remove(1) == true);
//	assert(s.remove(6) == false);
//	assert(s.size() == 4);
//    cout<<"Test iterator"<<endl;
//	SortedSetIterator it = s.iterator();
//    cout<<"Test first"<<endl;
//	iverif = 0;
//	it.first();
//    cout<<"Test valid"<<endl;
//	e = it.getCurrent();
//    cout<<"Test next"<<endl;
//	vverif[iverif++] = e;
//	it.next();
//    cout<<"Test valid"<<endl;
//	while (it.valid()) {
//        assert(r2(e, it.getCurrent()));
//        cout<<e<< " " <<it.getCurrent()<<endl;
//
//        e = it.getCurrent();
//        vverif[iverif++] = e;
//        it.next();
//    }
//	assert((vverif[0] == -3) && (vverif[1] == 5) && (vverif[2] == 7) && (vverif[3] == 10));

}

