//
// Created by kubun on 07/06/23.
//



#ifndef DISTRIBUTEUR_DATABASE_H
#define DISTRIBUTEUR_DATABASE_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>



class Database {
private:
    std::string Host, User, Password, BDD;

public:
    Database(std::string host, std::string user, std::string password, std::string database;);

    sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
    sql::Connection *con = driver->connect(Host, User, Password);
    sql::Statement *statement = con->createStatement();
    sql::ResultSet *resultSet= statement->executeQuery("SELECT * FROM produit");

    auto load(std::string table_name);
    void close_connecetor();
    void add_product();
    void insert_last_item();
    void del_product();
    void mod_product();

};


#endif //DISTRIBUTEUR_DATABASE_H
