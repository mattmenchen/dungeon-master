#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// room structure
typedef struct{
    char name[50];
    char code[3];
    char desc[1024];
} Room;


// function to print the room code and the room
void printRoom(Room *theRoom){
    printf("Room %s: %s\n", theRoom->code, theRoom->name);
}


// removes the newline character
void stripNewLine( char *string) {
    int len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
        len--;
    }
    if (len > 0 && string[len - 1] == '\r'){
        string[len - 1] = '\0';
    }
}


// removes "Room Code: " from the beginning of the line in the text file
char* removeRoomCode(char *string){
   char *prefix = "Room Code: ";
    int prefixLen = strlen(prefix);


   // if the beginning of the string is "Room code: " then copies it to a new location without the prefix
    if (strncmp(string, prefix, prefixLen) == 0){
        memmove(string, string + prefixLen, strlen(string) - prefixLen + 1);
    }
    stripNewLine(string);
    return string;
}


char* removeRoomDesc(char *string){
   char *prefix = "Room Description: ";
    int prefixLen = strlen(prefix);


   // if the beginning of the string is "Room Description: " then copies it to a new location without the prefix
    if (strncmp(string, prefix, prefixLen) == 0){
        memmove(string, string + prefixLen, strlen(string) - prefixLen + 1);
    }
    stripNewLine(string);
    return string;
}


char* removeRoomName(char *string){
   char *prefix = "Room Name: ";
    int prefixLen = strlen(prefix);


   // if the beginning of the string is "Room Name: " then copies it to a new location without the prefix
    if (strncmp(string, prefix, prefixLen) == 0){
        memmove(string, string + prefixLen, strlen(string) - prefixLen + 1);
    }
    stripNewLine(string);
    return string;
}




int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("Error: Missing file argument.\n");
        return 1;
    }
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file. Check if the file exists in this directory.\n");
        return 1;
    }
    char fileBuffer[1024];
    int lines = 0;
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines ++;
        }
    }


    int numOfRooms = lines / 4;


   // puts the file pointer to the beginning again
    rewind(fp);


   Room *dungeon = malloc(sizeof(Room) * numOfRooms);
    if (dungeon == NULL) {
        printf("Could not allocate memory.\n");
        fclose(fp);
        return 1;
    }




    for (int i = 0; i <numOfRooms; i++) {
       // reads room name
        if (fgets(fileBuffer, sizeof(fileBuffer), fp) != NULL) {
            removeRoomName(fileBuffer);
            strncpy(dungeon[i].name, fileBuffer, (sizeof(dungeon[i].name) - 1));
            dungeon[i].name[sizeof(dungeon[i].name) - 1] = '\0';
        } else break;
       // reads room code
        if (fgets(fileBuffer, sizeof(fileBuffer), fp) != NULL){
            removeRoomCode(fileBuffer);
            strncpy(dungeon[i].code, fileBuffer, 2);
            dungeon[i].code[2] = '\0';
        } else break;
       // reads room description
        if (fgets(fileBuffer, sizeof(fileBuffer), fp) != NULL) {
            removeRoomDesc(fileBuffer);
            strncpy(dungeon[i].desc, fileBuffer, sizeof(dungeon[i].desc) - 1);
            dungeon[i].desc[sizeof(dungeon[i].desc) - 1] = '\0';
        } else break;
       // reads the line separating the rooms
        fgets(fileBuffer, sizeof(fileBuffer), fp);
    }


    for (int i = 0; i < numOfRooms; i++) {
        printRoom(&dungeon[i]);
    }




    free(dungeon);


    fclose(fp);
    return 0;
}

