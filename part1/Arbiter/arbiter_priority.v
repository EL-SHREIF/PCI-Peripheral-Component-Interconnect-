module arbiter_priority(reqA,reqB,reqC,frame,clk,gntA,gntB,gntC);
input frame,clk;
input reqA,reqB,reqC;
output reg gntA ,gntB,gntC;



initial
begin
gntA=1;
gntB=1;
gntC=1;
end


always@(posedge clk)

begin
if(frame==1 && gntA==1 && gntB==1 && gntC==1)
begin
	if(reqA==0)     // device A needs the bus 
	@(negedge clk) gntA<=0;

	else if(reqB==0)      // device B needs the bus 
	@(negedge clk) gntB<=0;

	else if(reqC==0)     // device C needs the bus 
	@(negedge clk) gntC<=0;
end

else if(frame==0)
begin

	if(gntA==0) // means device A has taken the bus 
	begin
	if(reqA==0)  // device A needs the bus again
	@(negedge clk) begin gntA<=0;  end
	else if(reqB==0) // device B needs the bus
	@(negedge clk) begin gntA<=1; gntB<=0; end
	else if(reqC==0) // device C needs the bus
	@(negedge clk) begin gntA<=1; gntC<=0; end
	else        // no device needs the bus 
	@(negedge clk) begin gntA<=1; end
	end


	else if(gntB==0)  // means device B has taken the bus 
	begin
	if(reqA==0)        // device A needs the bus 
	@(negedge clk) begin gntB<=1; gntA<=0; end
	else if(reqB==0) // device B needs the bus again
	@(negedge clk) begin gntB<=0; end
	else if(reqC==0) // device C needs the bus 
	@(negedge clk) begin gntB<=1; gntC<=0; end
	else           // no device needs the bus
	@(negedge clk) begin gntB<=1; end
	end

	else if(gntC==0)  // means device C has taken the bus 
	begin
	if(reqA==0)          // device A needs the bus
	@(negedge clk) begin gntC<=1; gntA<=0; end     
	else if(reqB==0)   // device B needs the bus
	@(negedge clk) begin gntC<=1; gntB<=0; end
	else if(reqC==0)     // device C needs the bus again
	@(negedge clk) begin gntC<=0; end
	else           // no device needs the bus
	@(negedge clk) begin gntC<=1; end
	end

	/*else
	begin
	if(reqA==0)
	@(negedge clk) begin  gntA<=0; end
	else if(reqB==0)
	@(negedge clk) begin  gntB<=0;  end
	else if(reqC==0)
	@(negedge clk) begin gntC<=0; end
	end*/
end
end

endmodule
