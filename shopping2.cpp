#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class Clothes {
public:
    int product_id;
    string product_name;
    float selling_price;
    string brand;
    string gender;
    string size;
    string color;
    int stock_quantity;

    Clothes() : product_id(0), selling_price(0.0), stock_quantity(0) {}

    Clothes(int id, const string& name, float price, const string& brand_name,
            const string& gen, const string& siz, const string& col, int quantity)
        : product_id(id), product_name(name), selling_price(price), brand(brand_name),
          gender(gen), size(siz), color(col), stock_quantity(quantity) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand << endl;
        cout << "Size: " << size << ", Gender: " << gender << endl;
        cout << "Color: " << color << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
};

class Gadgets {
public:
    int product_id;
    string product_name;
    int stock_quantity;
    float selling_price;
    float cost_price;
    int items_sold;
    string brand;

    Gadgets() : product_id(0), selling_price(0.0), stock_quantity(0), cost_price(0.0), items_sold(0) {}

    Gadgets(int id, const string& name, int quantity, float sell_price, float cost, int sold, const string& brand_name)
        : product_id(id), product_name(name), stock_quantity(quantity), selling_price(sell_price),
          cost_price(cost), items_sold(sold), brand(brand_name) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        cout << "Brand: " << brand << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
};

void displayProductsFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    if (filename == "clothes.txt") {
        Clothes item;
        cout << "Available Clothes:" << endl;
        while (inFile >> item.product_id >> item.product_name >> item.selling_price
                     >> item.brand >> item.gender >> item.size >> item.color >> item.stock_quantity) {
            item.displayProductInfo();
        }
    } else if (filename == "gadgets.txt") {
        Gadgets item;
        cout << "Available Gadgets:" << endl;
        while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                     >> item.selling_price >> item.cost_price >> item.items_sold >> item.brand) {
            item.displayProductInfo();
        }
    }

    inFile.close();
}

void addToBill(const Clothes& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

void addToBill(const Gadgets& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

void shopping() {
    // Shopping for clothes
    cout << "Welcome to Clothes section. Here are the available products:" << endl;
    displayProductsFromFile("clothes.txt");

    ifstream clothesFile("clothes.txt");
    ofstream clothesBillFile("clothes_bill.txt", ios::app);

    // Shopping for gadgets
    cout << "Welcome to Gadgets section. Here are the available products:" << endl;
    displayProductsFromFile("gadgets.txt");

    ifstream gadgetsFile("gadgets.txt");
    ofstream gadgetsBillFile("gadgets_bill.txt", ios::app);

    char choice;
    do {
        int productId, quantity;
        cout << "Enter the Product ID you want to purchase: ";
        cin >> productId;
        cout << "Enter the quantity: ";
        cin >> quantity;

        Clothes clothesItem;
        Gadgets gadgetsItem;
        bool found = false;

        // Search for clothes product
        while (clothesFile >> clothesItem.product_id >> clothesItem.product_name >> clothesItem.selling_price
                           >> clothesItem.brand >> clothesItem.gender >> clothesItem.size >> clothesItem.color >> clothesItem.stock_quantity) {
            if (clothesItem.product_id == productId && clothesItem.stock_quantity >= quantity) {
                addToBill(clothesItem, quantity, clothesBillFile);
                found = true;
                break;
            }
        }

        // Search for gadgets product if not found in clothes
        if (!found) {
            while (gadgetsFile >> gadgetsItem.product_id >> gadgetsItem.product_name >> gadgetsItem.stock_quantity
                               >> gadgetsItem.selling_price >> gadgetsItem.cost_price >> gadgetsItem.items_sold >> gadgetsItem.brand) {
                if (gadgetsItem.product_id == productId && gadgetsItem.stock_quantity >= quantity) {
                    addToBill(gadgetsItem, quantity, gadgetsBillFile);
                    found = true;
                    break;
                }
            }
        }

        if (!found)
            cout << "Product not found or insufficient stock." << endl;

        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    clothesFile.close();
    clothesBillFile.close();
    gadgetsFile.close();
    gadgetsBillFile.close();
}

float printBill(const string& billFilename) {
    ifstream billFile(billFilename);
    if (!billFile) {
        cerr << "Error: Unable to open bill file for reading." << endl;
        return 0.0;
    }

    int productId, quantity;
    float totalPrice;
    string productName;
    float totalBillAmount = 0.0;

    cout << "Bill Details:" << endl;
    while (billFile >> productId >> productName >> quantity >> totalPrice) {
        cout << "Product ID: " << productId << endl;
        cout << "Name: " << productName << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << fixed << setprecision(2) << totalPrice << endl;
        cout << "-------------------------" << endl;

        totalBillAmount += totalPrice;
    }
    billFile.close();

    cout << "Total Bill Amount: $" << fixed << setprecision(2) << totalBillAmount << endl;

    return totalBillAmount;
}

void updateStockQuantity(const string& productsFilename, const string& billFilename) {
    // Similar to previous implementation, update stock quantities based on items listed in the bill file
}

int main() {
    // Step 1: Customer buys clothes and gadgets and generates bills
    shopping();

    // Step 2: Print the clothes bill and get the total bill amount
    float clothesTotalBill = printBill("clothes_bill.txt");

    // Step 3: Print the gadgets bill and get the total bill amount
    float gadgetsTotalBill = printBill("gadgets_bill.txt");

    // Step 4: Calculate the total bill amount
    float totalBill = clothesTotalBill + gadgetsTotalBill;
    cout << "Total Bill Amount (Clothes + Gadgets): $" << fixed << setprecision(2) << totalBill << endl;

    // Step 5: Update stock quantities in clothes and gadgets files
    updateStockQuantity("clothes.txt", "clothes_bill.txt");
    updateStockQuantity("gadgets.txt", "gadgets_bill.txt");

    return 0;
}
