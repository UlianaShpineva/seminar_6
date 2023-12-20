#include "vector.h"

int main() {
    struct vector* my_vector = create_vector(5);
    change_size(my_vector, 20);

    for (int64_t i = 0; i <= 20; i++) {
        add_element_to_end(my_vector, i*i);
    }
    print_vector(my_vector);

    change_size(my_vector, 10);
    print_vector(my_vector);
    free_vector(my_vector);

    return 0;
}
