//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: backsupport_gyems_v4_f446_capi.cpp
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
#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "backsupport_gyems_v4_f446_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  // HOST_CAPI_BUILD
#include "builtin_typeid_types.h"
#include "backsupport_gyems_v4_f446.h"
#include "backsupport_gyems_v4_f446_capi.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 // HOST_CAPI_BUILD

// Block output signal information
static rtwCAPI_Signals rtBlockSignals[] = {
  // addrMapIndex, sysNum, blockPath,
  //  signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex

  { 0, 1, TARGET_STRING("backsupport_gyems_v4_f446/Back Exoskeleton Controller/Lowpass Filter1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 2, TARGET_STRING("backsupport_gyems_v4_f446/Back Exoskeleton Controller/Lowpass Filter3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("backsupport_gyems_v4_f446/Back Exoskeleton Controller/Chirp Signal3/Gain"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 3, 0, TARGET_STRING("backsupport_gyems_v4_f446/Back Exoskeleton Controller/Chirp Signal3/Product"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 4, 0, TARGET_STRING("backsupport_gyems_v4_f446/Back Exoskeleton Controller/DOb Controller (External Gains)/Saturation"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 5, 3, TARGET_STRING("backsupport_gyems_v4_f446/Back Exoskeleton Controller/Tare/Sample and Hold"),
    TARGET_STRING(""), 0, 0, 0, 0, 3 },

  { 6, 3, TARGET_STRING("backsupport_gyems_v4_f446/Back Exoskeleton Controller/Tare/Sample and Hold/In"),
    TARGET_STRING(""), 0, 0, 0, 0, 3 },

  { 7, 0, TARGET_STRING("backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/Filtered Derivative (Discrete or Continuous)/Enable//disable time constant/Probe"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 8, 0, TARGET_STRING("backsupport_gyems_v4_f446/Back Exoskeleton Controller/Trunk Tilt Calculation/Tilt Measurement/Cross Product/Element product"),
    TARGET_STRING(""), 0, 0, 2, 0, 1 },

  { 9, 0, TARGET_STRING("backsupport_gyems_v4_f446/Back Exoskeleton Controller/Trunk Tilt Calculation/Tilt Measurement/Cross Product/Add3"),
    TARGET_STRING(""), 0, 0, 3, 0, 1 },

  { 10, 0, TARGET_STRING(
    "backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter/Add1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING(
    "backsupport_gyems_v4_f446/Back Exoskeleton Controller/Delta Lognormal Control/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter/Unit Delay"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

// Individual block tuning is not valid when inline parameters is *
//  selected. An empty map is produced to provide a consistent     *
//  interface independent  of inlining parameters.                 *

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  // addrMapIndex, blockPath,
  //  paramName, dataTypeIndex, dimIndex, fixPtIdx

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

// Block states information
static rtwCAPI_States rtBlockStates[] = {
  // addrMapIndex, contStateStartIndex, blockPath,
  //  stateName, pathAlias, dWorkIndex, dataTypeIndex, dimIndex,
  //  fixPtIdx, sTimeIndex, isContinuous, hierInfoIdx, flatElemIdx

  { 12, -1, TARGET_STRING(
    "backsupport_gyems_v4_f446/Back Exoskeleton\nController/DOb Controller\n(External Gains)/Inverse Nominal Plant"),
    TARGET_STRING("states"), "", 0, 0, 1, 0, 0, 0, -1, 0 },

  { 13, -1, TARGET_STRING(
    "backsupport_gyems_v4_f446/Back Exoskeleton\nController/DOb Controller\n(External Gains)/Low Pass Filter"),
    TARGET_STRING("states"), "", 0, 0, 1, 0, 0, 0, -1, 0 },

  { 14, -1, TARGET_STRING(
    "backsupport_gyems_v4_f446/Back Exoskeleton\nController/Trunk Tilt Calculation/Tilt Measurement/Complementary Filter/Delay"),
    TARGET_STRING("DSTATE"), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  { 15, -1, TARGET_STRING(
    "backsupport_gyems_v4_f446/Back Exoskeleton\nController/DOb Controller\n(External Gains)/Discrete PID Controller/Filter/Disc. Forward Euler Filter/Filter"),
    TARGET_STRING("DSTATE"), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  { 16, -1, TARGET_STRING(
    "backsupport_gyems_v4_f446/Back Exoskeleton\nController/DOb Controller\n(External Gains)/Discrete PID Controller/Integrator/Discrete/Integrator"),
    TARGET_STRING("DSTATE"), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  { 17, -1, TARGET_STRING(
    "backsupport_gyems_v4_f446/Back Exoskeleton\nController/Delta Lognormal Control/Filtered Derivative\n(Discrete or Continuous)/Integrator\n(Discrete or Continuous)/Discrete/Integrator"),
    TARGET_STRING("DSTATE"), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  { 18, -1, TARGET_STRING(
    "backsupport_gyems_v4_f446/Back Exoskeleton\nController/Delta Lognormal Control/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter/Unit Delay"),
    TARGET_STRING("DSTATE"), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  {
    0, -1, (NULL), (NULL), (NULL), 0, 0, 0, 0, 0, 0, -1, 0
  }
};

// Tunable variable parameters
static rtwCAPI_ModelParameters rtModelParameters[] = {
  // addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

// Initialize Data Address
static void InitializeDataAddr(void* dataAddr[], backsupportModelClass::DW *rtDW)
{
  dataAddr[0] = (void*) (&rtDW->LowpassFilter1_p.LowpassFilter1_c);
  dataAddr[1] = (void*) (&rtDW->LowpassFilter3.LowpassFilter1_c);
  dataAddr[2] = (void*) (&rtConstB.Gain);
  dataAddr[3] = (void*) (&rtConstB.Product);
  dataAddr[4] = (void*) (&rtDW->Saturation);
  dataAddr[5] = (void*) (&rtDW->In);
  dataAddr[6] = (void*) (&rtDW->In);
  dataAddr[7] = (void*) (&rtDW->Probe[0]);
  dataAddr[8] = (void*) (&rtConstB.Elementproduct[0]);
  dataAddr[9] = (void*) (&rtConstB.Add3[0]);
  dataAddr[10] = (void*) (&rtDW->UnitDelay_DSTATE);
  dataAddr[11] = (void*) (&rtDW->UnitDelay_DSTATE);
  dataAddr[12] = (void*) (&rtDW->InverseNominalPlant_states[0]);
  dataAddr[13] = (void*) (&rtDW->LowPassFilter_states[0]);
  dataAddr[14] = (void*) (&rtDW->Delay_DSTATE);
  dataAddr[15] = (void*) (&rtDW->Filter_DSTATE);
  dataAddr[16] = (void*) (&rtDW->Integrator_DSTATE_n);
  dataAddr[17] = (void*) (&rtDW->Integrator_DSTATE);
  dataAddr[18] = (void*) (&rtDW->UnitDelay_DSTATE);
}

#endif

// Initialize Data Run-Time Dimension Buffer Address
#ifndef HOST_CAPI_BUILD

static void InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

// Initialize logging function pointers
static void InitializeLoggingFunctions(RTWLoggingFcnPtr loggingPtrs[])
{
  loggingPtrs[0] = (NULL);
  loggingPtrs[1] = (NULL);
  loggingPtrs[2] = (NULL);
  loggingPtrs[3] = (NULL);
  loggingPtrs[4] = (NULL);
  loggingPtrs[5] = (NULL);
  loggingPtrs[6] = (NULL);
  loggingPtrs[7] = (NULL);
  loggingPtrs[8] = (NULL);
  loggingPtrs[9] = (NULL);
  loggingPtrs[10] = (NULL);
  loggingPtrs[11] = (NULL);
  loggingPtrs[12] = (NULL);
  loggingPtrs[13] = (NULL);
  loggingPtrs[14] = (NULL);
  loggingPtrs[15] = (NULL);
  loggingPtrs[16] = (NULL);
  loggingPtrs[17] = (NULL);
  loggingPtrs[18] = (NULL);
}

#endif

// Data Type Map - use dataTypeMapIndex to access this structure
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  // cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
  //  isComplex, isPointer, enumStorageType
  { "float", "real32_T", 0, 0, sizeof(real32_T), (uint8_T)SS_SINGLE, 0, 0, 0 },

  { "double", "real_T", 0, 0, sizeof(real_T), (uint8_T)SS_DOUBLE, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

// Structure Element Map - use elemMapIndex to access this structure
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  // elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex
  { (NULL), 0, 0, 0, 0 },
};

// Dimension Map - use dimensionMapIndex to access elements of ths structure
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  // dataOrientation, dimArrayIndex, numDims, vardimsIndex
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 }
};

// Dimension Array- use dimArrayIndex to access elements of this array
static uint_T rtDimensionArray[] = {
  1,                                   // 0
  1,                                   // 1
  2,                                   // 2
  1,                                   // 3
  6,                                   // 4
  1,                                   // 5
  3,                                   // 6
  1                                    // 7
};

// C-API stores floating point values in an array. The elements of this  *
//  are unique. This ensures that values which are shared across the model*
//  are stored in the most efficient way. These values are referenced by  *
//            - rtwCAPI_FixPtMap.fracSlopePtr,                            *
//            - rtwCAPI_FixPtMap.biasPtr,                                 *
//            - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
//            - rtwCAPI_SampleTimeMap.sampleOffsetPtr
static const real_T rtcapiStoredFloats[] = {
  0.002, 0.0
};

// Fixed Point Map
static rtwCAPI_FixPtMap rtFixPtMap[] = {
  // fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, (boolean_T)0 },
};

// Sample Time Map - use sTimeIndex to access elements of ths structure
static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  // samplePeriodPtr, sampleOffsetPtr, tid, samplingMode
  { static_cast<const void *>(&rtcapiStoredFloats[0]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), static_cast<int8_T>(1), static_cast<uint8_T>(0) },

  { (NULL), (NULL), -2, 0 },

  { static_cast<const void *>(&rtcapiStoredFloats[1]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), static_cast<int8_T>(0), static_cast<uint8_T>(0) },

  { (NULL), (NULL), -1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  // Signals:{signals, numSignals,
  //            rootInputs, numRootInputs,
  //            rootOutputs, numRootOutputs},
  //  Params: {blockParameters, numBlockParameters,
  //           modelParameters, numModelParameters},
  //  States: {states, numStates},
  //  Maps:   {dataTypeMap, dimensionMap, fixPtMap,
  //           elementMap, sampleTimeMap, dimensionArray},
  //  TargetType: targetType

  { rtBlockSignals, 12,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 0,
    rtModelParameters, 0 },

  { rtBlockStates, 7 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1013343880U,
    2345358492U,
    1647028158U,
    1939128111U },
  (NULL), 0,
  (boolean_T)0
};

// Function to get C API Model Mapping Static Info
const rtwCAPI_ModelMappingStaticInfo*
  backsupport_gyems_v4_f446_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

// Cache pointers into DataMapInfo substructure of RTModel
#ifndef HOST_CAPI_BUILD

void backsupport_gyems_v4_f446_InitializeDataMapInfo(backsupportModelClass::
  RT_MODEL *const rtM, backsupportModelClass::DW *rtDW)
{
  // Set C-API version
  rtwCAPI_SetVersion(rtM->DataMapInfo.mmi, 1);

  // Cache static C-API data into the Real-time Model Data structure
  rtwCAPI_SetStaticMap(rtM->DataMapInfo.mmi, &mmiStatic);

  // Cache static C-API logging data into the Real-time Model Data structure
  rtwCAPI_SetLoggingStaticMap(rtM->DataMapInfo.mmi, (NULL));

  // Cache C-API Data Addresses into the Real-Time Model Data structure
  InitializeDataAddr(rtM->DataMapInfo.dataAddress, rtDW);
  rtwCAPI_SetDataAddressMap(rtM->DataMapInfo.mmi, rtM->DataMapInfo.dataAddress);

  // Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure 
  InitializeVarDimsAddr(rtM->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(rtM->DataMapInfo.mmi,
    rtM->DataMapInfo.vardimsAddress);

  // Set Instance specific path
  rtwCAPI_SetPath(rtM->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(rtM->DataMapInfo.mmi, (NULL));

  // Cache C-API logging function pointers into the Real-Time Model Data structure 
  InitializeLoggingFunctions(rtM->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(rtM->DataMapInfo.mmi, rtM->DataMapInfo.loggingPtrs);

  // Cache the instance C-API logging pointer
  rtwCAPI_SetInstanceLoggingInfo(rtM->DataMapInfo.mmi, (NULL));

  // Set reference to submodels
  rtwCAPI_SetChildMMIArray(rtM->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(rtM->DataMapInfo.mmi, 0);
}

#else                                  // HOST_CAPI_BUILD
#ifdef __cplusplus

extern "C"
{

#endif

  void backsupport_gyems_v4_f446_host_InitializeDataMapInfo
    (backsupport_gyems_v4_f446_host_DataMapInfo_T *dataMap, const char *path)
  {
    // Set C-API version
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    // Cache static C-API data into the Real-time Model Data structure
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    // host data address map is NULL
    rtwCAPI_SetDataAddressMap(dataMap->mmi, (NULL));

    // host vardims address map is NULL
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, (NULL));

    // Set Instance specific path
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, (NULL));

    // Set reference to submodels
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}

#endif
#endif                                 // HOST_CAPI_BUILD

//
// File trailer for generated code.
//
// [EOF]
//
