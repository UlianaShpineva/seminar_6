#include "vector.h"

struct vector {
    size_t length;
    size_t capacity;
    int64_t *data;
};

struct vector* create_vector(size_t length) {
    struct vector* new_vector = malloc(sizeof(struct vector));
    if (new_vector == NULL)
        return NULL;
    new_vector->data = malloc(sizeof(int64_t) * length);
    if (new_vector->data == NULL)
        return NULL;
    new_vector->length = 0;
    new_vector->capacity = length;
    return new_vector;
}

int64_t* get_element_at(struct vector* vector, size_t i) {
    if (i >= vector->length)
        return NULL;
    return vector->data + i;
}

size_t get_length(struct vector const* vector) {
    return vector->length;
}

size_t get_capacity(struct vector const* vector) {
    return vector->capacity;
}

void change_size(struct vector* vector, size_t i) {
    vector->data = realloc(vector->data, sizeof(int64_t) * i);
    if (i < vector->length)
        vector->length = i;
    vector->capacity = i;
}

void add_element_to_end(struct vector* vector, int64_t value) {
    if (vector->length == vector->capacity) {
        change_size(vector, vector->capacity * 2);
    }
    vector->data[vector->length++] = value;
}

void add_vector_to_end(struct vector* v1, struct vector* v2) {
    for (size_t i = 0; i < v2->length; i++) {
        add_element_to_end(v1, v2->data[i]);
    }
}

void free_vector(struct vector *vector) {
    if (vector->data)
        free(vector->data);
    free(vector);
}

void print_vector(struct vector* vector) {
    for (size_t i = 0; i < vector->length; ++i) {
        printf("%" PRId64 " ", vector->data[i]);
    }
    printf("\n");
}
