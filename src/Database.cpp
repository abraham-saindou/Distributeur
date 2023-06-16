//
// Created by kubun on 07/06/23.
//

#include "Database.h"
#include <vector>
#include <utility>

Database::Database(std::string host, std::string user, std::string password, std::string database)
    : Host (host), User(user), Passwordd(password), BDD(database) {};

Database::~Database()= default;

auto Database::connection(std::string Host, std::string User, std::string Passwordd, std::string BDD) {
    driver = get_driver_instance();
    con = driver->connect(Host,User,Passwordd);
    con->setSchema(BDD);
    if (con->isValid()){
        std::cout<<"You are log to "<< BDD << " database as "<<User<<"\n";
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

    std::vector<std::tuple<int, std::string, int, int, std::string, std::string>> datalist;
    while (resultSet->next()) {
        int id = resultSet->getInt("id");
        std::string nom = resultSet->getString("nom");
        int quantite = resultSet->getInt("quantite");
        int prix = resultSet->getInt("prix");
        std::string description = resultSet->getString("description");
        int categorie = resultSet->getInt("categorie");

        std::tuple<int, std::string, int, int, std::string, int> t = std::make_tuple(id, nom, quantite, prix, description, categorie);

        std::cout << id << nom << quantite << prix << description << categorie;
        datalist.push_back(t);

        struct list {
            int clone = id;
            std::string nom2 = nom;
            int quantite2 = quantite;
            int prix2 = prix;
            std::string des = description;
            int cat = categorie;
        };
    }
}


void Database::add_product(std::string nom, int quantite, int prix, std::string description, int categorie) {

}

void Database::close_connecetor() {
    con->close();
    delete con;
}


