#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> // for formatting output

using namespace std;

class clothes {
public:
       int product_id = 0;
    string product_name = "";
    float selling_price = 0.0;
    string brand = "";
    string gender = "";
    string size = "";
    string color = "";
    int stock_quantity = 0;

    // Default constructor
    clothes() = default;

    clothes(int id, const string& name, float price, const string& brand_name,
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

void displayClothesFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    clothes item;
    cout << "Available Clothes:" << endl;
    while (inFile >> item.product_id >> item.product_name >> item.selling_price
                 >> item.brand >> item.gender >> item.size >> item.color >> item.stock_quantity) {
        item.displayProductInfo();
    }
    inFile.close();
}

void addToBill(const clothes& item, int quantity, ofstream& billFile) {
    float totalPrice = item.selling_price * quantity;

    billFile << item.product_id<<'\t' ;
    billFile << item.product_name <<'\t' ;
    billFile <<  quantity <<'\t' ;
    billFile << fixed << setprecision(2) << totalPrice << endl;
    
}


void shopping() {
    cout << "Welcome to Clothes section. Here are the available products:" << endl;
    displayClothesFromFile("clothes.txt");

    ifstream inFile("clothes.txt");
    ofstream billFile("bill.txt", ios::app); // Append mode to add items to bill

    char choice;
    do {
        int productId, quantity;
        cout << "Enter the Product ID you want to purchase: ";
        cin >> productId;
        cout << "Enter the quantity: ";
        cin >> quantity;

        clothes item;
        bool found = false;
        while (inFile >> item.product_id >> item.product_name >> item.selling_price
                    >> item.brand >> item.gender >> item.size >> item.color >> item.stock_quantity) {
            if (item.product_id == productId && item.stock_quantity >= quantity) {
                addToBill(item, quantity, billFile);

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

// the file updation
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

// Function to update stock quantity based on items listed in the bill file
void updateStockQuantity(const string& clothesFilename, const string& billFilename) {
    ifstream clothesFile(clothesFilename);
    ofstream tempFile("temp1.txt");

    if (!clothesFile || !tempFile) {
        cerr << "Error: Unable to open file for reading or writing." << endl;
        return;
    }

    ifstream billFile(billFilename);
    if (!billFile) {
        cerr << "Error: Unable to open bill file for reading." << endl;
        return;
    }

    vector<Clothes> clothesList;
    Clothes item;
    // Read clothes data into a vector
    while (clothesFile >> item.product_id >> item.product_name >> item.selling_price
                        >> item.brand >> item.gender >> item.size >> item.color >> item.stock_quantity) {
        clothesList.push_back(item);
    }

    billFile.clear(); // Clear any error flags
    billFile.seekg(0); // Move the file pointer to the beginning

    
    int productId, quantity;
    float totalprice ;
    string productname;
    

    while (billFile >> productId >>productname>> quantity >> totalprice) {
        bool found = false;
        for (size_t i = 0; i < clothesList.size(); ++i) {
            if (clothesList[i].product_id == productId) {
                // Update stock quantity
                clothesList[i].stock_quantity -=quantity ;
                found = true;
                break;
            }
        }
        if (!found) {
            cerr << "Product with ID " <<  productId<< " not found in the clothes file." << endl;
        }
    }

    // Write the updated clothes data to the temporary file
    for (size_t i = 0; i < clothesList.size(); ++i) {
        tempFile << clothesList[i].product_id << " " << clothesList[i].product_name << " "
                 << clothesList[i].selling_price << " " << clothesList[i].brand << " "
                 << clothesList[i].gender << " " << clothesList[i].size << " " << clothesList[i].color << " "
                 << clothesList[i].stock_quantity << endl;
    }

    // Close the files
    clothesFile.close();
    billFile.close();
    tempFile.close();

    // Rename the temporary file to overwrite the original clothes file
    if (rename("temp1.txt", clothesFilename.c_str()) != 0) {
        cerr << "Error: Unable to update stock quantities in the clothes file." << endl;
    } else {
        cout << "Stock quantities updated successfully." << endl;
    }
}







int main() {
    // Step 1: Customer buys clothes and generates bill
    shopping();

    // Step 2: Print the bill and get the total bill amount
    float totalBill = printBill("bill.txt");

    // Step 3: Update stock quantity in clothes file
    updateStockQuantity("clothes.txt", "bill.txt");

    // Step 4: Print the sum of total bill
    cout << "Sum of Total Bill: $" << fixed << setprecision(2) << totalBill << endl;

    return 0;
}
