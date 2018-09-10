// ConsoleApplication3.cpp : Defines the entry point for the console application.
//


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <assert.h>
#include <limits.h>
#include <math.h>



// link list form plursight

//typedef char bool;
//#define true 1
//#define false 0
//// strut decleared with a * to itself
//struct list_element
//{
//	struct list_element *next;
//};
//
//typedef struct list_element list_element;
//
//typedef struct
//{
//	list_element * first;
//	list_element *last;
//}list;
//
//void list_init(list *container)
//{
//	container->first = 0;
//	container->last = 0;
//
//}
//
//bool list_empty(list * container)
//{
//	return 0 == container->first;
//
//}
//
//list_element* list_begin(list *container)
//{
//	return container->first;
//}
//
//list_element *list_next(list_element * element)
//{
//	return element->next;
//}
//
//void list_push_back(list *  container, list_element* element)
//{
//	// empty
//	if (list_empty(container))
//	{
//		container->first = element;
//		container->last = element;
//	}
//	else
//	{
//		container->last->next = element;
//		container->last = element;
//		
//	}
//	element->next = 0;
//
//}
//
//
//list_element * list_pop_front(list *container)
//{
//	list_element * tmp = list_begin(container);
//	container->first = container->first->next;
//
//	return tmp;
//}
//
//
//typedef struct
//{
//	list_element header;
//	int value;
//
//}apple;
//
//int main()
//{
//	list apples;
//	apple * a = (apple*)malloc(sizeof(apple));
//	apple * b = (apple*)malloc(sizeof(apple));
//	apple * c = (apple*)malloc(sizeof(apple));
//
//	a->value = 1;
//	b->value = 2;
//	c->value = 3;
//
//	list_init(&apples);
//	list_push_back(&apples, &a->header);
//	list_push_back(&apples, &b->header);
//	list_push_back(&apples, &c->header);
//
//	for (a =(apple*)list_begin(&apples); a; a=(apple*)list_next(&a->header))
//	{ 
//		printf("%d\n", a->value);
//	}
//
//
//	while (!list_empty (&apples))
//	{
//
//		a = (apple*)list_pop_front(&apples);
//		free(a);
// }
//
//	system("Pause");
//	return 0;
//}
//
//



//void swap(char** s, int a, int b)
//{
//	char * tmp;
//	tmp  = s[a];
//	s[a] = s[b];
//	s[b] = tmp;
//}
//
//void 	reverse_sequence(char**s, int start, int end)
//{
//	while (start < end)
//	{
//		swap(s, start++, end++);
//	}
//
//}
//
//int next_permutation(int n, char **s)
//{
//	int k = -1;
//	int l = -1;
//	for (int i = n - 2; i > -1; i--)
//	{
//		if (strcmp(s[i], s[i + 1]) < 0)
//		{
//			k = i;
//			break;
//		}
//	}
//	for (int j = n - 1; j > k && k > -1; j--)
//	{
//		if (strcmp(s[k], s[j]) < 0)
//		{
//			l = j;
//			swap(s, k, l);
//			reverse_sequence(s, k + 1, n - 1);
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char **s;
//	int n;
//	scanf_s("%d", &n, 10 );
//	s = calloc(n, sizeof(char*));
//	for (int i = 0; i < n; i++)
//	{
//		s[i] = calloc(11, sizeof(char));
//		//scanf_s("%s", s[i], (unsigned)_countof(s));
//		scanf_s("%s", s[i], 30);
//	}
//	do
//	{
//		for (int i = 0; i < n; i++)
//			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
//	} while (next_permutation(n, s));
//	for (int i = 0; i < n; i++)
//		free(s[i]);
//	free(s);
//
//	system("Pause");
//	return 0;
//}

//int main() {
//
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//	//char *str = malloc(100);
//	int array[10] = { 0 };
//	//scanf_s("%s", str);
//	char* str = "this24";
//	while (str != NULL)
//	{
//		printf("%d", *str);
//		str++;
//		
//	}
//	return 0;
//}
//
//int main() {
//	sum(2, 3);
//
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//	//char *str = malloc(100);
//	//int array[10] = { 0 };
//	int *nums = (int*)malloc(10 * sizeof(int));
//	char c;
//	// clear 
//
//	for (int j = 0; j <= 10; j++)
//	{
//		*(nums + j) = 0;
//
//	}
//
//	while (scanf_s("%c", &c) == 1)
//	{
//		if (c >= '0' && c <= '9')
//			(*(nums + (c - '0')))++;
//	}
//
//	for (int i = 0; i < 10; i++)
//		printf("\n");
//	return 0;
//}
//
/*
** TODO:
**     need array of pointers to Shelf
**     finish handing queries
**     DONE - Perhaps a rewrite using structs in a linked list for the shelf
**     DONE - functions to deal with linked list
*/

/*
** the first input contains the total number of shelves (set size of books_on_shelf as int[total_number_of_shelves])
** the second input contains the number of queries
** the following inputs describe the actions to be taken
**
** the following actions can be taken:
** 1 x y    --    insert book with y pages at end of shelf x
** 2 x y    --    print number of pages in the yth book on shelf x
** 3 x      --    print the number of books on shelf x
**
** Constrains:
**     total_number_of_shelves <= 10^5
**     total_number_of_queries <= 10^5
**     for each query of the second type, a book is present
**     maximum number of books per shelf <= 1100
*/
//
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

int getNumberOfBooks(Shelf *head)
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
			printf("%d\n", getNumberOfBooks(shelves[x]));
		}
	}

	goto end;

end:
	/**** free calls ****/
	system("pause");

	exit(0); // should kill program before executing anything else
}


//int main() {
//
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//	int n;
//	scanf_s("%d", &n);
//	int *arr = (int*)malloc(n * sizeof(int));
//	
//	int sum = 0;
//	for (int i = 0; i<n; i++)
//	{
//		scanf_s("%d", &arr[i]);
//	//	sum = sum + arr[i];
//		sum = sum + *(arr + i);
//	}
//
//	/* for (int i =0; i++; i<n)
//	{
//	sum = sum+ *(arr+i);
//	}*/
//	printf("%d\n", sum);
//	system("Pause");
//
//	return 0;
//}
// Test ifit is little endien
//int checksys()
//{
//	union check
//	{
//		int i;
//		char ch;
//	}c;
//	c.i = 1;
//	
//	
//	return (c.ch == 1);
//}
//
//int main()
//{
//   int edien=	checksys();
//		
//   printf("edien  %d\n", edien);
//	system("Pause");
//}

//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int *ptr1 = (int*)(&a + 1);
//	int *ptr2 = (int*)((int)a + 1);
//	printf("%x, %x", ptr1[-1], *ptr2);
//	system("Pause");
//		return 0;
//
//}

//
//int main()
//{
//	char a[5] = { 'A','B','C','D' };
//	char(*p3)[5] = &a;
//	char(*p4)[5] = a;
//	system("Pause");
//	return 0;
//}
//



//
//static const char *strings[] = { "one","two","three","four","five",
//"six","seven","eight","nine" };
//int main()
//{
//	int n = 0;
//	if (scanf_s("%d", &n) < 1)
//		return 1;
//
//	if (n >= 1 && n <= 9)
//		printf("%s", strings[n - 1]);
//	else
//		printf("Greater than 9");
//	system("Pause");
//	return 0;
//}














// mine
//void calculate_the_maximum(int n, int k)
//{
//	//Write your code here.
//	// set up a array to save and 
//	int and = 0;
//	int or = 0;
//	int nor = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = i + 1; j <= n; j++)
//		{
//			if (((and < (i & j)) && ((i & j)<k)))
//				and = i&j;
//			if (((or < (i | j)) && ((i | j)<k)))
//				or = i | j;
//			if (((nor < (i^j)) && ((i ^j)<k)))
//				nor = i ^ j;
//		}
//	}
//	printf("%d\n%d\n%d\n", and, or , nor);
//}
// sort


//Complete the following function.
//
//void calculate_the_maximum(int n, int k) {
//	int maxAnd = 0;
//	int maxOr = 0;
//	int maxXor = 0;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			if (((i&j) > maxAnd) && ((i&j) < k)) {
//				maxAnd = i&j;
//			}
//			if (((i | j) > maxOr) && ((i | j) < k)) {
//				maxOr = i | j;
//			}
//			if (((i^j) > maxXor) && ((i^j) < k)) {
//				maxXor = i^j;
//			}
//		}
//	}
//
//	printf("%d\n%d\n%d\n", maxAnd, maxOr, maxXor);
//}
//void calculate_the_maximum(int n, int k)
//{
//	//Write your code here.
//	// set up a array to save and 
//	int arrayAnd[n];
//	int arrayOR[n];
//	int arrayNor[n];
//
//	for (int i = 1; i<n; i++)
//	{
//		arrayAnd[i] = i &  (++i);
//		arrayOR[i] = i | (++i);
//		arrayNor[i] = i ^ (++i);
//	}
//	// sort
//	int i = 0;
//	while (arrayAnd[i] < k)
//	{
//		i++;
//	}
//	printf("%d \n", arrayAnd[i]);
//	while (arrayOR[i] < k)
//	{
//		i++;
//	}
//	printf("%d \n", arrayOR[i]);
//	while (arrayNor[i] < k)
//	{
//		i++;
//	}
//	printf("%d \n", arrayNor[i]);
//
//
//}

//int main() {
//	int n, k;
//
//	scanf_s("%d %d", &n, &k);
//	calculate_the_maximum(n, k);
//	system("Pause");
//	return 0;
//}

//
//
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
//
//
//
//
//int main() {
//	char str[30] = "2030300 This is test";
//	char *ptr;
//	long ret;
//
//	ret = strtol(str, &ptr, 10);
//	printf("The number(unsigned long integer) is %ld\n", ret);
//	printf("String part is |%s|", ptr);
//	system("Pause");
//	return(0);
//}

//int main() {
//
//	int n;
//	scanf_s("%d", &n);
//	//Complete the code to calculate the sum of the five digits on n.
//	int sum = 0;
//	while (n>0)
//	{
//		sum += (n % 10);
//		n = n / 10;
//  }
//	printf("sum %d \n", sum);
//	system("Pause");
//	return 0;
//}

//
//int  marks_summation(int* marks, int number_of_students, char gender)
//{
//
//	int tmp = 0;
//	int n = number_of_students;
//
//	if (gender == 'b')
//
//	{
//		for (int i = 0; i< n; i++)
//
//			if (i % 2==0)
//			{
//				tmp += marks[i];
//			}
//
//	}
//
//	//girls
//	else if (gender == 'g')
//
//	{
//
//		for (int i = 1; i< n; i++)
//		{
//			if (i % 2 >0)
//			{
//				tmp += marks[i];
//			}
//		}
//
//
//	}
//	return tmp;
//
//
//}
//
//int main() {
//	int number_of_students;
//	char gender;
//	int sum;
//
//	scanf_s("%d", &number_of_students);
//	int *marks = (int *)malloc(number_of_students * sizeof(int));
//
//	for (int student = 0; student < number_of_students; student++) {
//		scanf_s("%d", (marks + student));
//	}
//
//	scanf_s(" %c", &gender);
//	sum = marks_summation(marks, number_of_students, gender);
//	printf("%d", sum);
//	free(marks);
//	system("Pause");
//	return 0;
//}