//
// Created by kubun on 07/06/23.
//

#include "Database.h"

Database::Database(std::string host, std::string user, std::string password, std::string database;)
{ Host = host, User = user, Password = password, BDD = database;} ;

auto Database::load(std::string table_name) {
    sql::ResultSet *resultSet= statement->executeQuery("SELECT produit.id, produit.nom, produit.quantite,"
                                                       "produit.prix, produit.description, produit.categorie");
    auto data;
}