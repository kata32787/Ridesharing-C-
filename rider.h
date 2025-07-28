#ifndef RIDER_H
#define RIDER_H

#include "Ride.h"
#include <vector>

class Rider {
private:
    int riderID;
    string name;
    vector<Ride*> requestedRides;  // Encapsulation

public:
    Rider(int id, string n) : riderID(id), name(n) {}

    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() {
        cout << "\nRider ID: " << riderID << ", Name: " << name << endl;
        cout << "Requested Rides:\n";
        for (auto ride : requestedRides) {
            ride->rideDetails();
            cout << endl;
        }
    }
};

#endif
