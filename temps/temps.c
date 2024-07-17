// INCOMPLETE
// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define NUM_CITIES 10
#define SORT_TYPE "MERGE" //LINEAR, BUBBLE or MERGE.
typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];
avg_temp tmp[NUM_CITIES];
avg_temp l[NUM_CITIES];
avg_temp r[NUM_CITIES];

void bubble_sort(void);
void linear_sort(void);
void make_array(char l_or_r, int init, int end);
void merge(avg_temp arr[], int l_initial, int l_final, int r_initial, int r_final);
void merge_sort(void);
void print_arr(avg_temp arr[], int initial, int final);
void sort(avg_temp arr[], int initial, int final);
void sort_cities(string sort);
void swap_temp(int i, int j);

int main(void)
{
    string sort = SORT_TYPE;
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities(sort);

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
// Types of sort I know: linear, bubble, merge.
// Code for each implementation
void sort_cities(string sort)
{
    if (strcmp(sort, "LINEAR") == 0)
    {
        linear_sort();
    }
    else if (strcmp(sort, "BUBBLE") == 0)
    {
        bubble_sort();
    }
    else if (strcmp(sort, "MERGE") == 0)
    {
        merge_sort();
    }
    else
    {
        printf("Incorrect selection.");
    }
}
/*
// Linear (selection sort) (descending)
// Repeat until no unsorted elements remain:
//      Search the unsorted part of the data to find the smallest value
//      Swap the smallest found value with the first element of the unsorted part
*/
void linear_sort(void)
{
    int holding;
    for (int i = 0; i < NUM_CITIES; i++)
    {
        holding = i;
        for (int j = i; j < NUM_CITIES; j++)
        {
            if (temps[j].temp > temps[holding].temp)
            {
                holding = j;
            }
        }
        if (holding != i)
        {
            swap_temp(holding, i);
        }
        else
        {
            return;
        }
    }
}
/*
// Bubble Sort (Descending)
//  Set swap counter to a non-zero value
//  Repeat until the swap counter is 0:
//      Reset swap counter to 0
//      Look at each adjacent pair
//          if two adjacent elements are not in order, swap them and add one to
//          the swap counter
*/
void bubble_sort(void)
{
    int counter = -1;
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0; i < NUM_CITIES - 1; i++)
        {
            if (temps[i].temp < temps[i + 1].temp)
            {
                swap_temp(i, i + 1);
                counter++;
            }
        }
    }
}
/*
Merge sort pseudocode:
    If only one
        quit
    else
        sort the left side
        sort the right side
        merge
*/
void merge_sort(void)
{
//    print_arr(temps, NUM_CITIES); //prints all temps unsorted.
    int begin = 0;
    int end = NUM_CITIES - 1;
    sort(temps, begin, end);

    return;
}
void swap_temp(int i, int j)
{
    tmp[i] = temps[j];
    temps[j] = temps[i];
    temps[i] = tmp[i];
}
void sort(avg_temp arr[], int initial, int final)
{
    int arr_size = final - initial + 1;
    if (arr_size == 1)
    {
        return;
    }
    else
    {
        int middle = (final + initial) / 2;
        // make left array
        // make_array('l', begin, middle);
        /*for (int i = begin; i <= middle; i++)
        {
            l[i] = temps[i];
            //printf("Making first left array: in sort\n");
            //print_arr(l, i + 1);
        }*/
        //make right array
        // make_array('r', middle + 1, end);
        /*for (int i = middle + 1; i < end; i++)
        {
            r[i] = temps[i];
            //printf("Making first right array: in sort\n");
            //print_arr(r, i - middle + 1);
        }*/
        // sort the left half
        // print_arr(l, lsize);
        sort(temps, initial, middle);
        // sort the right half
        sort(temps, middle + 1, final);
        merge(temps, initial, middle, middle + 1, final);
    }
    return;
}
void merge(avg_temp arr[], int l_initial, int l_final, int r_initial, int r_final)
{
    /*
    // Prints indexes passed to merge().
    printf("{ ");
    for (int i = l_initial; i < r_final + 1; i++)
    {
        printf("%i ", i);
    }
    printf("}\n");
    get_string("Press Enter.");
    return;*/
    // Maybe there was never a need to create a new array.
    // Maybe my "new[]" should be temps[].
    int i_max = l_final + 1;
    int j_max = r_final + 1;
    int k_max = j_max;
    int k_size = (l_final - l_initial) + 1 + (r_final - r_initial) + 1;
    //avg_temp new[new_size];
    int i = l_initial;
    int j = r_initial;
    int k = i;
    while (k < k_max)
    {
        // Check base case first
        // base case is i or j is greater than the index of l[] or r[]
        // if i is max, add what remains of r[]
        if (i == i_max)
        {
            while (j < j_max)
            {
                tmp[k] = temps[j];
                k++;
                j++;
            }
        }
        // if j is max, add what remains of l[]
        if (j == j_max)
        {
            while (i < i_max)
            {
                tmp[k] = temps[i];
                k++;
                i++;
            }
        }
        // Add the left half while it's less than the right half
        while ((temps[i].temp < temps[j].temp) && (i < i_max))
        {
            tmp[k] = temps[i];
            i++;
            k++;
        }
        // Add the right half while it's less than the left half
        while ((temps[i].temp > temps[j].temp) && (j < j_max))
        {
            tmp[k] = temps[j];
            j++;
            k++;
        }
        if ((temps[i].temp == temps[j].temp) && (i < i_max) && (j < j_max))
        {
            tmp[k] = temps[i];
            i++;
            k++;
        }
    }
    // Consider updating l[] and r[] at this point.
    // Finally, dump the new array into the original array

    for (k = l_initial; k < k_max; k++)
    {
        temps[k] = tmp[k];
    }
    //print_arr(arr, l_initial, k_max);
    return;
}
// Takes an array of avg_temp and the size as an int to print the
// array on the display. At the end of the printed array, the user
// is prompted to hit return to return from the function.
void print_arr(avg_temp arr[], int initial, int final)
{
    for (int i = initial; i < final - initial; i++)
        {
            printf("%s: %i\n", arr[i].city, arr[i].temp);
        }
        get_string("Press enter to continue. \n");
}
void make_array(char l_or_r, int init, int end)
{
    for (int i = init; i <= end; i++)
        {
            if (l_or_r == 'l')
            {
                l[i] = temps[i];
            }
            else if (l_or_r == 'r')
            {
                r[i] = temps[i];
            }
        }
    return;
}