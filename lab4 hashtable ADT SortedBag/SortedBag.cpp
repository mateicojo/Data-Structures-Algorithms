#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <cstdio>

SortedBag::SortedBag(Relation r) {
	//TODO - Implementation
    this->capacity=10000;
    this->relation=r;
    this->length=0;
    this->hash_table=new TElem[this->capacity];
    for(int i=0;i<this->capacity;i++)
        this->hash_table[i]=NULL_TCOMP;
    this->next=new int[this->capacity];
    for(int i=0;i<this->capacity;i++)
        this->next[i]=-1;
    this->head=-1;
}

void SortedBag::add(TComp e) {
    //TODO - Implementation
    //check first if the length is equal to the capacity
    if(this->length==this->capacity){
        this->resize();
        //if it is, we need to resize the hash table
    }

    int position=this->hash(e);
    if(this->hash_table[position]!=NULL_TCOMP){
        position=getFirstEmpty();
    }
    //case 1: the hash table is empty
    if(this->head==-1){
        this->head=position;
        this->hash_table[position]=e;
        this->next[position]=-1;
        this->length++;
//        printf("%d added first, the list is empty\n",this->hash_table[position]);
        return;
    }
    //case 2: the hash table is not empty
    int current=this->head;
    int previous=-1;
    while(current!=-1 && this->relation(this->hash_table[current],e)){
        previous=current;
//        printf("%d\n",this->hash_table[current]);
        current=this->next[current];
    }
    if(current==-1){
        this->next[previous]=position;
        this->hash_table[position]=e;
        this->next[position]=-1;
        this->length++;
//        printf("%d added last\n",this->hash_table[position]);
        return;
    }
    if(previous==-1){
        this->head=position;
        this->hash_table[position]=e;
        this->next[position]=current;
        this->length++;
//        printf("%d added first\n",this->hash_table[position]);
        return;
    }
    this->next[previous]=position;
    this->hash_table[position]=e;
    this->next[position]=current;
    this->length++;
//    printf("%d added in the middle\n",this->hash_table[position]);

    return;
}


bool SortedBag::remove(TComp e) {
	//TODO - Implementation
    int current=this->head;
    int previous=-1;
    while(current!=-1 && this->hash_table[current]!=e){
        previous=current;
        current=this->next[current];
    }
    if(current==-1){
        return false;
    }
    if(previous==-1){
        this->head=this->next[current];
        this->length--;
        return true;
    }
    this->next[previous]=this->next[current];
    this->length--;
    return true;
}


bool SortedBag::search(TComp elem) const {
    //TODO - Implementation
    int current=this->head;
    while(current!=-1 && this->hash_table[current]!=elem){
        current=this->next[current];
    }
    if(current==-1){
        return false;
    }
    return true;
}


int SortedBag::nrOccurrences(TComp elem) const {
    int current=this->head;
    int count=0;
    while(current!=-1){
        if(this->hash_table[current]==elem)
            count++;
        current=this->next[current];
    }
    return count;
}

int SortedBag::distinctCount() const {
    int app=0;
    int current=this->head;
    while(current!=-1){
        app++;
        if(this->hash_table[next[current]]==this->hash_table[current]){
            current=next[current];
            while(this->hash_table[next[current]]==this->hash_table[current]){
                current=next[current];
            }
        }
    }
    return app;
}


int SortedBag::size() const {
	return this->length;
}


bool SortedBag::isEmpty() const {
    return this->length==0;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	//TODO - Implementation
    delete[] this->hash_table;
    delete[] this->next;
}
