#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>


struct data{

	int key;
	int value;
};

struct hashtable_item{;


	int flag;
	struct data *item;

};

struct hashtable_item *arr;

int max = 7;
int size = 0;
int prime = 3;

int hashfun1(int key)
{
	return (key % max);
}

int hashfun2(int key)
{
	return (prime - (key % prime));
}

void insert(int key, int value)
{
	int h1 = hashfun1(key);
	int h2 = hashfun2(key);

	int index = h1;

	/* insertion */


	struct data *newitem = (struct data*) malloc(sizeof(struct data));

	newitem->key = key;
	newitem->value = value;



if (size == max)
        {
		printf("\n Hash Table is full, cannot insert more items \n");
		return;
	}

	/* probing through other array elements */
	while (arr[index].flag == 1) {
		if (arr[index].item->key == key){

			printf("\n Key already present, hence updating its value \n");
			arr[index].item->value = value;
			return;
		}
		index = (index + h2) % max;
		if (index == h1){

			printf("\n Add is failed \n");
			return;
		}
		printf("\n probing \n");

	}
    arr[index].item = newitem;
	arr[index].flag = 1;
	size++;
	printf("\n Key (%d) has been inserted \n", key);

}

// array


void array(){
	int i;
	for(i = 0; i < max; i++){

		arr[i].item = NULL;
		arr[i].flag = 0;
	}

	prime = get_prime();
}

// returns largest prime number less than size of array


int get_prime(){

	int i,j;

	for (i = max - 1; i >= 1; i--){

		int flag = 0;

		for (j = 2; j <= (int)sqrt(i); j++){

			if (i % j == 0){

				flag++;
			}
		}
		if (flag == 0){

			return i;   //empty entry
		}
	}

	return 3;

}

/* deletion */


void remove_element(int key)
{
	int h1 = hashfun1(key);
	int h2 = hashfun2(key);
	int index = h1;

	if (size == 0)
        {
		printf("\n Hash Table is empty \n");
		return;
	}


 /* searching */


	while (arr[index].flag != 0){

            if (arr[index].flag == 1  &&  arr[index].item->key == key){

			arr[index].item = NULL;
			arr[index].flag = 2;
			size--;
			printf("\n Key (%d) has been removed \n", key);
			return;
		}
		index = (index + h2) % max;
		if (index == h1){
			break;
		}
	}

	printf("\n Key (%d) does not exist \n", key);

}

int size_of_hashtable()
{
	return size;
}


// displays all


void display(){

	int i;
	for (i = 0; i < max; i++){

		if (arr[i].flag != 1){

			printf("\n Array[%d] has no elements \n", i);
		}
		else{

			printf("\n Array[%d] has elements \n Key (%d) and Value (%d) \n", i, arr[i].item->key, arr[i].item->value);
		}
	}
}





void main(){

	int choice, key, value, n, c;

	arr = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item));

	array();

	do {
		printf("Implementation Double Hash Table\n\n");
		printf("\n1.Inserting item in the Hash Table"
               "\n2.Removing item from the Table"
               "\n3.Check the size of the Table"
               "\n4.Display Hash Table"
		       "\n\n Please enter your choice:");
scanf("%d", &choice);

		switch(choice)
                {

		case 1:

		      printf("Inserting element in Hash Table\n");
		      printf("Enter key and value-:\t");
		      scanf("%d %d", &key, &value);
		      insert(key, value);

		      break;

   		case 2:

		      printf("Deleting in Hash Table \n Enter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);

		      break;
 case 3:

		      n = size_of_hashtable();
		      printf("Size of Hash Table is-:%d\n", n);

		      break;

		case 4:

		      display();

		      break;

		default:

		       printf("Wrong Input\n");

		}

		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);

	}while(c == 1);

	getch();


}
