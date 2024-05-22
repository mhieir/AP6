#include "Global.hpp"
#include "Interface.hpp"

int main(int argc, char *argv[]){
    Interface* interface = new Interface(argv);
    interface->run();
}