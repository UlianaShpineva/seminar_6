//
// Created by ulian on 02.12.2023.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct vector;

struct vector* create_vector(size_t);
int64_t* get_element_at(struct vector* vector, size_t i);
size_t get_length(struct vector const* vector);
size_t get_capacity(struct vector const* vector);
void change_size(struct vector* vector, size_t i);
void add_element_to_end(struct vector* vector, int64_t value);
void add_vector_to_end(struct vector* v1, struct vector* v2);
void free_vector(struct vector *vector);
void print_vector(struct vector* vector);

#endif
