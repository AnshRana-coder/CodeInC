#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_USERS 100
#define MAX_NAME_LEN 50
#define MANAGER_USERNAME "admin"
#define MANAGER_PASSWORD "admin123"
#define MAX_CART_ITEMS 100

// Define the CartItem structure
struct CartItem {
    int productId;
    int quantity;
};

struct CartItem cart[MAX_CART_ITEMS];
int cartCount = 0;  // Keeps track of the number of items in the carty
// Function to add product to cart
void addToCart(int productId, int quantity) {
    // Check if the cart is full
    if (cartCount >= MAX_CART_ITEMS) {
        printf("Cart is full. Cannot add more items.\n");
        return;
    }

    // Check if the product already exists in the cart
    for (int i = 0; i < cartCount; i++) {
        if (cart[i].productId == productId) {
            // If the product is already in the cart, update the quantity
            cart[i].quantity += quantity;
            printf("Added %d more of product ID %d to the cart.\n", quantity, productId);
            return;
        }
    }

    // If product is not in cart, add it
    cart[cartCount].productId = productId;
    cart[cartCount].quantity = quantity;
    cartCount++;
    printf("Added product ID %d to the cart.\n", productId);
}


// Define the Product structure
struct Product {
    int id;
    char name[MAX_NAME_LEN];
    float price;
    int stock;
    char category[MAX_NAME_LEN];
};

// Define the User structure
struct User {
    char username[MAX_NAME_LEN];
    char password[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    float balance;  
};

// Arrays to store products, users, and their counts
struct Product catalog[MAX_PRODUCTS];
int product_count = 0;

struct User users[MAX_USERS];
int user_count = 0;

// Function to load users from file
void loadUsersFromFile() {
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open user file.\n");
        return;
    }

    // Read users from file
    while (fscanf(file, "%s %s %s %f\n", 
                  users[user_count].username, 
                  users[user_count].password, 
                  users[user_count].name, 
                  &users[user_count].balance) == 4) {
        user_count++;
        if (user_count >= MAX_USERS) {
            break;
        }
    }

    fclose(file);

    if (user_count == 0) {
        printf("No users were loaded from the file.\n");
    }
}

// Function to save users to the file
void saveUsersToFile() {
    FILE *file = fopen("user.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open user file for writing.\n");
        return;
    }

    // Write users to the file
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s %s %s %.2f\n", 
                users[i].username, 
                users[i].password, 
                users[i].name, 
                users[i].balance);
    }

    fclose(file);
}

// Function to load products from the file
void loadProductsFromFile() {
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open products file.\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%f,%d,%49[^\n]\n", 
                  &catalog[product_count].id, 
                  catalog[product_count].name, 
                  &catalog[product_count].price, 
                  &catalog[product_count].stock, 
                  catalog[product_count].category) == 5) {
        product_count++;
    }

    fclose(file);

    if (product_count == 0) {
        printf("No products were loaded from the file.\n");
    }
}

// Function to save products to the file
void saveProductsToFile() {
    FILE *file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open products file for writing.\n");
        return;
    }

    for (int i = 0; i < product_count; i++) {
        fprintf(file, "%d,%s,%.2f,%d,%s\n", 
                catalog[i].id, 
                catalog[i].name, 
                catalog[i].price, 
                catalog[i].stock, 
                catalog[i].category);
    }

    fclose(file);
}

// Function to display the list of products


// Function to display products
void displayProducts(struct Product *products, int count) {
    if (count == 0) {
        printf("No products available!\n");
        return;
    }

    printf("ID\tName\t\tPrice\tStock\tCategory\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-20s\t%.2f\t%d\t%s\n", 
               products[i].id, products[i].name, 
               products[i].price, products[i].stock, 
               products[i].category);
    }
}

// Function to filter products by category
void filterByCategory() {
    char category[MAX_NAME_LEN];
    
    printf("\nEnter category to filter by: ");
    scanf(" %[^\n]%*c", category);  // Allow spaces in category

    struct Product filteredProducts[MAX_PRODUCTS];
    int filteredCount = 0;

    for (int i = 0; i < product_count; i++) {
        if (strcmp(catalog[i].category, category) == 0) {
            filteredProducts[filteredCount++] = catalog[i];
        }
    }

    if (filteredCount > 0) {
        displayProducts(filteredProducts, filteredCount);
    } else {
        printf("No products found in the specified category.\n");
    }
}

// Function to filter products by price range
void filterByPriceRange() {
    float minPrice, maxPrice;

    printf("\nEnter minimum price: ");
    scanf("%f", &minPrice);
    printf("Enter maximum price: ");
    scanf("%f", &maxPrice);

    struct Product filteredProducts[MAX_PRODUCTS];
    int filteredCount = 0;

    for (int i = 0; i < product_count; i++) {
        if (catalog[i].price >= minPrice && catalog[i].price <= maxPrice) {
            filteredProducts[filteredCount++] = catalog[i];
        }
    }

    if (filteredCount > 0) {
        displayProducts(filteredProducts, filteredCount);
    } else {
        printf("No products found in the specified price range.\n");
    }
}

// Function to filter products by stock availability
void filterByStockAvailability() {
    struct Product filteredProducts[MAX_PRODUCTS];
    int filteredCount = 0;

    for (int i = 0; i < product_count; i++) {
        if (catalog[i].stock > 0) {
            filteredProducts[filteredCount++] = catalog[i];
        }
    }

    if (filteredCount > 0) {
        displayProducts(filteredProducts, filteredCount);
    } else {
        printf("No products available in stock.\n");
    }
}
// Function to view products with optional filtering
void viewProducts() {
    int filterOption;

    printf("\n--- Product Catalog ---\n");
    printf("1. View All Products\n");
    printf("2. Filter by Category\n");
    printf("3. Filter by Price Range\n");
    printf("4. Filter by Stock Availability\n");
    printf("5. Return to Customer Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &filterOption);

    switch (filterOption) {
        case 1:
            // View all products without any filter
            displayProducts(catalog, product_count);
            break;
        case 2:
            // Filter by category
            filterByCategory();
            break;
        case 3:
            // Filter by price range
            filterByPriceRange();
            break;
        case 4:
            // Filter by stock availability
            filterByStockAvailability();
            break;
        case 5:
            return;  // Return to the customer menu
        default:
            printf("Invalid choice. Returning to Customer Menu.\n");
            return;
    }
}

// Function for manager to add a product
void addProduct() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Product catalog is full.\n");
        return;
    }

    struct Product newProduct;

    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    scanf(" %[^\n]%*c", newProduct.name);  // To allow spaces in the name
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product stock: ");
    scanf("%d", &newProduct.stock);
    printf("Enter product category: ");
    scanf(" %[^\n]%*c", newProduct.category);

    // Add the new product to the catalog
    catalog[product_count] = newProduct;
    product_count++;
    saveProductsToFile();

    printf("Product added successfully!\n");
}

// Function for manager to remove a product
void removeProduct() {
    int productId;
    printf("Enter product ID to remove: ");
    scanf("%d", &productId);

    int found = 0;
    for (int i = 0; i < product_count; i++) {
        if (catalog[i].id == productId) {
            // Shift all subsequent products left
            for (int j = i; j < product_count - 1; j++) {
                catalog[j] = catalog[j + 1];
            }
            product_count--;  // Decrease product count
            found = 1;
            break;
        }
    }

    if (found) {
        saveProductsToFile();
        printf("Product removed successfully!\n");
    } else {
        printf("Product ID not found.\n");
    }
}

// Function for manager to update a product
void updateProduct() {
    int productId;
    printf("Enter product ID to update: ");
    scanf("%d", &productId);

    int found = 0;
    for (int i = 0; i < product_count; i++) {
        if (catalog[i].id == productId) {
            printf("Enter new product name (current: %s): ", catalog[i].name);
            scanf(" %[^\n]%*c", catalog[i].name);  // To allow spaces in the name
            printf("Enter new product price (current: %.2f): ", catalog[i].price);
            scanf("%f", &catalog[i].price);
            printf("Enter new product stock (current: %d): ", catalog[i].stock);
            scanf("%d", &catalog[i].stock);
            printf("Enter new product category (current: %s): ", catalog[i].category);
            scanf(" %[^\n]%*c", catalog[i].category);

            saveProductsToFile();
            printf("Product updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product ID not found.\n");
    }
}
// Function to view cart
void viewCart() {
    if (cartCount == 0) {
        printf("Your cart is empty.\n");
        return;
    }

    printf("\n--- Your Cart ---\n");
    printf("ID\tQuantity\n");
    for (int i = 0; i < cartCount; i++) {
        printf("%d\t%d\n", cart[i].productId, cart[i].quantity);
    }
}

// Function to checkout
void checkout() {
    float totalAmount = 0.0;

    for (int i = 0; i < cartCount; i++) {
        for (int j = 0; j < product_count; j++) {
            if (cart[i].productId == catalog[j].id) {
                totalAmount += catalog[j].price * (float)cart[i].quantity;
                break;
            }
        }
    }

    printf("Total amount: %.2f\n", totalAmount);
    printf("Proceeding with the checkout...\n");

    // Optionally, update user balance or clear cart here
    cartCount = 0;  // Clear the cart after checkout
}
// Function to remove item from cart
void removeFromCart() {
    int productId;
    printf("Enter product ID to remove from cart: ");
    scanf("%d", &productId);

    int found = 0;
    for (int i = 0; i < cartCount; i++) {
        if (cart[i].productId == productId) {
            // Shift all subsequent items left
            for (int j = i; j < cartCount - 1; j++) {
                cart[j] = cart[j + 1];
            }
            cartCount--;  // Decrease cart count
            printf("Product removed from cart.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found in cart.\n");
    }
}
// Function to add product to cart
void addToCartFlow() {
    int productId, quantity;
    
    // Display products to the user
    printf("\n--- Product Catalog ---\n");
    printf("ID\tName\t\tPrice\tStock\tCategory\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%-20s\t%.2f\t%d\t%s\n", 
               catalog[i].id, catalog[i].name, 
               catalog[i].price, catalog[i].stock, 
               catalog[i].category);
    }

    printf("\nEnter the product ID to add to the cart: ");
    scanf("%d", &productId);

    // Check if the product ID is valid
    int productIndex = -1;
    for (int i = 0; i < product_count; i++) {
        if (catalog[i].id == productId) {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1) {
        printf("Invalid product ID.\n");
        return;
    }

    // Prompt the user for the quantity
    printf("Enter the quantity you want to add: ");
    scanf("%d", &quantity);

    // Check if the requested quantity is available
    if (quantity > catalog[productIndex].stock) {
        printf("Not enough stock available. Only %d units are in stock.\n", catalog[productIndex].stock);
        return;
    }

    // Add the product to the cart
    addToCart(productId, quantity);
    
    printf("\nProduct added to your cart.\n");
}



// Function to display manager options
void managerMenu() {
    int option;
    while (1) {
        printf("\n--- Manager Menu ---\n");
        printf("1. View Products\n");
        printf("2. Add Product\n");
        printf("3. Remove Product\n");
        printf("4. Update Product\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                viewProducts();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                printf("Logging out.\n");
                return;  // Return to main menu
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

// Function to login manager
int loginManager() {
    char username[MAX_NAME_LEN], password[MAX_NAME_LEN];

    printf("\nManager Login\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, MANAGER_USERNAME) == 0 && strcmp(password, MANAGER_PASSWORD) == 0) {
        printf("Manager login successful!\n");
        return 1;  // Manager logged in
    }

    printf("Invalid manager credentials.\n");
    return 0;  // Login failed
}

// Main menu for customers
// Main menu for customers
void customerMenu() {
    int option;
    while (1) {
        printf("\n--- Customer Menu ---\n");
        printf("1. View Products\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Remove from Cart\n");
        printf("5. Checkout\n");
        printf("6. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                viewProducts();  // View products, stay in customer menu
                break;
            case 2:
                addToCartFlow();  // Add to cart flow (you should implement this function)
                break;
            case 3:
                viewCart();  // View cart
                break;
            case 4:
                removeFromCart();  // Remove from cart
                break;
            case 5:
                checkout();  // Checkout
                break;
            case 6:
                printf("Logging out.\n");
                return;  // Logout, return to main menu
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

// Function for user login
int loginUser() {
    char username[MAX_NAME_LEN], password[MAX_NAME_LEN];
    
    printf("\nUser Login\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("User login successful!\n");
            return i;  // Return the index of the logged-in user
        }
    }

    printf("Invalid user credentials.\n");
    return -1;  // Login failed
}

// Function for user sign-up
void signUpUser() {
    struct User newUser;

    printf("\nSign Up\n");
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    printf("Enter name: ");
    scanf(" %[^\n]%*c", newUser.name);  // To allow spaces in the name
    newUser.balance = 0.0f;  // Initialize with 0 balance

    // Add new user to the users list
    if (user_count < MAX_USERS) {
        users[user_count] = newUser;
        user_count++;
        saveUsersToFile();
        printf("User signed up successfully!\n");
    } else {
        printf("User limit reached. Cannot sign up more users.\n");
    }
}


// Main menu
void mainMenu() {
    int option;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Log in\n");
        printf("2. Sign Up\n");
        printf("3. Manager Login\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (loginUser() != -1) {
                    customerMenu();
                }
                break;
            case 2:
                signUpUser();
                break;
            case 3:
                if (loginManager()) {
                    managerMenu();
                }
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    // Load products and users from files
    loadProductsFromFile();
    loadUsersFromFile();

    // Show main menu4
    mainMenu();

    return 0;
}
