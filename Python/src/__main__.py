# Fonction de recherche de films

def search_movies():
    search_term = input("Entrez un terme de recherche : ")

    with open("../C/src/database.txt", "r", encoding="utf-8") as file:
        movies = file.readlines()

    found_movies = []

    for movie in movies:
        movie_info = movie.strip().split(",")
        title = movie_info[1]

        if search_term.lower() in title.lower():
            found_movies.append(movie)

    if found_movies:
        print(f"\nRésultats de la recherche pour '{search_term}':\n")
        for movie in found_movies:
            movie_info = movie.strip().split(",")
            print("Titre :", movie_info[1])
            print("Description :", movie_info[2])
            print("Genre :", movie_info[3])
            print("Plateforme :", movie_info[4])
            print("Acteurs :", movie_info[5])
            print("Réalisateurs :", movie_info[6])
            print("-------------------------------------")
    else:
        print(f"Aucun film trouvé pour '{search_term}'.")

search_movies()