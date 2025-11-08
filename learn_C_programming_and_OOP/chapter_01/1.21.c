#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define COLUMNMAX 80

int get_blank(char c);
int get_line(char line[], int lim);
void process_line(char line[], int length, int width);

/*
* Exercise 1-21. Write a program to "fold" long input lines after the last non-blank character that occurs before the n-th column of input, where n is a parameter. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
*/

int main() /* Folds input lines after reaching COLUMNMAX columns. */
{
    char *test = "* Exercise 1-21. Write a program to 'fold' long input lines after the last non-blank character that occurs before the n-th column of input, where n is a parameter. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.";
    // printf("%s", test);
    char line[MAXLINE]; /* current input line */
    char output[MAXLINE]; 
    
    //starting_position = get_line(test, COLUMNMAX, starting_position);
    int length = get_line(line, (MAXLINE-(MAXLINE/COLUMNMAX + 1)));
    process_line(line, length, COLUMNMAX);
    printf("%s", line);
    return 0;
}
/*
Obtains line from stdin and returns int length.
*/
int get_line(char line[], int lim){
    // What qualifies as blanks? blanks = [' ']
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
*/
void process_line(char line[], int length, int width){
    int cursor;
    int last_blank = 0; /* Index of the previously encountered blank (0 if none found)*/    
    
    for (int cursor=0; cursor<length; cursor++){
        if (cursor == width){
            if ((width - last_blank)>0){
                // Blank between start and end. replace line[last_blank] with '\n' 
                line[last_blank]='\n';                              
            } else if ((width - last_blank) == 0){
                // This segment is long, so push everything back by one, then insert '\n' at width.
                // Does this break at 0?
                for(int i=length; i>width; i--){
                    line[i] = line[i-1];
                }
                line[width]='\n';
                last_blank = cursor; // Am I off by one here?                
            }
            width = last_blank + COLUMNMAX;
            if (width > length){
                width = length;
            }                
        }
        if (line[cursor] == ' '){
            last_blank = cursor;
        }        
    }
    return;
}
