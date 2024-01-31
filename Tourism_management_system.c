#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Location {
    char id[20];
    char name[100];
    char description[500];
    struct Location* next;
}Location;
typedef struct Package {
    char id[20];
    char name[100];
    float price;
    int available;
    struct Package* next;
}Package;
typedef struct Guide {
    char id[20];
    char name[100];
    char language[50];
    int available;
    struct Guide* next;
}Guide;
typedef struct Booking {
    char id[20];
    char name[100];
    float price;
    struct Booking* next;
}Booking;
#define ADMIN_PASSWORD "admin"
#define USER_PASSWORD "user"
Location* locationList = NULL;
Package* packageList = NULL;
Guide* guideList = NULL;
Booking* bookingList = NULL;
void adminMode();
void userMode();
void addLocation();
void addPackage();
void addGuide();
void deleteLocation();
void deletePackage();
void deleteGuide();
void findLocations();
void findPackages();
void findGuides();
void searchLocation();
void searchPackages();
void searchGuides();
void bookPackage();
void bookGuide();
void saveData();
void loadData();
void displayMainMenu();
void displayAdminMenu();
void displayUserMenu();
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
int main() {

    system("color 3f");
    loadData();
    int choice;
    char password[50];
    printf("\n\n\n\t\t\t\t\t\****Tourism Management System****\n\n\n");
    do {
        displayMainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                clearScreen();
                printf("Enter admin password: ");
                scanf("%s", password);
                if (strcmp(password, ADMIN_PASSWORD) == 0) {
                    clearScreen();
                    adminMode();
                } else {
                    printf("Invalid password. Access denied.\n");
                }
                break;
            case 2:
                clearScreen();
                printf("Enter user password: ");
                scanf("%s", password);
                if (strcmp(password, USER_PASSWORD) == 0) {
                    clearScreen();
                    userMode();
                } else {
                    printf("Invalid password. Access denied.\n");
                }
                break;
            case 3:
                saveData();
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}
void displayMainMenu() {
    printf("\nMain Menu\n");
    printf("1. Admin Mode\n");
    printf("2. User Mode\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}
void adminMode() {
    int choice;
    do {
        displayAdminMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clearScreen();
                addLocation();
                break;
            case 2:
                clearScreen();
                addPackage();
                break;
            case 3:
                clearScreen();
                addGuide();
                break;
            case 4:
                clearScreen();
                deleteLocation();
                break;
            case 5:
                clearScreen();
                deletePackage();
                break;
            case 6:
                clearScreen();
                deleteGuide();
                break;
            case 7:
                clearScreen();
                saveData();
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}
void displayAdminMenu() {
    printf("\n\n\n\t\t\t\t\t\****Tourism Management System****\n\n\n");
    printf("\nAdmin Mode\n");
    printf("1. Add Locations\n");
    printf("2. Add Packages\n");
    printf("3. Add Guides\n");
    printf("4. Delete Locations\n");
    printf("5. Delete Packages\n");
    printf("6. Delete Guides\n");
    printf("7. Save and Exit\n");
    printf("Enter your choice: ");
}

void userMode() {
    int choice;
    do {
        displayUserMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clearScreen();
                findLocations();
                break;
            case 2:
                clearScreen();
                findPackages();
                break;
            case 3:
                clearScreen();
                findGuides();
                break;
            case 4:
                clearScreen();
                searchLocation();
                break;
            case 5:
                clearScreen();
                searchPackages();
                break;
            case 6:
                clearScreen();
                searchGuides();
                break;
            case 7:
                clearScreen();
                bookPackage();
                break;
            case 8:
                clearScreen();
                bookGuide();
                break;
            case 9:
                clearScreen();
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}

void displayUserMenu() {
    printf("\t\t\t\t\t****Tourism Management System****\n\n");
    printf("\nUser Mode\n");
    printf("1. Find Locations\n");
    printf("2. Available Packages\n");
    printf("3. Available Guides\n");
    printf("4. Search Location\n");
    printf("5. Search Packages\n");
    printf("6. Search Guides\n");
    printf("7. Book Package\n");
    printf("8. Book Guide\n");
    printf("9. Main Menu\n");
    printf("Enter your choice: ");
}
//for adding location
void addLocation() {
    Location* newLocation = (Location*)malloc(sizeof(Location));
    if (newLocation == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter location ID: ");
    scanf("%s", newLocation->id);
    printf("Enter location name: ");
    scanf("%s", newLocation->name);
    printf("Enter location description: ");
    scanf("%s", newLocation->description);
    newLocation->next = locationList;
    locationList = newLocation;
    printf("Location added successfully!\n");
}
//for adding packages
void addPackage() {
    Package* newPackage = (Package*)malloc(sizeof(Package));
    if (newPackage == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter package ID: ");
    scanf("%s", newPackage->id);
    printf("Enter package name: ");
    scanf("%s", newPackage->name);
    printf("Enter package price: ");
    scanf("%f", &newPackage->price);
    newPackage->available = 1;
    newPackage->next = packageList;
    packageList = newPackage;
    printf("Package added successfully!\n");
}
//for adding guides
void addGuide() {
    Guide* newGuide = (Guide*)malloc(sizeof(Guide));
    if (newGuide == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter guide ID: ");
    scanf("%s", newGuide->id);
    printf("Enter guide name: ");
    scanf("%s", newGuide->name);
    printf("Enter guide language: ");
    scanf("%s", newGuide->language);
    newGuide->available = 1;
    newGuide->next = guideList;
    guideList = newGuide;
    printf("Guide added successfully!\n");
}
//for deleting any package
void deleteLocation() {
    char locationId[20];
    printf("Enter location ID to delete: ");
    scanf("%s", locationId);
    Location* current = locationList;
    Location* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->id, locationId) == 0) {
            if (prev == NULL) {
                locationList = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Location deleted successfully!\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Location not found.\n");
}
//for deleting any package
void deletePackage() {
    char packageId[20];
    printf("Enter package ID to delete: ");
    scanf("%s", packageId);

    Package* current = packageList;
    Package* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->id, packageId) == 0) {
            if (prev == NULL) {
                packageList = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Package deleted successfully!\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Package not found.\n");
}
//for deleting any guides
void deleteGuide() {
    char guideId[20];
    printf("Enter guide ID to delete: ");
    scanf("%s", guideId);

    Guide* current = guideList;
    Guide* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->id, guideId) == 0) {
            if (prev == NULL) {
                guideList = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Guide deleted successfully!\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Guide not found.\n");
}
//available locations
void findLocations() {
    printf("List of Locations:\n");
    Location* current = locationList;
    while (current != NULL) {
        printf("Location ID: %s\n", current->id);
        printf("Location Name: %s\n", current->name);
        printf("Location Description: %s\n", current->description);
        printf("\n");
        current = current->next;
    }
}
//available packages
void findPackages() {
    printf("List of Packages:\n");
    Package* current = packageList;

    while (current != NULL) {
        printf("Package ID: %s\n", current->id);
        printf("Package Name: %s\n", current->name);
        printf("Package Price: %.2f\n", current->price);
        printf("Availability: %s\n", current->available ? "Available" : "Not Available");
        printf("\n");

        current = current->next;
    }
}
//available guides
void findGuides() {
    printf("List of Guides:\n");
    Guide* current = guideList;

    while (current != NULL) {
        printf("Guide ID: %s\n", current->id);
        printf("Guide Name: %s\n", current->name);
        printf("Guide Language: %s\n", current->language);
        printf("Availability: %s\n", current->available ? "Available" : "Not Available");
        printf("\n");
        current = current->next;
    }
}
//search by location
void searchLocation() {
    char locationId[20];
    printf("Enter location ID to search: ");
    scanf("%s", locationId);
    Location* current = locationList;
    while (current != NULL) {
        if (strcmp(current->id, locationId) == 0) {
            printf("Location ID: %s\n", current->id);
            printf("Location Name: %s\n", current->name);
            printf("Location Description: %s\n", current->description);
            return;
        }
        current = current->next;
    }
    printf("Location not found.\n");
}
//search package
void searchPackages() {
    char packageId[20];
    printf("Enter package ID to search: ");
    scanf("%s", packageId);
    Package* current = packageList;
    while (current != NULL) {
        if (strcmp(current->id, packageId) == 0) {
            printf("Package ID: %s\n", current->id);
            printf("Package Name: %s\n", current->name);
            printf("Package Price: %.2f\n", current->price);
            printf("Availability: %s\n", current->available ? "Available" : "Not Available");
            return;
        }
        current = current->next;
    }
    printf("Package not found.\n");
}
//search guides
void searchGuides() {
    char guideId[20];
    printf("Enter guide ID to search: ");
    scanf("%s", guideId);

    Guide* current = guideList;
    while (current != NULL) {
        if (strcmp(current->id, guideId) == 0) {
            printf("Guide ID: %s\n", current->id);
            printf("Guide Name: %s\n", current->name);
            printf("Guide Language: %s\n", current->language);
            printf("Availability: %s\n", current->available ? "Available" : "Not Available");
            return;
        }
        current = current->next;
    }
    printf("Guide not found.\n");
}
//book package
void bookPackage() {
    char packageId[20];
    printf("Enter package ID to book: ");
    scanf("%s", packageId);
    Package* current = packageList;
    while (current != NULL) {
        if (strcmp(current->id, packageId) == 0) {
            if (current->available){
                Booking* newBooking = (Booking*)malloc(sizeof(Booking));
                strcpy(newBooking->id, current->id);
                strcpy(newBooking->name, current->name);
                newBooking->price = current->price;
                newBooking->next = bookingList;
                bookingList = newBooking;
                printf("Package booked successfully!\n");
                current->available = 0;
            } else {
                printf("Package is not available for booking.\n");
            }
            return;
        }
        current = current->next;
    }

    printf("Package not found.\n");
}
//book guides
void bookGuide() {
    char guideId[20];
    printf("Enter guide ID to book: ");
    scanf("%s", guideId);
    Guide* current = guideList;
    while (current != NULL) {
        if (strcmp(current->id, guideId) == 0) {
            if (current->available) {
                Booking* newBooking = (Booking*)malloc(sizeof(Booking));
                strcpy(newBooking->id, current->id);
                strcpy(newBooking->name, current->name);
                newBooking->price = 0;
                newBooking->next = bookingList;
                bookingList = newBooking;
                printf("Guide booked successfully!\n");
                current->available = 0;
            } else {
                printf("Guide is not available for booking.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("Guide not found.\n");
}

void saveData() {
    FILE* locationFile = fopen("locations.txt", "w");
    FILE* packageFile = fopen("packages.txt", "w");
    FILE* guideFile = fopen("guides.txt", "w");
    FILE* bookingFile = fopen("bookings.txt", "w");
    if (locationFile == NULL || packageFile == NULL || guideFile == NULL || bookingFile == NULL) {
        printf("Error opening files\n");
        return;
    }
    Location* location = locationList;
    while (location != NULL) {
        fprintf(locationFile, "%s %s %s\n", location->id, location->name, location->description);
        location = location->next;
    }
    Package* package = packageList;
    while (package != NULL) {
        fprintf(packageFile, "%s %s %.2f %d\n", package->id, package->name, package->price, package->available);
        package = package->next;
    }
    Guide* guide = guideList;
    while (guide != NULL) {
        fprintf(guideFile, "%s %s %s %d\n", guide->id, guide->name, guide->language, guide->available);
        guide = guide->next;
    }
    Booking* booking = bookingList;
    while (booking != NULL) {
        fprintf(bookingFile, "%s %s %.2f\n", booking->id, booking->name, booking->price);
        booking = booking->next;
    }
    fclose(locationFile);
    fclose(packageFile);
    fclose(guideFile);
    fclose(bookingFile);
    printf("Data saved successfully.\n");
}
void loadData() {
    FILE* locationFile = fopen("locations.txt", "r");
    FILE* packageFile = fopen("packages.txt", "r");
    FILE* guideFile = fopen("guides.txt", "r");
    FILE* bookingFile = fopen("bookings.txt", "r");
    if (locationFile == NULL || packageFile == NULL || guideFile == NULL || bookingFile == NULL) {
        printf("Error opening files for reading.\n");
        return;
    }
    char id[20];
    char name[100];
    char description[500];
    float price;
    char language[50];
    int available;
    while (fscanf(locationFile, "%s %s %s", id, name, description) != EOF) {
        Location* newLocation = (Location*)malloc(sizeof(Location));
        strcpy(newLocation->id, id);
        strcpy(newLocation->name, name);
        strcpy(newLocation->description, description);
        newLocation->next = locationList;
        locationList = newLocation;
    }
    while (fscanf(packageFile, "%s %s %f %d", id, name, &price, &available) != EOF) {
        Package* newPackage = (Package*)malloc(sizeof(Package));
        strcpy(newPackage->id, id);
        strcpy(newPackage->name, name);
        newPackage->price = price;
        newPackage->available = available;
        newPackage->next = packageList;
        packageList = newPackage;
    }
    while (fscanf(guideFile, "%s %s %s %d", id, name, language, &available) != EOF) {
        Guide* newGuide = (Guide*)malloc(sizeof(Guide));
        strcpy(newGuide->id, id);
        strcpy(newGuide->name, name);
        strcpy(newGuide->language, language);
        newGuide->available = available;
        newGuide->next = guideList;
        guideList = newGuide;
    }
    while (fscanf(bookingFile, "%s %s %f", id, name, &price) != EOF) {
        Booking* newBooking = (Booking*)malloc(sizeof(Booking));
        strcpy(newBooking->id, id);
        strcpy(newBooking->name, name);
        newBooking->price = price;
        newBooking->next = bookingList;
        bookingList = newBooking;
    }
    fclose(locationFile);
    fclose(packageFile);
    fclose(guideFile);
    fclose(bookingFile);
}
