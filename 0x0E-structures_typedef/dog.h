#ifndef dog_H
#define dog_H
/**
 * struct dog - Define a new type vars
 * @name: name char dog
 * @age: age float dog
 * @owner: owner char dog
 */

struct dog
{
char  *name;
float  age;
char  *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
typedef struct dog dog_t;
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
