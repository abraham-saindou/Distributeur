//
// Created by kubun on 07/06/23.
//

#include "Database.h"
#include <vector>
#include <utility>

Database::Database(std::string host, std::string user, std::string password, std::string database)
{ Host = std::move(host), User = std::move(user), Password = std::move(password), BDD = std::move(database);};



Database::~Database()= default;

void Database::load(std::string table_name) {
    sql::ResultSet *resultSet = statement->executeQuery("SELECT produit.id, produit.nom, produit.quantite,"
                                                       "produit.prix, produit.description, produit.categorie");
    std::cout<<"I am here";


    std::vector<std::vector<std::variant<int, std::string, int, int, std::string, std::string>>> datalist;
    while (resultSet->next()){
        int id = resultSet->getInt("id");
        std::string nom = resultSet->getString("nom");
        int quantite = resultSet->getInt("quantite");
        int prix = resultSet->getInt("prix");
        std::string description = resultSet->getString("description");
        std::string categorie = resultSet->getString("categorie");

        std::cout<<id<<nom<<quantite<<prix<<description<<categorie;


        /*struct list{
            int clone = id;
            std::string nom2 = nom;
            int quantite2 = quantite;
            int prix2 = prix;
            std::string des = description;
            std::string cat = categorie;*/
        }
   /* auto data;*/
}

void Database::count_tablelen() {
    sql::ResultSet *resultSet1 = statement->executeQuery("SELECT COUNT(*) FROM produit");
}

void Database::close_connecetor() {
    con->close();
    delete con;
}


