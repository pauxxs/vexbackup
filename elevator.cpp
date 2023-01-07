#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
motor MotorGroup2MotorA = motor(PORT2, ratio18_1, false);
motor MotorGroup2MotorB = motor(PORT3, ratio18_1, true);
motor_group MotorGroup2 = motor_group(MotorGroup2MotorA, MotorGroup2MotorB);

controller Controller1 = controller(primary);



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {author}                                                  */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

void m_up() {
  if (MotorGroup2.position(degrees) <= 0)
    {
    MotorGroup2.spinFor(forward, 180, degrees);
    }
}

void m_back() {
  MotorGroup2.spinToPosition(-0.8, degrees);
}

int main() {
  MotorGroup2.setPosition(0, degrees);
  int loop = true;
  while (loop) {
    // Brain.Screen.print(MotorGroup2.position(degrees));
    // Brain.Screen.newLine();

    Controller1.ButtonL2.pressed(m_up);
    Controller1.ButtonR2.pressed(m_back);
  }
}
