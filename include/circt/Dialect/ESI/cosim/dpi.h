//===- dpi.h - DPI function C++ declarations --------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Originally generated from 'Cosim_DpiPkg.sv' by an RTL simulator. All these
// functions are called from RTL. Some of the funky types are produced by the
// RTL simulators when it did the conversion.
//
//===----------------------------------------------------------------------===//

#ifndef CIRCT_DIALECT_ESI_COSIM_DPI_H
#define CIRCT_DIALECT_ESI_COSIM_DPI_H

#include "external/dpi/svdpi.h"

#ifdef WIN32
#define DPI extern "C" __declspec(dllexport)
#else
#define DPI extern "C"
#endif

#ifdef __cplusplus
extern "C" {
#endif
/// Register an endpoint.
DPI int sv2cCosimserverEpRegister(char *endpointId, long long sendTypeId,
                                  int sendTypeSize, long long recvTypeId,
                                  int recvTypeSize);
/// Try to get a message from a client.
DPI int sv2cCosimserverEpTryGet(char *endpointId,
                                // NOLINTNEXTLINE(misc-misplaced-const)
                                const svOpenArrayHandle data,
                                unsigned int *sizeBytes);
/// Send a message to a client.
DPI int sv2cCosimserverEpTryPut(char *endpointId,
                                // NOLINTNEXTLINE(misc-misplaced-const)
                                const svOpenArrayHandle data, int dataLimit);

/// Start the server. Not required as the first endpoint registration will do
/// this. Provided if one wants to start the server early.
DPI int sv2cCosimserverInit();
/// Shutdown the RPC server.
DPI void sv2cCosimserverFinish();

/// Register an MMIO module. Just checks that there is only one instantiated.
DPI int sv2cCosimserverMMIORegister();

/// Read MMIO function pair. Assumes that reads come back in the order in which
/// they were requested.
DPI int sv2cCosimserverMMIOReadTryGet(int *address);
DPI void sv2cCosimserverMMIOReadRespond(long long data, char error);

/// Write MMIO function pair. Assumes that write errors come back in the order
/// in which the writes were issued.
DPI int sv2cCosimserverMMIOWriteTryGet(int *address, long long *data);
DPI void sv2cCosimserverMMIOWriteRespond(char error);

#ifdef __cplusplus
}

#endif

#endif
