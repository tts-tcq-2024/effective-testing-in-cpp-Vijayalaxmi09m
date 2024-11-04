// alerter_test.cpp
#include "alerter.h"

void testAlertInCelcius() {
    alertFailureCount = 0;  // Reset count for testing
    
    // Test case 1: Very high temperature that should trigger an alert
    alertInCelcius(400.5);
    assert(alertFailureCount == 1 && "Expected failure count to be 1 for high temperature alert");

    // Test case 2: Another high temperature, expect failure count to increase
    alertInCelcius(303.6);
    assert(alertFailureCount == 2 && "Expected failure count to be 2 for multiple high temperature alerts");

    // Test case 3: Low temperature that should not trigger an alert
    alertInCelcius(32.0); // Normal freezing point in Fahrenheit
    assert(alertFailureCount == 2 && "Expected failure count to remain 2 for low temperature");

    // Test case 4: Test at the threshold value for alerting (assuming 303.6 is alert threshold)
    alertInCelcius(303.5); // Just below threshold, should not increment
    assert(alertFailureCount == 2 && "Expected failure count to remain 2 for threshold temperature");

    // Test case 5: Negative temperature (very low, should not trigger an alert)
    alertInCelcius(-40.0); // -40°F should not trigger an alert
    assert(alertFailureCount == 2 && "Expected failure count to remain 2 for very low temperature");

    // Test case 6: Boundary case just below the alert threshold
    alertInCelcius(303.4); // Should not increment alertFailureCount
    assert(alertFailureCount == 2 && "Expected failure count to remain 2 for boundary case below threshold");

    // Test case 7: Extremely high temperature (e.g., absolute extreme)
    alertInCelcius(1000.0); // Should trigger alert
    assert(alertFailureCount == 3 && "Expected failure count to be 3 for extremely high temperature alert");

    // Test case 8: Extreme low, non-triggering value
    alertInCelcius(-100.0); // Should not trigger alert
    assert(alertFailureCount == 3 && "Expected failure count to remain 3 for extreme low temperature");

    std::cout << "All alerter test cases completed (some may intentionally fail to reveal bugs).\n";
}

int main() {
    testAlertInCelcius();
    std::cout << "Alerter tests complete.\n";
    return 0;
}
