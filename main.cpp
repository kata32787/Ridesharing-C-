#include "Ride.h"
#include "Driver.h"
#include "Rider.h"
#include <vector>

int main() {
    // Create some rides
    StandardRide stdRide(101, "Downtown", "Mall", 10);
    PremiumRide premRide(102, "Airport", "Hotel", 15);

    // Store rides polymorphically
    vector<Ride*> rides = { &stdRide, &premRide };

    cout << "=== Ride Details ===\n";
    for (Ride* ride : rides) {
        ride->rideDetails();
        cout << endl;
    }

    // Create a Driver and assign rides
    Driver driver1(201, "Alice", 4.8);
    driver1.addRide(&stdRide);
    driver1.addRide(&premRide);
    driver1.getDriverInfo();

    // Create a Rider and request rides
    Rider rider1(301, "Bob");
    rider1.requestRide(&stdRide);
    rider1.requestRide(&premRide);
    rider1.viewRides();

    return 0;
}
