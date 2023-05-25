#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

struct Movie {
    int id;
    char title[100];
    char description[500];
    char genre[50];
    char platform[50];
    char actors[100];
    char directors[100];
};

void addMovie(struct Movie movies[], int *count);
void modifyMovie(struct Movie movies[], int count);
void deleteMovie(struct Movie movies[], int *count);
void displayMovies();
void generateStatistics(struct Movie movies[], int count);
void searchMovie(struct Movie movies[], int count);
void saveMovies(struct Movie movies[], int count);

#endif /* RECOMMENDATION_H */