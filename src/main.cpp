#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>

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
private : std::string DrinkName; 
          unsigned short int quantity ;
          unsigned short int number;
          float price;

public :
    std::fstream fs{"DRINK LIST.txt", std::ios::out};
    Drinks(std::string Name, float prix, int quant, int num) 
    { DrinkName = Name, price = prix, quantity = quant, number = num;} ;
    
    void Add_Drinks()
    {
        std::fstream fs{"DRINK LIST.txt", std::ios::out};
        std::cout<<"Enter the name, quantity, price and the number of the new drink";
        std::cin>>DrinkName>>quant>>prix>>num;
        std::pair<std::pair<std::string, int>,std::pair<double,int>> Drink = {std::make_pair("pepsi", 15), std::make_pair(1.5, 5 )};
        
    };
   
   
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
    
    Drinks Pepsi{"Pepsi", 1.5, 2, 6};
};