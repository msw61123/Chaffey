#include <iostream>
#include <vector>

using namespace std;

struct order 
{
    int youth;
    int xl; 
    int doubleXl;
    int colorAmount; 
};
void addCustomerInputs(int amountOfOrders, vector <order> *listOfAmountOrders) {
    int amountOfTshirts; 
    int amountOfColors; 
    int amountOfYouthSizes;
    int amountOfXLSizes;
    int amountOfDoubleXLSizes;

    vector <order> listOfOrders; 
    order orders_vec;                

    for (int i = 0; i < amountOfOrders - 1; i++){

         std::cout << "How many colors?";
         std::cin >> amountOfColors;
         orders_vec.colorAmount = amountOfColors;

         std::cout << "How many youth sizes?" << endl;
         std::cin >> amountOfYouthSizes; 
         orders_vec.youth = amountOfYouthSizes;

         std::cout << "How many XL sizes?" << endl;
         orders_vec.xl = amountOfDoubleXLSizes;

         std::cout << "How many Double XL sizes?" << endl;
         std::cin >> amountOfDoubleXLSizes;
         orders_vec.doubleXl = amountOfDoubleXLSizes;
         
         listOfOrders.push_back(orders_vec);
         
    };
    *listOfAmountOrders = listOfOrders; 
    
}


int main()
{
	
    vector <int> amountOfTshirts; 
    vector <int> amountOfColors; 
    vector <order> amountOrdersList;
    int amountOfOrders;
// commnetd
    cout << "Welcome to Tshirt-Co." << endl; 
    
    cout << "How many other orders will you be making today?";
    cin >> amountOfOrders;

    addCustomerInputs(amountOfOrders, &amountOrdersList);
    std::cout << amountOrdersList[0].youth;
	return 0;
}