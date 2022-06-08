
//Omansh Arora
//301415265
//June 1 2022
#include "PlayList.h"
#include <iostream>

using namespace std;

// PlayList method implementations go here

PlayList::PlayList() : top(nullptr){}

PlayList::PlayList(const PlayList& pl){

    copy(pl);

}

PlayList& PlayList::operator=(const PlayList & pl){

    PlayList copy1(pl);
    deletePL();
    copy(copy1);
    return *this;

}

PlayList::~PlayList(){

    deletePL();
    lstSize = 0;
    top = nullptr;

}


void PlayList::insert(Song sng, unsigned int pos){

    if (pos == 0 && lstSize == 0){

        top = new PlayListNode(sng);
        lstSize++;
        return;

    } else if(pos == 0){

        PlayListNode* temp = new PlayListNode(sng, top);;
        top = temp;
        lstSize++;
        return;

    }

    PlayListNode* nxt = top->next;
    PlayListNode* prv = top;
    unsigned int i = 1;

    while (i != pos){
        
        prv = prv->next;
        nxt = nxt->next;
        i++;

    }

    PlayListNode* nNode = new PlayListNode(sng,nxt);
    prv->next = nNode;
    lstSize++;

    
}

Song PlayList::remove(unsigned int pos){

    if(pos == 0){

        PlayListNode* temp = top;
        top = temp->next;
        Song delSong = temp->song;
        lstSize--;
        delete temp;
        return delSong;

    }

    PlayListNode* nxt = top->next;
    PlayListNode* prv = top;
    unsigned int i = 1;

    while (i != pos){
        
        prv = prv->next;
        nxt = nxt->next;
        i++;

    }

    prv->next = nxt->next;
    Song delSong = nxt->song;
    delete nxt;
    lstSize--;
    return delSong;

    
}

void PlayList::swap(unsigned int pos1, unsigned int pos2){

    PlayListNode* nxt = top;
    unsigned int i = 0;

    while (i != pos1){
        
        nxt = nxt->next;
        i++;

    }

    Song sng1 = nxt->song;

    PlayListNode* nxt1 = top;
    i = 0;

    while (i != pos2){
        
        nxt1 = nxt1->next;
        i++;

    }

    nxt->song = nxt1->song;
    nxt1->song = sng1; 

}

Song PlayList::get(unsigned int pos) const{

    PlayListNode* nxt = top;
    unsigned int i = 0;

    while (i != pos){
        
        nxt = nxt->next;
        i++;

    }

    return nxt->song;

}

unsigned int PlayList::size() const{

    return lstSize;

}

