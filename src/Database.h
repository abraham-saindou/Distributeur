//
// Created by kubun on 07/06/23.
//



#ifndef DISTRIBUTEUR_DATABASE_H
#define DISTRIBUTEUR_DATABASE_H

#include <variant>
#include <list>
#include <any>
#include <string>
#include <vector>
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
    sql::Statement *statement;
    sql::PreparedStatement *prep;
    sql::ResultSet *resultSet;

    Database(std::string host, std::string user, std::string password, std::string database);
    ~Database();

    auto connection(std::string h, std::string u, std::string p, std::string d);
    std::vector<std::tuple<int, std::string, int, int, std::string, int>> load(std::string table_name);
    void close_connecetor();
    void add_product(std::string nom, int quantite, int prix, std::string description, int categorie);
    void insert_last_item();
    void del_product(int num);
    void mod_product(std::string nom, int quantite, int prix, std::string description, int categorie, int id);

};


#endif //DISTRIBUTEUR_DATABASE_H
