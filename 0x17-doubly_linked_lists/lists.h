#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/* Structure for a doubly linked list node */
typedef struct dlistint_s {
    int n;                          /* Data */
    struct dlistint_s *prev;        /* Pointer to the previous node */
    struct dlistint_s *next;        /* Pointer to the next node */
} dlistint_t;

/* Function prototype */
size_t print_dlistint(const dlistint_t *h);

#endif /* LISTS_H */
