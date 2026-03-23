#include <math.h>

// This is the "Dark Father" core distortion algorithm
float processDarkFather(float input, float gain) {
    // Increase the signal strength before clipping
    float boosted = input * gain;
    
    // Using a Hyperbolic Tangent (tanh) for that "Heavy" but smooth distortion
    return tanhf(boosted); 
}
