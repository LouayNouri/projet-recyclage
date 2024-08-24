#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QDebug>

class connection {
public:
    static connection& getInstance() {
        static connection instance; // Guaranteed to be destroyed and instantiated on first use.
        return instance;
    }

    bool createconnect() {
        if (db.isOpen()) {
            qDebug() << "Database already open.";
            return true;
        }

        db.setDatabaseName("Source_Projet2A");
        db.setUserName("ham");
        db.setPassword("ham6969");

        if (!db.open()) {
            qDebug() << "Database connection failed.";
            return false;
        }

        qDebug() << "Database connection succeeded.";
        return true;
    }

    void closeconnection() {
        if (db.isOpen()) {
            db.close();
            qDebug() << "Database connection closed.";
        }
    }

private:
    connection() {
        db = QSqlDatabase::addDatabase("QODBC");
    }
    ~connection() {
        closeconnection(); // Ensure connection is closed when the instance is destroyed.
    }

    connection(connection const&) = delete;
    void operator=(connection const&) = delete;

    QSqlDatabase db;
};

#endif // CONNECTION_H

