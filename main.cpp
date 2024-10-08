#include <iostream>
#include <string>

/*    template <typename To>
    bool TryConvertStr(std::string& from, To& to) {
        if (typeid(from) == typeid(std::string)) {
            if (typeid(to) == typeid(float)) {
                to = stof(from);
                return true;
            }

            if (typeid(to) == typeid(int)) {
                to = stoi(from);
                return true;
            }

            if (typeid(to) == typeid(long)) {
                to = stol(from);
                return true;
            }

            if (typeid(to) == typeid(long long)) {
                to = stoll(from);
                return true;
            }

            if (typeid(to) == typeid(double)) {
                to = stod(from);
                return true;
            }

            if (typeid(to) == typeid(long double)) {
                to = stold(from);
                return true;
            }

            return false;
        }*/

bool isOn = false;

template <typename... Words>
bool IsInputStringThis(const std::string line, Words... words) {  //after a long troublesome while I realised "const" in (const std::string line, Words... words) is needed
    return ((line == words) || ...);
}


int main()
{   
    
    bool isfinished = false;
    std::string inputLine;


    std::cout << "Enter 'exit' to exit" << std::endl;
    while (isfinished == false) {
        std::cout << "type 'off' to turn switch off, 'on' to turn switch on: ";
        std::getline(std::cin, inputLine);
        bool wasRead = false;
        if (IsInputStringThis<std::string>(inputLine, "On", "on", "oN", "ON") == true) {                  //Bag Of words          
            if (isOn == true) {
                std::cout << "already turned on" << std::endl;
            }
            if (isOn == false) {
                std::cout << "turned on" << std::endl;
            }
            isOn = true;
            wasRead = true;
        }

        if (IsInputStringThis<std::string>(inputLine, "off", "OFF", "oFF", "Off", "oFf") == true) {
            if (isOn == true) {
                std::cout << "turned off" << std::endl;
            }
            if (isOn == false) {
                std::cout << "Already turned off" << std::endl;
            }
           
            wasRead = true;
        }

        if (wasRead == false) {
            std::cout << "You did not give a valid response. Please enter off or on." << std::endl;
        }
        if (IsInputStringThis(inputLine,"exit")) {
            system("cls");
            isfinished = true;
        }



    }
      //using std::cout in not using namespace std;

    

}
