#ifndef RIDE_H
#define RIDE_H

#include <iostream>
#include <string>
using namespace std;

// Base Class: Ride
class Ride {
protected:
    int rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;

public:
    Ride(int id, string pickup, string dropoff, double dist)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {}

    // Virtual methods for polymorphism
    virtual double fare() = 0;
    virtual void rideDetails() {
        cout << "Ride ID: " << rideID
             << ", Pickup: " << pickupLocation
             << ", Dropoff: " << dropoffLocation
             << ", Distance: " << distance << " miles" << endl;
    }

    virtual ~Ride() {}
};

// StandardRide subclass
class StandardRide : public Ride {
public:
    StandardRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() override {
        return distance * 1.5;  // Example: $1.5 per mile
    }

    void rideDetails() override {
        Ride::rideDetails();
        cout << "Ride Type: Standard, Fare: $" << fare() << endl;
    }
};

// PremiumRide subclass
class PremiumRide : public Ride {
public:
    PremiumRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() override {
        return distance * 2.5;  // Example: $2.5 per mile
    }

    void rideDetails() override {
        Ride::rideDetails();
        cout << "Ride Type: Premium, Fare: $" << fare() << endl;
    }
};

#endif
