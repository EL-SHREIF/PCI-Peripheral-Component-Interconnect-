module arbiter_tb();
reg reqA,reqB,reqC,frame,clk,mode;
wire gntA,gntB,gntC;
initial
begin
clk=0;
mode = 0;
frame=1;
reqA=1;
reqB=1;
reqC=1;
#2
reqA=0;
reqB=1;
reqC=1;
#8
reqB=0;
#10

frame = 0;
#10
frame=1;
#20
frame = 0;
reqB=1;
#10
frame = 1;
#20
frame=0;
reqA=1;
#10
frame=1;
// for roundrobin
#20
frame=0;
#10
frame=1;
end
always
begin
#5 clk=~clk;
end
arbiter_fcfs a1(reqA,reqB,reqC,frame,clk,gntA,gntB,gntC);
endmodule
