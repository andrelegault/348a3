#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char *data;
    struct node *next;
};


struct node* findNode(struct node *head, char find[]) {
    struct node *it = head;
    while(it != NULL) {
        if(strcmp(it->data, find) == 0) {
            return it;
        }
        it = it->next;
    }
    return it;
}

struct node* findParentNode(struct node *head, char find[]) {
    struct node *it = head;
    while(it->next != NULL) {
        if(strcmp(it->next->data, find) == 0) {
            return it;
        }
        it = it->next;
    }
    return it;
}

void add_after(struct node *head, char a_word[], char word_after[]) {
    struct node *found = findNode(head, a_word);
    if(found != NULL) {
        struct node *new = malloc(sizeof(struct node));
        new->data = word_after;
        new->next = found->next;
        found->next = new;
        return;
    } else {
        printf("could not find word %s", a_word);
    }
}

 void delete_node(struct node *head, char a_word[]) {
    struct node *parent = findParentNode(head, a_word);
    if(parent != NULL) {
        parent->next = parent->next->next;
    } else {
        printf("could not find word %s", a_word);
    }
 }

void print(struct node *head) {
    printf("\nTHE LIST IS NOW:\n");
    struct node *ting = head;
    while(ting != NULL) {
        printf("%s ", ting->data);
        ting = ting->next;
    }
    printf("\n");
}


//void list_selection_sort(const node_ptr *list);

int main() {
    struct node *head = NULL;
    char str[20];
    printf("Enter first word (or '.' to end list): ");
    scanf("%s", str);
    while(str[0] != '.' && strlen(str) != 1) {
        char *dst = strdup(str);
        if(head == NULL) {
            head = malloc(sizeof(struct node));
            head->data = dst;
            head->next = NULL;
        } else {
            struct node *new = malloc(sizeof(struct node));
            new->data = dst;
            new->next = NULL;
            struct node *parent = head;
            while(parent->next != NULL) {
              parent = parent->next;
            }
            parent->next = new;
        }
        printf("Enter next word (or '.' to end list): ");
        scanf("%s", str);
    }
    print(head);

    char toAdd[20];
    char theWord[20];
    printf("\nAFTER WHICH WORD WOULD YOU LIKE TO ADD AN EXTRA WORD? ");
    scanf("%s", theWord);
    
    printf("WHICH WORD WOULD YOU LIKE TO ADD? ");
    scanf("%s", toAdd);
    add_after(head, theWord, toAdd);
    print(head);
    
    char toDelete[20];
    printf("\nWHICH WORD WOULD YOU LIKE TO DELETE? ");
    scanf("%s", toDelete);
    if(strcmp(head->data, toDelete) == 0) {
        head = head->next;
    } else {
        delete_node(head, toDelete);
    }
    print(head);
    return 0;
}