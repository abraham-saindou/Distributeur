//
// Created by kubun on 07/06/23.
//

#include "Database.h"
#include <vector>
#include <iostream>

Database::Database(std::string host, std::string user, std::string password, std::string database)
    : Host (host), User(user), Passwordd(password), BDD(database) {};

Database::~Database() = default;

auto Database::connection(std::string Host, std::string User, std::string Passwordd, std::string BDD) {
    driver = get_driver_instance();
    con = driver->connect(Host,User,Passwordd);
    con->setSchema(BDD);
    if (con->isValid()){
        std::cout<<"You are log to "<< BDD << " database as "<<User<<".\n\n";
    }
    else {
        std::cout<<"You are not connected, check your username and password\n";
    }
    return con;
}

std::vector<std::tuple<int, std::string, int, int, std::string, int>> Database::load(std::string table_name){
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
    std::cout<<"id"<<" | "<<"nom"<<" | "<<"quantite"<<" | "<<"prix"<<" | "<<"description"<<" | "<<"categorie\n";
    for (auto & i : datalist) {
        std::cout<<get<0>(i)<< " | "<<get<1>(i)<< " | "<<get<2>(i)<<" | "<<get<3>(i)<<" | "<<get<4>(i)<<" | "<<get<5>(i)<<"\n";
    }
    delete resultSet;
    return datalist;
}

void Database::add_product(std::string nom, int quantite, int prix, std::string description, int categorie) {
    std::string item = "INSERT into produit (nom, quantite, prix, description, categorie) VALUES (?, ?, ?, ?, ?)";
    std::string cat = "INSERT into categorie (nom) VALUES (%s)";
    std::tuple<std::string, int, int, std::string, int> data = std::make_tuple(nom, quantite, prix, description, categorie);

    prep = con->prepareStatement(item);
    prep->setString(1, nom);
    prep->setInt(2, quantite);
    prep->setInt(3, prix);
    prep->setString(4, description);
    prep->setInt(5, categorie);
    prep->executeUpdate();

    delete prep;
}

void Database::mod_product(std::string nom, int quantite, int prix, std::string description, int categorie, int id) {
    std::string mod_item = "UPDATE produit SET nom = ?, quantite = ?, prix = ?, description = ?, categorie = ? WHERE id = ?";

    prep = con->prepareStatement(mod_item);
    prep->setString(1, nom);
    prep->setInt(2, quantite);
    prep->setInt(3, prix);
    prep->setString(4, description);
    prep->setInt(5, categorie);
    prep->setInt(6, id);

    prep->executeUpdate();

}

void Database::del_product(int num) {
    std::string del_item = "DELETE FROM produit WHERE id = ?";

    prep = con->prepareStatement(del_item);
    prep->setInt(1,num);
    prep->executeUpdate();
    load("produit");

    delete prep;
}

std::tuple<int, std::string, int, int, std::string, int> Database::insert_last_item() {
    statement = con->createStatement();
    resultSet = statement->executeQuery("SELECT * FROM produit ORDER BY ID DESC LIMIT 1");
    std::tuple<int, std::string, int, int, std::string, int> tuple;
    while (resultSet->next()){
        int id = resultSet->getInt("id");
        std::string nom = resultSet->getString("nom");
        int quantite = resultSet->getInt("quantite");
        int prix = resultSet->getInt("prix");
        std::string description = resultSet->getString("description");
        int categorie = resultSet->getInt("categorie");

        tuple = std::make_tuple(id, nom, quantite, prix, description, categorie);
    }
    return tuple;
}

std::vector<std::tuple<int, std::string, std::string>> Database::show_item() {
    statement = con->createStatement();
    resultSet = statement->executeQuery("SELECT produit.id, produit.nom, produit.description FROM produit");
    std::vector<std::tuple<int, std::string, std::string>> itemlist;

    while (resultSet->next()){
        int id = resultSet->getInt("id");
        std::string nom = resultSet->getString("nom");
        std::string description = resultSet->getString("description");

        std::tuple<int, std::string, std::string> tuple = std::make_tuple(id, nom, description);
        itemlist.push_back(tuple);
    }

    for (auto & obj : itemlist) {
        std::cout<<get<0>(obj)<< " | "<<get<1>(obj)<< " | "<<get<2>(obj)<<"\n";
    }
    return itemlist;
}

void Database::select_item() {
    auto itemlist = Database::show_item();
    int choice;
    std::cin>>choice;

    for(auto & tuple : itemlist){
        if (choice == std::get<0>(tuple)){
            std::cout<<"You've chosen "<<std::get<0>(tuple)<<" drink";
        }
    }
}

void Database::insert_money() {
    std::cout<<"Insert";
}

void Database::close_connector() {
    con->close();
    delete con;
}
