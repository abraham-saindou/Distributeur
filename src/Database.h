//
// Created by kubun on 07/06/23.
//



#ifndef DISTRIBUTEUR_DATABASE_H
#define DISTRIBUTEUR_DATABASE_H

#include <variant>
#include <list>
#include <any>
#include <string>


class Database {


public:
    static std::string Host, User, Passwordd, BDD;
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

    void load(std::string table_name);
    void close_connecetor();
    void count_tablelen();
    void add_product();
    void insert_last_item();
    void del_product();
    void mod_product();

};


#endif //DISTRIBUTEUR_DATABASE_H
