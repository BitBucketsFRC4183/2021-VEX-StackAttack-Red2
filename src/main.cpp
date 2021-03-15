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
// Motor8               motor         8               
// Motor3               motor         3               
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

// void intakeOn(bool enabled){
//   if (enabled){
//     Motor3.spin(forward);
//   }
// }

void intakeForward(){
  Motor8.spin(forward);
}

void intakeReverse(){
  Motor8.spin(reverse);
}

void climbUp(){
  Motor3.spin(forward);
}

void climbDown(){
  Motor3.spin(reverse);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  vex::controller::button intake1 = Controller1.ButtonR1;
  vex::controller::button intake2 = Controller1.ButtonR2;
  vex::controller::button climb1 = Controller1.ButtonL1;
  vex::controller::button climb2 = Controller1.ButtonL2;
  
  Drivetrain.setDriveVelocity(50,percent);
  Motor3.setVelocity(50,percent);
  Motor8.setVelocity(50,percent);

  Controller1.Axis3.changed(driveRobot);

  while (true){
    if (intake1.pressing()){
      intakeForward();
    }
    else if (intake2.pressing()){
      intakeReverse();
    }
    else{
      Motor8.stop();
    }

    if (climb1.pressing()){
      climbUp();
    }
    else if (climb2.pressing()){
      climbDown();
    }
    else{
      Motor3.stop();
    }
  }
}
