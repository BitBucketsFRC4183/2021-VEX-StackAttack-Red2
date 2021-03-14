/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Sajo                                             */
/*    Created:      Wed Mar 10 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void driveRobot() {
  if (Controller1.Axis3.position() == 0){
    Drivetrain.stop();
  }

  else if (Controller1.Axis3.position() > 0){
    Drivetrain.drive(forward);
  }
  else {
    Drivetrain.drive(reverse);
  }
}

void turnRobot(){
  if (Controller1.Axis1.position() > 0){
    Drivetrain.turn(right);
  }
  else {
    Drivetrain.turn(left);
  } 
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Drivetrain.setDriveVelocity(50,percent);

  Controller1.Axis3.changed(driveRobot);
}
