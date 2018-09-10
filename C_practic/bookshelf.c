
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <assert.h>
#include <limits.h>
#include <math.h>
typedef struct Shelf {
	int pages;
	struct Shelf *next;
}Shelf;

Shelf* addBook(Shelf *head, int pages)
{
	Shelf *to_add = malloc(sizeof(Shelf));
	to_add->pages = pages;
	to_add->next = NULL;
	if (head == NULL) {
		return to_add;
	}
	else if (head->next == NULL) {
		head->next = to_add;
		return head;
	}
	else {
		Shelf *current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = to_add;
		return head;
	}
}

int getPages(Shelf *head, int book_number)
{
	Shelf *current = head;
	for (int i = 0; i != book_number; i++) {
		current = current->next;
	}
	return current->pages;
}

int getNumberofBooks(Shelf *head)
{
	int counter = 0;
	if (head == NULL) {
		return counter;
	}

	counter = 1;

	Shelf *current = head;
	while (current->next != NULL) {
		counter++;
		current = current->next;
	}
	return counter;
}

Shelf *freeShelf(Shelf *head)
{
	Shelf *current = head;
	Shelf *next;
	while (current->next != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	return NULL;
}

int main()
{
	int number_of_shelves;
	int number_of_queries;
	scanf("%d", &number_of_shelves);
	scanf("%d", &number_of_queries);

	Shelf **shelves = malloc(number_of_shelves * sizeof(Shelf*)); // create an array of Shelf
	if (shelves == NULL) { printf("Memory allocation error 1\n"); goto end; }


   /*****************************/

	int input_type;

	while (number_of_queries--) {
		scanf("%d", &input_type);
		if (input_type == 1) {
			int x, y;
			scanf("%d", &x);
			scanf("%d", &y);
			shelves[x] = addBook(shelves[x], y);
		}
		else if (input_type == 2) {
			int x, y;
			scanf("%d", &x);
			scanf("%d", &y);
			printf("%d\n", getPages(shelves[x], y));
		}
		else if (input_type == 3) {
			int x;
			scanf("%d", &x);
			printf("%d\n", getNumberofBooks(shelves[x]));
		}
	}

	goto end;

end:
	/**** free calls ****/
	//system("pause");

	exit(0); // should kill program before executing anything else
}

