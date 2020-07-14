#include <stdio.h>
#include <stdlib.h>

typedef struct node {
 int data;
 struct node *next;
} Node;
int main (void) {
 Node four = {77, NULL};
 Node three = {34, &four};
 Node two = {13, &three};
 Node one = {52, &two};
 Node *zero = &one;
 while (zero != NULL) {
 printf("%d ", zero->data);
 zero = zero->next;
 }
 return EXIT_SUCCESS;
}