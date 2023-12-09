#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class connection
{
public:
    connection();
    bool createconnect();
    void closeconnection();

private:
    QSqlDatabase db;
};

#endif // CONNECTION_H
