#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include "textStreamHttpClient.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TextStreamHttpClient http{QUrl("https://reqbin.com")};
    
    http.sendRequest(QUrl("/echo/get/json"));
    
    http.sendRequest(TextStreamHttpClient::HttpRequest{QUrl("/echo/get/json"),
                                                   TextStreamHttpClient::RequestType::GET,
                                                   {},
                                                   "",
                                                   "",
                                                   "usr",
                                                   "pass"});
    
    http.sendRequest(TextStreamHttpClient::HttpRequest{QUrl("/echo/post/json"),
                                                   TextStreamHttpClient::RequestType::POST,
                                                   {},
                                                   "",
                                                   "",
                                                   "usr",
                                                   "pass"});
    
    http.sendRequest(TextStreamHttpClient::HttpRequest{QUrl("/echo/post/json"),
                                                   TextStreamHttpClient::RequestType::POST,
                                                   {{"Content-Type", "text/plain"}},
                                                   "Plain text content",
                                                   "",
                                                   "",
                                                   ""});
    
    QJsonObject json;
    json.insert("id", 0);
    json.insert("name", "Bibasmall");
    json.insert("age", "27");
    QJsonDocument doc(json);
    
    http.sendRequest(TextStreamHttpClient::HttpRequest{QUrl("/echo/post/json"),
                                                   TextStreamHttpClient::RequestType::POST,
                                                   {{"Content-Type", "application/json"}},
                                                   doc.toJson(),
                                                   "",
                                                   "",
                                                   ""});
    
    return a.exec();
}
