//
// Created by kubun on 07/06/23.
//



#ifndef DISTRIBUTEUR_DATABASE_H
#define DISTRIBUTEUR_DATABASE_H

#include <variant>
#include <list>
#include <any>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>


class Database {

private:
    std::string& Host, User, Passwordd, BDD;

public:
    sql::Driver *driver;
    sql::Connection *con;

    Database(std::string host, std::string user, std::string password, std::string database);
    ~Database();

    /*union MyUnion{
        int id;
        std::string nom;
        int quantite;
        int prix;
        std::string description;
        std::string categorie;
    };
    std::list<std::list<MyUnion>> list;
    MyUnion element1;
    MyUnion element2;
    MyUnion element3;
    MyUnion element4;
    MyUnion element5;
    MyUnion element6; */


    /*sql::ResultSet *resultSet3= statement->executeQuery("SELECT * FROM produit");*/

    auto connection(std::string h, std::string u, std::string p, std::string d);
    auto load(std::string table_name);
    void close_connecetor();
    void count_tablelen();
    void add_product(std::string nom, int quantite, int prix, std::string description, int categorie);
    void insert_last_item();
    void del_product();
    void mod_product();

};


#endif //DISTRIBUTEUR_DATABASE_H
