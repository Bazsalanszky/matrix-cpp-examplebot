#include <iostream>
#include <matrix/Client.h>
#include <json/json.h>

struct BasicEventListener : public Matrix::EventListener{
    BasicEventListener(Matrix::Client*c): Matrix::EventListener(c) {}
    virtual void onEvent(const Matrix::Event& event) {
        if(event.getType() == "m.room.message" && event.getContent()["body"].asString() == "!ping"){
            Json::Value msg_content;
            msg_content["msgtype"] = "m.type";
            msg_content["body"] = "pong!";
            client->send(event.getRoomId(),"m.room.message",msg_content);
        }
    }
};

int main(){
    Matrix::Logger logger;
    Matrix::Homeserver server(getenv("HOMESERVER_NAME"),getenv("HOMESERVER_URL"));
    Matrix::Client c(&server, getenv("ACCESS_TOKEN"));

    Matrix::EventListener* listener = new BasicEventListener(&c);
    c.addEventListener(listener);
    c.start_thread();
    delete listener;
    return 0;
}
