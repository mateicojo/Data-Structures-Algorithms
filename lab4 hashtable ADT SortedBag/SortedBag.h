#pragma once
#include <cmath>
//DO NOT INCLUDE SORTEDBAGITERATOR

//DO NOT CHANGE THIS PART
typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TCOMP -11111

class SortedBagIterator;

class SortedBag {
	friend class SortedBagIterator;

private:
	//TODO - Representation
    Relation relation;
    int capacity;
    int length;
    TElem* hash_table;
    int* next;
    int hash(TComp e) const{
        return abs(e) % capacity;
    }
    int head;
    int first_empty;
    int getFirstEmpty() const {
        for (int i = 0; i < capacity; i++) {
            if (hash_table[i] == NULL_TCOMP) {
                return i;
            }
        }
        return -1;
    }
    void resize(){
        this->capacity*=2;
        TElem* new_hash_table=new TElem[this->capacity];
        int* new_next=new int[this->capacity];
        for(int i=0;i<this->capacity;i++)
            new_next[i]=-1;
        for(int i=0;i<this->length;i++){
            new_hash_table[i]=this->hash_table[i];
            new_next[i]=this->next[i];
        }
        delete[] this->hash_table;
        delete[] this->next;
        this->hash_table=new_hash_table;
        this->next=new_next;
        this->first_empty=this->length;
    }

public:
	//constructor
	SortedBag(Relation r);

	//adds an element to the sorted bag
	void add(TComp e);

	//removes one occurence of an element from a sorted bag
	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)
	bool remove(TComp e);

	//checks if an element appears in the sorted bag
	bool search(TComp e) const;

	//returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e) const;

	//returns the number of elements from the sorted bag
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator() const;

	//checks if the sorted bag is empty
	bool isEmpty() const;

    int distinctCount() const;

	//destructor
	~SortedBag();
};