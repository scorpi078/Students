#include <stdio.h>
#include <math.h>

// Дефиниция на структура за артикул
struct Product {
    char name[50];
    int quantity;
    float price;
};

// Дефиниция на изброим тип
enum Category {
    ELECTRONICS,
    CLOTHING,
    FOOD,
};

// Дефиниция на константа
#define MAX_PRODUCTS 100

// Дефиниция на функция за запис на данни във файл
void saveToFile(struct Product *inventory, int count) {
    FILE *file = fopen("inventory.txt", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Product %d:\n", i + 1);
        fprintf(file, "Name: %s\n", inventory[i].name);
        fprintf(file, "Quantity: %d\n", inventory[i].quantity);
        fprintf(file, "Price: %.2f\n", inventory[i].price);
        fprintf(file, "------------------------\n");
    }

    fclose(file);
}

// Дефиниция на функция за добавяне на нов запис
void addProduct(struct Product *inventory, int *count) {
    printf("Enter product name: ");
    scanf("%s", inventory[*count].name);

    printf("Enter quantity: ");
    scanf("%d", &inventory[*count].quantity);

    printf("Enter price: ");
    scanf("%f", &inventory[*count].price);

    (*count)++;
}

// Дефиниция на функция за триене на запис
void deleteProduct(struct Product *inventory, int *count) {
    int index;
    printf("Enter the index of the product to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < *count) {
        // Премахване на продукта и преместване на останалите записи
        for (int i = index; i < *count - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*count)--;
        printf("Product deleted successfully.\n");
    } else {
        printf("Invalid index.\n");
    }
}

// Дефиниция на функция за изкарване на записи на конзолата
void displayInventory(struct Product *inventory, int count) {
    printf("\nInventory:\n");
    for (int i = 0; i < count; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("------------------------\n");
    }
}

int main() {
    // Дефиниция на променливи
    struct Product inventory[MAX_PRODUCTS];  // Масив от продукти
    int itemCount = 0;  // Брой налични продукти

    int choice;

    do {
        // Избор на операция от потребителя
        printf("\n1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Display Inventory\n");
        printf("4. Save to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &itemCount);
                break;
            case 2:
                deleteProduct(inventory, &itemCount);
                break;
            case 3:
                displayInventory(inventory, itemCount);
                break;
            case 4:
                saveToFile(inventory, itemCount);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
