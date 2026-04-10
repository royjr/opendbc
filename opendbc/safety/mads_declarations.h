/**
 * MADS (Modified Assistive Driving Safety) - Type definitions and declarations.
 * Ported from sunnypilot (Copyright (c) 2021-, Haibin Wen, sunnypilot contributors, MIT License).
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

// ===============================
// Global Variables
// ===============================

extern ButtonState mads_button_press;
extern MADSState m_mads_state;

extern bool heartbeat_engaged_mads;
extern uint32_t heartbeat_engaged_mads_mismatches;

// ===============================
// Function Declarations
// ===============================

extern void mads_set_system_state(bool enabled, bool disengage_lateral_on_brake, bool pause_lateral_on_brake);
extern void mads_set_alternative_experience(const int *mode);
extern void mads_state_update(bool op_vehicle_moving, bool op_acc_main, bool op_allowed, bool is_braking, bool steering_disengage);
extern void mads_exit_controls(DisengageReason reason);
extern bool mads_is_lateral_control_allowed_by_mads(void);
extern void mads_heartbeat_engaged_check(void);
extern bool is_lat_active(void);
