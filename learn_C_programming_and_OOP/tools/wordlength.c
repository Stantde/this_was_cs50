int wordlength(void){
/*
*/
    unsigned int bit_tracker=1;
    int count=0;

    while(bit_tracker){
        bit_tracker=bit_tracker<<1;
        ++count;
        //printf("%i\n", count);
        //printf("%b\n", bit_tracker);
    }
    return count;
}
