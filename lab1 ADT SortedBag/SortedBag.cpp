#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <malloc.h>

SortedBag::SortedBag(Relation r) {
    this->elements=new Pair [1];
    this->capacity=1;
    this->length=0;
    this->relation=r;
}

void SortedBag::add(TComp e) {
    //has complexity O(n) worst case: if e's correct position is on the last position in the array
    if(this->length==0){
        this->elements[0].first=e;
        this->elements[0].second=1;
        this->length++;
        return;
    }
    if(this->length==this->capacity){
        this->capacity*=3;
        Pair* newelements=new Pair[this->capacity];
        for(int i =0;i<this->length;i++){
            newelements[i]=this->elements[i];
        }
        delete[] this->elements;
        this->elements=newelements;
    }
    int index=0;
    while(index<this->length && relation(this->elements[index].first,e)){
        index++;
    }
    if(this->elements[index-1].first==e){
        this->elements[index-1].second++;
        return;
    }
    else{
        this->length++;
        for( int i=this->length-1;i>index;i--){
            this->elements[i]=this->elements[i-1];
        }
        this->elements[index].first=e;
        this->elements[index].second=1;
    }
}



bool SortedBag::remove(TComp e) {
//has complexity O(n) for every case: Theta(n)
    if(!search(e))
        return false;
    for(int i=0;i<this->length;i++){
        if(this->elements[i].first==e) {
            if (this->elements[i].second > 1) {
                this->elements[i].second--;
                return true;
            } else {
                for (int j = i; j < this->length - 1; j++) {
                    this->elements[j] = this->elements[j + 1];
                }
                this->length--;
                return true;
            }
        }
    }
}


bool SortedBag::search(TComp elem) const {
    //O(n)
	for(int i=0;i<this->length;i++){
        if(this->elements[i].first==elem)
            return true;
    }
	return false;
}


int SortedBag::nrOccurrences(TComp elem) const {
    //O(n)
    if(search(elem))
        for(int i =0;i<this->length;i++){
            if(this->elements[i].first==elem)
                return this->elements[i].second;
        }
    return 0;
}

int SortedBag::removeOccurrences(int nr, TElem elem) {
    //complexity O(n)
    int times_deleted=0;
    if(!search(elem))
        return 0;
    for(int i=0;i<this->length;i++){
        if(this->elements[i].first==elem){
            if(this->elements[i].second<=nr){
                times_deleted=this->elements[i].second;
                remove(elem);
                return times_deleted;
            }
        }
    }
}


int SortedBag::size() const {
    int nrEl=0;
    if(this->length==0)
        return 0;
	for(int i=0;i<this->length;i++){
        nrEl+=this->elements[i].second;
    }
    return nrEl;
}


bool SortedBag::isEmpty() const {
	if(this->length==0)
        return true;
	return false;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    delete[] this->elements;
}
