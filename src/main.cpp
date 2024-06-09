#include "Global.hpp"
#include "Handle.hpp"

int main(int argc, char *argv[]){
    try {
        int port = 8080;
        cout << "fuck" << endl;
        Handle* handle = new Handle(argv, port);
        handle->run();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const Server::Exception& e) {
        std::cerr << e.getMessage() << std::endl;
    }
}