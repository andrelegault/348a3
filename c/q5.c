#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valid(int ch) {
    if(!(ch >= 97 && ch <= 122) && !(ch >= 65 && ch <= 90)) {
        fprintf(stderr, "invalid character");
        exit(EXIT_FAILURE);
    }
    return 1;
}

int twoStrCompr(const char* first, const char* second) {
    int i;
    int len1 = strlen(first);
    int len2 = strlen(second);
    int minLen = len1 < len2? len1: len2;
    for(i = 0; i < minLen; i++) {
        int ch1 = *(first+i);
        int ch2 = *(second+i);
        valid(ch1);
        valid(ch2);
        if (ch1 < ch2) return 1;
    }
    if(len1 < len2) {
        return 1;
    } else {
        if(len1 == len2) {
            return *(first+minLen-1) <= *(second+minLen-1);
        }
    }
    return 0;
}

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


void list_selection_sort(struct node **head) {
    struct node **front = head;
    print(*(front));
    struct node *it = *(head);

    while(!sorted(*(front))) {
        while(it->next != NULL) {
            if(strcmp(it->next->data, it->data) < 1) {
                char *tmp = strdup(it->data);
                char *tmp2 = strdup(it->next->data);
                it->next->data = tmp;
                it->data = tmp2;
            }
            it = it->next;
        }
        it = *(head);
    }
    print(*(head));
}

int sorted(const struct node *head) {
    while(head->next != NULL) {
        int keepSorting = twoStrCompr(head->data, head->next->data);
        if(twoStrCompr(head->data, head->next->data) == 0) {
            return 0;
        }
        head = head->next;
    }
    return 1;
}

struct node* duplicate(const struct node *head) {
    if(head == NULL) {
        return NULL;
    }
    struct node *newHead = malloc(sizeof(struct node));
    newHead->data = strdup(head->data);
    struct node *it = head->next;
    struct node *follower = newHead;
    while(it != NULL) {
        struct node *newLink = malloc(sizeof(struct node));
        newLink->data = strdup(it->data);
        follower->next = newLink;
        it = it->next;
        follower = follower->next;
    }
    return newHead;
}

int main() {
    struct node *head = NULL;
    char str[20];
    printf("Enter first word (or '.' to end list): ");
    scanf("%s", str);
    while(strcmp(&str[0], ".") != 0) {
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

    struct node *copy = duplicate(head);
    list_selection_sort(&copy);

    return 0;
}
