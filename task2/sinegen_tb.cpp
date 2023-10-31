#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    //init top verilog instance
    Vsinegen* top = new Vsinegen;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("sinegen.vcd");

    // init Vbuddy
    if(vbdOpen()!=1) return(-1);
    vbdHeader("Lab 2: SigGen");

    top->incr = 1;
    top->clk = 1;
    top->rst = 0;
    top->en = 1;

    for(i=0; i<1000000; i++){

        for (clk=0; clk<2; clk++){
            tfp->dump (2*i+clk); 
            top->clk = !top->clk;
            top->eval ();
        }

        top->offst = vbdValue();

        // ++++ Plot output on Vbuddy
        vbdPlot(int(top->dout1), 0, 255);
        vbdPlot(int(top->dout2), 0, 255);
        vbdCycle(i+1);
        // ---- end of Vbuddy output section

        // either simulation finished, or 'q' is pressed
        if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
            exit(0);                // ... exit if finish OR 'q' pressed
    }
    vbdClose();
    tfp->close();
    exit(0);
}
