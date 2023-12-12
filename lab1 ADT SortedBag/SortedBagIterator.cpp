#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    this->current=0;
    this->ocurr=0;
}

TComp SortedBagIterator::getCurrent() {
    if(valid())
        return this->bag.elements[this->current].first;
    throw std::exception();
}

bool SortedBagIterator::valid() {
    if(this->current>this->bag.length-1 || this->ocurr>this->bag.elements[this->current].second)
	    return false;
    else
        return true;
}

void SortedBagIterator::next() {
    if(valid())
        if(this->ocurr<this->bag.elements[this->current].second-1){
            this->ocurr++;
        }
        else{
            this->ocurr=0;
            this->current++;
        }
    else
        throw exception();
}

void SortedBagIterator::first() {
	this->current=0;
    this->ocurr=0;
}

