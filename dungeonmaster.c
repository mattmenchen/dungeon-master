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
    FILE *fp = fopen("dungeonRoomList_large.txt", "r");
    char fileBuffer[512];
    int lines = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines ++;
        }
    }

    int numOfRooms = lines / 4;






    fclose(fp);
    return 0;
}