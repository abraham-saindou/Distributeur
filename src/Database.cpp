//
// Created by kubun on 07/06/23.
//

#include "Database.h"
#include <vector>
#include <utility>
#include <iostream>

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

auto Database::load(std::string table_name) {
    Database::connection("localhost","abraham", "abraham","distributeur");
    statement = con->createStatement();
    resultSet = statement->executeQuery("SELECT id, nom, quantite, prix, description, categorie FROM produit");

    std::vector<std::tuple<int, std::string, int, int, std::string, int>> datalist;
    while (resultSet->next()) {
        int id = resultSet->getInt("id");
        std::string nom = resultSet->getString("nom");
        int quantite = resultSet->getInt("quantite");
        int prix = resultSet->getInt("prix");
        std::string description = resultSet->getString("description");
        int categorie = resultSet->getInt("categorie");

        std::tuple<int, std::string, int, int, std::string, int> tuple = std::make_tuple(id, nom, quantite, prix, description, categorie);
        datalist.push_back(tuple);

    }
    for (auto & i : datalist) {
        std::cout<<get<0>(i)<< " "<<get<1>(i)<< " "<<get<2>(i)<<" "<<get<3>(i)<<" "<<get<4>(i)<<" "<<get<5>(i)<<"\n";

    }
    std::cout<<datalist.size();
    delete resultSet;
    return datalist;
}

void Database::add_product(std::string nom, int quantite, int prix, std::string description, int categorie) {
    auto obj = load("produit");
    std::string item = "INSERT into produit (nom, description, prix, quantite, id_categorie) VALUES(%s,%s,%s,%s,%s)";
    std::string cat = "INSERT into categorie (nom) VALUES (%s)";
    std::tuple<std::string, int, int, std::string, int> data = std::make_tuple(nom, quantite, prix, description, categorie);

    /*for(int i = 0; i < obj.size(); ++i){
        if (nom != get<0>(obj[i]))
    }*/

}

void Database::del_product(int num) {
    std::string del_item = "DELETE FROM produit WHERE id = %s";

    prep = con->prepareStatement(del_item);
    prep->setInt(1,num);
    prep->executeUpdate();

    delete prep;

}

void Database::close_connecetor() {
    con->close();
    delete con;
}


