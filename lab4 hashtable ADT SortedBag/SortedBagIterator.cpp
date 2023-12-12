#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	//TODO - Implementation
    size = bag.length;
    elements = new TComp[size];
    current = 0;
    createSortedArray();
}

TComp SortedBagIterator::getCurrent() {
	//TODO - Implementation
    if (!valid()) {
        throw std::exception();
    }
    return elements[current];
}

bool SortedBagIterator::valid() {
    //TODO - Implementation
    return current >= 0 && current < size;
}

void SortedBagIterator::next() {
    //TODO - Implementation
    if (!valid()) {
        throw std::exception();
    }
    current++;
}

void SortedBagIterator::first() {
    current=0;
}

