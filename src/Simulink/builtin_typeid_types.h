//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: builtin_typeid_types.h
//
// Code generated for Simulink model 'backsupport_gyems_v4_f446'.
//
// Model version                  : 7.21
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri May 10 14:10:16 2024
//
#ifndef BUILTIN_TYPEID_TYPES_H
#define BUILTIN_TYPEID_TYPES_H
#ifndef BUILTIN_TYPEID_TYPES
#define BUILTIN_TYPEID_TYPES

// Enumeration of built-in data types
typedef enum {
  SS_DOUBLE = 0,
  SS_SINGLE = 1,
  SS_INT8 = 2,
  SS_UINT8 = 3,
  SS_INT16 = 4,
  SS_UINT16 = 5,
  SS_INT32 = 6,
  SS_UINT32 = 7,
  SS_BOOLEAN = 8
} BuiltInDTypeId;

#define SS_NUM_BUILT_IN_DTYPE          ((int)SS_BOOLEAN+1)

// Enumeration for MAT-file logging code
typedef int DTypeId;

// Enumeration of pre-defined data types
typedef enum {
  SS_FCN_CALL = 9,
  SS_INTEGER = 10,
  SS_POINTER = 11,
  SS_INTERNAL_DTYPE2 = 12,
  SS_TIMER_UINT32_PAIR = 13,
  SS_CONNECTION_TYPE = 14
} PreDefinedDTypeId;

#endif                                 // BUILTIN_TYPEID_TYPES
#endif                                 // BUILTIN_TYPEID_TYPES_H

//
// File trailer for generated code.
//
// [EOF]
//
