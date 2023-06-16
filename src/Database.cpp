//
// Created by kubun on 07/06/23.
//

#include "Database.h"
#include <vector>
#include <utility>

Database::Database(std::string host, std::string user, std::string password, std::string database)
    : Host (host), User(user), Passwordd(password), BDD(database) {};

Database::~Database()= default;

auto Database::connection(std::string h, std::string u, std::string p, std::string d) {
    driver = get_driver_instance();
    con = driver->connect(h,u,p);
    con->setSchema(d);
    if (con->isValid()){
        std::cout<<"You are log to "<< d << " database as "<<u<<"\n";
    }
    else {
        std::cout<<"You are not connected, check your username and password\n";
    }
    return con;
}

void Database::load(std::string table_name) {
    Database::connection("localhost","abraham", "abraham","distributeur");
    sql::Statement *statement = con->createStatement();
    sql::ResultSet *resultSet = statement->executeQuery("SELECT id, nom, quantite, prix, description, categorie FROM produit");

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
    /*sql::ResultSet *resultSet1 = statement->executeQuery("SELECT COUNT(*) FROM produit");*/
}

void Database::close_connecetor() {
    con->close();
    delete con;
}


