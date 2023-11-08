#pragma once
#include "httpClient.h"


class TextStreamHttpClient final : public HttpClient
{
    Q_OBJECT
    
public:
    static TextStreamHttpClient& instance(QUrl);
    void processResponse(QByteArray data) override;
    
private:
    TextStreamHttpClient(QUrl);
};
