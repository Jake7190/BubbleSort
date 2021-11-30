// Project Name: Assignment_1_Jacob_McMahon 
// Purpose: Sort Arrays
// Author: Jacob McMahon

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void swap(int list[], int first, int second)
{
	int minIndex;
	minIndex = first;
	minIndex = list[first];
	list[first] = list[second];
	list[second] = minIndex;
} 


int minLocation(int list[], int first, int last, int& comp, int& assignment)
{
	int minIndex;
	assignment++; 
	minIndex = first;
	assignment++; 
	for (int location = first + 1; location <= last; location++)
	{
		comp++; 
		if (list[location] < list[minIndex])
		{
			comp++; 
			minIndex = location;
			assignment++; 
		}
	}
	return minIndex;
} 


void Create_Array(int mylist[], int len)
{
	srand(time(0));
	for (int i = 0; i < len; i++)
	{
		mylist[i] = rand() % 10000;
	}
}

void insertionSort(int list[], int length)
{
	int comparison = 0, item_assignment = 0;
	item_assignment++;
	for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
	{
		comparison++;
		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
		{
			comparison++;
			int temp = list[firstOutOfOrder];
			int location = firstOutOfOrder;
			item_assignment += 2;
			do
			{
				list[location] = list[location - 1];
				location--;
				item_assignment++;
				comparison += 2;
			} while (location > 0 && list[location - 1] > temp);

			list[location] = temp;
			item_assignment++;
		}
	}
	cout << "---- Insertion Sort ----\n";
	cout << "# of comparisons: " << comparison << "\n";
	cout << "# of item assignments: " << item_assignment << "\n";
}

void selectionSort(int list[], int length)
{
	int minIndex, comparison = 0, item_assignment = 0;

	item_assignment++;
	for (int loc = 0; loc < length; loc++)
	{
		comparison++;
		minIndex = minLocation(list, loc, length - 1, comparison, item_assignment);
		swap(list, loc, minIndex);
		item_assignment += 3;
	}
	cout << "---- Selection Sort ----\n";
	cout << "# of comparison: " << comparison << "\n";
	cout << "# of item assignment: " << item_assignment << "\n";
}



void bubbleSort(int list[], int length)
{
	int item_assignment = 0;
	int comp = 0;
	item_assignment++;
	for (int iteration = 1; iteration < length; iteration++)
	{
		item_assignment++;
		comp++;
		for (int index = 0; index < length - iteration; index++)
		{
			comp++;
			if (list[index] > list[index + 1])
			{
				comp++;
				int item_assignment = list[index];
				list[index] = list[index + 1];
				list[index + 1] = item_assignment;
				item_assignment += 3;
			}
		}
	}
	cout << "---- Bubble Sort ---- \n";
	cout << "# of comparisons: " << comp << "\n";
	cout << "# of item assignments: " << item_assignment << "\n";
}



int main()
{
	int mylist_1[250], mylist_2[250], mylist_3[250];
	Create_Array(mylist_1, 250);
	for (int i = 0; i < 250; i++)
	{
		mylist_2[i] = mylist_1[i];
		mylist_3[i] = mylist_1[i];
	}
	bubbleSort(mylist_1, 250);
	selectionSort(mylist_2, 250);
	insertionSort(mylist_3, 250);
	return 0;
}