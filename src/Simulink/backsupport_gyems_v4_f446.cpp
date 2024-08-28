//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: backsupport_gyems_v4_f446.cpp
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
#include "backsupport_gyems_v4_f446.h"
#include "rtwtypes.h"
#include <cmath>
#include "backsupport_gyems_v4_f446_capi.h"
#include "zero_crossing_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern const real32_T rtCP_pooled_O1JBuklV5D4R[6];

#define rtCP_Constant7_Value           rtCP_pooled_O1JBuklV5D4R  // Computed Parameter: rtCP_Constant7_Value
                                                                 //  Referenced by: '<S1>/Constant7'


// System initialize for atomic system:
void backsupportModelClass::LowpassFilter1_Init(DW_LowpassFilter1 *localDW)
{
  b_dspcodegen_BiquadFilter *iobj_0;

  // Start for MATLABSystem: '<S1>/Lowpass Filter1'
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.NumChannels == -1) {
    localDW->obj.NumChannels = 1;
  }

  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj._pobj0.isInitialized = 0;

  // System object Constructor function: dsp.BiquadFilter
  localDW->obj._pobj0.cSFunObject.P0_ICRTP = 0.0F;
  localDW->obj._pobj0.cSFunObject.P1_RTP1COEFF[0] = 0.000599225867F;
  localDW->obj._pobj0.cSFunObject.P1_RTP1COEFF[1] = 0.000810228637F;
  localDW->obj._pobj0.cSFunObject.P1_RTP1COEFF[2] = 0.000599225867F;
  localDW->obj._pobj0.cSFunObject.P2_RTP2COEFF[0] = -1.9400996F;
  localDW->obj._pobj0.cSFunObject.P3_RTP3COEFF[0] = 0.0F;
  localDW->obj._pobj0.cSFunObject.P4_RTP_COEFF3_BOOL[0] = false;
  localDW->obj._pobj0.cSFunObject.P2_RTP2COEFF[1] = 0.942131519F;
  localDW->obj._pobj0.cSFunObject.P3_RTP3COEFF[1] = 0.0F;
  localDW->obj._pobj0.cSFunObject.P4_RTP_COEFF3_BOOL[1] = false;
  localDW->obj._pobj0.cSFunObject.P5_IC2RTP = 0.0F;
  localDW->obj.FilterObj = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;

  // InitializeConditions for MATLABSystem: '<S1>/Lowpass Filter1'
  iobj_0 = localDW->obj.FilterObj;
  if (iobj_0->isInitialized == 1) {
    // System object Initialization function: dsp.BiquadFilter
    iobj_0->cSFunObject.W0_ZERO_STATES[0] = iobj_0->cSFunObject.P0_ICRTP;
    iobj_0->cSFunObject.W1_POLE_STATES[0] = iobj_0->cSFunObject.P5_IC2RTP;
    iobj_0->cSFunObject.W0_ZERO_STATES[1] = iobj_0->cSFunObject.P0_ICRTP;
    iobj_0->cSFunObject.W1_POLE_STATES[1] = iobj_0->cSFunObject.P5_IC2RTP;
  }

  // End of InitializeConditions for MATLABSystem: '<S1>/Lowpass Filter1'
}

// Output and update for atomic system:
void backsupportModelClass::LowpassFilter1(real32_T rtu_0, DW_LowpassFilter1
  *localDW)
{
  b_dspcodegen_BiquadFilter *obj;
  real32_T numAccum;

  // MATLABSystem: '<S1>/Lowpass Filter1'
  obj = localDW->obj.FilterObj;
  if (localDW->obj.FilterObj->isInitialized != 1) {
    localDW->obj.FilterObj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;

    // System object Initialization function: dsp.BiquadFilter
    obj->cSFunObject.W0_ZERO_STATES[0] = obj->cSFunObject.P0_ICRTP;
    obj->cSFunObject.W1_POLE_STATES[0] = obj->cSFunObject.P5_IC2RTP;
    obj->cSFunObject.W0_ZERO_STATES[1] = obj->cSFunObject.P0_ICRTP;
    obj->cSFunObject.W1_POLE_STATES[1] = obj->cSFunObject.P5_IC2RTP;
  }

  // System object Outputs function: dsp.BiquadFilter
  numAccum = obj->cSFunObject.P1_RTP1COEFF[0] * rtu_0;
  numAccum += obj->cSFunObject.W0_ZERO_STATES[0] * obj->
    cSFunObject.P1_RTP1COEFF[1];
  numAccum += obj->cSFunObject.W0_ZERO_STATES[1] * obj->
    cSFunObject.P1_RTP1COEFF[2];
  localDW->LowpassFilter1_c = numAccum - obj->cSFunObject.P2_RTP2COEFF[0] *
    obj->cSFunObject.W1_POLE_STATES[0];
  localDW->LowpassFilter1_c -= obj->cSFunObject.P2_RTP2COEFF[1] *
    obj->cSFunObject.W1_POLE_STATES[1];
  obj->cSFunObject.W0_ZERO_STATES[1] = obj->cSFunObject.W0_ZERO_STATES[0];
  obj->cSFunObject.W0_ZERO_STATES[0] = rtu_0;
  obj->cSFunObject.W1_POLE_STATES[1] = obj->cSFunObject.W1_POLE_STATES[0];
  obj->cSFunObject.W1_POLE_STATES[0] = localDW->LowpassFilter1_c;

  // End of MATLABSystem: '<S1>/Lowpass Filter1'
}

// Model step function
void backsupportModelClass::step()
{
  // local block i/o variables
  real32_T rtb_uT;
  real32_T rtb_Sum1_l;
  real32_T rtb_NProdOut;
  real32_T rtb_IProdOut;

  {
    real_T rtb_Clock1;
    int32_T rtb_DiscretePulseGenerator;
    real32_T rtb_TmpSignalConversionAtDotPro[6];
    real32_T rtb_DataTypeConversion;
    real32_T rtb_Filter;
    real32_T rtb_Integrator_e;
    real32_T rtb_InverseNominalPlant;
    real32_T rtb_MultiportSwitch;
    real32_T rtb_Product3_p;
    real32_T rtb_Product_f;
    boolean_T rtb_GreaterThan;

    // MinMax: '<S69>/MinMax' incorporates:
    //   Gain: '<S69>/Minimum sampling to time constant ratio'

    rtb_Clock1 = 10.0F * rtDW.Probe[0];

    // DiscreteIntegrator: '<S73>/Integrator' incorporates:
    //   Inport: '<Root>/IMU1'

    if (rtDW.Integrator_IC_LOADING != 0) {
      rtDW.Integrator_DSTATE = rtU.IMU1[5];
    }

    if (rtDW.Integrator_PrevResetState != 0) {
      rtDW.Integrator_DSTATE = rtU.IMU1[5];
    }

    // MinMax: '<S69>/MinMax'
    if (rtb_Clock1 < 0.3) {
      rtb_Clock1 = 0.3;
    }

    // Product: '<S63>/1//T' incorporates:
    //   DiscreteIntegrator: '<S73>/Integrator'
    //   Inport: '<Root>/IMU1'
    //   MinMax: '<S69>/MinMax'
    //   Sum: '<S63>/Sum1'

    rtb_uT = 1.0F / static_cast<real32_T>(rtb_Clock1) * (rtU.IMU1[5] -
      rtDW.Integrator_DSTATE);

    // Math: '<S62>/Square' incorporates:
    //   Inport: '<Root>/IMU1'
    //   Math: '<S7>/Square'

    rtb_MultiportSwitch = rtU.IMU1[5] * rtU.IMU1[5];

    // Math: '<S68>/Math Function' incorporates:
    //   Constant: '<S62>/A'
    //   Constant: '<S62>/B'
    //   Constant: '<S62>/C'
    //   Constant: '<S68>/Constant'
    //   Gain: '<S62>/Gain'
    //   Inport: '<Root>/IMU1'
    //   Math: '<S62>/Square'
    //   Math: '<S62>/Square1'
    //   Math: '<S68>/Exp'
    //   Product: '<S62>/Product'
    //   Product: '<S62>/Product1'
    //   Product: '<S62>/Product2'
    //   Product: '<S62>/Product3'
    //   Sum: '<S62>/Add'
    //   Sum: '<S68>/Sum'
    //   UnaryMinus: '<S68>/Unary Minus'
    //
    //  About '<S68>/Math Function':
    //   Operator: reciprocal
    //
    //  About '<S68>/Exp':
    //   Operator: exp

    rtb_InverseNominalPlant = 1.0F / (std::exp(-((((rtU.IMU1[5] * rtb_uT *
      -0.185580492F + rtb_MultiportSwitch * 0.53674F) + rtb_uT * rtb_uT *
      0.228260025F) - 0.113906249F) * 130.0F)) + 1.0F);

    // Math: '<S65>/Math Function' incorporates:
    //   Constant: '<S65>/Constant'
    //   Gain: '<S7>/Gain'
    //   Gain: '<S7>/Gain1'
    //   Inport: '<Root>/IMU1'
    //   Math: '<S65>/Exp'
    //   Sum: '<S65>/Sum'
    //   Sum: '<S7>/Sum'
    //   UnaryMinus: '<S65>/Unary Minus'
    //
    //  About '<S65>/Math Function':
    //   Operator: reciprocal
    //
    //  About '<S65>/Exp':
    //   Operator: exp

    rtb_Product_f = 1.0F / (std::exp(-((rtb_uT - 3.60210252F * rtU.IMU1[5]) *
      10.0F)) + 1.0F);

    // Product: '<S7>/Product1' incorporates:
    //   Constant: '<S7>/Constant'
    //   Sum: '<S7>/Sum1'

    rtb_Product3_p = (1.0F - rtb_Product_f) * rtb_InverseNominalPlant;

    // Math: '<S66>/Math Function' incorporates:
    //   Constant: '<S66>/Constant'
    //   Gain: '<S7>/Gain2'
    //   Gain: '<S7>/Gain3'
    //   Inport: '<Root>/IMU1'
    //   Math: '<S66>/Exp'
    //   Sum: '<S66>/Sum'
    //   Sum: '<S7>/Sum2'
    //   UnaryMinus: '<S66>/Unary Minus'
    //
    //  About '<S66>/Math Function':
    //   Operator: reciprocal
    //
    //  About '<S66>/Exp':
    //   Operator: exp

    rtb_DataTypeConversion = 1.0F / (std::exp(-((rtb_uT - 0.244716704F *
      rtU.IMU1[5]) * 10.0F)) + 1.0F);

    // Product: '<S7>/Product2'
    rtb_Filter = rtb_Product3_p * rtb_DataTypeConversion;

    // Product: '<S7>/Product3' incorporates:
    //   Constant: '<S7>/Constant1'
    //   Sum: '<S7>/Sum3'

    rtb_Product3_p *= 1.0F - rtb_DataTypeConversion;

    // Product: '<S7>/Product'
    rtb_Product_f *= rtb_InverseNominalPlant;

    // Math: '<S67>/Math Function' incorporates:
    //   Constant: '<S67>/Constant'
    //   Gain: '<S7>/Gain4'
    //   Gain: '<S7>/Gain5'
    //   Inport: '<Root>/IMU1'
    //   Math: '<S67>/Exp'
    //   Sum: '<S67>/Sum'
    //   Sum: '<S7>/Sum4'
    //   UnaryMinus: '<S67>/Unary Minus'
    //
    //  About '<S67>/Math Function':
    //   Operator: reciprocal
    //
    //  About '<S67>/Exp':
    //   Operator: exp

    rtb_DataTypeConversion = 1.0F / (std::exp(-((rtb_uT - 0.836480319F *
      rtU.IMU1[5]) * 10.0F)) + 1.0F);

    // Product: '<S7>/Product5' incorporates:
    //   Constant: '<S7>/Constant2'
    //   Sum: '<S7>/Sum5'

    rtb_Integrator_e = (1.0F - rtb_DataTypeConversion) * rtb_Product_f;

    // Product: '<S7>/Product4'
    rtb_DataTypeConversion *= rtb_Product_f;

    // SignalConversion generated from: '<S1>/Dot Product'
    rtb_TmpSignalConversionAtDotPro[0] = rtb_InverseNominalPlant;
    rtb_TmpSignalConversionAtDotPro[1] = rtb_Filter;
    rtb_TmpSignalConversionAtDotPro[2] = rtb_Product3_p;
    rtb_TmpSignalConversionAtDotPro[3] = rtb_Integrator_e;
    rtb_TmpSignalConversionAtDotPro[4] = rtb_DataTypeConversion;
    rtb_TmpSignalConversionAtDotPro[5] = rtb_Product_f;

    // Trigonometry: '<S81>/Atan2' incorporates:
    //   DotProduct: '<S81>/Dot Product2'
    //   Inport: '<Root>/IMU1'
    //   Sum: '<S83>/Add3'

    rtb_InverseNominalPlant = std::atan2((rtU.IMU1[0] * rtConstB.Add3[0] +
      rtU.IMU1[1] * rtConstB.Add3[1]) + rtU.IMU1[2] * rtConstB.Add3[2],
      rtU.IMU1[1]);

    // Delay: '<S82>/Delay'
    if (rtDW.icLoad) {
      rtDW.Delay_DSTATE = rtb_InverseNominalPlant;
    }

    // Sum: '<S82>/Sum1' incorporates:
    //   Constant: '<S81>/Constant'
    //   Delay: '<S82>/Delay'
    //   DotProduct: '<S81>/Dot Product'
    //   Gain: '<S82>/Gain'
    //   Gain: '<S82>/Gain1'
    //   Gain: '<S82>/Gain2'
    //   Inport: '<Root>/IMU1'
    //   Sum: '<S82>/Sum'

    rtb_Sum1_l = (0.002F * rtU.IMU1[5] + rtDW.Delay_DSTATE) * 0.99F + 0.01F *
      rtb_InverseNominalPlant;

    // Sum: '<S81>/Sum' incorporates:
    //   Gain: '<S84>/Gain'

    rtb_InverseNominalPlant = 57.2957802F * rtb_Sum1_l;

    // Sum: '<S76>/Add1' incorporates:
    //   Constant: '<S76>/Filter_Constant'
    //   Constant: '<S76>/One'
    //   Product: '<S76>/Product'
    //   Product: '<S76>/Product1'
    //   UnitDelay: '<S76>/Unit Delay'

    rtDW.UnitDelay_DSTATE = rtb_MultiportSwitch * 0.1F + 0.9F *
      rtDW.UnitDelay_DSTATE;

    // Sin: '<S1>/Sine Wave3'
    if (rtDW.systemEnable != 0) {
      rtb_Clock1 = 6.2831853071795862 * (((&rtM)->Timing.clockTick1) * 0.002);
      rtDW.lastSin = std::sin(rtb_Clock1);
      rtDW.lastCos = std::cos(rtb_Clock1);
      rtDW.systemEnable = 0;
    }

    // Sin: '<S1>/Sine Wave4'
    if (rtDW.systemEnable_d != 0) {
      rtb_Clock1 = 6.2831853071795862 * (((&rtM)->Timing.clockTick1) * 0.002);
      rtDW.lastSin_a = std::sin(rtb_Clock1);
      rtDW.lastCos_f = std::cos(rtb_Clock1);
      rtDW.systemEnable_d = 0;
    }

    // DiscretePulseGenerator: '<S1>/Pulse Generator'
    rtb_DiscretePulseGenerator = ((rtDW.clockTickCounter < 500) &&
      (rtDW.clockTickCounter >= 0));
    if (rtDW.clockTickCounter >= 999) {
      rtDW.clockTickCounter = 0;
    } else {
      rtDW.clockTickCounter++;
    }

    // End of DiscretePulseGenerator: '<S1>/Pulse Generator'

    // Clock: '<S5>/Clock1'
    rtb_Clock1 = (&rtM)->Timing.t[0];

    // MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
    //   Constant: '<S1>/Constant2'
    //   Constant: '<S1>/Constant3'
    //   Constant: '<S1>/Constant5'
    //   Constant: '<S1>/Constant6'
    //   Constant: '<S5>/initialFreq'
    //   DataTypeConversion: '<S1>/Data Type Conversion4'
    //   DataTypeConversion: '<S1>/Data Type Conversion5'
    //   DataTypeConversion: '<S1>/Data Type Conversion7'
    //   DataTypeConversion: '<S1>/Data Type Conversion8'
    //   Gain: '<S1>/Gain12'
    //   Gain: '<S1>/Gain13'
    //   Gain: '<S1>/Gain14'
    //   Gain: '<S1>/Gain4'
    //   Gain: '<S1>/Gain7'
    //   Gain: '<S1>/Gain8'
    //   Gain: '<S1>/Gain9'
    //   Inport: '<Root>/Mode'
    //   Product: '<S5>/Product1'
    //   Product: '<S5>/Product2'
    //   Saturate: '<S7>/Saturation'
    //   Sin: '<S1>/Sine Wave3'
    //   Sin: '<S1>/Sine Wave4'
    //   Sum: '<S1>/Sum3'
    //   Sum: '<S1>/Sum4'
    //   Sum: '<S1>/Sum7'
    //   Sum: '<S1>/Sum9'
    //   Sum: '<S5>/Sum'
    //   Trigonometry: '<S5>/Output'

    switch (rtU.Mode) {
     case 1:
      rtb_MultiportSwitch = static_cast<real32_T>((rtDW.lastSin *
        0.99992104420381611 + rtDW.lastCos * -0.012566039883352607) *
        0.99992104420381611 + (rtDW.lastCos * 0.99992104420381611 - rtDW.lastSin
        * -0.012566039883352607) * 0.012566039883352607) * 5000.0F;
      break;

     case 2:
      rtb_MultiportSwitch = (static_cast<real32_T>((rtDW.lastSin_a *
        0.99992104420381611 + rtDW.lastCos_f * -0.012566039883352607) *
        0.99992104420381611 + (rtDW.lastCos_f * 0.99992104420381611 -
        rtDW.lastSin_a * -0.012566039883352607) * 0.012566039883352607) * 0.5F +
        0.5F) * 8192.0F + 2048.0F;
      break;

     case 3:
      rtb_MultiportSwitch = 8000.0F * static_cast<real32_T>
        (rtb_DiscretePulseGenerator);
      break;

     case 4:
      rtb_MultiportSwitch = (static_cast<real32_T>(std::sin((rtb_Clock1 *
        rtConstB.Gain + 0.62831853071795862) * rtb_Clock1)) * 0.5F + 0.5F) *
        9000.0F - 3000.0F;
      break;

     case 5:
      rtb_MultiportSwitch = 0.0F;
      break;

     default:
      // Gain: '<S7>/Gain6' incorporates:
      //   Constant: '<S7>/Constant3'
      //   DotProduct: '<S7>/Dot Product'
      //   Inport: '<Root>/k_theta'
      //   Product: '<S7>/Product6'
      //   Product: '<S7>/Product7'
      //   SignalConversion generated from: '<S7>/Dot Product'
      //   Sum: '<S7>/Sum6'
      //   UnitDelay: '<S76>/Unit Delay'

      rtb_MultiportSwitch = ((((rtb_Filter * -2.5F + rtb_Product3_p * 6.5F) +
        rtb_Integrator_e * 4.0F) + rtb_DataTypeConversion * 1.5F) *
        rtDW.UnitDelay_DSTATE + rtb_InverseNominalPlant * rtU.k_theta) * 0.7F;

      // Saturate: '<S7>/Saturation'
      if (rtb_MultiportSwitch > 50.0F) {
        rtb_MultiportSwitch = 50.0F;
      } else if (rtb_MultiportSwitch < -0.1F) {
        rtb_MultiportSwitch = -0.1F;
      }

      rtb_MultiportSwitch *= 510.204071F;
      break;
    }

    // End of MultiPortSwitch: '<S1>/Multiport Switch'

    // RateLimiter: '<S1>/Rate Limiter' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion6'
    //   Inport: '<Root>/EnableAssist'

    rtb_Product3_p = static_cast<real32_T>(rtU.EnableAssist) - rtDW.PrevY;
    if (rtb_Product3_p > 0.01F) {
      // RateLimiter: '<S1>/Rate Limiter'
      rtDW.PrevY += 0.01F;
    } else if (rtb_Product3_p < -0.2F) {
      // RateLimiter: '<S1>/Rate Limiter'
      rtDW.PrevY -= 0.2F;
    } else {
      // RateLimiter: '<S1>/Rate Limiter'
      rtDW.PrevY = static_cast<real32_T>(rtU.EnableAssist);
    }

    // End of RateLimiter: '<S1>/Rate Limiter'

    // Product: '<S1>/Product'
    rtb_Filter = rtb_MultiportSwitch * rtDW.PrevY;

    // RelationalOperator: '<S11>/GreaterThan' incorporates:
    //   Constant: '<S11>/Constant'
    //   Inport: '<Root>/TimeSignal'

    rtb_GreaterThan = (rtU.TimeSignal > 1.0F);

    // Outputs for Triggered SubSystem: '<S11>/Sample and Hold' incorporates:
    //   TriggerPort: '<S80>/Trigger'

    if (rtb_GreaterThan && (rtPrevZCX.SampleandHold_Trig_ZCE != POS_ZCSIG)) {
      // SignalConversion generated from: '<S80>/In' incorporates:
      //   Memory generated from: '<S11>/Sample and Hold'

      rtDW.In = rtDW.TmpLatchAtSampleandHoldInport1_;
    }

    rtPrevZCX.SampleandHold_Trig_ZCE = rtb_GreaterThan;

    // End of Outputs for SubSystem: '<S11>/Sample and Hold'

    // Sum: '<S11>/Sum' incorporates:
    //   Inport: '<Root>/SpringEncoder1'

    rtb_DataTypeConversion = rtU.SpringEncoder1 - rtDW.In;

    // Sum: '<S6>/Sum'
    rtb_Product3_p = rtb_Filter - rtb_DataTypeConversion;

    // Product: '<S48>/NProd Out' incorporates:
    //   Constant: '<S1>/Constant'
    //   DiscreteIntegrator: '<S40>/Filter'
    //   Inport: '<Root>/Kd'
    //   Product: '<S39>/DProd Out'
    //   Sum: '<S40>/SumD'

    rtb_NProdOut = (rtb_Product3_p * rtU.Kd - rtDW.Filter_DSTATE) * 100.0F;

    // DiscreteTransferFcn: '<S6>/Inverse Nominal Plant'
    rtDW.InverseNominalPlant_tmp = (rtb_DataTypeConversion - -1.64824426F *
      rtDW.InverseNominalPlant_states[0]) - 0.701061726F *
      rtDW.InverseNominalPlant_states[1];

    // Sum: '<S6>/Sum1' incorporates:
    //   DiscreteIntegrator: '<S45>/Integrator'
    //   DiscreteTransferFcn: '<S6>/Inverse Nominal Plant'
    //   DiscreteTransferFcn: '<S6>/Low Pass Filter'
    //   Inport: '<Root>/Kff'
    //   Inport: '<Root>/Kp'
    //   Product: '<S50>/PProd Out'
    //   Product: '<S6>/Product'
    //   Sum: '<S54>/Sum'
    //   Sum: '<S6>/Sum3'

    rtDW.Saturation = (((rtb_Product3_p * rtU.Kp + rtDW.Integrator_DSTATE_n) +
                        rtb_NProdOut) + rtU.Kff * rtb_Filter) - (((2.30634308F *
      rtDW.InverseNominalPlant_tmp + -4.50215912F *
      rtDW.InverseNominalPlant_states[0]) + 2.2024343F *
      rtDW.InverseNominalPlant_states[1]) - (0.000198121052F *
      rtDW.LowPassFilter_states[0] + 0.000196261914F *
      rtDW.LowPassFilter_states[1]));

    // Saturate: '<S6>/Saturation'
    if (rtDW.Saturation > 1499.0F) {
      // Sum: '<S6>/Sum1' incorporates:
      //   Saturate: '<S6>/Saturation'

      rtDW.Saturation = 1499.0F;
    } else if (rtDW.Saturation < -1499.0F) {
      // Sum: '<S6>/Sum1' incorporates:
      //   Saturate: '<S6>/Saturation'

      rtDW.Saturation = -1499.0F;
    }

    // End of Saturate: '<S6>/Saturation'

    // S-Function (sdspunwrap2): '<S78>/Unwrap' incorporates:
    //   Inport: '<Root>/Left Hip Angle'

    if (rtDW.Unwrap_FirstStep) {
      rtDW.Unwrap_Prev = rtU.LeftHipAngle;
      rtDW.Unwrap_FirstStep = false;
    }

    rtb_Filter = rtU.LeftHipAngle - rtDW.Unwrap_Prev;
    rtb_Integrator_e = rtb_Filter - std::floor((rtb_Filter + 3.14159274F) /
      6.28318548F) * 6.28318548F;
    if ((rtb_Integrator_e == -3.14159274F) && (rtb_Filter > 0.0F)) {
      rtb_Integrator_e = 3.14159274F;
    }

    rtb_Filter = rtb_Integrator_e - rtb_Filter;
    if (std::abs(rtb_Filter) > 3.14159274F) {
      rtDW.Unwrap_Cumsum += rtb_Filter;
    }

    rtDW.Unwrap_Prev = rtU.LeftHipAngle;

    // Gain: '<S78>/Gain1' incorporates:
    //   Inport: '<Root>/Left Hip Angle'
    //   S-Function (sdspunwrap2): '<S78>/Unwrap'
    //   Sum: '<S78>/Sum'

    LowpassFilter1(0.5F * ((rtU.LeftHipAngle + rtDW.Unwrap_Cumsum) - 1.6904F),
                   &rtDW.LowpassFilter1_p);

    // S-Function (sdspunwrap2): '<S79>/Unwrap' incorporates:
    //   Inport: '<Root>/Right Hip Angle'

    if (rtDW.Unwrap_FirstStep_n) {
      rtDW.Unwrap_Prev_l = rtU.RightHipAngle;
      rtDW.Unwrap_FirstStep_n = false;
    }

    rtb_Filter = rtU.RightHipAngle - rtDW.Unwrap_Prev_l;
    rtb_Integrator_e = rtb_Filter - std::floor((rtb_Filter + 3.14159274F) /
      6.28318548F) * 6.28318548F;
    if ((rtb_Integrator_e == -3.14159274F) && (rtb_Filter > 0.0F)) {
      rtb_Integrator_e = 3.14159274F;
    }

    rtb_Filter = rtb_Integrator_e - rtb_Filter;
    if (std::abs(rtb_Filter) > 3.14159274F) {
      rtDW.Unwrap_Cumsum_n += rtb_Filter;
    }

    rtDW.Unwrap_Prev_l = rtU.RightHipAngle;

    // UnaryMinus: '<S79>/Unary Minus' incorporates:
    //   Gain: '<S79>/Gain1'
    //   Inport: '<Root>/Right Hip Angle'
    //   S-Function (sdspunwrap2): '<S79>/Unwrap'
    //   Sum: '<S79>/Sum'

    LowpassFilter1(-(0.5F * ((rtU.RightHipAngle + rtDW.Unwrap_Cumsum_n) - 2.639F)),
                   &rtDW.LowpassFilter3);

    // DotProduct: '<S1>/Dot Product' incorporates:
    //   Constant: '<S1>/Constant7'

    rtb_Filter = 0.0F;
    for (rtb_DiscretePulseGenerator = 0; rtb_DiscretePulseGenerator < 6;
         rtb_DiscretePulseGenerator++) {
      rtb_Filter += rtb_TmpSignalConversionAtDotPro[rtb_DiscretePulseGenerator] *
        rtCP_Constant7_Value[rtb_DiscretePulseGenerator];
    }

    // Outport: '<Root>/LogData' incorporates:
    //   Constant: '<S81>/Constant'
    //   DotProduct: '<S1>/Dot Product'
    //   DotProduct: '<S81>/Dot Product'
    //   Gain: '<S8>/Gain'
    //   Gain: '<S9>/Gain'
    //   Inport: '<Root>/IMU1'

    rtY.LogData[0] = rtb_DataTypeConversion;
    rtY.LogData[1] = rtDW.Saturation;
    rtY.LogData[2] = rtb_MultiportSwitch;
    rtY.LogData[3] = rtb_InverseNominalPlant;
    rtY.LogData[4] = 57.2957802F * rtDW.LowpassFilter1_p.LowpassFilter1_c;
    rtY.LogData[5] = 57.2957802F * rtDW.LowpassFilter3.LowpassFilter1_c;
    rtY.LogData[6] = rtU.IMU1[5];
    rtY.LogData[7] = 0.0F;
    rtY.LogData[8] = rtb_Filter;

    // Outport: '<Root>/Motor1Command'
    rtY.Motor1Command = rtDW.Saturation;

    // Product: '<S42>/IProd Out' incorporates:
    //   Inport: '<Root>/Ki'

    rtb_IProdOut = rtb_Product3_p * rtU.Ki;

    // Outport: '<Root>/LED States' incorporates:
    //   DiscretePulseGenerator: '<S1>/Discrete Pulse Generator'

    rtY.LEDStates[0] = ((rtDW.clockTickCounter_p < 50) &&
                        (rtDW.clockTickCounter_p >= 0));

    // DiscretePulseGenerator: '<S1>/Discrete Pulse Generator'
    if (rtDW.clockTickCounter_p >= 99) {
      rtDW.clockTickCounter_p = 0;
    } else {
      rtDW.clockTickCounter_p++;
    }

    // Outport: '<Root>/LED States' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion'

    rtY.LEDStates[1] = static_cast<int32_T>(std::floor(0.0F));
  }

  {
    real_T HoldSine;
    real32_T denAccum;

    // Update for DiscreteIntegrator: '<S73>/Integrator'
    rtDW.Integrator_IC_LOADING = 0U;
    rtDW.Integrator_DSTATE += 0.002F * rtb_uT;
    rtDW.Integrator_PrevResetState = 0;

    // Update for Delay: '<S82>/Delay'
    rtDW.icLoad = false;
    rtDW.Delay_DSTATE = rtb_Sum1_l;

    // Update for Sin: '<S1>/Sine Wave3'
    HoldSine = rtDW.lastSin;
    rtDW.lastSin = rtDW.lastSin * 0.99992104420381611 + rtDW.lastCos *
      0.012566039883352607;
    rtDW.lastCos = rtDW.lastCos * 0.99992104420381611 - HoldSine *
      0.012566039883352607;

    // Update for Sin: '<S1>/Sine Wave4'
    HoldSine = rtDW.lastSin_a;
    rtDW.lastSin_a = rtDW.lastSin_a * 0.99992104420381611 + rtDW.lastCos_f *
      0.012566039883352607;
    rtDW.lastCos_f = rtDW.lastCos_f * 0.99992104420381611 - HoldSine *
      0.012566039883352607;

    // Update for Memory generated from: '<S11>/Sample and Hold' incorporates:
    //   Inport: '<Root>/SpringEncoder1'

    rtDW.TmpLatchAtSampleandHoldInport1_ = rtU.SpringEncoder1;

    // Update for DiscreteIntegrator: '<S45>/Integrator'
    rtDW.Integrator_DSTATE_n += 0.002F * rtb_IProdOut;

    // Update for DiscreteIntegrator: '<S40>/Filter'
    rtDW.Filter_DSTATE += 0.002F * rtb_NProdOut;

    // Update for DiscreteTransferFcn: '<S6>/Low Pass Filter'
    denAccum = (rtDW.Saturation - -1.9717176F * rtDW.LowPassFilter_states[0]) -
      0.972112F * rtDW.LowPassFilter_states[1];
    rtDW.LowPassFilter_states[1] = rtDW.LowPassFilter_states[0];
    rtDW.LowPassFilter_states[0] = denAccum;

    // Update for DiscreteTransferFcn: '<S6>/Inverse Nominal Plant'
    rtDW.InverseNominalPlant_states[1] = rtDW.InverseNominalPlant_states[0];
    rtDW.InverseNominalPlant_states[0] = rtDW.InverseNominalPlant_tmp;
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  (&rtM)->Timing.t[0] =
    ((time_T)(++(&rtM)->Timing.clockTick0)) * (&rtM)->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.002s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.002, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&rtM)->Timing.clockTick1++;
  }
}

// Model initialize function
void backsupportModelClass::initialize()
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&rtM)->solverInfo, &(&rtM)->Timing.simTimeStep);
    rtsiSetTPtr(&(&rtM)->solverInfo, &rtmGetTPtr((&rtM)));
    rtsiSetStepSizePtr(&(&rtM)->solverInfo, &(&rtM)->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&(&rtM)->solverInfo, (&rtmGetErrorStatus((&rtM))));
    rtsiSetRTModelPtr(&(&rtM)->solverInfo, (&rtM));
  }

  rtsiSetSimTimeStep(&(&rtM)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&(&rtM)->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr((&rtM), &(&rtM)->Timing.tArray[0]);
  (&rtM)->Timing.stepSize0 = 0.002;

  // Initialize DataMapInfo substructure containing ModelMap for C API
  backsupport_gyems_v4_f446_InitializeDataMapInfo((&rtM), &rtDW);

  // Start for Probe: '<S69>/Probe'
  rtDW.Probe[0] = 0.002F;
  rtDW.Probe[1] = 0.0F;
  rtPrevZCX.SampleandHold_Trig_ZCE = POS_ZCSIG;

  // InitializeConditions for DiscreteIntegrator: '<S73>/Integrator'
  rtDW.Integrator_IC_LOADING = 1U;

  // InitializeConditions for Delay: '<S82>/Delay'
  rtDW.icLoad = true;

  // InitializeConditions for S-Function (sdspunwrap2): '<S78>/Unwrap'
  rtDW.Unwrap_FirstStep = true;

  // InitializeConditions for S-Function (sdspunwrap2): '<S79>/Unwrap'
  rtDW.Unwrap_FirstStep_n = true;
  LowpassFilter1_Init(&rtDW.LowpassFilter1_p);
  LowpassFilter1_Init(&rtDW.LowpassFilter3);

  // Enable for Sin: '<S1>/Sine Wave3'
  rtDW.systemEnable = 1;

  // Enable for Sin: '<S1>/Sine Wave4'
  rtDW.systemEnable_d = 1;
}

// Constructor
backsupportModelClass::backsupportModelClass() :
  rtU(),
  rtY(),
  rtDW(),
  rtPrevZCX(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
backsupportModelClass::~backsupportModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
backsupportModelClass::RT_MODEL * backsupportModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
