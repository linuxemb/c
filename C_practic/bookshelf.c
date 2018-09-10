int main()
{
	int i;
	int total_number_of_shelves;
	scanf("%d", &total_number_of_shelves);

	int total_number_of_queries;
	scanf("%d", &total_number_of_queries);
	total_number_of_books = (int *)calloc(total_number_of_shelves, sizeof(int));
	total_number_of_pages = (int **)calloc(total_number_of_shelves, sizeof(int *));
	for (i = 0; i<total_number_of_shelves; i++) {
		total_number_of_pages[i] = (int *)calloc(1100, sizeof(int));
	}
	while (total_number_of_queries--) {
		int type_of_query;
		scanf("%d", &type_of_query);

		if (type_of_query == 1) {
			/*
			* Process the query of first type here.
			*/
			int x, y;
			scanf("%d %d", &x, &y);
			for (i = 0; i<1100; i++) {
				if ((*(total_number_of_pages + x))[i] == 0) {
					(*(total_number_of_pages + x))[i] = y;
					total_number_of_books[x] += 1;
					break;
				}
			}
		}
		else if (type_of_query == 2) {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%d\n", *(*(total_number_of_pages + x) + y));
		}
		else {
			int x;
			scanf("%d", &x);
			printf("%d\n", *(total_number_of_books + x));
		}
	}

	if (total_number_of_books) {
		free(total_number_of_books);
	}

	for (int i = 0; i < total_number_of_shelves; i++) {
		if (*(total_number_of_pages + i)) {
			free(*(total_number_of_pages + i));
		}
	}

	if (total_number_of_pages) {
		free(total_number_of_pages);
	}
	system("Pause");
	return 0;
}
