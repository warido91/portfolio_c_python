#include <stdio.h>
#include <string.h>
#include "recommendation.h"
#include <locale.h>

int main() {
    //setlocale(LC_ALL, "");  Fonction de localisation pour les accents
    struct Movie movies[100];
    int count = 0;
    int choice;

    

    do {
        printf("\n-- Menu --\n");
        printf("1. Ajouter un film\n");
        printf("2. Modifier un film\n");
        printf("3. Supprimer un film\n");
        printf("4. Afficher tous les films\n");
        printf("5. Générer des statistiques\n");
        printf("6. Rechercher un film\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                modifyMovie(movies, count);
                break;
            case 3:
                deleteMovie(movies, &count);
                break;
            case 4:
                displayMovies();
                break;
            case 5:
                generateStatistics(movies, count);
                break;
            case 6:
                searchMovie(movies, count);
                break;
            case 7:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
