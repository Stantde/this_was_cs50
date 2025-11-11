#include <stdio.h>

#define COLUMNMAX 80 /* Maximum width for a processed line.*/
#define MAXLINE 1000 /* maximum input line size */
#define TAB 2 /* Number of spaces represented by '\t' */

void detab_line(char line[], int length, int conversion);
int get_blank(char c);
int get_line(char line[], int lim);
void process_line(char line[], int length, int width);

/*
* Exercise 1-21. Write a program to "fold" long input lines after the last non-blank character that occurs before the n-th column of input, where n is a parameter. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
*/

int main() /* Folds input lines after reaching COLUMNMAX columns. */
{
    char line[MAXLINE]; /* current input line */
    int length;
    
    length = get_line(line, (MAXLINE-(MAXLINE/COLUMNMAX + 1))); // Second argument, lim changes based of max number of largest ... What am I thinking?
    process_line(line, length, COLUMNMAX);
    printf("%s", line);
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
Takes line, line length, and width as parameters. Finds the blanks and tries 
to fold the line to an appropriate width, breaking it into smaller lines if 
necessary.

This works for ' ', but what should I do about '\t'? 
    1. Treat '\t' as single ' '.
    2. Treat '\t' as multiple ' '.
        How many? 2, 4, 8. Confgiurable as symbolic constant.
    3. Ignore.
    4. Something else?
*/
void process_line(char line[], int length, int width){
    int cursor;
    int end_point = width;
    int last_blank = 0; /* Index of the previously encountered blank (0 if none found)*/    
    
    for (int cursor=0; cursor<length; cursor++){ //SI
        if (cursor == end_point && line[cursor] == ' '){ // SIII EP is on blank
            // Under these conditions, It doesn't matter what LB was set position to blank, and update LB (later). Update new_EP.
            line[cursor]='\n';
            end_point+=width;
            if (end_point > length){
                end_point = length;
            }
        }
        else if (cursor == end_point){ // SIV EP not on blank
            if ((end_point - last_blank)>0){ // Found LB since last EP
                // Blank between start and end. replace line[last_blank] with '\n' 
                line[last_blank]='\n';              
                end_point = last_blank + width;
                if (end_point > length){
                    end_point = length;
                }
            } else if ((end_point - last_blank) == 0){ //No LB since last EP
                // This segment is long, so push everything back by one, then insert '\n' at EP.
                // Does this break at 0?
                for(int i=length; i>end_point; i--){ //here
                    line[i] = line[i-1];
                }
                line[end_point]='\n';
                last_blank = cursor; // Am I off by one here?
                end_point = last_blank + width;
                if (end_point > length){
                    end_point = length;
                }                
            }            
        }
        if (line[cursor] == ' '){ // SII
            last_blank = cursor;
        }        
    }
    return;
}
/*
Iterate through line. If '\t' is found, extend line by conversion - 1, move 
each element from the end refer to diagram to complete...
*/
void detab_line(char line[], int length, int conversion);
/*
Taken from entab program:
(c =='\t'){
            c=' ';
            for (int i = 0; i < TABCONVERSION-1; i++){
                putchar(' ');
*/