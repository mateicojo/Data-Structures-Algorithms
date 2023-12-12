#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);

	//TODO - Representation
    int current;
    TComp* elements;
    int size;
    void createSortedArray()
    {

    }
//    TComp* sort(SortedBag b){
//        //returns a sorted array of the elements in the bag
//        TComp* sorted_array=new TComp[b.length];
//        int i=0;
//        int current=b.head;
//        while(current!=-1){
//            sorted_array[i]=b.hash_table[current];
//            current=b.next[current];
//            i++;
//        }
//    }
public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

