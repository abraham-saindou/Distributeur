#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
#include "Database.h"


void Menu(){;
    int choice;
    
    std::cout<<"|______________________________________|\n\n";
    std::cout<<"|                                      |\n\n";
    std::cout<<"|        Quebec Machine Drinks         |\n\n";
    std::cout<<"|                                      |\n\n";
    std::cout<<"|______________________________________|\n\n";
    std::cout<<"|                                      |\n\n";
    std::cout<<"|                 Menu                 |\n\n";
    std::cout<<"|                                      |\n\n";
    std::cout<<"|1- Admin(add, remove drinks and stats)|\n\n";
    std::cout<<"|2- Buy drinks                         |\n\n";
    std::cout<<"|3- Exit                               |\n\n";
    std::cin>>choice;
    
    switch (choice)
    {
    case 1:
        std::cout<<"|You've chosen to access admin|\n\n";
        void AdminMenu();
        break;
    
    case 2 :
        std::cout<<"|What do you want to buy ?|\n\n";
        void Choose_Drinks();

    case 3 :
        std::cout<<"|Goodbye !|\n\n";
        
    default:
        break;
    }

};
class Drinks
{
   
   
    void Remove_Drinks();
    void Archive_Drinks();
    void Shows_Stats();
};

class Buy_Choose
{
private : 

public :
    void Choose_Drinks();
    void With_Card();
    void With_Coins();
};

int main()
{
    Database test{"localhost", "abraham", "abraham", "distributeur"};
    test.load("produit");
    test.mod_product("Ice Tea", 12, 1, "Thé glacé", 1, 2);
    test.load("produit");
    test.close_connector();
    /*test.del_product(3);*/
    /*test.add_product("Sambo", 13, 1,"Jus de bananes", 1);*/
    /*Drinks Pepsi{"Pepsi", 1.5, 2, 6};*/
};