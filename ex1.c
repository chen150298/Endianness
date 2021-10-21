// 209192798 Chen Larry

/**
 * is big endian.
 * check if the memory stored by big endian representation.
 *
 * i checked if number 1 representation is with big endian.
 * if big: 1 will be located in the last address byte.
 */
int is_big_endian() {
    long int num = 1;
    char* start_address = (char*) &num;
    // access the last byte address
    return start_address[sizeof(num) - 1];
}

/**
 * merge bytes.
 * creating number with half of x bytes and half of y bytes.
 *
 * i created unsigned long result and put x and y bytes in it.
 * */
unsigned long merge_bytes(unsigned long x, unsigned long int y){
    // making access to bytes
    char* x_bytes = (char*) &x;
    char* y_bytes = (char*) &y;
    unsigned long result = 0;
    char* result_bytes = (char*) &result;
    // setting result
    if(is_big_endian()) {
        // setting result as half x half y from *start* address
        int i = 0;
        for(; i < sizeof(x)/2; i++)
            result_bytes[i] = x_bytes [i];
        for (; i < sizeof(y); i++)
            result_bytes[i] = y_bytes [i];
    }
    if (!is_big_endian()){
        // setting result as half x half y from *end* address
        int i = sizeof(x) - 1;
        for(; i >= sizeof(x)/2; i--)
            result_bytes[i] = x_bytes[i];
        for(;i >= 0; i--)
            result_bytes[i] = y_bytes[i];
    }
    // result is set
    return result;
}

/**
 * put byte.
 * gets a char and located it in the i byte of x.
 * */
unsigned long put_byte(unsigned long x, unsigned char b, int i){
    // making access to x bytes
    char* x_bytes = (char*) &x;
    if (is_big_endian())
        // big endian, access from start address
        x_bytes[i] = b;
    else
        // little endian, access from last address
        x_bytes[sizeof(x) - 1 - i] = b;
    return x;
}




