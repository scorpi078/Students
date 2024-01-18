#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char name[50];
    char lastName[50];
    int facultyNumber;
    struct item* next;
} item;

item* front = NULL;

void insert_l(char* name, char* lastName, int facultyNumber) 
{	
    item* newitem = (item*)malloc(sizeof(item));
    strcpy(newitem->name, name);
    strcpy(newitem->lastName, lastName);
    newitem->facultyNumber = facultyNumber;
    printf("Vuvedete student:");
    scanf("%49s", newitem->name);
    scanf("%49s", newitem->lastName);
    printf("Vuvedete fakulteten nomer:");
    scanf("%d", &newitem->facultyNumber);
    if (front == NULL || strcmp(front->name, newitem->name) >= 0 || front->facultyNumber >= newitem->facultyNumber)
    {
        newitem->next = front;
        front = newitem;
    }
    else
    {
        item *curr = front;
        item* prev = NULL;
        while (curr != NULL && strcmp(curr->name, name) < 0) 
        { 
            prev = curr;
            curr = curr->next;
        }
        prev->next = newitem;
        newitem->next = curr;
    } 
}
void search_l(char* name, char* lastName, int facultyNumber)
{	
    printf("Vuvedete fakulteten nomer:");
    scanf("%d", &facultyNumber);
    item* curr = front;
    item* prev = NULL; 
    while (curr != NULL && curr->facultyNumber != facultyNumber) 
    {
        prev = curr;
        curr = curr->next; 
    }
    if (curr == NULL)  
        printf("Studentyt ne e nameren\n");
    else 
    {
        printf("%s %s, %d\n", curr->name, curr->lastName, facultyNumber);  
    } 	
}
void delete_l(char* name, char* lastName, int facultyNumber) {
    printf("Vuvedete fakulteten nomer:");
    scanf("%d", &facultyNumber);
    if (front == NULL) {
        printf("empty list\n");
        return;
    }
    item* curr = front;
    item* prev = NULL;
    while (curr != NULL && curr->facultyNumber != facultyNumber) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Studentyt ne e nameren\n");
    } else {
        printf("%s %s, %d is deleted\n", curr->name, curr->lastName, facultyNumber);
        if (prev == NULL) {
            front = front->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}

void save_to_file(char* name, char* lastName, int facultyNumber) {
    item* curr = front;
    FILE* fi = fopen("List.txt", "a");
    if (fi != NULL) {
        printf("Zapisvane vuv file...\n");
        while (curr != NULL) {
            fprintf(fi, "\nIme na student: %s %s\n", curr->name, curr->lastName);
            fprintf(fi, "\nFakulteten nomer: %d\n", curr->facultyNumber);
            curr = curr->next;
        }
        printf("Studentite sa zapisani\n");
        fclose(fi);
    } else {
        printf("Unable to open file\n");
    }
}

int main()
{
    char name[256];
    char lastName[256];
    int facultyNumber;
    char ch;
    do
    {
        printf("1. Dobavqne na student\n2. Premahvane na student\n3. Izvezhdane na student\n4. Zapis vuv file\n5.Izhod\nIzberete... ");
        scanf(" %c", &ch);
        switch(ch)
        {
            case '1': 
                insert_l(name, lastName, facultyNumber);
                break;
            case '2':
                delete_l(name, lastName, facultyNumber);
                break;
            case '3':
                search_l(name, lastName, facultyNumber);
                break;
            case '4': 
                save_to_file(name, lastName, facultyNumber); 
                break;
        }
    }
    while(ch != '5');
    return 0;
}
