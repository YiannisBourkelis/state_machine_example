#include <iostream>

using namespace std;

enum class State
{
    READING_CARD,
    READING_PIN,
    CHOOSING_SERVICE,
    SELECTING_WITHDRAW_AMOUNT,
    DISPLAY_BALANCE,
    REMOVE_CARD,
};

State current_state = State::READING_CARD;

bool process_state()
{
    std::string user_input = "";

    switch (current_state) {
        case State::READING_CARD:
            std::cout << "Insert your card" << std::endl;
            std::cin >> user_input;
            current_state = State::READING_PIN;
        break;

        case State::READING_PIN:
            std::cout << "Please enter your PIN" << std::endl;
            std::cin >> user_input;
            current_state = State::CHOOSING_SERVICE;
        break;

        case State::CHOOSING_SERVICE:
            std::cout << "Please select service required" << std::endl;
            std::cout << "1. Withdraw cash" << std::endl;
            std::cout << "2. Display balance" << std::endl;
            std::cin >> user_input;
            if (user_input == "1"){
                current_state = State::SELECTING_WITHDRAW_AMOUNT;
            }
            else if (user_input == "2"){
                current_state = State::DISPLAY_BALANCE;
            }
        break;

        case State::SELECTING_WITHDRAW_AMOUNT:
            std::cout << "Please select amount required" << std::endl;
            std::cout << "1. 20" << std::endl;
            std::cout << "2. 50" << std::endl;
            std::cout << "3. Other amount" << std::endl;
            std::cin >> user_input;
            std::cout << "Your cash is being counted..." << std::endl;
            std::cout << "Please remove your money" << std::endl;
            current_state = State::REMOVE_CARD;

        break;

        case State::DISPLAY_BALANCE:
            std::cout << "Your available balance is 1.000.000" << std::endl;
            std::cout << "Wish another transaction? (y/n)" << std::endl;
            std::cin >> user_input;
            if (user_input == "y"){
                current_state = State::CHOOSING_SERVICE;
            }
            else if (user_input == "n") {
                current_state = State::REMOVE_CARD;
            }
        break;

        case State::REMOVE_CARD:
            std::cout << "Please remove your card" << std::endl;
            std::cout << "Thank you for using our bank" << std::endl;
            current_state = State::READING_CARD;
        break;
    }

    return true;
}

int main()
{
    while (process_state()) {

    }
    return 0;
}
