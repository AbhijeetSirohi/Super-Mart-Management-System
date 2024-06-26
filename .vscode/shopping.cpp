#include <iostream>
#include <limits> // for clearing input buffer
#include <conio.h> // for _getch()
#include <bits/stdc++.h>
#include<fstream>
using namespace std;
void blue()
{
    cout<<"\033[0;34m";
}
void purple()
{
    cout<<"\033[0;35m";
}
void red()
{
    cout<<"\033[0;31m";
}
void green()
{
    cout<<"\033[0;32m";
}
void yellow()
{
    cout<<"\033[0;33m";
}
void reset()
{
    cout<<"\033[0m";
}
void highlight()
{
    cout<<"\033[0;41m";
}
void signin_cust();
void signin();
void signup();
void displaySecondpage();
void category(){};


//here2

//priting the bill
// Define the Bill class
class Bill {
public:
    int productId;
    string productName;
    float totalprice;
    int quantity;

    // Constructor
    Bill(int id, const string& name, float price, int qty)
        : productId(id), productName(name), totalprice(price), quantity(qty) {}

    // Function to add item to bill
    void addToBill(ofstream& billFile) const {
        float totalPrice1 = totalprice;

        billFile << "Product ID: " << productId << endl;
        billFile << "Name: " << productName << endl;
        billFile << "Quantity: " << quantity << endl;
        billFile << "Price: $" << fixed << setprecision(2) << totalPrice1 << endl;
        billFile << "-------------------------" << endl;
    }
};

// Function to read bill from file and calculate total bill amount
float printBill(const string& billFilename) {
    ifstream billFile(billFilename);
    if (!billFile) {
        perror("Error: Unable to open bill file for reading.");
        return 0.0;
    }

    int productId, quantity;
    float totalprice ;
    string productname;
    float totalBillAmount = 0.0;

    std::cout << "Bill Details:" << endl;
    while (billFile >> productId >>productname>> quantity >> totalprice) {
        // Create a Bill object for the current item
        Bill item(productId, productname, totalprice, quantity);

        // Print details of the current item
        std::cout << "Product ID: " << item.productId << endl;
        std::cout << "Name: " << item.productName << endl;
std::cout << "Quantity: " << item.quantity << endl;
std::cout << "Price: $" << fixed << setprecision(2) << totalprice  << endl;
std::cout << "-------------------------" << endl;


        // Calculate the total price for the current item and add to total bill amount
        float totalPrice1 = totalprice;
        totalBillAmount += totalPrice1;
    }
    billFile.close();

    std::cout << "Total Bill Amount: $" << fixed << setprecision(2) << totalBillAmount << endl;

    return totalBillAmount;
}

//here
 class Clothes {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float cost_price;
    float selling_price;
    int items_sold;
    string brand_name;
    string gender;
    string size;
    string color;

    // Default constructor
    Clothes() = default;

    Clothes(int id, const string& name, int stock_qty, float cost, float price,
            int sold, const string& brand, const string& gen, const string& siz,
            const string& col)
        : product_id(id), product_name(name), stock_quantity(stock_qty),
          cost_price(cost), selling_price(price), items_sold(sold), brand_name(brand),
          gender(gen), size(siz), color(col) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand_name << endl;
        cout << "Size: " << size << ", Gender: " << gender << endl;
        cout << "Color: " << color << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
      float calculateProfit() const {
        return (selling_price - cost_price) * items_sold;
    }
};

void displayClothesFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
       // cerr << "Error: Unable to open file " << filename << endl;
       perror("hi");
        return;
    }

    Clothes item;
    cout << "Available Clothes:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.gender >> item.size >> item.color) {
        item.displayProductInfo();
    }
    inFile.close();
}

vector<Clothes> readClothesFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Clothes> clothesList;

    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return clothesList;
    }

    Clothes item;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.gender >> item.size >> item.color) {
        clothesList.push_back(item);
    }
    inFile.close();
    return clothesList;
}
void writeClothesToFile(const string& filename, const vector<Clothes>& clothesList) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& item : clothesList) {
        outFile << item.product_id << '\t'
                << item.product_name << '\t'
                << item.stock_quantity << '\t'
                << item.cost_price << '\t'
                << item.selling_price << '\t'
                << item.items_sold << '\t'
                << item.brand_name << '\t'
                << item.gender << '\t'
                << item.size << '\t'
                << item.color << endl;
    }

    outFile.close();
}
void updateStockQuantityByManagerClothes(const string& filename, int productId, int newQuantity) {
    // Read all clothes data from file
    vector<Clothes> clothesList = readClothesFromFile(filename);

    // Find the item with the given product ID
    bool found = false;
    for (auto& item : clothesList) {
        if (item.product_id == productId) {
            // Update the stock quantity
            item.stock_quantity = newQuantity;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Clothes with product ID " << productId << " not found." << endl;
        return;
    }

    // Write the updated clothes data back to file
    writeClothesToFile(filename, clothesList);
    cout << "Stock quantity for clothes with product ID " << productId << " updated to " << newQuantity << " successfully." << endl;
}

void addToBill1(const Clothes& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}
void displayProfitForClothes(const vector<Clothes>& clothesList) {
    cout << "Profit for Each Clothes Item:" << endl;
    cout << "------------------------------" << endl;
    for (const auto& clothes : clothesList) {
        float profit = clothes.calculateProfit();
        cout << "Product ID: " << clothes.product_id << endl;
        cout << "Name: " << clothes.product_name << endl;
        cout << "Profit: $" << fixed << setprecision(2) << profit << endl;
        cout << "------------------------------" << endl;
    }}
//foood
class Food {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float cost_price;
    float selling_price;
    int items_sold;
    string brand_name;
    string category;

    // Default constructor
    Food() = default;

    Food(int id, const string& name, int stock_qty, float cost, float price,
         int sold, const string& brand, const string& cat)
        : product_id(id), product_name(name), stock_quantity(stock_qty),
          cost_price(cost), selling_price(price), items_sold(sold), brand_name(brand),
          category(cat) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand_name << endl;
        cout << "Category: " << category << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
    float calculateProfit() const {
        return (selling_price - cost_price) * items_sold;
}};
void displayProfitForFood(const vector<Food>& foodList) {
    cout << "Profit for Each Food Item:" << endl;
    cout << "---------------------------" << endl;
    for (const auto& food : foodList) {
        float profit = food.calculateProfit();
        cout << "Product ID: " << food.product_id << endl;
        cout << "Name: " << food.product_name << endl;
        cout << "Profit: $" << fixed << setprecision(2) << profit << endl;
        cout << "---------------------------" << endl;
    }}

void displayFoodFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Food item;
    cout << "Available Food Items:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.category) {
        item.displayProductInfo();
    }
    inFile.close();
}
vector<Food> readFoodFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Food> foodList;

    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return foodList;
    }

    Food item;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.category) {
        foodList.push_back(item);
    }
    inFile.close();
    return foodList;
}

void writeFoodToFile(const string& filename, const vector<Food>& foodList) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& item : foodList) {
        outFile << item.product_id << '\t'
                << item.product_name << '\t'
                << item.stock_quantity << '\t'
                << item.cost_price << '\t'
                << item.selling_price << '\t'
                << item.items_sold << '\t'
                << item.brand_name << '\t'
                << item.category << endl;
    }

    outFile.close();
}

void updateStockQuantityForFood(const string& filename, int productId, int newQuantity) {
    // Read all food data from file
    vector<Food> foodList = readFoodFromFile(filename);

    // Find the item with the given product ID
    bool found = false;
    for (auto& item : foodList) {
        if (item.product_id == productId) {
            // Update the stock quantity
            item.stock_quantity = newQuantity;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Food with product ID " << productId << " not found." << endl;
        return;
    }

    // Write the updated food data back to file
    writeFoodToFile(filename, foodList);
    cout << "Stock quantity for food with product ID " << productId << " updated to " << newQuantity << " successfully." << endl;
}

void addToBill2(const Food& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

// gadegets
class Gadget {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float cost_price;
    float selling_price;
    int items_sold;
    string brand_name;

    // Default constructor
    Gadget() = default;

    Gadget(int id, const string& name, int stock_qty, float cost, float price,
           int sold, const string& brand)
        : product_id(id), product_name(name), stock_quantity(stock_qty),
          cost_price(cost), selling_price(price), items_sold(sold), brand_name(brand) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand_name << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
    float calculateProfit() const {
        return (selling_price - cost_price) * items_sold;
}};
void displayProfitForGadgets(const vector<Gadget>& gadgetList) {
    cout << "Profit for Each Gadget Item:" << endl;
    cout << "------------------------------" << endl;
    for (const auto& gadget : gadgetList) {
        float profit = gadget.calculateProfit();
        cout << "Product ID: " << gadget.product_id << endl;
        cout << "Name: " << gadget.product_name << endl;
        cout << "Profit: $" << fixed << setprecision(2) << profit << endl;
        cout << "------------------------------" << endl;
    }
}

void displayGadgetsFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Gadget item;
    cout << "Available Gadgets:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name) {
        item.displayProductInfo();
    }
    inFile.close();
}

vector<Gadget> readGadgetsFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Gadget> gadgetList;

    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return gadgetList;
    }

    Gadget item;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name) {
        gadgetList.push_back(item);
    }
    inFile.close();
    return gadgetList;
}

void writeGadgetsToFile(const string& filename, const vector<Gadget>& gadgetList) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& item : gadgetList) {
        outFile << item.product_id << '\t'
                << item.product_name << '\t'
                << item.stock_quantity << '\t'
                << item.cost_price << '\t'
                << item.selling_price << '\t'
                << item.items_sold << '\t'
                << item.brand_name << endl;
    }

    outFile.close();
}

void updateStockQuantityForGadget(const string& filename, int productId, int newQuantity) {
    // Read all gadget data from file
    vector<Gadget> gadgetList = readGadgetsFromFile(filename);

    // Find the item with the given product ID
    bool found = false;
    for (auto& item : gadgetList) {
        if (item.product_id == productId) {
            // Update the stock quantity
            item.stock_quantity = newQuantity;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Gadget with product ID " << productId << " not found." << endl;
        return;
    }

    // Write the updated gadget data back to file
    writeGadgetsToFile(filename, gadgetList);
    cout << "Stock quantity for gadget with product ID " << productId << " updated to " << newQuantity << " successfully." << endl;
}

void addToBill3(const Gadget& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

//healthcare
class Healthcare {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float cost_price;
    float selling_price;
    int items_sold;
    string brand_name;
    string category;

    // Default constructor
    Healthcare() = default;

    Healthcare(int id, const string& name, int stock_qty, float cost, float price,
                int sold, const string& brand, const string& cat)
        : product_id(id), product_name(name), stock_quantity(stock_qty),
          cost_price(cost), selling_price(price), items_sold(sold), brand_name(brand),
          category(cat) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand_name << endl;
        cout << "Category: " << category << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }float calculateProfit() const {
        return (selling_price - cost_price) * items_sold;
}};
void displayProfitForHealthcare(const vector<Healthcare>& healthcareList) {
    cout << "Profit for Each Healthcare Item:" << endl;
    cout << "---------------------------------" << endl;
    for (const auto& healthcare : healthcareList) {
        float profit = healthcare.calculateProfit();
        cout << "Product ID: " << healthcare.product_id << endl;
        cout << "Name: " << healthcare.product_name << endl;
        cout << "Profit: $" << fixed << setprecision(2) << profit << endl;
        cout << "---------------------------------" << endl;
    }
}

void displayHealthcareFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Healthcare item;
    cout << "Available Healthcare Products:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.category) {
        item.displayProductInfo();
    }
    inFile.close();
}


vector<Healthcare> readHealthcareFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Healthcare> healthcareList;

    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return healthcareList;
    }

    Healthcare item;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.category) {
        healthcareList.push_back(item);
    }
    inFile.close();
    return healthcareList;
}

void writeHealthcareToFile(const string& filename, const vector<Healthcare>& healthcareList) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& item : healthcareList) {
        outFile << item.product_id << '\t'
                << item.product_name << '\t'
                << item.stock_quantity << '\t'
                << item.cost_price << '\t'
                << item.selling_price << '\t'
                << item.items_sold << '\t'
                << item.brand_name << '\t'
                << item.category << endl;
    }

    outFile.close();
}

void updateStockQuantityForHealthcare(const string& filename, int productId, int newQuantity) {
    // Read all healthcare data from file
    vector<Healthcare> healthcareList = readHealthcareFromFile(filename);

    // Find the item with the given product ID
    bool found = false;
    for (auto& item : healthcareList) {
        if (item.product_id == productId) {
            // Update the stock quantity
            item.stock_quantity = newQuantity;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Healthcare product with product ID " << productId << " not found." << endl;
        return;
    }

    // Write the updated healthcare data back to file
    writeHealthcareToFile(filename, healthcareList);
    cout << "Stock quantity for healthcare product with product ID " << productId << " updated to " << newQuantity << " successfully." << endl;
}

void addToBill4(const Healthcare& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

// stationary
class Stationary {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float cost_price;
    float selling_price;
    int items_sold;
    string brand_name;

    // Default constructor
    Stationary() = default;

    Stationary(int id, const string& name, int stock_qty, float cost, float price,
                int sold, const string& brand)
        : product_id(id), product_name(name), stock_quantity(stock_qty),
          cost_price(cost), selling_price(price), items_sold(sold), brand_name(brand) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand_name << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }float calculateProfit() const {
        return (selling_price - cost_price) * items_sold;
}};
void displayProfitForStationary(const vector<Stationary>& stationaryList) {
    cout << "Profit for Each Stationary Item:" << endl;
    cout << "----------------------------------" << endl;
    for (const auto& stationary : stationaryList) {
        float profit = stationary.calculateProfit();
        cout << "Product ID: " << stationary.product_id << endl;
        cout << "Name: " << stationary.product_name << endl;
        cout << "Profit: $" << fixed << setprecision(2) << profit << endl;
        cout << "----------------------------------" << endl;
    }
}

void displayStationaryFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Stationary item;
    cout << "Available Stationary Products:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name) {
        item.displayProductInfo();
    }
    inFile.close();
}

vector<Stationary> readStationaryFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Stationary> stationaryList;

    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return stationaryList;
    }

    Stationary item;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name) {
        stationaryList.push_back(item);
    }
    inFile.close();
    return stationaryList;
}

void writeStationaryToFile(const string& filename, const vector<Stationary>& stationaryList) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& item : stationaryList) {
        outFile << item.product_id << '\t'
                << item.product_name << '\t'
                << item.stock_quantity << '\t'
                << item.cost_price << '\t'
                << item.selling_price << '\t'
                << item.items_sold << '\t'
                << item.brand_name << endl;
    }

    outFile.close();
}

void updateStockQuantityForStationary(const string& filename, int productId, int newQuantity) {
    // Read all stationary data from file
    vector<Stationary> stationaryList = readStationaryFromFile(filename);

    // Find the item with the given product ID
    bool found = false;
    for (auto& item : stationaryList) {
        if (item.product_id == productId) {
            // Update the stock quantity
            item.stock_quantity = newQuantity;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Stationary product with product ID " << productId << " not found." << endl;
        return;
    }

    // Write the updated stationary data back to file
    writeStationaryToFile(filename, stationaryList);
    cout << "Stock quantity for stationary product with product ID " << productId << " updated to " << newQuantity << " successfully." << endl;
}

void addToBill5(const Stationary& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}
//here3


void updateStockQuantity1(const string& clothesFilename, const string& billFilename) {
    ifstream clothesFile(clothesFilename);
    ofstream tempFile("temp_clothes.txt");

    if (!clothesFile || !tempFile) {
        cerr << "Error: Unable to open file for reading or writing." << endl;
        return;
    }

    vector<Clothes> clothesList;
    Clothes item;
    // Read clothes data into a vector
    while (clothesFile >> item.product_id >> item.product_name >> item.stock_quantity
                        >> item.cost_price >> item.selling_price >> item.items_sold
                        >> item.brand_name >> item.gender >> item.size >> item.color) {
        clothesList.push_back(item);
    }

    ifstream billFile(billFilename);
    if (!billFile) {
        perror("Error: Unable to open bill file for reading.");
        return;
    }

    int productId, quantity;
    float totalPrice;
    string pname;
    while (billFile >> productId >>pname>> quantity >> totalPrice) {
        bool found = false;
        for (size_t i = 0; i < clothesList.size(); ++i) {
            if (clothesList[i].product_id == productId) {
                // Update stock quantity
                clothesList[i].stock_quantity -= quantity;
                // Update items_sold
                clothesList[i].items_sold += quantity;
                found = true;
                break;
            }
        }
        if (!found) {
            cerr << "Product with ID " << productId << " not found in the clothes file." << endl;
        }
    }

    // Write the updated clothes data to the temporary file
    for (size_t i = 0; i < clothesList.size(); ++i) {
        tempFile << clothesList[i].product_id << " " << clothesList[i].product_name << " "
                 << clothesList[i].stock_quantity << " " << clothesList[i].cost_price << " "
                 << clothesList[i].selling_price << " " << clothesList[i].items_sold << " "
                 << clothesList[i].brand_name << " " << clothesList[i].gender << " "
                 << clothesList[i].size << " " << clothesList[i].color << endl;
    }

    // Close the files
    clothesFile.close();
    billFile.close();
    tempFile.close();

    // Remove the original clothes file
    if (remove(clothesFilename.c_str()) != 0) {
        perror("Error removing existing file");
    }

    // Rename the temporary file to overwrite the original clothes file
    if (rename("temp_clothes.txt", clothesFilename.c_str()) != 0) {
        perror("Error renaming file");
    } else {
        std::cout << "Stock quantities and items sold updated successfully." << endl;
    }
}

// update function for food

void updateStockQuantity2(const string& foodFilename, const string& billFilename) {
    ifstream foodFile(foodFilename);
    ofstream tempFile("temp_food.txt");

    if (!foodFile || !tempFile) {
        cerr << "Error: Unable to open file for reading or writing." << endl;
        return;
    }

    vector<Food> foodList;
    Food item;
    // Read food data into a vector
    while (foodFile >> item.product_id >> item.product_name >> item.stock_quantity
                     >> item.cost_price >> item.selling_price >> item.items_sold
                     >> item.brand_name >> item.category) {
        foodList.push_back(item);
    }

    ifstream billFile(billFilename);
    if (!billFile) {
        perror("Error: Unable to open bill file for reading.");
        return;
    }

    int productId, quantity;
    float totalPrice;
    string pname;
    while (billFile >> productId >> pname>>quantity >> totalPrice) {
        bool found = false;
        for (size_t i = 0; i < foodList.size(); ++i) {
            if (foodList[i].product_id == productId) {
                // Update stock quantity
                foodList[i].stock_quantity -= quantity;
                // Update items_sold
                foodList[i].items_sold += quantity;
                found = true;
                break;
            }
        }
        if (!found) {
            cerr << "Product with ID " << productId << " not found in the food file." << endl;
        }
    }

    // Write the updated food data to the temporary file
    for (size_t i = 0; i < foodList.size(); ++i) {
        tempFile << foodList[i].product_id << " " << foodList[i].product_name << " "
                 << foodList[i].stock_quantity << " " << foodList[i].cost_price << " "
                 << foodList[i].selling_price << " " << foodList[i].items_sold << " "
                 << foodList[i].brand_name << " " << foodList[i].category << endl;
    }

    // Close the files
    foodFile.close();
    billFile.close();
    tempFile.close();

    // Remove the original food file
    if (remove(foodFilename.c_str()) != 0) {
        perror("Error removing existing file");
    }

    // Rename the temporary file to overwrite the original food file
    if (rename("temp_food.txt", foodFilename.c_str()) != 0) {
        perror("Error renaming file");
    } else {
        std::cout << "Stock quantities and items sold updated successfully." << endl;
    }
}

// update fucntion for gadgets
void updateStockQuantity3(const string& gadgetsFilename, const string& billFilename) {
    ifstream gadgetsFile(gadgetsFilename);
    ofstream tempFile("temp_gadgets.txt");

    if (!gadgetsFile || !tempFile) {
        cerr << "Error: Unable to open file for reading or writing." << endl;
        return;
    }

    vector<Gadget> gadgetsList;
    Gadget item;
    // Read gadgets data into a vector
    while (gadgetsFile >> item.product_id >> item.product_name >> item.stock_quantity
                       >> item.cost_price >> item.selling_price >> item.items_sold
                       >> item.brand_name) {
        gadgetsList.push_back(item);
    }

    ifstream billFile(billFilename);
    if (!billFile) {
        perror("Error: Unable to open bill file for reading.");
        return;
    }

    int productId, quantity;
    float totalPrice;string pname;
    while (billFile >> productId >>pname>> quantity >> totalPrice) {
        bool found = false;
        for (size_t i = 0; i < gadgetsList.size(); ++i) {
            if (gadgetsList[i].product_id == productId) {
                // Update stock quantity
                gadgetsList[i].stock_quantity -= quantity;
                // Update items_sold
                gadgetsList[i].items_sold += quantity;
                found = true;
                break;
            }
        }
        if (!found) {
            cerr << "Product with ID " << productId << " not found in the gadgets file." << endl;
        }
    }

    // Write the updated gadgets data to the temporary file
    for (size_t i = 0; i < gadgetsList.size(); ++i) {
        tempFile << gadgetsList[i].product_id << " " << gadgetsList[i].product_name << " "
                 << gadgetsList[i].stock_quantity << " " << gadgetsList[i].cost_price << " "
                 << gadgetsList[i].selling_price << " " << gadgetsList[i].items_sold << " "
                 << gadgetsList[i].brand_name << endl;
    }

    // Close the files
    gadgetsFile.close();
    billFile.close();
    tempFile.close();

    // Remove the original gadgets file
    if (remove(gadgetsFilename.c_str()) != 0) {
        perror("Error removing existing file");
    }

    // Rename the temporary file to overwrite the original gadgets file
    if (rename("temp_gadgets.txt", gadgetsFilename.c_str()) != 0) {
        perror("Error renaming file");
    } else {
        std::cout << "Stock quantities and items sold updated successfully." << endl;
    }
}

// update function for healthcare
void updateStockQuantity4(const string& healthcareFilename, const string& billFilename) {
    ifstream healthcareFile(healthcareFilename);
    ofstream tempFile("temp_healthcare.txt");

    if (!healthcareFile || !tempFile) {
        cerr << "Error: Unable to open file for reading or writing." << endl;
        return;
    }

    vector<Healthcare> healthcareList;
    Healthcare item;
    // Read healthcare data into a vector
    while (healthcareFile >> item.product_id >> item.product_name >> item.stock_quantity
                            >> item.cost_price >> item.selling_price >> item.items_sold
                            >> item.brand_name >> item.category) {
        healthcareList.push_back(item);
    }

    ifstream billFile(billFilename);
    if (!billFile) {
        perror("Error: Unable to open bill file for reading.");
        return;
    }

    int productId, quantity;
    float totalPrice;string pname;
    while (billFile >> productId >>pname>> quantity >> totalPrice) {
        bool found = false;
        for (size_t i = 0; i < healthcareList.size(); ++i) {
            if (healthcareList[i].product_id == productId) {
                // Update stock quantity
                healthcareList[i].stock_quantity -= quantity;
                // Update items_sold
                healthcareList[i].items_sold += quantity;
                found = true;
                break;
            }
        }
        if (!found) {
            cerr << "Product with ID " << productId << " not found in the healthcare file." << endl;
        }
    }

    // Write the updated healthcare data to the temporary file
    for (size_t i = 0; i < healthcareList.size(); ++i) {
        tempFile << healthcareList[i].product_id << " " << healthcareList[i].product_name << " "
                 << healthcareList[i].stock_quantity << " " << healthcareList[i].cost_price << " "
                 << healthcareList[i].selling_price << " " << healthcareList[i].items_sold << " "
                 << healthcareList[i].brand_name << " " << healthcareList[i].category << endl;
    }

    // Close the files
    healthcareFile.close();
    billFile.close();
    tempFile.close();

    // Remove the original healthcare file
    if (remove(healthcareFilename.c_str()) != 0) {
        perror("Error removing existing file");
    }

    // Rename the temporary file to overwrite the original healthcare file
    if (rename("temp_healthcare.txt", healthcareFilename.c_str()) != 0) {
        perror("Error renaming file");
    } else {
        std::cout << "Stock quantities and items sold updated successfully." << endl;
    }
}

// update function for stationary
void updateStockQuantity5(const string& stationaryFilename, const string& billFilename) {
    ifstream stationaryFile(stationaryFilename);
    ofstream tempFile("temp_stationary.txt");

    if (!stationaryFile || !tempFile) {
        cerr << "Error: Unable to open file for reading or writing." << endl;
        return;
    }

    vector<Stationary> stationaryList;
    Stationary item;
    // Read stationary data into a vector
    while (stationaryFile >> item.product_id >> item.product_name >> item.stock_quantity
                            >> item.cost_price >> item.selling_price >> item.items_sold
                            >> item.brand_name) {
        stationaryList.push_back(item);
    }

    ifstream billFile(billFilename);
    if (!billFile) {
        perror("Error: Unable to open bill file for reading.");
        return;
    }

    int productId, quantity;
    float totalPrice;string pname;

    while (billFile >> productId >>pname>> quantity >> totalPrice) {
        bool found = false;
        for (size_t i = 0; i < stationaryList.size(); ++i) {
            if (stationaryList[i].product_id == productId) {
                // Update stock quantity
                stationaryList[i].stock_quantity -= quantity;
                // Update items_sold
                stationaryList[i].items_sold += quantity;
                found = true;
                break;
            }
        }
        if (!found) {
            cerr << "Product with ID " << productId << " not found in the stationary file." << endl;
        }
    }

    // Write the updated stationary data to the temporary file
    for (size_t i = 0; i < stationaryList.size(); ++i) {
        tempFile << stationaryList[i].product_id << " " << stationaryList[i].product_name << " "
                 << stationaryList[i].stock_quantity << " " << stationaryList[i].cost_price << " "
                 << stationaryList[i].selling_price << " " << stationaryList[i].items_sold << " "
                 << stationaryList[i].brand_name << endl;
    }

    // Close the files
    stationaryFile.close();
    billFile.close();
    tempFile.close();

    // Remove the original stationary file
    if (remove(stationaryFilename.c_str()) != 0) {
        perror("Error removing existing file");
    }

    // Rename the temporary file to overwrite the original stationary file
    if (rename("temp_stationary.txt", stationaryFilename.c_str()) != 0) {
        perror("Error renaming file");
    } else {
        std::cout << "Stock quantities and items sold updated successfully." << endl;
    }
}

void shop() {

    float totalbill1=0,totalbill2=0,totalbill3=0,totalbill4=0,totalbill5=0;
    string category;
    float totalBillAmount = 0.0;

    // Loop until the customer finishes shopping
    while (true) {
        cout << "Choose a category to shop from (clothes/food/gadgets/healthcare/stationary): ";
        cin >> category;

        if (category == "clothes") {
    
    cout << "Welcome to Clothes section. Here are the available products:" << endl;
    displayClothesFromFile("clothes.txt");

    
    ofstream billFile("clothes_bill.txt", ios::app); // Append mode to add items to bill
    ifstream inFile("clothes.txt");
    char choice;
    do {
        
        int productId, quantity;
        cout << "Enter the Product ID you want to purchase: ";
        cin >> productId;
        cout << "Enter the quantity: ";
        cin >> quantity;

        Clothes item1;
        bool found = false;
        while (inFile >> item1.product_id >> item1.product_name >> item1.stock_quantity>>item1.cost_price>>item1.selling_price>>
                    item1.items_sold>> item1.brand_name >> item1.gender >> item1.size >> item1.color  ) {
            if (item1.product_id == productId && item1.stock_quantity >= quantity) {
                addToBill1(item1, quantity, billFile);

                found = true;
                // Update stock quantity in the clothes file (if needed)
                // This would involve rewriting the entire file with updated quantities
                // or using a temporary file to update quantities
                break;
            }
        }

        if (!found)
            cout << "Product not found or insufficient stock." << endl;

        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    inFile.close();
    billFile.close();

     totalbill1 = printBill("clothes_bill.txt");
}

else if (category == "food") {

    cout << "Welcome to Food section. Here are the available products:" << endl;
    displayFoodFromFile("food.txt");

    
    ofstream billFile("food_bill.txt", ios::app); // Append mode to add items to bill
ifstream inFile("food.txt");
    char choice;
    do {
        
        int productId, quantity;
        cout << "Enter the Product ID you want to purchase: ";
        cin >> productId;
        cout << "Enter the quantity: ";
        cin >> quantity;

        Food item;
        bool found = false;
        while (inFile >> item.product_id >> item.product_name >> item.stock_quantity >> item.cost_price >> item.selling_price
                    >> item.items_sold>>item.brand_name >> item.category) {
            if (item.product_id == productId && item.stock_quantity >= quantity) {
                addToBill2(item, quantity, billFile);

                found = true;
                break;
            }
        }

        if (!found)
            cout << "Product not found or insufficient stock." << endl;

        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    inFile.close();
    billFile.close();

     totalbill2 = printBill("food_bill.txt");
}

 else if (category == "gadgets") {

    cout << "Welcome to Gadgets section. Here are the available products:" << endl;
    displayGadgetsFromFile("gadgets.txt");

    
    ofstream billFile("gadgets_bill.txt", ios::app); // Append mode to add items to bill
ifstream inFile("gadgets.txt");
    char choice;
    do {
        
        int productId, quantity;
        cout << "Enter the Product ID you want to purchase: ";
        cin >> productId;
        cout << "Enter the quantity: ";
        cin >> quantity;

        Gadget item;
        bool found = false;
        while (inFile >> item.product_id >> item.product_name >> item.stock_quantity >> item.cost_price >> item.selling_price
                    >> item.items_sold >> item.brand_name) {
            if (item.product_id == productId && item.stock_quantity >= quantity) {
                addToBill3(item, quantity, billFile);

                found = true;
                // Update stock quantity in the gadgets file (if needed)
                // This would involve rewriting the entire file with updated quantities
                // or using a temporary file to update quantities
                break;
            }
        }

        if (!found)
            cout << "Product not found or insufficient stock." << endl;

        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    inFile.close();
    billFile.close();

     totalbill3= printBill("gadgets_bill.txt");
}

else if (category == "healthcare") {

cout << "Welcome to Healthcare section. Here are the available products:" << endl;
    displayHealthcareFromFile("healthcare.txt");

    
    ofstream billFile("healthcare_bill.txt", ios::app); // Append mode to add items to bill
ifstream inFile("healthcare.txt");
    char choice;
    do {
        
        int productId, quantity;
        cout << "Enter the Product ID you want to purchase: ";
        cin >> productId;
        cout << "Enter the quantity: ";
        cin >> quantity;

        Healthcare item;
        bool found = false;
        while (inFile >> item.product_id >> item.product_name >> item.stock_quantity >> item.cost_price >> item.selling_price
                    >> item.items_sold >> item.brand_name >> item.category) {
            if (item.product_id == productId && item.stock_quantity >= quantity) {
                addToBill4(item, quantity, billFile);

                found = true;
                // Update stock quantity in the healthcare file (if needed)
                // This would involve rewriting the entire file with updated quantities
                // or using a temporary file to update quantities
                break;
            }
        }

        if (!found)
            cout << "Product not found or insufficient stock." << endl;

        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    inFile.close();
    billFile.close();

     totalbill4 = printBill("healthcare_bill.txt");
}

else if (category == "stationary") {
 cout << "Welcome to Stationary section. Here are the available products:" << endl;
    displayStationaryFromFile("stationary.txt");

    
    ofstream billFile("stationary_bill.txt", ios::app); // Append mode to add items to bill
ifstream inFile("stationary.txt");
    char choice;
    do {
        
        int productId, quantity;
        cout << "Enter the Product ID you want to purchase: ";
        cin >> productId;
        cout << "Enter the quantity: ";
        cin >> quantity;

        Stationary item;
        bool found = false;
        while (inFile >> item.product_id >> item.product_name >> item.stock_quantity >> item.cost_price >> item.selling_price
                    >> item.items_sold >> item.brand_name) {
            if (item.product_id == productId && item.stock_quantity >= quantity) {
                addToBill5(item, quantity, billFile);

                found = true;
                // Update stock quantity in the stationary file (if needed)
                // This would involve rewriting the entire file with updated quantities
                // or using a temporary file to update quantities
                break;
            }
        }

        if (!found)
            cout << "Product not found or insufficient stock." << endl;

        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    inFile.close();
    billFile.close();

     totalbill5 = printBill("stationary_bill.txt");
}

 else {
            cout << "Invalid category! Please choose again." << endl;
            continue;
        }

        // Ask if the customer wants to shop more
        char choice;
        cout << "Do you want to shop more? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

  updateStockQuantity1("clothes.txt", "clothes_bill.txt");
  updateStockQuantity2("food.txt", "food_bill.txt");
  updateStockQuantity3("healthcare.txt", "healthcare_bill.txt");
  updateStockQuantity4("gadgets.txt", "gadgets_bill.txt");
  updateStockQuantity5("stationary.txt", "stationary_bill.txt");  


cout << "Sum of Total Bill: $" << fixed << setprecision(2) << totalbill1+ totalbill2 + totalbill3 + totalbill4 + totalbill5<< endl;



}

//tohere
void login_customer()
{

    int signInChoice;
    bool signInValid = false;

    while (!signInValid) {
        green();
        cout<<endl;
        cout << "\t\t\t\t\t -------------------------------------------------------- \n";
        cout << "\t\t\t\t\t|    Press 1 to go to Customer Sign in                   |\n";
        cout << "\t\t\t\t\t|    Press 2 to go to Customer Sign up (New Customer)    |\n";
        cout << "\t\t\t\t\t|    Press 3 to go back                                  |\n";
        cout << "\t\t\t\t\t -------------------------------------------------------- \n\n";
        cout << "\t\t\t\t\tChoice (1/2/3):";
        reset();

        cin >> signInChoice;

        switch (signInChoice) {
            case 1:
                signin();
                signInValid = true;
                break;
            case 2:
                signup();
                signInValid = true;
                signin();
                break;
            case 3:
            displaySecondpage();
            break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a number from given choice(1/2):\n";
                break;
        }
    }
}

class customer{
public:
     string cust_name;
     string cust_mail;
     string cust_passwd;
     string cust_phone_no;
     float discount;
     float amount_spent;
    /* int star_customer;1 if yes 0 if no */
    customer(){};
     void check_star_cust(){
        if(amount_spent>50000.0){
            discount=10;
        }
     }
      customer(string name, string mail, string passwd,  string phone_no, float spent,int dis) :
        cust_name(name),
        cust_mail(mail),
        cust_passwd(passwd),
        cust_phone_no(phone_no),
        discount(dis),
        amount_spent(spent)
    {
        check_star_cust(); // Check if the customer qualifies for a star customer discount
    }
};

class staff{
public:
    string staff_id;
    string staff_name;
    string gender;
    string staff_pswd;
    float salary;
    string staff_phone_no;
    string staff_mail;
    string staff_type;
    staff(){};


staff(string id, const std::string& name, const std::string& gen, float sal, const std::string& phone_no, const std::string& mail, const std::string& type) :
        staff_id(id),
        staff_name(name),
        gender(gen),
        salary(sal),
        staff_phone_no(phone_no),
        staff_mail(mail),
        staff_type(type)
    {}
};

void signup_staff(); //pre

int MANAGER(staff& s)
{
    cout<<"hi "<<s.staff_name<<endl<<"How can i help you today?";
    cout<<endl<<"press 1 for employee details";
    cout<<endl<<"press 2 to add new employee";
    cout<<endl<<"press 3 to delete an employee";
    cout<<endl<<"press 4 update product quantity";
    cout<<endl<<"press 5 to see profit";
    cout<<endl<<"press 6 to go back";

    int choice;
    cout<<endl<<"choice";
    cin>>choice;
    if(choice==1)
    {
    string id, first_name, email, phone_no, password, last_name, type_staff, gender;
    float salary;
    ifstream myfile("staff_file.txt");
     if (!myfile.is_open()) {
        perror("file");

    }


    while (myfile >> id >> first_name >> last_name >> email >> phone_no >> password >> type_staff >> salary >> gender) {

        string full_name = first_name + " " + last_name;


        cout << "Staff name: " << full_name << endl;
        cout << "Staff ID: " << id << endl;
        cout << "Email: " << email << endl;
        cout << "Phone number: " << phone_no << endl;
        cout << "Password: " << password << endl;
        cout << "Staff type: " << type_staff << endl;
        cout << "Salary: " << salary << endl;
        cout << "Gender: " << gender << endl;
        cout << endl;
    }

    myfile.close();
    }

    else if(choice==2)
    {
        signup_staff();
    }
    else if(choice==3)
    {
        ifstream myfile("staff_file.txt");
    vector<staff> staffList;

    if (!myfile.is_open()) {
        cout << "Error: Unable to open file " << endl;

    }

    staff s;
    string first_name,last_name;
    while (myfile >> s.staff_id >> first_name >> last_name >> s.staff_mail >> s.staff_phone_no >> s.staff_pswd >> s.staff_type >> s.salary >> s.gender) {
        s.staff_name=first_name+" "+last_name;
        staffList.push_back(s);
    }

    myfile.close();
    bool found = false;
    cout<<"enter id";
    string staffId;
    cin>>staffId;
    for (auto it = staffList.begin(); it != staffList.end(); ++it) {
        if (it->staff_id==staffId) {
            // Remove the staff member from the list
            staffList.erase(it);
            found = true;
            break;
        }
    }if (!found) {
        cout << "Staff with ID " << staffId << " not found." << endl;

    }
    ofstream myFile("staff_file.txt");

    if (!myFile.is_open()) {
        cout << "Error: Unable to open file  for writing." << endl;
        if(found)
        {
            cout<<"deleted successfully";
        }

    }

    for (const auto& s : staffList) {
        myFile<< s.staff_id << " " << s.staff_name<<  " " << s.staff_mail << " " << s.staff_phone_no << " " << s.staff_pswd << " " << s.staff_type << " " << s.salary << " " << s.gender << endl;
    }

    myFile.close();
}
    else if(choice==6)
    {
        displaySecondpage();
    }
    else if(choice==4)
    {
   cout<<"You are in  update function";
   cout<<"1-clothes/n2-food/n3-gadgets/n4-helthcare/n5-stationary";
   int c;
   cin>>c;
   if(c==1){
    displayClothesFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\clothes.txt");
    cout<<"ENter product id you want to update";
    int id,val;
    cin>>id;
    cout<<"enter no of items present in inventory";
    cin>>val;
     updateStockQuantityByManagerClothes("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\clothes.txt", id, val);
    }
    else if(c==2)
    {
        displayFoodFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\food.txt");
    cout<<"ENter product id you want to update";
    int id,val;
    cin>>id;
    cout<<"enter no of items present in inventory";
    cin>>val;
     updateStockQuantityForFood("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\food.txt", id, val);
    }
    else if(c==3)
    {
        displayGadgetsFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\gadgets.txt");
    cout<<"ENter product id you want to update";
    int id,val;
    cin>>id;
    cout<<"enter no of items present in inventory";
    cin>>val;
     updateStockQuantityForGadget("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\gadgets.txt", id, val);
    }
    else if(c==4)
    {
        displayHealthcareFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\healthcare.txt");
    cout<<"ENter product id you want to update";
    int id,val;
    cin>>id;
    cout<<"enter no of items present in inventory";
    cin>>val;
     updateStockQuantityForHealthcare("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\healthcare.txt", id, val);
    }
    else if(c==5)
    {
        displayStationaryFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\stationary.txt");
    cout<<"ENter product id you want to update";
    int id,val;
    cin>>id;
    cout<<"enter no of items present in inventory";
    cin>>val;
     updateStockQuantityForStationary("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\stationary.txt", id, val);
    }
    else{
        cout<<"wrong choice";
    }
    }
    else if(choice==5)
    {
        cout<<"1-clothes/n2-food/n3-gadgets/n4-helthcare/n5-stationary";
   int c;
   cin>>c;
   if(c==1){
   vector<Clothes> clothesList = readClothesFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\clothes.txt");

    
    displayProfitForClothes(clothesList);
    }
    else if(c==2)
    {
       vector<Food> foodList = readFoodFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\food.txt");

    // Display profit for each food item
    displayProfitForFood(foodList);
    }
    else if(c==3)
    {
       vector<Gadget> gadgetList = readGadgetsFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\gadgets.txt");

    displayProfitForGadgets(gadgetList);
    }
    else if(c==4)
    {
        vector<Healthcare> healthcareList = readHealthcareFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\healthcare.txt");

    displayProfitForHealthcare(healthcareList);
    }
    else if(c==5)
    {
       vector<Stationary> stationaryList = readStationaryFromFile("C:\\Users\\atuls\\OneDrive\\Desktop\\cpp\\project\\Super-Mart-Management-System\\stationary.txt");

    
    displayProfitForStationary(stationaryList);
    }
    else{
        cout<<"wrong choice";
    }}
    else{cout<<"wrong choice";}
return 0;
}

void signin_staff() {

    string staff_id, staff_pass;
    cout << "Enter your Staff ID to SignIn:";
    yellow();
    cin >> staff_id;
    reset();
    cout << "Enter your password to SignIn:";
    yellow();
    cin >> staff_pass;
    reset();

    ifstream myfile("staff_file.txt");
    if (!myfile) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string id, first_name, email, phone_no, password, last_name, type_staff, gender;
    float salary;
    bool found = false;

    while (myfile >> id >> first_name >> last_name >> email >> phone_no >> password >> type_staff >> salary >> gender) {
        if (staff_id == id && staff_pass == password) {
            first_name = first_name + " " + last_name;
    
            cout << "Staff name is: ";
            green();
            cout<<  first_name << endl;
            reset();
            cout << "Staff ID is: ";
            green();
            cout<< id << endl;
            reset();
            cout << "Staff Designation is: ";
            green();
            cout << type_staff << endl;
            reset();
            found = true;
            staff s(id,first_name,gender,salary,phone_no, email,type_staff);
            MANAGER(s);
            break;
        }
    }
    myfile.close();

    if (!found) {
        cout << "Invalid credentials." << endl;
    }
}
void signup_staff() //newuser
{

    staff s;
    cout<<"Enter employee name: ";
    yellow();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,s.staff_name);
    reset();
    cout<<"Enter employee ID:";
    yellow();
    cin>>s.staff_id;
    reset();
    cout<<"Enter employee Mail-ID: ";
    yellow();
    cin>>s.staff_mail;
    reset();
    cout<<"Enter employee Phone-num:  ";
    yellow();
    cin>>s.staff_phone_no;
    reset();
    cout<<"Enter employee Password:";
    yellow();
    cin>>s.staff_pswd;
    reset();
    cout<<"Enter employee salary:";
    yellow();
    cin>>s.salary;
    reset();
    cout<<"Enter employee type:";
    yellow();
    cin>>s.staff_type;
    reset();
    cout<<"Enter employee gender:";
    yellow();
    cin>>s.gender;
    reset();
    ofstream myfile("staff_file.txt",ios::app);

          myfile<<s.staff_id<<" "<<s.staff_name<<" "<<s.staff_mail<<" "<<s.staff_phone_no<<" "<<s.staff_pswd<<" "<<s.staff_type<<" "<<s.salary<<" "<<s.gender<<"\n";
          myfile.close();
}
void signin()
{
    system("cls");
    cout<<endl;
    string pnum,pswd; //customer phone number
    cout<<"Enter your ID(Phone number): to SignIn:";
    yellow();
    cin>>pnum;
    reset();
    cout<<"Enter your password: to SignIn:";
    yellow();
    cin>>pswd;
    reset();
    cin.ignore();
    int i=0;
ifstream myfile("cust_file.txt");

        string first_name, email, phone_no, password ,last_name;
        float amt_spent;
        int discount;
        while (myfile >> first_name >>last_name>>email >>phone_no >> password >> amt_spent >> discount) {
            if ((phone_no == pnum)&&(password==pswd)) {
                first_name=first_name+" "+last_name;
                green();
                cout<<"Welcome "<<first_name<<"to the supermart."<<endl<<"What do you want to buy today?";
                reset();
                customer C(first_name, email, phone_no , password , amt_spent,discount);
                i=1;
                shop();
                break;
            }

        }
        if(i==0)
        {cout<<"Invalid credentials."<<endl;
            if((phone_no == pnum)&&(password!=pswd)){
            cout<<"Please enter the correct password."<<endl;}
            signin_cust();
        
        }




}


void signup() //newuser
{
    system("cls");
    cout<<endl;
    customer c;
    cout<<"Hi!Welcome to AGRAMART :)\nEnter your Full name: ";
    yellow();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,c.cust_name);
    reset();
    cout<<"Enter your Mail-ID: ";
    yellow();
    cin>>c.cust_mail;
    reset();
    cout<<"Enter Phone-num:  ";
    yellow();
    cin>>c.cust_phone_no;
    reset();
    cout<<"Enter Password:";
    yellow();
    cin>>c.cust_passwd;
    reset();
    c.amount_spent=0;
    c.discount=0;
    ofstream myfile("cust_file.txt",ios::app);

          myfile<<c.cust_name<<" "<<c.cust_mail<<" "<<c.cust_phone_no<<" "<<c.cust_passwd<<" "<<c.amount_spent<<" "<<c.discount<<"\n";
          myfile.close();
}

void signin_cust() {
    char choice;
    cout << "Incorrect phone number or password. Try again? (Y/N): ";
    cin >> choice;

    switch (choice) {
        case 'Y':
        case 'y':
            signin();
            break;
        case 'N':
        case 'n':
            cout << "Returning to main menu...\n";
            displaySecondpage();
            break;
        default:
            cout << "Invalid choice. Returning to main menu...\n";
            displaySecondpage();
            break;
    }
}

void displayFrontPage() {
    system("cls"); // Clear the console screen
    yellow();
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout << "   \t\t\t\t\t --------------------------------------------- \n";
    cout << "   \t\t\t\t\t|                                             | \n";
    cout << "   \t\t\t\t\t|   ---------------------------------------   |\n";
    cout << "   \t\t\t\t\t|  |                                       |  |\n";
    cout << "   \t\t\t\t\t|  |              WELCOME TO               |  |\n";
    cout << "   \t\t\t\t\t|  |               AGRAMART                |  |\n";
    cout << "   \t\t\t\t\t|  |                                       |  |\n";
    cout << "   \t\t\t\t\t|   ---------------------------------------   |\n";
    cout << "   \t\t\t\t\t|                                             |\n";
    cout << "   \t\t\t\t\t --------------------------------------------- \n";
    cout<<endl;
    cout << "   \t\t\t\t\tPress any key to proceed to login: ";
    reset();
}

void displayLoginPage() {
    system("cls"); // Clear the console screen
}
void displaySecondpage(){
    system("cls");

    char loginChoice;
    bool validChoice = false;
while (!validChoice) {
        cout<<endl;
        green();
        cout << "\t\t\t\t\t -------------------------------------------------------- \n";
        cout << "\t\t\t\t\t|                                                        |\n";
        cout << "\t\t\t\t\t|             Enter c for Customer Login page            |\n";
        cout << "\t\t\t\t\t|             Enter s for Staff Login Page)              |\n";
        cout << "\t\t\t\t\t|                                                        |\n";
        cout << "\t\t\t\t\t -------------------------------------------------------- \n\n";
        cout << "\t\t\t\t\tChoice (c/s):";
        reset();
        cin >> loginChoice;
        // Check if the input is not alphabetic
        if (!isalpha(loginChoice)) {
            // Clear the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a letter from given choice(c/s):\n";
        } else {
            switch (loginChoice) {
                case 'c':
                case 'C':
                    validChoice = true;
                    displayLoginPage();
                    login_customer();
                    break;
                case 's':
                case 'S':
                    validChoice = true;
                    displayLoginPage();
                    signin_staff();
                    break;
                default:
                    cout << "Enter a letter from given choice(c/s):\n";
                    break;
            }
        }
    }
 }
int main() {
   /* char choice;
    displayFrontPage();
    _getch(); // Wait for a key press
    displayLoginPage();
    displaySecondpage();

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;*/
    shop();
   
}
