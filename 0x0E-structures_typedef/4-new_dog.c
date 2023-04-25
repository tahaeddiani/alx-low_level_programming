#include "dog.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * new_dog - function that creates a new dog.
 * @name: name dog
 * @age: age dog
 * @owner: owner dog
 * Return: pointer new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
int name_len, owner_len;
dog_t *doge;

if (name == NULL || owner == NULL)
return (NULL);

name_len = strlen(name);
owner_len = strlen(owner);

doge = malloc(sizeof(dog_t));
if (doge == NULL)
return (NULL);

doge->name = malloc((name_len + 1) * sizeof(char));
if (doge->name == NULL)
{
free(doge);
return (NULL);
}
strncpy(doge->name, name, name_len);
doge->name[name_len] = '\0';

doge->age = age;

doge->owner = malloc((owner_len + 1) * sizeof(char));
if (doge->owner == NULL)
{
free(doge->name);
free(doge);
return (NULL);
}
strncpy(doge->owner, owner, owner_len);
doge->owner[owner_len] = '\0';

return (doge);
}
