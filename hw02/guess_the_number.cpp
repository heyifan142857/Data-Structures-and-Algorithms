#include <iostream>
#include <string>

int main() {
    unsigned long long low = 0, high = 18446744073709551615; 
    unsigned long long mid;
    std::string response;

    for (int i = 0; i < 75; ++i) { 
        mid = low + (high - low) / 2; 
        std::cout << mid << std::endl; 
        std::cin >> response; 

        if (response == "Correct") {
            return 0; 
        } else if (response == "TooBig") {
            high = mid - 1; 
        } else if (response == "TooSmall") {
            low = mid + 1; 
        } else if (response == "GameOver") {
            return 0; 
        }
    }

    
    return 0;
}