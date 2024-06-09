#include "Global.hpp"
#include "handlers.hpp"

int main(int argc, char *argv[]){
    try {
        int port = 8080;
        Handle handle;
        handle.setServer(port);
        handle.setUniversity(argv);
        handle.run();
    }
    catch (const std::invalid_argument& e) {
        cout << "eruisijgfr";
        std::cerr << e.what() << std::endl;
    }
    catch (const Server::Exception& e) {
        cout << "eruisijgfr";cout << "eruisijgfr";
        std::cerr << e.getMessage() << std::endl;
    }
}