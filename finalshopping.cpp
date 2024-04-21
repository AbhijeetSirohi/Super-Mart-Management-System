#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

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
};

void displayClothesFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
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

void addToBill(const Clothes& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

//food
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
};

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

void addToBill(const Food& item, int quantity, ofstream& billFile) {
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
};

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

void addToBill(const Gadget& item, int quantity, ofstream& billFile) {
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
    }
};

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

void addToBill(const Healthcare& item, int quantity, ofstream& billFile) {
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
    }
};

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

void addToBill(const Stationary& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id << '\t';
    billFile << item.product_name << '\t';
    billFile << quantity << '\t';
    billFile << fixed << setprecision(2) << totalPrice << endl;
}

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
        cerr << "Error: Unable to open bill file for reading." << endl;
        return 0.0;
    }

    int productId, quantity;
    float totalprice ;
    string productname;
    float totalBillAmount = 0.0;

    cout << "Bill Details:" << endl;
    while (billFile >> productId >>productname>> quantity >> totalprice) {
        // Create a Bill object for the current item
        Bill item(productId, productname, totalprice, quantity);

        // Print details of the current item
        cout << "Product ID: " << item.productId << endl;
cout << "Name: " << item.productName << endl;
cout << "Quantity: " << item.quantity << endl;
cout << "Price: $" << fixed << setprecision(2) << totalprice  << endl;
cout << "-------------------------" << endl;


        // Calculate the total price for the current item and add to total bill amount
        float totalPrice1 = totalprice;
        totalBillAmount += totalPrice1;
    }
    billFile.close();

    cout << "Total Bill Amount: $" << fixed << setprecision(2) << totalBillAmount << endl;

    return totalBillAmount;
}

// update function for clothes
void updateStockQuantity(const string& clothesFilename, const string& billFilename) {
    ifstream clothesFile(clothesFilename);
    ofstream tempFile("temp.txt");

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
        cerr << "Error: Unable to open bill file for reading." << endl;
        return;
    }

    int productId, quantity;
    float totalPrice;
    while (billFile >> productId >> quantity >> totalPrice) {
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
    if (rename("temp.txt", clothesFilename.c_str()) != 0) {
        perror("Error renaming file");
    } else {
        cout << "Stock quantities and items sold updated successfully." << endl;
    }
}

// update function for food

void updateStockQuantity(const string& foodFilename, const string& billFilename) {
    ifstream foodFile(foodFilename);
    ofstream tempFile("temp.txt");

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
        cerr << "Error: Unable to open bill file for reading." << endl;
        return;
    }

    int productId, quantity;
    float totalPrice;
    while (billFile >> productId >> quantity >> totalPrice) {
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
    if (rename("temp.txt", foodFilename.c_str()) != 0) {
        perror("Error renaming file");
    } else {
        cout << "Stock quantities and items sold updated successfully." << endl;
    }
}

// update fucntion for gadgets
void updateStockQuantity(const string& gadgetsFilename, const string& billFilename) {
    ifstream gadgetsFile(gadgetsFilename);
    ofstream tempFile("temp.txt");

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
        cerr << "Error: Unable to open bill file for reading." << endl;
        return;
    }

    int productId, quantity;
    float totalPrice;
    while (billFile >> productId >> quantity >> totalPrice) {
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
    if (rename("temp.txt", gadgetsFilename.c_str()) != 0) {
        perror("Error renaming file");
    } else {
        cout << "Stock quantities and items sold updated successfully." << endl;
    }
}

// update function for healthcare
void updateStockQuantity(const string& healthcareFilename, const string& billFilename) {
    ifstream healthcareFile(healthcareFilename);
    ofstream tempFile("temp.txt");

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
        cerr << "Error: Unable to open bill file for reading." << endl;
        return;
    }

    int productId, quantity;
    float totalPrice;
    while (billFile >> productId >> quantity >> totalPrice) {
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
    if (rename("temp.txt", healthcareFilename.c_str()) != 0) {
        perror("Error renaming file");
    } else {
        cout << "Stock quantities and items sold updated successfully." << endl;
    }
}

// update function for stationary
void updateStockQuantity(const string& stationaryFilename, const string& billFilename) {
    ifstream stationaryFile(stationaryFilename);
    ofstream tempFile("temp.txt");

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
        cerr << "Error: Unable to open bill file for reading." << endl;
        return;
    }

    int productId, quantity;
    float totalPrice;
    while (billFile >> productId >> quantity >> totalPrice) {
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
    if (rename("temp.txt", stationaryFilename.c_str()) != 0) {
        perror("Error renaming file");
    } else {
        cout << "Stock quantities and items sold updated successfully." << endl;
    }
}


