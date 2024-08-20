#include <iostream>


struct Player{
    std::string name;  // The name of the player.
    int health;        // The current health of the player.
    int xp;            // Experience points gained by the player. Could be used for leveling up or other game mechanics.
    std::string inventory[10];  // An array of strings for the player's inventory.
    int inventoryCount = 0;
};

int main()
{
    std::cout << "Welcome to the Dragon Realm!" << std::endl;

    // Create an instance of the Player struct
    Player player;
    player.health = 100; // Assign a default value for HP

    // Prompt the user to enter their player name
    std::cout << "Please enter your name: ";
    std::cin >> player.name;

    // Display a personalized welcome message to the player with their name
    std::cout << "Welcome " << player.name << " to The Dragon Realm!" << std::endl;

    // Declare an int variable to capture the user's choice
    int choice;
    // Declare an int variable to capture the user's nested choice
    int nestedChoice;

    
    bool exploring = true;
    while(exploring) {

    
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "Where will " << player.name << " go next?" << std::endl;
        std::cout << "1. Moonlight Markets" << std::endl;
        std::cout << "2. Grand Library" << std::endl;
        std::cout << "3. Shimmering Lake" << std::endl;
        std::cout << "Please enter your choice: ";

        std::cin >> choice;
  
        switch(choice) {
            //  Handle the Moonlight Markets scenario
            case 1:
                std::cout << "You chose Moonlight Markets." << std::endl;
                break;
            // Handle the Grand Library scenario.
            case 2:
                std::cout << "You chose Grand Library." << std::endl;
                break;
            // Handle the Shimmering Lake scenario.
            case 3:
                std::cout << player.name << " arrives at Shimmering Lake. It is one of the most beautiful lakes that" << player.name << " has seen. They hear a mysterious melody from the water. They can either: " << std::endl;
                std::cout << "1. Stay quiet and listen" << std::endl;
                std::cout << "2. Sing along with the melody" << std::endl;
                std::cout << "Please enter your choice: ";

                // Capture the user's nested choice
                std::cin >> nestedChoice;

                // If the player chooses to remain silent
                if (nestedChoice == 1)
                {
                    std::cout << "Remaining silent, " << player.name << " hears whispers of the merfolk below, but nothing happens." << std::endl;
                }
                // If the player chooses to sing along with the melody
                else if (nestedChoice == 2)
                {
                    std::cout << "Singing along, a merfolk surfaces and gifts " << player.name
                            << " a special blue gem as a token of appreciation for their voice."
                            << std::endl;
                    player.inventory[player.inventoryCount] = "Blue Gem";
                    player.inventoryCount++;

                    std::cout << player.name << "'s Inventory:" << std::endl;
                    // Loop through the player's inventory up to the count of items they have
                    for (int i = 0; i < player.inventoryCount; i++)
                    {
                        // Check if the inventory slot is not empty.
                        if (!player.inventory[i].empty())
                        {
                            // Output the item in the inventory slot
                            std::cout << "- " << player.inventory[i] << std::endl;
                        }
                    }

                }
                break;
            
            case 4:
                exploring = false;
                break;
            default:
                std::cout << "You did not enter a valid choice." << std::endl;
                continue;
        }
    }

    return 0;
}