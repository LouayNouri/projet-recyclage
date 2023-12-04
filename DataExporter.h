#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class DataExporter
{
public:
    DataExporter(const QString &filename, const QStringList &data) : filename(filename), data(data) {}

    void exportData()
    {
        QFile file(filename);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);

            for (const QString &line : data)
            {
                stream << line << "\n";
            }

            file.close();

            QMessageBox::information(nullptr, "Export Successful", "Data exported successfully!");
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "Could not open file for writing");
        }
    }

private:
    QString filename;
    QStringList data;
};
