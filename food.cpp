#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FoodItem {
public:
    int product_id;
    string product_name;
    float selling_price;
    string brand;
    string category;
    int stock_quantity;

    FoodItem() : product_id(0), selling_price(0.0), stock_quantity(0) {}

    FoodItem(int id, const string& name, float price, const string& br, const string& cat, int quantity)
        : product_id(id), product_name(name), selling_price(price), brand(br), category(cat), stock_quantity(quantity) {}

    void displayProductInfo() const {
        cout << "Product ID: " << product_id << endl;
        cout << "Name: " << product_name << endl;
        cout << "Price: $" << selling_price << endl;
        cout << "Brand: " << brand << endl;
        cout << "Category: " << category << endl;
        cout << "Stock Quantity: " << stock_quantity << endl;
        cout << "-------------------------" << endl;
    }
};

void displayFoodItemsFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    FoodItem item;
    cout << "Available Food Items:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.selling_price
                 >> item.brand >> item.category >> item.stock_quantity) {
        item.displayProductInfo();
    }
    inFile.close();
}

void addToBill(const FoodItem& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << item.brand << '\t';
    billFile << item.category << '\t';
    billFile << quantity << '\t';
    billFile << totalPrice << endl;
}

void shopping() {
    cout << "Welcome to the Food section. Here are the available products:" << endl;
    displayFoodItemsFromFile("food.txt");

    ofstream billFile("food_bill.txt"); // Writing mode to overwrite the file

    string choice; // Change to string type
    do {
        ifstream inFile("food.txt"); // Open the file in each iteration

        int productId, quantity;
        cout << "Enter the Product ID you want to purchase: ";
        cin >> productId;
        cout << "Enter the quantity: ";
        cin >> quantity;

        FoodItem item;
        bool found = false;
        while (inFile >> item.product_id >> item.product_name >> item.selling_price
                    >> item.brand >> item.category >> item.stock_quantity) {
            if (item.product_id == productId && item.stock_quantity >= quantity) {
                addToBill(item, quantity, billFile);

                found = true;
                // Update stock quantity in the food file (if needed)
                // This would involve rewriting the entire file with updated quantities
                // or using a temporary file to update quantities
                break;
            }
        }

        inFile.close(); // Close the file after reading
        if (!found)
            cout << "Product not found or insufficient stock." << endl;

        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;
    } while (choice == "y" || choice == "Y"); // Check for string "y" or "n"

    billFile.close(); // Close the bill file
}

class Bill {
public:
    int productId;
    string productName;
    string brand;
    string category;
    float totalprice;
    int quantity;

    Bill(int id, const string& name, const string& br, const string& cat, float price, int qty)
        : productId(id), productName(name), brand(br), category(cat), totalprice(price), quantity(qty) {}

    void addToBill(ofstream& billFile) const {
        float totalPrice1 = totalprice;

        billFile << "Product ID: " << productId << endl;
        billFile << "Name: " << productName << endl;
        billFile << "Brand: " << brand << endl;
        billFile << "Category: " << category << endl;
        billFile << "Quantity: " << quantity << endl;
        billFile << "Price: $" << totalPrice1 << endl;
        billFile << "-------------------------" << endl;
    }
};

float printBill(const string& billFilename) {
    ifstream billFile(billFilename);
    if (!billFile) {
        cerr << "Error: Unable to open bill file for reading." << endl;
        return 0.0;
    }

    int productId, quantity;
    float totalprice;
    string productName, brand, category;
    float totalBillAmount = 0.0;

    cout << "Bill Details:" << endl;
    while (billFile >> productId >> productName >> brand >> category >> quantity >> totalprice) {
        Bill item(productId, productName, brand, category, totalprice, quantity);

        cout << "Product ID: " << item.productId << endl;
        cout << "Name: " << item.productName << endl;
        cout << "Brand: " << item.brand << endl;
        cout << "Category: " << item.category << endl;
        cout << "Quantity: " << item.quantity << endl;
        cout << "Price: $" << totalprice << endl;
        cout << "-------------------------" << endl;

        totalBillAmount += totalprice;
    }
    billFile.close();

    cout << "Total Bill Amount: $" << totalBillAmount << endl;

    return totalBillAmount;
}

void updateStockQuantity(const string& foodFilename, const string& billFilename) {
    ifstream foodFile(foodFilename);
    ofstream tempFile("temp_food.txt");

    if (!foodFile || !tempFile) {
        cerr << "Error: Unable to open file for reading or writing." << endl;
        return;
    }

    ifstream billFile(billFilename);
    if (!billFile) {
        cerr << "Error: Unable to open bill file for reading." << endl;
        return;
    }

    FoodItem item;
    // Read and update stock quantities
    while (foodFile >> item.product_id >> item.product_name >> item.selling_price
                    >> item.brand >> item.category >> item.stock_quantity) {
        int productId, quantity;
        float totalprice;
        string productName, brand, category;

        billFile.clear();
        billFile.seekg(0);

        while (billFile >> productId >> productName >> brand >> category >> quantity >> totalprice) {
            if (item.product_id == productId) {
                // Update stock quantity
                item.stock_quantity -= quantity;
            }
        }

        // Write updated data to temporary file
        tempFile << item.product_id << " " << item.product_name << " "
                 << item.selling_price << " " << item.brand << " " << item.category << " "
                 << item.stock_quantity << endl;
    }

    // Close files
    foodFile.close();
    billFile.close();
    tempFile.close();

    // Rename temporary file to overwrite original food file
    if (rename("temp_food.txt", foodFilename.c_str()) != 0) {
        cerr << "Stock Updation in process." << endl;
    } else {
        cout << "Stock quantities updated successfully." << endl;
    }
}

int main() {
    // Step 1: Customer buys food items and generates bill
    shopping();

    // Step 2: Print the bill and get the total bill amount
    float totalBill = printBill("food_bill.txt");

    // Step 3: Update stock quantity in food file
    updateStockQuantity("food.txt", "food_bill.txt");

    // Step 4: Print the sum of total bill
    cout << "Sum of Total Bill: $" << totalBill << endl;

    return 0;
}
