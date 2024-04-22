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