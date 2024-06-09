#include "Handle.hpp"
#include "Primary.hpp"

#include "handlers.hpp"

void Handle::mapServerPaths() {
    server->setNotFoundErrPage("static/404.html");
    server->get("/", new ShowPage("static/home.html"));
    server->get("/home.png", new ShowImage("static/home.png"));
    server->get("/rand", new RandomNumberHandler());
    server->get("/login", new ShowPage("static/logincss.html"));
    server->post("/login", new LoginHandler());
    server->get("/up", new ShowPage("static/upload_form.html"));
    server->post("/up", new UploadHandler());
    server->get("/colors", new ColorHandler("template/colors.html"));
    server->get("/music", new ShowPage("static/music.html"));
    server->get("/music/moonlight.mp3", new ShowFile("static/moonlight.mp3", "audio/mpeg"));
}

Handle::Handle(char **argv, int port) {
    university = new University(argv);
    server = new Server(port);
    mapServerPaths();
    cout << SHOW_SERVER_PORT << port << endl;
}

void Handle::run() {
    server->run();
}