#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// room structure
typedef struct{
    char name[50];
    char code[3];
    char desc[512];
} Room;

// function to print the room code and the room
void printRoom(Room *theRoom){
    printf("Room %s: %s\n", theRoom->code, theRoom->name);
}



int main(){
    return 0;
}