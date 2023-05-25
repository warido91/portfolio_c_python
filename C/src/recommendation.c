#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "recommendation.h"

void saveMovies(struct Movie movies[], int count) {
    FILE *file = fopen("..\\..\\database.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    int i;
    for (i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%s,%s,%s,%s\n",
                movies[i].id,
                movies[i].title,
                movies[i].description,
                movies[i].genre,
                movies[i].platform,
                movies[i].actors,
                movies[i].directors);
    }

    fclose(file);
}

void addMovie(struct Movie movies[], int *count) {
    printf("\n-- Ajouter un produit --\n");

    struct Movie newMovie;
    printf("Titre : ");
    scanf(" %[^\n]s", newMovie.title);
    printf("Description : ");
    scanf(" %[^\n]s", newMovie.description);
    printf("Genre : ");
    scanf(" %[^\n]s", newMovie.genre);
    printf("Plateforme : ");
    scanf(" %[^\n]s", newMovie.platform);
    printf("Acteurs : ");
    scanf(" %[^\n]s", newMovie.actors);
    printf("Réalisateurs : ");
    scanf(" %[^\n]s", newMovie.directors);

    movies[*count] = newMovie;
    movies[*count].id = *count + 1; // Générer un identifiant unique pour le produit
    (*count)++;

    printf("Produit ajouté avec succès.\n");

    saveMovies(movies, *count); // Appel de la fonction pour sauvegarder les produits
}

void modifyMovie(struct Movie movies[], int count) {
    printf("\n-- Modifier un produit --\n");

    char title[100];
    printf("Entrez le titre du produit à modifier : ");
    scanf(" %[^\n]s", title);

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("mouveau titre : ");
            scanf(" %[^\n]s", movies[i].title);
            printf("Nouvelle description : ");
            scanf(" %[^\n]s", movies[i].description);
            printf("Nouveau genre : ");
            scanf(" %[^\n]s", movies[i].genre);
            printf("Nouvelle plateforme : ");
            scanf(" %[^\n]s", movies[i].platform);
            printf("Nouveaux acteurs : ");
            scanf(" %[^\n]s", movies[i].actors);
            printf("Nouveaux réalisateurs : ");
            scanf(" %[^\n]s", movies[i].directors);

            printf("Produit modifié avec succès.\n");
            return;
        }
    }

    printf("Produit non trouvé.\n");
}

void deleteMovie(struct Movie movies[], int *count) {
    printf("\n-- Supprimer un produit --\n");

    char title[100];
    printf("Entrez le titre du produit à supprimer : ");
    scanf(" %[^\n]s", title);

    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            int j;
            for (j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*count)--;

            printf("Produit supprimé avec succès.\n");
            return;
        }
    }

    printf("Produit non trouvé.\n");
}

void displayMovies() {
    FILE *file = fopen("..\\..\\database.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("\n-- Tous les produits --\n");

    struct Movie movies;
    while (fscanf(file, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                  &movies.id,
                  movies.title,
                  movies.description,
                  movies.genre,
                  movies.platform,
                  movies.actors,
                  movies.directors) != EOF) {
        printf("\nProduit %d\n", movies.id);
        printf("Titre : %s\n", movies.title);
        printf("Description : %s\n", movies.description);
        printf("Genre : %s\n", movies.genre);
        printf("Plateforme : %s\n", movies.platform);
        printf("Acteurs : %s\n", movies.actors);
        printf("Réalisateurs : %s\n", movies.directors);
    }

    fclose(file);
}

void generateStatistics(struct Movie movies[], int count) {
    printf("\n-- Statistiques --\n");

    printf("Nombre total de produits : %d\n", count);

    float averageRating = 0.0;
    int i;
    for (i = 0; i < count; i++) {
        // Supposons que chaque produit a une note moyenne de 4.5 (pour illustrer l'exemple)
        averageRating += 4.5;
    }
    averageRating /= count;
    printf("Note moyenne des utilisateurs : %.2f\n", averageRating);
}

void searchMovie(struct Movie movies[], int count) {
    printf("\n-- Rechercher un produit --\n");

    char searchTitle[100];
    printf("Entrez le titre du produit recherché : ");
    scanf(" %[^\n]s", searchTitle);

    int found = 0;
    int i;
    for (i = 0; i < count; i++) {
        if (strstr(movies[i].title, searchTitle) != NULL) {
            printf("\nProduit trouvé :\n");
            printf("Titre : %s\n", movies[i].title);
            printf("Description : %s\n", movies[i].description);
            printf("Genre : %s\n", movies[i].genre);
            printf("Plateforme : %s\n", movies[i].platform);
            printf("Acteurs : %s\n", movies[i].actors);
            printf("Réalisateurs : %s\n", movies[i].directors);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun produit trouvé avec ce titre.\n");
    }
}

