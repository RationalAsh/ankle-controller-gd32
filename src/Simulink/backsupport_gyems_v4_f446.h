//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: backsupport_gyems_v4_f446.h
//
// Code generated for Simulink model 'backsupport_gyems_v4_f446'.
//
// Model version                  : 7.23
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri May 10 14:28:18 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives:
//    1. Execution efficiency
//    2. Traceability
// Validation result: Not run
//
#ifndef RTW_HEADER_backsupport_gyems_v4_f446_h_
#define RTW_HEADER_backsupport_gyems_v4_f446_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rtw_modelmap.h"
#include <stddef.h>
#include "zero_crossing_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef struct_b_dsp_BiquadFilter_0
#define struct_b_dsp_BiquadFilter_0

struct b_dsp_BiquadFilter_0
{
  int32_T S0_isInitialized;
  real32_T W0_ZERO_STATES[2];
  real32_T W1_POLE_STATES[2];
  int32_T W2_PreviousNumChannels;
  real32_T P0_ICRTP;
  real32_T P1_RTP1COEFF[3];
  real32_T P2_RTP2COEFF[2];
  real32_T P3_RTP3COEFF[2];
  boolean_T P4_RTP_COEFF3_BOOL[2];
  real32_T P5_IC2RTP;
};

#endif                                 // struct_b_dsp_BiquadFilter_0

#ifndef struct_b_dspcodegen_BiquadFilter
#define struct_b_dspcodegen_BiquadFilter

struct b_dspcodegen_BiquadFilter
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_BiquadFilter_0 cSFunObject;
};

#endif                                 // struct_b_dspcodegen_BiquadFilter

#ifndef struct_cell_wrap
#define struct_cell_wrap

struct cell_wrap
{
  uint32_T f1[8];
};

#endif                                 // struct_cell_wrap

#ifndef struct_dsp_simulink_LowpassFilter
#define struct_dsp_simulink_LowpassFilter

struct dsp_simulink_LowpassFilter
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_BiquadFilter *FilterObj;
  b_dspcodegen_BiquadFilter _pobj0;
};

#endif                                 // struct_dsp_simulink_LowpassFilter

// Function to get C API Model Mapping Static Info
extern const rtwCAPI_ModelMappingStaticInfo*
  backsupport_gyems_v4_f446_GetCAPIStaticMap(void);

// Class declaration for model backsupport_gyems_v4_f446
class backsupportModelClass
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<S1>/Lowpass Filter1' 
  struct DW_LowpassFilter1 {
    dsp_simulink_LowpassFilter obj;    // '<S1>/Lowpass Filter1'
    real32_T LowpassFilter1_c;         // '<S1>/Lowpass Filter1'
    boolean_T objisempty;              // '<S1>/Lowpass Filter1'
    boolean_T isInitialized;           // '<S1>/Lowpass Filter1'
    boolean_T isInitialized_a;         // '<S1>/Lowpass Filter1'
  };

  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    DW_LowpassFilter1 LowpassFilter3;  // '<S1>/Lowpass Filter1'
    DW_LowpassFilter1 LowpassFilter1_p;// '<S1>/Lowpass Filter1'
    real_T lastSin;                    // '<S1>/Sine Wave3'
    real_T lastCos;                    // '<S1>/Sine Wave3'
    real_T lastSin_a;                  // '<S1>/Sine Wave4'
    real_T lastCos_f;                  // '<S1>/Sine Wave4'
    real32_T Probe[2];                 // '<S69>/Probe'
    real32_T LowPassFilter_states[2];  // '<S6>/Low Pass Filter'
    real32_T InverseNominalPlant_states[2];// '<S6>/Inverse Nominal Plant'
    real32_T Saturation;               // '<S6>/Saturation'
    real32_T In;                       // '<S80>/In'
    real32_T Integrator_DSTATE;        // '<S73>/Integrator'
    real32_T Delay_DSTATE;             // '<S82>/Delay'
    real32_T UnitDelay_DSTATE;         // '<S76>/Unit Delay'
    real32_T Integrator_DSTATE_n;      // '<S45>/Integrator'
    real32_T Filter_DSTATE;            // '<S40>/Filter'
    real32_T PrevY;                    // '<S1>/Rate Limiter'
    real32_T TmpLatchAtSampleandHoldInport1_;// synthesized block
    real32_T InverseNominalPlant_tmp;  // '<S6>/Inverse Nominal Plant'
    real32_T Unwrap_Prev;              // '<S78>/Unwrap'
    real32_T Unwrap_Cumsum;            // '<S78>/Unwrap'
    real32_T Unwrap_Prev_l;            // '<S79>/Unwrap'
    real32_T Unwrap_Cumsum_n;          // '<S79>/Unwrap'
    int32_T systemEnable;              // '<S1>/Sine Wave3'
    int32_T systemEnable_d;            // '<S1>/Sine Wave4'
    int32_T clockTickCounter;          // '<S1>/Pulse Generator'
    int32_T clockTickCounter_p;        // '<S1>/Discrete Pulse Generator'
    int8_T Integrator_PrevResetState;  // '<S73>/Integrator'
    uint8_T Integrator_IC_LOADING;     // '<S73>/Integrator'
    boolean_T icLoad;                  // '<S82>/Delay'
    boolean_T Unwrap_FirstStep;        // '<S78>/Unwrap'
    boolean_T Unwrap_FirstStep_n;      // '<S79>/Unwrap'
  };

  // Zero-crossing (trigger) state
  struct PrevZCX {
    ZCSigState SampleandHold_Trig_ZCE; // '<S11>/Sample and Hold'
  };

  // Invariant block signals (default storage)
  struct ConstB {
    real_T Product;                    // '<S5>/Product'
    real_T Gain;                       // '<S5>/Gain'
    real32_T Elementproduct[6];        // '<S83>/Element product'
    real32_T Add3[3];                  // '<S83>/Add3'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real32_T TimeSignal;               // '<Root>/TimeSignal'
    real32_T IMU1[6];                  // '<Root>/IMU1'
    real32_T IMU2[6];                  // '<Root>/IMU2'
    int32_T Mode;                      // '<Root>/Mode'
    int32_T EnableAssist;              // '<Root>/EnableAssist'
    real32_T IMU3[6];                  // '<Root>/IMU3'
    real32_T LeftHipAngle;             // '<Root>/Left Hip Angle'
    real32_T RightHipAngle;            // '<Root>/Right Hip Angle'
    real32_T SpringEncoder1;           // '<Root>/SpringEncoder1'
    real32_T SpringEncoder2;           // '<Root>/SpringEncoder2'
    real32_T Kp;                       // '<Root>/Kp'
    real32_T Kd;                       // '<Root>/Kd'
    real32_T Ki;                       // '<Root>/Ki'
    real32_T Kff;                      // '<Root>/Kff'
    real32_T N;                        // '<Root>/N'
    real32_T k_theta;                  // '<Root>/k_theta'
    real32_T A2;                       // '<Root>/A2'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real32_T LogData[9];               // '<Root>/LogData'
    int32_T LEDStates[2];              // '<Root>/LED States'
    real32_T Motor1Command;            // '<Root>/Motor1Command'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T *errorStatus;
    RTWSolverInfo solverInfo;

    //
    //  DataMapInfo:
    //  The following substructure contains information regarding
    //  structures generated in the model's C API.

    struct {
      rtwCAPI_ModelMappingInfo mmi;
      void* dataAddress[19];
      int32_T* vardimsAddress[19];
      RTWLoggingFcnPtr loggingPtrs[19];
    } DataMapInfo;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      uint32_T clockTick0;
      time_T stepSize0;
      uint32_T clockTick1;
      SimTimeStep simTimeStep;
      time_T *t;
      time_T tArray[2];
    } Timing;
  };

  // Real-Time Model get method
  backsupportModelClass::RT_MODEL * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU *pExtU)
  {
    rtU = *pExtU;
  }

  // Root outports get method
  const ExtY &getExternalOutputs() const
  {
    return rtY;
  }

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  backsupportModelClass();

  // Destructor
  ~backsupportModelClass();

  // private data and function members
 private:
  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // Block states
  DW rtDW;

  // Triggered events
  PrevZCX rtPrevZCX;

  // private member function(s) for subsystem '<S1>/Lowpass Filter1'
  static void LowpassFilter1_Init(DW_LowpassFilter1 *localDW);
  static void LowpassFilter1(real32_T rtu_0, DW_LowpassFilter1 *localDW);

  // Real-Time Model
  RT_MODEL rtM;
};

extern const backsupportModelClass::ConstB rtConstB;// constant block i/o

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S76>/Data Type Duplicate' : Unused code path elimination
//  Block '<S7>/Scope' : Unused code path elimination
//  Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S63>/Gain' : Eliminated nontunable gain of 1
//  Block '<S73>/Saturation' : Eliminated Saturate block
//  Block '<S63>/[A,B]' : Eliminated Saturate block
//  Block '<S1>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S77>/Gain18' : Eliminated nontunable gain of 1
//  Block '<S77>/Gain5' : Eliminated nontunable gain of 1
//  Block '<S78>/Constant' : Unused code path elimination
//  Block '<S78>/Unary Minus' : Unused code path elimination
//  Block '<S79>/Constant' : Unused code path elimination
//  Block '<S81>/Constant2' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'backsupport_gyems_v4_f446'
//  '<S1>'   : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller'
//  '<S2>'   : 'backsupport_gyems_v4_f446/IMU Data Conversion'
//  '<S3>'   : 'backsupport_gyems_v4_f446/IMU Data Conversion1'
//  '<S4>'   : 'backsupport_gyems_v4_f446/IMU Data Conversion2'
//  '<S5>'   : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Chirp Signal3'
//  '<S6>'   : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)'
//  '<S7>'   : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control'
//  '<S8>'   : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Radians to Degrees'
//  '<S9>'   : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Radians to Degrees1'
//  '<S10>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Subsystem'
//  '<S11>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Tare'
//  '<S12>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Trunk Tilt Calculation'
//  '<S13>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller'
//  '<S14>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Anti-windup'
//  '<S15>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/D Gain'
//  '<S16>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Filter'
//  '<S17>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Filter ICs'
//  '<S18>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/I Gain'
//  '<S19>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Ideal P Gain'
//  '<S20>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S21>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Integrator'
//  '<S22>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Integrator ICs'
//  '<S23>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/N Copy'
//  '<S24>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/N Gain'
//  '<S25>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/P Copy'
//  '<S26>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Parallel P Gain'
//  '<S27>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Reset Signal'
//  '<S28>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Saturation'
//  '<S29>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Saturation Fdbk'
//  '<S30>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Sum'
//  '<S31>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Sum Fdbk'
//  '<S32>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Tracking Mode'
//  '<S33>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Tracking Mode Sum'
//  '<S34>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Tsamp - Integral'
//  '<S35>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Tsamp - Ngain'
//  '<S36>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/postSat Signal'
//  '<S37>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/preSat Signal'
//  '<S38>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Anti-windup/Passthrough'
//  '<S39>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/D Gain/External Parameters'
//  '<S40>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S41>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S42>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/I Gain/External Parameters'
//  '<S43>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S44>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S45>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Integrator/Discrete'
//  '<S46>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S47>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/N Copy/Disabled'
//  '<S48>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/N Gain/External Parameters'
//  '<S49>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/P Copy/Disabled'
//  '<S50>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Parallel P Gain/External Parameters'
//  '<S51>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Reset Signal/Disabled'
//  '<S52>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Saturation/Passthrough'
//  '<S53>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S54>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Sum/Sum_PID'
//  '<S55>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S56>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S57>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S58>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S59>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S60>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S61>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S62>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Elliptical Boundary'
//  '<S63>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Filtered Derivative (Discrete or Continuous)'
//  '<S64>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/IIR Filter'
//  '<S65>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Sigmoid Function'
//  '<S66>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Sigmoid Function1'
//  '<S67>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Sigmoid Function2'
//  '<S68>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Elliptical Boundary/Sigmoid Function'
//  '<S69>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Filtered Derivative (Discrete or Continuous)/Enable//disable time constant'
//  '<S70>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Filtered Derivative (Discrete or Continuous)/Initialization'
//  '<S71>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Filtered Derivative (Discrete or Continuous)/Integrator (Discrete or Continuous)'
//  '<S72>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Filtered Derivative (Discrete or Continuous)/Initialization/Init_u'
//  '<S73>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Filtered Derivative (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
//  '<S74>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/IIR Filter/IIR Filter'
//  '<S75>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/IIR Filter/IIR Filter/Low-pass'
//  '<S76>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
//  '<S77>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Subsystem/Angle Signal Conditioning 001'
//  '<S78>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Subsystem/Angle Signal Conditioning 001/Left Hip Angle Signal  Conditioning (RMB20)'
//  '<S79>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Subsystem/Angle Signal Conditioning 001/Right Hip Angle Signal  Conditioning (RMB20)'
//  '<S80>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Tare/Sample and Hold'
//  '<S81>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Trunk Tilt Calculation/Tilt Measurement'
//  '<S82>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Trunk Tilt Calculation/Tilt Measurement/Complementary Filter'
//  '<S83>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Trunk Tilt Calculation/Tilt Measurement/Cross Product'
//  '<S84>'  : 'backsupport_gyems_v4_f446/Back Exoskeleton Controller/Trunk Tilt Calculation/Tilt Measurement/Radians to Degrees'


//-
//  Requirements for '<Root>': backsupport_gyems_v4_f446


#endif                               // RTW_HEADER_backsupport_gyems_v4_f446_h_

//
// File trailer for generated code.
//
// [EOF]
//
