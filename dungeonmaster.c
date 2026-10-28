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


// removes "Room Code: " from the beginning of the line in the text file
char* removeRoomCode(char *string){
    char *prefix = "Room Code: ";
    int prefixLen = strlen(prefix);

    // if the beginning of the string is "Room code: " then copies it to a new location without the prefix
    if (strncmp(string, prefix, prefixLen) == 0){
        memmove(string, string + prefixLen, strlen(string) - prefixLen + 1);
    }
    return *string;
}

char removeRoomName(char *string){
    char *prefix = "Room Name: ";
    int prefixLen = strlen(prefix);

    // if the beginning of the string is "Room Name: " then copies it to a new location without the prefix
    if (strncmp(string, prefix, prefixLen) == 0){
        memmove(string, string + prefixLen, strlen(string) - prefixLen + 1);
    }
    return *string;
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

    // puts the file pointer to the beginning again
    rewind(fp);

    fclose(fp);
    return 0;
}