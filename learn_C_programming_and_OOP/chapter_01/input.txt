#include <stdio.h>

#define MAXLINE 1000
#define SLASH 47
#define STAR 42

int get_line(char line[], int lim);
void find_comments(char line[], int length);

/*
* Exercise 1-22. Write a program to remove all comments from a C program. Don't
forget to handle quoted strings and character constants properly.
*/

int main() /* Folds input lines after reaching COLUMNMAX columns. */
{
    char line[MAXLINE]; /* current input line */
    int length;

    length = get_line(line, MAXLINE);
    find_comments(line, length);
    return 0;
}
/*
Obtains line from stdin and returns int length.
*/
int get_line(char line[], int lim){
    
    int current_position; /* Index of current position*/
    char c; /* Variable to hold stdin */
    
    
    for (current_position=0; current_position<lim-1 && (c=getchar())!= EOF && c!='\n'; current_position++ ){
        line[current_position] = c;
    }
    if (c == '\n'){
        line[current_position] = '\n';
        current_position++;
    }
    line[current_position] = '\0';        
    return current_position;
}
/*
Find lines containing "//" and or "/*""star/" pairs

*/
void find_comments(char line[], int length){
    int start; // index of opening "/"
    int end; // Index of comment terminus
    for (int i=0; i<length; i++){
        if (line[i]==SLASH && i<length-1){
            if (line[i+1]==SLASH){} //Remove remaining line
            // iterate through line starting after second slash until \n found.
            // consider new function taking line, start and end, to process line moving value @ end index to start index and  continuing through the line to the end. Will return new length.
            else if (line[i+1]==STAR){} // Find matching terminus
        }
    }
    return;
}