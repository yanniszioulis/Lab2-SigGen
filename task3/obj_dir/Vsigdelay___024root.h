// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsigdelay.h for the primary calling header

#ifndef VERILATED_VSIGDELAY___024ROOT_H_
#define VERILATED_VSIGDELAY___024ROOT_H_  // guard

#include "verilated.h"

class Vsigdelay__Syms;

class Vsigdelay___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(en,0,0);
    VL_IN8(wr,0,0);
    VL_IN8(rd,0,0);
    VL_IN8(offset,7,0);
    VL_IN8(incr,7,0);
    CData/*7:0*/ sigdelay__DOT____Vcellout__sigRam__dout;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VL_IN16(mic_signal,8,0);
    VL_OUT16(delayed_signal,8,0);
    SData/*8:0*/ sigdelay__DOT__wr_address;
    SData/*8:0*/ __Vdly__sigdelay__DOT__wr_address;
    VlUnpacked<CData/*7:0*/, 512> sigdelay__DOT__sigRam__DOT__ram_array;

    // INTERNAL VARIABLES
    Vsigdelay__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsigdelay___024root(Vsigdelay__Syms* symsp, const char* name);
    ~Vsigdelay___024root();
    VL_UNCOPYABLE(Vsigdelay___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
