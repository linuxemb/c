// ConsoleApplication3.cpp : Defines the entry point for the console application.
//


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>


#include <stdio.h> 
char *removeDuplicate(char str[], int n)
{

	if (n <= 3)
		return str;
	// Used as index in the modified string 
	int index = 0;

	// Traverse through all characters 
	for (int i = 0; i<n; i++) {

		// Check if str[i] is present before it   
		int j;
		for (j = 0; j<i; j++)
			if (str[i] == str[j])
				break;

		// If not present, then add it to 
		// result. 
		if (j == i)
			str[index++] = str[i];
	}
	
	return str;
}

// Driver code 
int main()
{
	//const char* str = "abcedfd";  Exception , no mem located, only 1 char pointer, 
	char str[] = "ab";
	//char str[] = "geeksforgeeks";
	int n = sizeof(str) / sizeof(str[0]);  // n is number of str +1;
	char * tmp = removeDuplicate(str, n);
	for (int i = 0; i<n; i++)
	{
		printf("%c", *tmp);
		tmp++;
	}
	system("Pause");
	return 0;
}

//====================
// void removeDuplicateds(char[] w)
//void removeDuplicateds(char str[], int n)
//{
//	char * mystr;
//	mystr = str;
//	int len = strlen(str)+1;
//	int tail = 1;
//	for (int i = 1; i < len; ++i)
//	{
//		int j;
//		for (j = 0; j < tail; ++j)
//		{
//			if (str[i] == str[j]) break;
//		}
//		if (j == tail) {
//			str[tail] == str[i];
//			++tail;
//		}
//		
//	}
//	mystr[tail] = '0';
//	
//	printf("%c", *str);
//
//	
//}
//
//char *removeDuplicate(char str[], int n)
//{
//	// Used as index in the modified string 
//	int index = 0;
//
//	// Traverse through all characters 
//	for (int i = 0; i<n; i++) {
//
//		// Check if str[i] is present before it   
//		int j;
//		for (j = 0; j<i; j++)
//			if (str[i] == str[j])
//				break;
//
//		// If not present, then add it to 
//		// result. 
//		if (j == i)
//		//	str[index++] = str[i];
//			str[index] = str[i];
//		index++;
//	}
//
//	return str;
//}
//
//void printStr(char str[])
//{
//	for (int i = 0; i < strlen(str); i++)
//	{
//		printf("%c", str[i]);
//	}
//	printf("\n");
//}
//int main()
//{
///*	char a[5];
//	a[0] = 'a';
//	a[1] = 'b';
//	a[2] = 'c';
//	a[3] = 'a';
//	a[4] = '\0'*/;
//int a = 8;
//int b = 7;
//a = a^b;
//b = a^b; // now b=a
////b = a^b^b;
//printf("%d\n", b);
//a = a^b;
//printf("%d\n", a);
//const char * mychar = "abcda";
//char*c;
//	printStr(mychar);
//	int n = sizeof(mychar) / sizeof(mychar[0]);
//	c= removeDuplicate(mychar,n);
//	printStr(c);
//	system("Pause");
//	return 0;
//
//
//}
//////====================
//#define MIN_ELEMENT 1
//#define MAX_ELEMENT 1000000
//int  sum(int count, ...) {
//	int sum = 0;
//	va_list values;
//	va_start(values, count);
//	for (int i = 0; i<count; i++) {
//		sum += va_arg(values, int);
//	}
//	va_end(values);
//	return sum;
//}
//int test_implementations_by_sending_three_elements() {
//	srand(time(NULL));
//
//	int elements[3];
//
//	elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//
//	fprintf(stderr, "Sending following three elements:\n");
//	for (int i = 0; i < 3; i++) {
//		fprintf(stderr, "%d\n", elements[i]);
//	}
//
//	int elements_sum = sum(3, elements[0], elements[1], elements[2]);
//	int minimum_element = min(3, elements[0], elements[1], elements[2]);
//	int maximum_element = max(3, elements[0], elements[1], elements[2]);
//
//	fprintf(stderr, "Your output is:\n");
//	fprintf(stderr, "Elements sum is %d\n", elements_sum);
//	fprintf(stderr, "Minimum element is %d\n", minimum_element);
//	fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
//
//	int expected_elements_sum = 0;
//	for (int i = 0; i < 3; i++) {
//		if (elements[i] < minimum_element) {
//			return 0;
//		}
//
//		if (elements[i] > maximum_element) {
//			return 0;
//		}
//
//		expected_elements_sum += elements[i];
//	}
//
//	return elements_sum == expected_elements_sum;
//}
//
//int test_implementations_by_sending_five_elements() {
//	srand(time(NULL));
//
//	int elements[5];
//
//	elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//
//	fprintf(stderr, "Sending following five elements:\n");
//	for (int i = 0; i < 5; i++) {
//		fprintf(stderr, "%d\n", elements[i]);
//	}
//
//	int elements_sum = sum(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
//	int minimum_element = min(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
//	int maximum_element = max(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
//
//	fprintf(stderr, "Your output is:\n");
//	fprintf(stderr, "Elements sum is %d\n", elements_sum);
//	fprintf(stderr, "Minimum element is %d\n", minimum_element);
//	fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
//
//	int expected_elements_sum = 0;
//	for (int i = 0; i < 5; i++) {
//		if (elements[i] < minimum_element) {
//			return 0;
//		}
//
//		if (elements[i] > maximum_element) {
//			return 0;
//		}
//
//		expected_elements_sum += elements[i];
//	}
//
//	return elements_sum == expected_elements_sum;
//}
//
//int test_implementations_by_sending_ten_elements() {
//	srand(time(NULL));
//
//	int elements[10];
//
//	elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[5] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[6] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[7] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[8] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//	elements[9] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//
//	fprintf(stderr, "Sending following ten elements:\n");
//	for (int i = 0; i < 10; i++) {
//		fprintf(stderr, "%d\n", elements[i]);
//	}
//
//	int elements_sum = sum(10, elements[0], elements[1], elements[2], elements[3], elements[4],
//		elements[5], elements[6], elements[7], elements[8], elements[9]);
//	int minimum_element = min(10, elements[0], elements[1], elements[2], elements[3], elements[4],
//		elements[5], elements[6], elements[7], elements[8], elements[9]);
//	int maximum_element = max(10, elements[0], elements[1], elements[2], elements[3], elements[4],
//		elements[5], elements[6], elements[7], elements[8], elements[9]);
//
//	fprintf(stderr, "Your output is:\n");
//	fprintf(stderr, "Elements sum is %d\n", elements_sum);
//	fprintf(stderr, "Minimum element is %d\n", minimum_element);
//	fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
//
//	int expected_elements_sum = 0;
//	for (int i = 0; i < 10; i++) {
//		if (elements[i] < minimum_element) {
//			return 0;
//		}
//
//		if (elements[i] > maximum_element) {
//			return 0;
//		}
//
//		expected_elements_sum += elements[i];
//	}
//
//	return elements_sum == expected_elements_sum;
//}
//
//int main()
//{
//	int number_of_test_cases;
//	scanf("%d", &number_of_test_cases);
//
//	while (number_of_test_cases--) {
//		if (test_implementations_by_sending_three_elements()) {
//			printf("Correct Answer\n");
//		}
//		else {
//			printf("Wrong Answer\n");
//		}
//
//		if (test_implementations_by_sending_five_elements()) {
//			printf("Correct Answer\n");
//		}
//		else {
//			printf("Wrong Answer\n");
//		}
//
//		if (test_implementations_by_sending_ten_elements()) {
//			printf("Correct Answer\n");
//		}
//		else {
//			printf("Wrong Answer\n");
//		}
//	}
//
//	return 0;
//}
//==================
 // Printing Tokens
  // split string from sentence
//================== 
//int main() {
//
//	char *s;
//	s = malloc(1024 * sizeof(char));
//	scanf("%[^\n]", s);
//	s = realloc(s, strlen(s) + 1);
//	//Write your logic to print the tokens of the sentence here.
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//	{
//		if(s[i] ==' ')
//		{
//			printf("%\n" );
//		}
//		else
//		printf("%c",s[i]);
//	}
//	system("Pause");
//
//	return 0;
//}



//===============
//Sum of Digits of a Five Digit Number
//====================

//In order to get the last digit of a number, we use modulo operator \%.When the number is modulo divided by 10 we get the last digit.

//
//int main() {
//
//	int n;
//	scanf("%d", &n);
//	//Complete the code to calculate the sum of the five digits on n.
//	int sum = 0;
//	do {
//		sum+= (n % 10) ;
//		n /=10;
//	} while (n != 0);
//		printf("%d\n", sum);
//		system("Pause");
//	return 0;
//}


//======================== 
// Max of 4
//===========================

//#include <stdio.h>
///*
//Add `int max_of_four(int a, int b, int c, int d)` here.
//*/
//int max(int a, int b) {
//	return a > b ? a : b;
//}
//
//int max_of_four(int a, int b, int c, int d) {
//	return max(a, max(b, max(c, d)));
//}
//
//int main() {
//	int a, b, c, d;
//	scanf("%d %d %d %d", &a, &b, &c, &d);
//	int ans = max_of_four(a, b, c, d);
//	printf("%d", ans);
//
//	return 0;
//}








/*In order to take a line a
s input, you can use scanf("%[^\n]%*c"
, s); where  is defined as char s[MAX_LEN] where
is the maximum size of . Here, [] is the scanset char
acter. ^\n stands for taking input until a newline isn't encounte
red. Then, with this %*c, it reads the newline character and here,
the used * indicates that this newline character is discarde
Note: After inputting the character and the string, inputting the sentence by the above mentioned 
statement won't work. This is because, at the end of each line, a new line character (\n) is present.
So, the statement: scanf("%[^\n]%*c", s); will not work because the last statement will read a newline
character from the previous line
. This can be handled in a variety of ways and one of them being: scanf("\n"); before the last statement.

Task
*/

//int main()
//{
//	char c;
//
//	char s[20];
//
//	char sentence[200];
//
//	scanf("%c", &c);
//
//	scanf("%s", &s);
//	scanf("\n");   
//	scanf("%[^\n]%*c", &sentence);
//
//	printf("%c\n", c);
//	printf("%s\n", s);
//	printf("%s\n", sentence);
//	system("Pause");
//	
//	return 0;
//}







// C program to rotate an array by
// d elements



//struct node {
//
//	int data;
//	struct node *left;
//	struct node *right;
//
//};
//
//struct node* insert(struct node* root, int data) {
//
//	if (root == NULL) {
//
//		struct node* node = (struct node*)malloc(sizeof(struct node));
//
//		node->data = data;
//
//		node->left = NULL;
//		node->right = NULL;
//		return node;
//
//	}
//	else {
//
//		struct node* cur;
//
//		if (data <= root->data) {
//			cur = insert(root->left, data);
//			root->left = cur;
//		}
//		else {
//			cur = insert(root->right, data);
//			root->right = cur;
//		}
//
//		return root;
//	}
//}

/* you only have to complete the function given below.
node is defined as

struct node {

int data;
struct node *left;
struct node *right;

};

//*/
//void preOrder(struct node *root) {
//
//	if (root == NULL)
//
//		return;
//	// print root data
//	printf("preorder .. %d ", root->data);
//	preOrder(root->left);
//	preOrder(root->right);
//	}
//
//void postOrder(struct node *root)
//{
//	if (root == NULL)
//		return;
//	// traval until end 
//	postOrder(root->left);
//	postOrder(root->right);
//	printf("postorder..%d ", root->data);
//
//
//}
//
//void inOrder(struct node *root)
//{
//	if (root == NULL)
//		return;
//	// traval until end 
//	inOrder(root->left);
//	printf("/n inorder..%d ", root->data);
//	inOrder(root->right);
//	
//
//
//}
//
//int main() {
//
//	struct node* root = NULL;
//
//	int t;
//	int data;
//
//	scanf("%d", &t);
//
//	while (t-- > 0) {
//		scanf("%d", &data);
//		root = insert(root, data);
//	}
//
//	//preOrder(root);
//	//postOrder(root);
//	inOrder(root);
//	system("Pause");
//	return 0;
//}


///* Function to left Rotate arr[] of size n by 1*/
//void leftRotatebyOne(int arr[], int n);
//
///*Function to left rotate arr[] of size n by d*/
//void leftRotate(int arr[], int d, int n)
//{
//	int i;
//	for (i = 0; i < d; i++)
//		leftRotatebyOne(arr, n);
//}
//
//void leftRotatebyOne(int arr[], int n)
//{
//	int temp = arr[0], i;
//	for (i = 0; i < n - 1; i++)
//		arr[i] = arr[i + 1];
//	arr[i] = temp;
//}
//
///* utility function to print an array */
//void printArray(int arr[], int n)
//{
//	int i;
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
///* Driver program to test above functions */
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	leftRotate(arr, 2, 7);
//	printArray(arr, 7);
//	system("Pause");
//	return 0;
//}

//
//
//int main()
//{
//	int n, c, d, a[100], b[100];
//	
//	n = sizeof(a) / sizeof(a[0]);
//	printf("sizeof ....n = %d\n", n);
//	printf("Enter the number of elements in array\n");
//	scanf("%d", &n);
//
//	printf("Enter the array elements\n");
//
//	for (c = 0; c < n; c++)
//		scanf("%d", &a[c]);
//
//	/*
//	* Copying elements into array b starting from end of array a
//	*/
//
//	//for (c = n - 1, d = 0; c >= 0; c--, d++)
//	//	b[d] = a[c];
//	for (c = n - 1 ;c >= 0; c--)
//		b[c] = a[n-c-1];
//	
//	/*
//	* Copying reversed array into the original.
//	* Here we are modifying original array, this is optional.
//	*/
//
//	for (c = 0; c < n; c++)
//		a[c] = b[c];
//
//	printf("Reverse array is\n");
//
//	for (c = 0; c < n; c++)
//		printf("%d\n", b[c]);
//	system("Pause");
//
//	return 0;
//}

//
//struct node
//{
//	int data;
//	struct node * next;
//};
//
//// helper function to get the count of both the lists.
//int getCount(struct node * head)
//{
//	int count = 0;
//	while (head)
//	{
//		head = head->next;
//		count++;
//	}
//	return count;
//}
//
//struct node * yNodeIntersecting(struct node * head1, struct node * head2)
//{
//	// get count of both the lists
//	int m = getCount(head1);
//	int n = getCount(head2);
//
//	//to store the merge point
//	struct node * merge_point = NULL;
//
//	// finding the value of d based on the longer list
//	int diff = (m > n) ? (m - n) : (n - m);
//
//	//traverse the smaller longer list for 'diff' steps
//	if (m > n)
//	{
//		while (diff--)
//			head1 = head1->next;
//	}
//	else
//	{
//		while (diff--)
//			head2 = head2->next;
//	}
//
//	// now both lists have equal nodes till the end.
//	while (head1 && head2)
//	{
//		if (head1->next == head2->next)
//		{
//			merge_point = head1->next;
//			break;
//		}
//
//		head1 = head1->next;
//		head2 = head2->next;
//	}
//
//	return merge_point;
//}
//
//struct node * addElement(struct node *head, int number)
//{
//	struct node * temp = (struct node*)malloc(sizeof(struct node));
//	temp->data = number;
//	temp->next = NULL;
//	struct node * temp2 = head;
//	while (temp2->next != NULL)
//		temp2 = temp2->next;
//	temp2->next = temp;
//	return head;
//}
//
//
//findMergeNode(struct node* headA, struct node* headB)
//{
//
//	int c1 = 0, c2 = 0;
//
//	struct node *p = headA, *q = headB;
//	while (p != NULL) {
//		p = p->next;
//		c1++;
//	}
//	while (q != NULL) {
//		q = q->next;
//		c2++;
//	}
//	if (c2>c1) {
//		p = headA;
//		q = headB;
//		for (int i = 0; i<(c2 - c1); i++) {
//			q = q->next;
//		}
//		while (p != q) {
//			p = p->next;
//			q = q->next;
//		}
//		return q->data;
//	}
//	else {
//		p = headA;
//		q = headB;
//		for (int i = 0; i<(c1 - c2); i++) {
//			p = p->next;
//		}
//		while (p != q) {
//			p = p->next;
//			q = q->next;
//		}
//		return p->data;
//	}
//
//}

//
//int main(void)
//{
//	//creating a list
//	struct node * listHead1 = (struct node*)malloc(sizeof(struct node));
//	listHead1->data = 4;
//	listHead1->next = NULL;
//	listHead1 = addElement(listHead1, 8);
//	listHead1 = addElement(listHead1, 15);
//	listHead1 = addElement(listHead1, 42);
//	listHead1 = addElement(listHead1, 99);
//
//	struct node * listHead2 = (struct node*)malloc(sizeof(struct node));
//	listHead2->data = 16;
//	listHead2->next = NULL;
//	listHead2 = addElement(listHead2, 23);
//
//	struct node * temp = listHead2;
//
//	temp = temp->next;
//	temp->next = listHead1->next->next->next;
//
//	//struct node * merge_p = yNodeIntersecting(listHead1, listHead2);
//	int merge_p = findMergeNode(listHead1, listHead2);
//	printf("Merge node is:- %d\n", merge_p);
//	system("Pause");
//	return 0;
//}
//char* readline();
//char** split_string(char*);
//
//// Complete the hourglassSum function below.
//int hourglassSum(int arr_rows, int arr_columns, int** arr) {
//
//	return 100;
//}
//
//int main()
//{
//	FILE* fptr = fopen("a.txt", "w");
//	///FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
//
//	int** arr = malloc(3 * sizeof(int*));
//
//	for (int i = 0; i < 3; i++) {
//		*(arr + i) = malloc(3 * (sizeof(int)));
//
//		char** arr_item_temp = split_string(readline());
//
//		for (int j = 0; j < 3; j++) {
//			char* arr_item_endptr;
//			char* arr_item_str = *(arr_item_temp + j);
//			int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);
//
//			if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }
//
//			*(*(arr + i) + j) = arr_item;
//		}
//	}
//
//	int arr_rows = 3;
//	int arr_columns = 3;
//
//	int result = hourglassSum(arr_rows, arr_columns, arr);
//
//	fprintf(fptr, "%d\n", result);
//	system("Pause");
//	fclose(fptr);
//
//	return 0;
//}
//
//char* readline() {
//	size_t alloc_length = 1024;
//	size_t data_length = 0;
//	char* data = malloc(alloc_length);
//
//	while (true) {
//		char* cursor = data + data_length;
//		char* line = fgets(cursor, alloc_length - data_length, stdin);
//
//		if (!line) { break; }
//
//		data_length += strlen(cursor);
//
//		if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }
//
//		size_t new_length = alloc_length << 1;
//		data = realloc(data, new_length);
//
//		if (!data) { break; }
//
//		alloc_length = new_length;
//	}
//
//	if (data[data_length - 1] == '\n') {
//		data[data_length - 1] = '\0';
//	}
//
//	data = realloc(data, data_length);
//
//	return data;
//}
//
//char** split_string(char* str) {
//	char** splits = NULL;
//	char* token = strtok(str, " ");
//
//	int spaces = 0;
//
//	while (token) {
//		splits = realloc(splits, sizeof(char*) * ++spaces);
//		if (!splits) {
//			return splits;
//		}
//
//		splits[spaces - 1] = token;
//
//		token = strtok(NULL, " ");
//	}
//
//	return splits;
//}

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

//typedef struct Shelf {
//	int pages;
//	struct Shelf *next;
//}Shelf;
//
//Shelf* addBook(Shelf *head, int pages)
//{
//	Shelf *to_add = malloc(sizeof(Shelf));
//	to_add->pages = pages;
//	to_add->next = NULL;
//	if (head == NULL) {
//		return to_add;
//	}
//	else if (head->next == NULL) {
//		head->next = to_add;
//		return head;
//	}
//	else {
//		Shelf *current = head;
//		while (current->next != NULL) {
//			current = current->next;
//		}
//		current->next = to_add;
//		return head;
//	}
//}
//
//int getPages(Shelf *head, int book_number)
//{
//	Shelf *current = head;
//	for (int i = 0; i != book_number; i++) {
//		current = current->next;
//	}
//	return current->pages;
//}
//
//int getNumberOfBooks(Shelf *head)
//{
//	int counter = 0;
//	if (head == NULL) {
//		return counter;
//	}
//
//	counter = 1;
//
//	Shelf *current = head;
//	while (current->next != NULL) {
//		counter++;
//		current = current->next;
//	}
//	return counter;
//}
//
//Shelf *freeShelf(Shelf *head)
//{
//	Shelf *current = head;
//	Shelf *next;
//	while (current->next != NULL) {
//		next = current->next;
//		free(current);
//		current = next;
//	}
//	return NULL;
//}
//
//int main()
//{
//	int number_of_shelves;
//	int number_of_queries;
//	scanf("%d", &number_of_shelves);
//	scanf("%d", &number_of_queries);
//
//	Shelf **shelves = malloc(number_of_shelves * sizeof(Shelf*)); // create an array of Shelf
//	if (shelves == NULL) { printf("Memory allocation error 1\n"); goto end; }
//		/*****************************/
//
//	int input_type;
//
//	while (number_of_queries--) {
//		scanf("%d", &input_type);
//		if (input_type == 1) {
//			int x, y;
//			scanf("%d", &x);
//			scanf("%d", &y);
//			shelves[x] = addBook(shelves[x], y);
//		}
//		else if (input_type == 2) {
//			int x, y;
//			scanf("%d", &x);
//			scanf("%d", &y);
//			printf("%d\n", getPages(shelves[x], y));
//		}
//		else if (input_type == 3) {
//			int x;
//			scanf("%d", &x);
//			printf("%d\n", getNumberOfBooks(shelves[x]));
//		}
//	}
//
//	goto end;
//
//end:
//	/**** free calls ****/
//	system("pause");
//
//	exit(0); // should kill program before executing anything else
//}


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

/*
* This stores the total number of books in each shelf.
*/
//int* total_number_of_books;

/*
* This stores the total number of pages in each book of each shelf.
* The rows represent the shelves and the columns represent the books.
*/
//int** total_number_of_pages;

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
//int main()
//{
//	int i;
//	int total_number_of_shelves;
//	scanf("%d", &total_number_of_shelves);
//
//	int total_number_of_queries;
//	scanf("%d", &total_number_of_queries);
//	total_number_of_books = (int *)calloc(total_number_of_shelves, sizeof(int));
//	total_number_of_pages = (int **)calloc(total_number_of_shelves, sizeof(int *));
//	for (i = 0; i<total_number_of_shelves; i++) {
//		total_number_of_pages[i] = (int *)calloc(1100, sizeof(int));
//	}
//	while (total_number_of_queries--) {
//		int type_of_query;
//		scanf("%d", &type_of_query);
//
//		if (type_of_query == 1) {
//			/*
//			* Process the query of first type here.
//			*/
//			int x, y;
//			scanf("%d %d", &x, &y);
//			for (i = 0; i<1100; i++) {
//				if ((*(total_number_of_pages + x))[i] == 0) {
//					(*(total_number_of_pages + x))[i] = y;
//					total_number_of_books[x] += 1;
//					break;
//				}
//			}
//		}
//		else if (type_of_query == 2) {
//			int x, y;
//			scanf("%d %d", &x, &y);
//			printf("%d\n", *(*(total_number_of_pages + x) + y));
//		}
//		else {
//			int x;
//			scanf("%d", &x);
//			printf("%d\n", *(total_number_of_books + x));
//		}
//	}
//
//	if (total_number_of_books) {
//		free(total_number_of_books);
//	}
//
//	for (int i = 0; i < total_number_of_shelves; i++) {
//		if (*(total_number_of_pages + i)) {
//			free(*(total_number_of_pages + i));
//		}
//	}
//
//	if (total_number_of_pages) {
//		free(total_number_of_pages);
//	}
//	system("Pause");
//	return 0;
//}

//int  main()
//{
//	char str[1001];
//	scanf_s("%s", str);
//	int lut[10] = { 0, };
//	for (int i = 0; i < strlen(str); ++i) {
//		if (str[i] >= '0' && str[i] <= '9') {
//			++lut[str[i] - '0'];
//		}
//	}
//	for (int i = 0; i < 10; ++i) {
//		printf("%d ", lut[i]);
//	}
//	return 0;
//}
//
//int main()
//{
//
//
//	char *s, *t;
//	s = malloc(1024 * sizeof(char));
//	scanf_s("%[^\n]", s);
//	s = realloc(s, strlen(s) + 1);
//
//	t = strtok(s, " ");
//	while (t != NULL) {
//		printf("%s\n", t);
//		t = strtok(NULL, " ");
//	}
//
//	return 0;
//}
//


// print out pattern 
//222
//212
//222
//#define  min(a, b) ((a) < (b) ? (a) : (b))
//int main()
//{
//
//	int n;
//	scanf_s("%d", &n);
//	int len = n * 2 - 1;
//	for (int row = 0; row < len; row++)
//	{
//		for (int col = 0; col < len; col++)
//		{
//			int m = min(row, col);
//			m = min(m, len - row - 1);
//			m = min(m, len - col - 1);
//			printf("%d ", n - m);
//		}
//		printf("\n");
//	}
//
//	system("Pause");
//	return 0;
//}

//// Test ifit is little endien
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
//		printf("edien  %d\n", edien);
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