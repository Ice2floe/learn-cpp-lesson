#include <iostream>
#include <cmath> // for square root

// Function to get the height of the tower from the user
double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin >> towerHeight;
    return towerHeight;
}

// Function to get the initial velocity of the ball from the user
double getStartSpeedBall()
{
    std::cout << "Enter the initial velocity of the ball (if the velocity is negative, then the ball is thrown up): ";
    double startSpeedBall{};
    std::cin >> startSpeedBall;
    return startSpeedBall;
}

// Function to get the coefficient of restitution (recovery rate) from the user
double getRecoveryRateBall()
{
    std::cout << "Enter the coefficient for restoring the speed of the ball (from zero to one): ";
    double recoveryRateBall{};
    std::cin >> recoveryRateBall;
    return recoveryRateBall;
}

// Function to calculate the speed of the ball just before it hits the ground
double calculateSpeedBeforeImpact(double towerHeight, double startSpeedBall)
{
    const double gravity{9.8};
    if (startSpeedBall < 0.0)
    {
        // If the ball is thrown upward, calculate the maximum height and then the speed before impact
        double maxBallHeight{towerHeight + ((startSpeedBall * startSpeedBall) / (2.0 * gravity))};
        return std::sqrt(2 * gravity * maxBallHeight);
    }
    else
    {
        // If the ball is thrown downward, calculate the speed before impact directly
        return std::sqrt((startSpeedBall * startSpeedBall) + (2.0 * gravity * towerHeight));
    }
}

// Function to calculate the height of the ball after a bounce
double calculateBallHeightBounce(double speedBeforeImpact, double recoveryRateBall)
{
    const double gravity{9.8};
    // Calculate the speed after the bounce
    double speedAfterBounce{recoveryRateBall * speedBeforeImpact};
    // Calculate the height after the bounce
    return (speedAfterBounce * speedAfterBounce) / (2.0 * gravity);
}

// Function to print the height of the ball after a bounce
void printBallHeightBounce(double ballHeightBounce, int bounce)
{
    if (ballHeightBounce > 0.0)
        std::cout << "At " << bounce << " bounce, the ball is at the height: " << ballHeightBounce << " meters.\n";
    else
        std::cout << "At " << bounce << " bounce, the ball is on the ground.\n";
}

int main()
{
    // Get the height of the tower from the user
    double towerHeight{getTowerHeight()};

    // Get the initial velocity of the ball from the user
    double startSpeedBall{getStartSpeedBall()};

    // Get the coefficient of restitution (recovery rate) from the user
    double recoveryRateBall{getRecoveryRateBall()};

    // Calculate the speed of the ball just before the first impact
    double speedBeforeImpact{calculateSpeedBeforeImpact(towerHeight, startSpeedBall)};

    // Calculate and print the height after each bounce (1 to 5)
    for (int bounce = 1; bounce <= 5; ++bounce)
    {
        // Calculate the height after the bounce
        double ballHeightBounce{calculateBallHeightBounce(speedBeforeImpact, recoveryRateBall)};

        // Print the height after the bounce
        printBallHeightBounce(ballHeightBounce, bounce);

        // Update the speed before the next impact
        speedBeforeImpact *= recoveryRateBall;
    }

    return 0;
}
