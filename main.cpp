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
/*vex-vision-config:begin*/
vision::signature Vision2__V_DISK = vision::signature (1, 1853, 2311, 2082,-4505, -4095, -4300,2.6, 0);
vision::signature Vision2__SIG_2 = vision::signature (2, 0, 0, 0,0, 0, 0,3, 0);
vision::signature Vision2__SIG_3 = vision::signature (3, 0, 0, 0,0, 0, 0,3, 0);
vision::signature Vision2__SIG_4 = vision::signature (4, 0, 0, 0,0, 0, 0,3, 0);
vision::signature Vision2__SIG_5 = vision::signature (5, 0, 0, 0,0, 0, 0,3, 0);
vision::signature Vision2__SIG_6 = vision::signature (6, 0, 0, 0,0, 0, 0,3, 0);
vision::signature Vision2__SIG_7 = vision::signature (7, 0, 0, 0,0, 0, 0,3, 0);
vision Vision2 = vision (PORT2, 19, Vision2__V_DISK, Vision2__SIG_2, Vision2__SIG_3, Vision2__SIG_4, Vision2__SIG_5, Vision2__SIG_6, Vision2__SIG_7);
/*vex-vision-config:end*/
motor LeftDriveSmart = motor(PORT9, ratio18_1, true);
motor RightDriveSmart = motor(PORT8, ratio18_1, false);
inertial DrivetrainInertial = inertial(PORT20);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 40, mm, 1);

distance Distance11 = distance(PORT11);
motor Motor1 = motor(PORT1, ratio18_1, false);

limit LimitSwitchA = limit(Brain.ThreeWirePort.A);
line LineTrackerC = line(Brain.ThreeWirePort.C);
bumper BumperH = bumper(Brain.ThreeWirePort.H);

void calibrateDrivetrain() {
  wait(200, msec);
  Brain.Screen.print("Calibrating");
  Brain.Screen.newLine();
  Brain.Screen.print("Inertial");
  DrivetrainInertial.calibrate();
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }

  // Clears the screen and returns the cursor to row 1, column 1.
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
}
#pragma endregion VEXcode Generated Robot Configuration

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

void colorSeg() {
  Drivetrain.setDriveVelocity(30, percent);
  
    if (Vision2.takeSnapshot(Vision2__V_DISK) > 0) {
      if (Vision2.largestObject.centerX < 160 && Vision2.largestObject.centerX > 140) {
        Drivetrain.drive(forward);
      }

      else if (Vision2.largestObject.centerX > 160) {
        Drivetrain.turn(left);

        if (Vision2.largestObject.centerX < 160) {
          Drivetrain.stop();
        }
      }

      else if (Vision2.largestObject.centerX < 140) {
        Drivetrain.turn(right);
        
        if (Vision2.largestObject.centerX > 140) {
          Drivetrain.stop();
        }
      }
    }

    else {
      Drivetrain.stop();
    }
}

void distanceSeg() {
  if (Distance11.isObjectDetected() &&
    Distance11.objectDistance(inches) < 10) {
    Motor1.stop();
    // Brain.Screen.print(
    //   Distance11.objectDistance(inches)
    // );
    // Brain.Screen.newLine();
  }

  else {
    Motor1.spin(forward);
  }
}

void limitSwitchSeg() {
  if (LimitSwitchA.pressing())  {
    // Brain.Screen.print("pressed");
  }
}

void lineTrackerSeg() {
  // Brain.Screen.print(LineTrackerC.reflectivity() * 0.01);
  // Brain.Screen.newLine();
}

void bumperSeg() {
  if (BumperH.pressing()) {
    // Brain.Screen.clearLine();
    // Brain.Screen.print("Pressing");
    // Brain.Screen.newLine();
  }
}

void mainLoop() {
  bool loop = true;
  while (loop) {
    colorSeg();
    distanceSeg();
    limitSwitchSeg();
    lineTrackerSeg();
    bumperSeg();
  }
}

int main() {
  // post event registration
  printf("hello");
  wait(30, msec);

  thread workMain = thread(mainLoop);
  // thread timeMain = thread(timerSeg); 

  // On right: CX = 242, CY = 139
  // On left: CX = 55, CY = 143

  return 0;
}
