import os

def display_products():
    file_path = "database.txt"  # Chemin relatif vers le fichier database.txt

    if not os.path.exists(file_path):
        print("Le fichier database.txt n'existe pas.")
        return

    with open(file_path, "r") as file:
        print("\n-- Tous les produits --")

        for line in file:
            product = line.strip().split(",")
            product_id, title, description, genre, platform, actors, directors = product

            print(f"\nProduit {product_id}")
            print(f"Titre : {title}")
            print(f"Description : {description}")
            print(f"Genre : {genre}")
            print(f"Plateforme : {platform}")
            print(f"Acteurs : {actors}")
            print(f"Réalisateurs : {directors}")

def search_product():
    file_path = "database.txt"  # Chemin relatif vers le fichier database.txt

    if not os.path.exists(file_path):
        print("Le fichier database.txt n'existe pas.")
        return

    search_term = input("Entrez un terme de recherche : ")

    with open(file_path, "r") as file:
        print("\n-- Résultats de la recherche --")

        for line in file:
            product = line.strip().split(",")
            product_id, title, description, genre, platform, actors, directors = product

            # Vérifier si le terme de recherche correspond au titre ou à la description
            if search_term.lower() in title.lower() or search_term.lower() in description.lower():
                print(f"\nProduit {product_id}")
                print(f"Titre : {title}")
                print(f"Description : {description}")
                print(f"Genre : {genre}")
                print(f"Plateforme : {platform}")
                print(f"Acteurs : {actors}")
                print(f"Réalisateurs : {directors}")

# Point d'entrée de l'application
def main():
    while True:
        print("\n--- Application Utilisateur ---")
        print("1. Afficher tous les produits")
        print("2. Rechercher un produit")
        print("3. Quitter")

        choice = input("Entrez votre choix : ")

        if choice == "1":
            display_products()
        elif choice == "2":
            search_product()
        elif choice == "3":
            break
        else:
            print("Choix invalide. Veuillez réessayer.")

    print("Merci d'avoir utilisé l'application utilisateur.")

if __name__ == "__main__":
    main()
