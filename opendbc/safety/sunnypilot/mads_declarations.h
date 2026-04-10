/**
 * Copyright (c) 2021-, Haibin Wen, sunnypilot, and a number of other contributors.
 *
 * This file is part of sunnypilot and is licensed under the MIT License.
 * See the LICENSE.md file in the root directory for more details.
 *
 * This project uses software from Haibin Wen and SUNNYPILOT LLC and is
 * licensed under a custom license requiring permission for use.
 */

#pragma once

// ===============================
// Type Definitions and Enums
// ===============================

typedef enum __attribute__((packed)) {
  MADS_BUTTON_UNAVAILABLE = -1,
  MADS_BUTTON_NOT_PRESSED = 0,
  MADS_BUTTON_PRESSED = 1
} ButtonState;

typedef enum __attribute__((packed)) {
  MADS_EDGE_NO_CHANGE = 0,
  MADS_EDGE_RISING = 1,
  MADS_EDGE_FALLING = 2
} EdgeTransition;

typedef enum __attribute__((packed)) {
  MADS_DISENGAGE_REASON_NONE = 0,
  MADS_DISENGAGE_REASON_BRAKE = 1,
  MADS_DISENGAGE_REASON_ACC_MAIN_OFF = 8,
  MADS_DISENGAGE_REASON_HEARTBEAT_ENGAGED_MISMATCH = 32,
  MADS_DISENGAGE_REASON_STEERING_DISENGAGE = 64,
} DisengageReason;

// ===============================
// Constants
// ===============================

#define ALT_EXP_ENABLE_MADS 1024
#define ALT_EXP_MADS_DISENGAGE_LATERAL_ON_BRAKE 2048
#define ALT_EXP_MADS_PAUSE_LATERAL_ON_BRAKE 4096

// ===============================
// Data Structures
// ===============================

typedef struct {
  DisengageReason active_reason;
  DisengageReason pending_reasons;
} DisengageState;

typedef struct {
  ButtonState current;
  ButtonState last;
  EdgeTransition transition;
} ButtonStateTracking;

typedef struct {
  EdgeTransition transition;
  bool current : 1;
  bool previous : 1;
} BinaryStateTracking;

typedef struct {
  bool is_vehicle_moving : 1;

  ButtonStateTracking mads_button;
  BinaryStateTracking acc_main;
  BinaryStateTracking op_controls_allowed;
  BinaryStateTracking braking;
  BinaryStateTracking mads_steering_disengage;

  DisengageState current_disengage;

  bool system_enabled : 1;
  bool disengage_lateral_on_brake : 1;
  bool pause_lateral_on_brake : 1;
  bool controls_requested_lat : 1;
  bool controls_allowed_lat : 1;
} MADSState;

