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
// Drivetrain           drivetrain    10, 1           
// Motor3               motor         3               
// Motor8               motor         8               
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
  Motor3.spin(forward);
}

void intakeReverse(){
  Motor3.spin(reverse);
}

void climbUp(){
  Motor8.spin(forward);
}

void climbDown(){
  Motor8.spin(reverse);
}

void auton(){
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward, 10, inches);
  Drivetrain.driveFor(reverse, 10, inches);
}
// void testAutonManual(){
//   Brain.Screen.print("Starting Autonomous");

//   auton();
// }

void teleop(){
  Drivetrain.setDriveVelocity(50,percent);
  Motor3.setVelocity(50,percent);
  Motor8.setVelocity(50,percent);

  Controller1.Axis3.changed(driveRobot);

  
  vex::controller::button intake1 = Controller1.ButtonR1;
  vex::controller::button intake2 = Controller1.ButtonR2;
  vex::controller::button climb1 = Controller1.ButtonL1;
  vex::controller::button climb2 = Controller1.ButtonL2;

  while (true){
    if (intake1.pressing()){
      intakeForward();
    }
    else if (intake2.pressing()){
      intakeReverse();
    }
    else{
      Motor3.stop();
    }

    if (climb1.pressing()){
      climbUp();
    }
    else if (climb2.pressing()){
      climbDown();
    }
    else{
      Motor8.setStopping(hold);
    }
  }
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  auton();
  teleop();

  
  

}
