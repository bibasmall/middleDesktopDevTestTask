#pragma once
#include "httpClient.h"


class TextStreamHttpClient final : public HttpClient
{
    Q_OBJECT
    
public:
    TextStreamHttpClient(QUrl);
    
public:
    void processResponse(QByteArray data) override;
};
