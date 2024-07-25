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
// commnetdjkhdhaf
    cout << "Welcome to Tshirt-Co." << endl; 
    
    cout << "How many other orders will you be making today?";
    cin >> amountOfOrders;

    addCustomerInputs(amountOfOrders, &amountOrdersList);
    std::cout << amountOrdersList[0].youth;
	return 0;
}
struct CustomerPrice {
    int totalShirts;
    int colorAmount;
    string size;
    double price;
};

double getPricePerShirt(int totalShirts, int colorAmount, const string& size) {
    const int priceTableSize = 5;
    double youthPrices[4][priceTableSize] = {
        {19.69, 20.69, 21.69, 22.69, 23.69},
        {9.69, 11.69, 12.69, 13.69, 14.69},
        {7.70, 9.70, 10.70, 11.70, 12.70},
        {6.70, 8.70, 9.70, 10.70, 11.70}
    };
    double sToXlPrices[4][priceTableSize] = {
        {19.99, 21.99, 22.99, 23.99, 24.99},
        {9.99, 11.99, 12.99, 13.99, 14.99},
        {8.00, 10.00, 11.00, 12.00, 13.00},
        {7.00, 9.00, 10.00, 11.00, 12.00}
    };
    double xlTo5xlPrices[4][priceTableSize] = {
        {21.64, 22.64, 23.64, 24.64, 25.64},
        {11.64, 12.64, 13.64, 14.64, 15.64},
        {9.65, 11.65, 12.65, 13.65, 14.65},
        {8.65, 10.65, 11.65, 12.65, 13.65}
    };

    double (*prices)[5] = nullptr;

    if (size == "youth") {
        prices = youthPrices;
    } else if (size == "S-XL") {
        prices = sToXlPrices;
    } else if (size == "2XL-5XL") {
        prices = xlTo5xlPrices;
    } else {
        return 0; // Default return if no conditions match
    }

    int index = -1;
    if (totalShirts >= 12 && totalShirts <= 24) {
        index = 0;
    } else if (totalShirts >= 25 && totalShirts <= 49) {
        index = 1;
    } else if (totalShirts >= 50 && totalShirts <= 199) {
        index = 2;
    } else if (totalShirts >= 200 && totalShirts <= 299) {
        index = 3;
    } else if (totalShirts >= 300) {
        std::cout << "Call for quote" << endl;
        return -1; // Placeholder for custom quote
    }

    if (index != -1 && colorAmount >= 1 && colorAmount <= 5) {
        return prices[index][colorAmount - 1];
    }

    return 0; // Default return if no conditions match
}

int main() {
    vector<CustomerPrice> CustomerPrices;

    
    vector<tuple<int, int, string>> listOfOrders = {
        {15, 2, "youth"},
        {30, 1, "S-XL"},
        {100, 3, "2XL-5XL"},
        {250, 5, "S-XL"}
    };

    
    for (const auto& order : listOfOrders) {
        int totalShirts = get<0>(order);
        int colorAmount = get<1>(order);
        string size = get<2>(order);
        double price = getPricePerShirt(totalShirts, colorAmount, size);
        CustomerPrices.push_back({totalShirts, colorAmount, size, price});
    }

    /
    for (const auto& customerPrice : CustomerPrices) {
        cout << "Total Shirts: " << customerPrice.totalShirts
             << ", Color Amount: " << customerPrice.colorAmount
             << ", Size: " << customerPrice.size
             << ", Price: $" << customerPrice.price << endl;
    }

    return 0;
}
