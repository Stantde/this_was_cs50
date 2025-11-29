void reverse(char s1[], char s2[], int len){
    int i;

    i = 0;
    s2[len]='\0';
    while ((s1[i]) != '\0'){
        s2[len-(i+1)] = s1[i];
        ++i;
        
        
    }
}