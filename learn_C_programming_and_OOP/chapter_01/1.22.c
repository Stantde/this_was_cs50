/*
* Exercise 1-22. Write a program to remove all comments from a C program. Don't
forget to handle quoted strings and character constants properly.
*/

#include <stdio.h>

#define BOOL int
#define FALSE 0
#define MAXLINE 1000
#define SLASH 47
#define STAR 42
#define TRUE 1
#define NORMAL	0	/*The processor is currently in standard code.*/
#define IN_S_QUOTE	1	/*The processor is inside a single-quoted character constant (e.g., 'a').*/
#define IN_D_QUOTE	2	/*The processor is inside a double-quoted string (e.g., "hello").*/
#define IN_BLOCK_COMMENT	3	/*The processor is inside a block comment (/* ... *\/).*/
#define IN_LINE_COMMENT	4	/*The processor is inside a line comment (// ...).*/
#define FINAL 5
#define STARTING_COMMENT 6
#define ESCAPED 7 
    
void check_state(char c);
int get_line(char line[], int lim);
void find_comments(char line[], int length);

int previous_state;
int current_state;
int new_state;

int main() /* Folds input lines after reaching COLUMNMAX columns. */
{
    char line[MAXLINE]; /* current input line */
    int length;

    new_state = NORMAL;
    current_state = new_state;
    
    while (current_state != FINAL){
        get_line(line, MAXLINE);
        find_comments(line, length);
    }
    
    return 0;
}
/*
Obtains line from stdin and returns int length.
length is equal to the index of line terminating \0
*/
int get_line(char line[], int lim){
    
    int current_position; /* Index of current position*/
    char c; /* Variable to hold stdin */
    BOOL state_changed = FALSE;
    
    
    for (current_position=0; current_position<lim-1 && (c=getchar())!= EOF && c!='\n'; current_position++ ){
        line[current_position] = c;
        state_changed = check_state(c);
    }
    state_changed = check_state(c);
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
int check_state(char c){
    /*
    From N to: single quote, double quote, starting comment, final
    From Q to 
    */   
    if (c == EOF){
        current_state = FINAL;
        return TRUE;        
    }    
    int state;
    if (current_state == NORMAL){
        if (c == '\''){
           new_state = IN_S_QUOTE;
        }
        if (c == '"'){
           new_state=IN_D_QUOTE;
        }
        
    }
    else if(current_state == STARTING_COMMENT){
        if (c == '/'){
            change_state(IN_LINE_COMMENT);
        }else if (c == '*'){
        change_state(IN_BLOCK_COMMENT);
    } else if (c == '\''){
        change_state(IN_S_QUOTE);
    } else if (c == '"'){
        change_state(IN_D_QUOTE);
    } else if (c == '/'){
        change_state(STARTING_COMMENT);
    }
    }

}