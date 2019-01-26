/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Auto1.h"

#include "Robot.h"
#include "commands/AutoDrive.h"
#include "commands/AutoTurn.h"

Auto1::Auto1() {
  AddSequential(new AutoDrive());
  AddSequential(new AutoTurn());
  AddSequential(new AutoDrive());
  // Use Requires() here to declare subsystem dependencies
}
