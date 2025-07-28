#ifndef DRIVER_H
#define DRIVER_H

#include "Ride.h"
#include <vector>

class Driver {
private:
    int driverID;
    string name;
    double rating;
    vector<Ride*> assignedRides;  // Encapsulation

public:
    Driver(int id, string n, double r) : driverID(id), name(n), rating(r) {}

    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }

    void getDriverInfo() {
        cout << "\nDriver ID: " << driverID << ", Name: " << name
             << ", Rating: " << rating << endl;
        cout << "Completed Rides:\n";
        for (auto ride : assignedRides) {
            ride->rideDetails();
            cout << endl;
        }
    }
};

#endif
