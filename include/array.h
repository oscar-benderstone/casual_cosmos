// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// Helper macros for statically allocated arrays.
// Warning: these MUST be used as the same
// scope of local arrays.
// However, for global ones,
// they can be used anywhere
// (or for static ones,
// anywhere in the same compilation unit).
// TODO: double check these against a static analyzer!

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ARRAY_TOP(array) (ARRAY_LENGTH(array) - 1)
