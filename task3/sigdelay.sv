module sigdelay #(
    parameter   A_WIDTH = 9,
                D_WIDTH = 8
)(
    // interface signals
    input   logic                   clk,    // clock
    input   logic                   rst,    // reset
    input   logic                   en,     // enable
    input   logic                   wr,     // write
    input   logic                   rd,     // read
    input   logic   [D_WIDTH-1:0]   offset,   // offset
    input   logic   [D_WIDTH-1:0]   incr,   // increment for addr counter
    input   logic   [A_WIDTH-1:0]   mic_signal,  // output data1
    output  logic   [A_WIDTH-1:0]   delayed_signal   // output data2
);

    logic   [A_WIDTH-1:0]           wr_address;    // interconnect wire1
    logic   [A_WIDTH-1:0]           rd_address;    // interconnect wire2

counter addCounter (
    .clk (clk),
    .rst (rst),
    .en (en),
    .incr (incr),
    .count (wr_address)
);

always_comb begin
        rd_address = wr_address - offset;
    end

ram sigRam (
    .clk (clk),
    .wr_en (wr),
    .wr_addr (wr_address),
    .din (mic_signal),
    .rd_en (rd),
    .rd_addr (rd_address),
    .dout (delayed_signal)
);

endmodule
