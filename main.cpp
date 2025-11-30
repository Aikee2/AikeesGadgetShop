#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <limits>
#include <conio.h>
using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Gadget info
struct Item {
    int id;
    string name;
    double price;
    int stock;
    string category;
};

// User cart
struct CartItem {
    int itemID;
    int quantity;
};

string formatNumber(double num) {
    string s = to_string((long long)num);

    // remove trailing .000000
    if (s.find('.') != string::npos) {
        s = s.substr(0, s.find('.'));
    }

    int insertPosition = s.length() - 3;

    while (insertPosition > 0) {
        s.insert(insertPosition, ",");
        insertPosition -= 3;
    }

    return s;
}

void viewAllItems(const vector<Item>& inventory) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n=========== ALL ITEMS ===========\n";

    for (auto& item : inventory) {
        // Item ID + Name → Bright Cyan
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << item.id << ". " << item.name << "\n";

        // Category → White
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "   Category: " << item.category << "\n";

        // Price → Bright Green 
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "   Price: ₱" << formatNumber(item.price) << "\n";

        // Stock → Bright Yellow
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "   Stock: " << item.stock << "\n";

        // Separator → Bright Magenta
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "-------------------------------------\n";
    }

    // Reset console color to default white
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// Initialize all gadgets in the shop
void loadInventory(vector<Item>& inventory) {
        clearScreen();
    // Smartphones
    inventory.push_back({1, "iPhone 17 📱", 79990, 5, "📱 Smartphones📱"});
    inventory.push_back({2, "Infinix Note 50 Pro 📱", 12999, 10, "📱 Smartphones📱"});
    inventory.push_back({3, "Huawei MatePad 11.5📟", 19999, 8, "📱 Smartphones📱"});
    inventory.push_back({4, "iPad A16 11th Gen📟", 30990, 7, "📱 Smartphones📱"});

    // Laptops
    inventory.push_back({5, "ASUS TUF Gaming F15 💻", 54995, 4, "💻 Laptops💻"});
    inventory.push_back({6, "Lenovo Legion 5 Pro (Gaming) 💻", 87995, 3, "💻 Laptops💻"});

    // Gaming Peripherals (updated)
    inventory.push_back({7, "AULA F75 Mechanical Keyboard⌨️", 3499, 10, "🖱️ Peripherals⌨️"});
    inventory.push_back({8, "Redragon M612 Predator 🖱️", 850, 15, "🖱️ Peripherals⌨️"});
    inventory.push_back({9, "Onikuma X15 Pro Headset 🎧", 799, 12, "🖱️ Peripherals⌨️"});

    // Accessories
    inventory.push_back({10, "Baseus 20W Charger🔌", 649, 20, "⚡Accessories🔌"});
    inventory.push_back({11, "Ugreen USB-C Cable⚡", 299, 30, "⚡Accessories🔌"});
}

// Show Main Menu
void showMainMenu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    clearScreen();

    // Title → Bright Red
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE| FOREGROUND_INTENSITY);
    cout << "\n====================================\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "   WELCOME TO AIKEE'S GADGET SHOP\n";

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE| FOREGROUND_INTENSITY);
    cout << "====================================\n";

    // Menu options → Cyan
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "1. View Categories 📂\n";
    cout << "2. View All Items 🛍️\n";
    cout << "3. View Cart 🛒\n";

    // Checkout → Green
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "4. Checkout 💳\n";

    // Exit → Yellow
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "5. Exit 🚪\n";

    // Separator → Bright Magenta
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "------------------------------------\n";

    // Input prompt → Bright White
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "Enter choice: ";
}

void showCategories() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    clearScreen();

    // Header → Bright Magenta
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n----------- CATEGORIES -----------\n";

    // Categories → Cyan
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "1. Smartphones📱\n";
    cout << "2. Laptops💻\n";
    cout << "3. Peripherals🖱️ ⌨️ 🎧\n";
    cout << "4. Accessories⚡🔌\n";

    // Back → Yellow
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "5. Back↩️\n";

    // Separator → Bright Magenta
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "----------------------------------\n";

    // Input prompt → Bright White
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "Enter category: ";
}

void printError(string message) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // bright red
    cout << "❌ " << message << " ❌\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // reset
}

void printSuccess(string message) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // bright green
    cout << "✔️  " << message << " ✔️\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // reset
}

void printInfo(string message) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // bright yellow
    cout << "➖ " << message << " ➖\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // reset
}

pair<int, int> viewItemsByCategory(const vector<Item>& inventory, string category) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    clearScreen();

    // Header → Bright Magenta
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n========== " << category << " ==========\n";

    vector<int> validIDs; // store IDs belonging to this category

    for (const auto& item : inventory) {
        if (item.category == category) {
            // ID + Name → Bright Cyan
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << item.id << ". " << item.name << "\n";

            // Category → White
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "   Category: " << item.category << "\n";

            // Price → Bright Green
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "   Price: ₱" << formatNumber(item.price) << "\n";

            // Stock → Bright Yellow
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "   Stock: " << item.stock << "\n";

            // Separator → Bright Magenta
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "-------------------------------------\n";

            validIDs.push_back(item.id);
        }
    }

    // Reset console color to default white
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    int id, qty;
    cout << "Enter item ID (0 to cancel): ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        printError("Invalid input");
        cout << "Please enter a number: ";
    }

    if (id == 0) return {0, 0};

    // Check if ID is part of this category
    bool valid = false;
    for (int v : validIDs) {
        if (v == id) { 
            valid = true; 
            break; 
        }
    }

    if (!valid) {
        clearScreen();
        printError("That item is not in this category!");
        Sleep(1500);
        return {0, 0};
    }

    cout << "Quantity: ";
    while (!(cin >> qty)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        printError("Invalid input");
        cout << "Please enter a number: ";
    }
    return {id, qty};
}

vector<CartItem> cart;

void addToCart(vector<CartItem>& cart, vector<Item>& inventory, int itemID, int qty) {
    // Find the item in the inventory
        clearScreen();
    for (auto& item : inventory) {
        if (item.id == itemID) {
            if (qty <= 0) {
                clearScreen();
                printError("Invalid quantity");
                Sleep(1500);
                return;
            }

            if (qty > item.stock) {
                printError("Not enough stock available");
                Sleep(1500);
                return;
            }

            // Reduce stock
            item.stock -= qty;

            // Check if item already in cart
            for (auto& c : cart) {
                if (c.itemID == itemID) {
                    c.quantity += qty;
                    cout << "Added " << qty << " more to cart.\n";
                    return;
                }
            }

            // If new item in cart
            cart.push_back({itemID, qty});
            printSuccess("Item added to cart!");
            Sleep(1500);
            return;
        }
    }

    printError("Item not found");
}

void viewCart(const vector<CartItem>& cart, const vector<Item>& inventory) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    clearScreen();
    if (cart.empty()) {
        printInfo("Your cart is empty.");
        return;
    }

    double total = 0;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n========= YOUR CART =========\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (const auto& c : cart) {
        for (const auto& item : inventory) {
            if (item.id == c.itemID) {
                double itemTotal = item.price * c.quantity;
                total += itemTotal;

                cout << item.name 
                     << " x" << c.quantity 
                     << " - " << u8"₱" << formatNumber(item.price)
                     << " each = " << u8"₱" << formatNumber(item.price * c.quantity) << "\n";
            }
        }
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "-----------------------------\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "TOTAL: " << u8"₱" << formatNumber(total) << "\n";
}

void manageCart(vector<CartItem>& cart, vector<Item>& inventory) {
    while (true) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        clearScreen();

        if (cart.empty()) {
            printInfo("Your cart is empty.");
            Sleep(1500);
            return;
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\n========= YOUR CART =========\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        int index = 1;
        for (const auto& c : cart) {
            for (const auto& item : inventory) {
                if (item.id == c.itemID) {
                    cout << index << ". " << item.name 
                         << " x" << c.quantity 
                         << " = " << u8"₱" << formatNumber(item.price * c.quantity) << "\n";
                }
            }
            index++;
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "-----------------------------\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "1. Remove Item 🗑️\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
        cout << "2. Change Quantity 🔢\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "3. Clear Cart ♻️\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_INTENSITY);
        cout << "4. Back ↩️\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Choose an option: ";

        int choice;
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printError("Not enough stock available");
            cout << "Please enter a number: ";
        }

        if (choice == 4) return;

        if (choice == 1) { 
            int removeIndex;
            cout << "Enter item number to remove: ";
            while (!(cin >> removeIndex)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                printError("Invalid input");
                cout << "Please enter a number: ";
            }

            if (removeIndex < 1 || removeIndex > cart.size()) {
                clearScreen();
                printError("Invalid item number");
                Sleep(1500);
                continue;
            }

            // Restore stock
            for (auto& item : inventory) {
                if (item.id == cart[removeIndex - 1].itemID) {
                    item.stock += cart[removeIndex - 1].quantity;
                }
            }

            cart.erase(cart.begin() + (removeIndex - 1));
            cout << "✔️ Item removed ✔️\n";
            Sleep(1500);
        }
        else if (choice == 2) {
            int idx, newQty;
            cout << "Enter item number: ";
            while (!(cin >> idx)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                printError("Invalid input");
                cout << "Please enter a number: ";
            }

            if (idx < 1 || idx > cart.size()) {
                clearScreen();
                printError("Invalid item number");
                Sleep(1500);
                continue;
            }

            cout << "Enter new quantity: ";
            while (!(cin >> newQty)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                printError("Invalid input");
                cout << "Please enter a number: ";
            }

            if (newQty <= 0) {
                clearScreen();
                printError("Invalid quantity");
                Sleep(1500);
                continue;
            }

            // Find matching item
            for (auto& item : inventory) {
                if (item.id == cart[idx - 1].itemID) {
                    int oldQty = cart[idx - 1].quantity;

                    // Return old stock first
                    item.stock += oldQty;

                    if (newQty > item.stock) {
                        printError("Not enough stock available");
                        Sleep(1500);
                        // restore old quantity
                        item.stock -= oldQty;
                        continue;
                    }

                    // Deduct new quantity
                    item.stock -= newQty;

                    cart[idx - 1].quantity = newQty;

                    cout << "✔️ Quantity updated ✔️\n";
                    Sleep(1500);
                }
            }
        }
        else if (choice == 3) {
            // Restore all stocks
            for (auto& c : cart) {
                for (auto& item : inventory) {
                    if (item.id == c.itemID) {
                        item.stock += c.quantity;
                    }
                }
            }

            cart.clear();
            printInfo("Cart cleared");
            Sleep(1500);
        }
        else {
            clearScreen();
            printError("Invalid option");
            Sleep(1500);
        }
    }
}

void checkout(vector<CartItem>& cart, const vector<Item>& inventory) {
        clearScreen();
    if (cart.empty()) {
        printInfo("Cart is empty. Nothing to checkout.");
        Sleep(1500);
        return;
    }

    viewCart(cart, inventory);
    cout << "\nProceed to checkout? (1 = Yes, 2 = No): ";
    int choice;
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        printError("Invalid input");
        cout << "Please enter a number: ";
    }


    if (choice == 1) {
        printSuccess("Order placed successfully! Thank you!");
        Sleep(1500);
        cart.clear(); // Clear cart after checkout
    } else {
        printError("Checkout cancelled");
        Sleep(1500);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector<Item> inventory;
    loadInventory(inventory);

    int choice;

    while (true) {
        showMainMenu();
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printError("Invalid input");
            cout << "Please enter a number: ";
        }
        
        if (choice == 1) {
            int catChoice;
            showCategories();
        while (!(cin >> catChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printError("Invalid input");
            cout << "Please enter a number: ";
        }
        pair<int, int> order;

        if (catChoice == 1) {
            order = viewItemsByCategory(inventory, "📱 Smartphones📱");
        }
        else if (catChoice == 2) {
            order = viewItemsByCategory(inventory, "💻 Laptops💻");
        }
        else if (catChoice == 3) {
            order = viewItemsByCategory(inventory, "🖱️ Peripherals⌨️");
        }
        else if (catChoice == 4) {
            order = viewItemsByCategory(inventory, "⚡Accessories🔌");
        }
        else if (catChoice == 5) {
            continue; // go back WITHOUT printing "invalid option"
        }
        else {
            clearScreen();
            printError("Invalid option");
            Sleep(1500);
            continue; // stay in main loop WITH message
        }

        if (order.first != 0) {
            addToCart(cart, inventory, order.first, order.second);
            }
        }
        else if (choice == 2) {
            clearScreen();
            viewAllItems(inventory); // ← use the function with colors
                cout << "\nPress any key to continue...";
                _getch();
        }
        
        else if (choice == 3) {
            manageCart(cart, inventory);
        }
        else if (choice == 4) {
            checkout(cart, inventory);
        }
        else if (choice == 5) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            clearScreen();
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "\nThank you for visiting Aikee's Gadget Shop!\n";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            Sleep(1500);
            break;
        }

        else {
            clearScreen();
            printError("Invalid option");
            Sleep(1500);
        }
    }

    return 0;
}