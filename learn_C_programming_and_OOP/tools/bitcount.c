int revised_bitcount(unsigned int n){
    int b=0;
    while(n &= ( n-1 )){
        b++;
    }
    b++;
    return b;
}