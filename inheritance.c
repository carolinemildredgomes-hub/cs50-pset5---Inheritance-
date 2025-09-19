#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

// Number of generations to simulate
#define GENERATIONS 3

// Number of parents each person has
#define PARENTS 2

// Function prototypes
person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele(void);

int main(void)
{
    // Seed random number generator
    srand(time(0));   // ✅ fixed (use srand, not srandom)

    // Create a new family with GENERATIONS generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);

    return 0;
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // Allocate memory for new person
    person *new_person = malloc(sizeof(person));
    if (new_person == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // Set parent pointers
        new_person->parents[0] = parent0;
        new_person->parents[1] = parent1;

        // Randomly assign alleles based on parents
        new_person->alleles[0] = parent0->alleles[rand() % 2];
        new_person->alleles[1] = parent1->alleles[rand() % 2];
    }
    else
    {
        // No parents (base generation)
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;

        // Random alleles
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    return new_person;
}

// Free `p` and all ancestors
void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }

    // Free parents recursively
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Free this person
    free(p);
}

// Print each family member and their alleles
void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }

    // Indentation for generation level
    for (int i = 0; i < generation * 4; i++)
    {
        printf(" ");
    }

    // Print person info
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);

    // Print parents recursively
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele
char random_allele(void)
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
