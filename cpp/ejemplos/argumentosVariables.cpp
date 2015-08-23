http://stackoverflow.com/questions/205529/passing-variable-number-of-arguments-around

 void func(type* values) {
        while(*values) {
            x = *values++;
            /* do whatever with x */
        }
    }
