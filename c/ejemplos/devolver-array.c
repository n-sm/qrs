
int *create_array(void) {
    int *array = malloc(3 * sizeof(int));
    assert(array != NULL);
    array[0] = 4;
    array[1] = 65;
    array[2] = 23;
    return array;
 }
 void destroy_array(int *array) {
     free(array);
 }
 int main(int argc, char **argv) {
     int *array = create_array();
     for (size_t i = 0; i < 3; ++i)
         printf("%d\n", array[i]);
     destroy_array(array);
     return 0;
 }
