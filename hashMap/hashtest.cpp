
#include "hashMap/hashmap.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    Hashmap<string> map;

    map.set(3, "7");
    map.set(26, "9");

    //map.printMap();
    map.printList(3);

    cout<<"74 "<<map.get(74)<<"\n";
    cout<<"26 "<<map.get(26)<<"\n";
    map.del(26);
    cout<<"26 "<<map.get(26)<<"\n";

    map.deleteMap();

    return 0;
}
