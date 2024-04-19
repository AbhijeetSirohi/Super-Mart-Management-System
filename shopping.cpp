#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> // for formatting output

using namespace std;

class clothes {
public:
    int product_id;
    string product_name;
    float selling_price;
    string brand;
    string gender;
    string size;
    string color;
    int stock_quantity;

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

void addToBill(const clothes& item, ofstream& billFile) {
    billFile << "Product ID: " << item.product_id << endl;
    billFile << "Name: " << item.product_name << endl;
    billFile << "Price: $" << fixed << setprecision(2) << item.selling_price << endl;
    billFile << "Brand: " << item.brand << endl;
    billFile << "Size: " << item.size << ", Gender: " << item.gender << endl;
    billFile << "Color: " << item.color << endl;
    billFile << "-------------------------" << endl;
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
                addToBill(item, billFile);
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


int main() {
    shopping();

    return 0;
}