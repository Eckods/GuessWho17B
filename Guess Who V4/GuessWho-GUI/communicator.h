#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QThread>
#include <QString>
#include <iostream>

using namespace std;

class Communicator : public QThread
{
    Q_OBJECT

public:
    Communicator();
    ~Communicator();

    void run();

};
#endif // COMMUNICATOR_H
