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

    void displayProductInfo1() const {
        std::cout << "Product ID: " << product_id << endl;
        std::cout << "Name: " << product_name << endl;
        std::cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        std::cout << "Brand: " << brand_name << endl;
        std::cout << "Size: " << size << ", Gender: " << gender << endl;
        std::cout << "Color: " << color << endl;
        std::cout << "Stock Quantity: " << stock_quantity << endl;
        std::cout << "-------------------------" << endl;
    }
};

void displayClothesFromFile1(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Clothes item;
    std::cout << "Available Clothes:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.gender >> item.size >> item.color) {
        item.displayProductInfo1();
    }
    inFile.close();
}

void addToBill1(const Clothes& item, int quantity, ofstream& billFile) {
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

    void displayProductInfo2() const {
        std::cout << "Product ID: " << product_id << endl;
        std::cout << "Name: " << product_name << endl;
        std::cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        std::cout << "Brand: " << brand_name << endl;
        std::cout << "Category: " << category << endl;
        std::cout << "Stock Quantity: " << stock_quantity << endl;
        std::cout << "-------------------------" << endl;
    }
};

void displayFoodFromFile2(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Food item;
    std::cout << "Available Food Items:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.category) {
        item.displayProductInfo2();
    }
    inFile.close();
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

    void displayProductInfo3() const {
        std::cout << "Product ID: " << product_id << endl;
        std::cout << "Name: " << product_name << endl;
        std::cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        std::cout << "Brand: " << brand_name << endl;
        std::cout << "Stock Quantity: " << stock_quantity << endl;
        std::cout << "-------------------------" << endl;
    }
};

void displayGadgetsFromFile3(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Gadget item;
    std::cout << "Available Gadgets:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name) {
        item.displayProductInfo3();
    }
    inFile.close();
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

    void displayProductInfo4() const {
        std::cout << "Product ID: " << product_id << endl;
        std::cout << "Name: " << product_name << endl;
        std::cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        std::cout << "Brand: " << brand_name << endl;
        std::cout << "Category: " << category << endl;
        std::cout << "Stock Quantity: " << stock_quantity << endl;
        std::cout << "-------------------------" << endl;
    }
};

void displayHealthcareFromFile4(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Healthcare item;
    std::cout << "Available Healthcare Products:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name >> item.category) {
        item.displayProductInfo4();
    }
    inFile.close();
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

    void displayProductInfo5() const {
        std::cout << "Product ID: " << product_id << endl;
        std::cout << "Name: " << product_name << endl;
        std::cout << "Price: $" << fixed << setprecision(2) << selling_price << endl;
        std::cout << "Brand: " << brand_name << endl;
        std::cout << "Stock Quantity: " << stock_quantity << endl;
        std::cout << "-------------------------" << endl;
    }
};

void displayStationaryFromFile5(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    Stationary item;
    std::cout << "Available Stationary Products:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.stock_quantity
                 >> item.cost_price >> item.selling_price >> item.items_sold
                 >> item.brand_name) {
        item.displayProductInfo5();
    }
    inFile.close();
}

void addToBill5(const Stationary& item, int quantity, ofstream& billFile) {
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

// update function for clothes
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
        cerr << "Error: Unable to open bill file for reading." << endl;
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
        cerr << "Error: Unable to open bill file for reading." << endl;
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
        cerr << "Error: Unable to open bill file for reading." << endl;
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
        cerr << "Error: Unable to open bill file for reading." << endl;
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
        cerr << "Error: Unable to open bill file for reading." << endl;
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
    displayClothesFromFile1("clothes.txt");

    
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
    displayFoodFromFile2("food.txt");

    
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
    displayGadgetsFromFile3("gadgets.txt");

    
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
    displayHealthcareFromFile4("healthcare.txt");

    
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
    displayStationaryFromFile5("stationary.txt");

    
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

int main() {
    // Call the shopping function
  shop();
return 0;
}

