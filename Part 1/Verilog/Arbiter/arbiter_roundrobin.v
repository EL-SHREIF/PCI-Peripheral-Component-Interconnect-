module arbiter_roundrobin(reqA,reqB,reqC,frame,clk,gntA,gntB,gntC);
input frame,clk;
input reqA,reqB,reqC;
output reg gntA ,gntB,gntC;
integer counter = 0;
initial
begin
gntA=1;
gntB=1;
gntC=1;
end

always @(posedge clk)
begin 
if(frame==1&& gntA==1 && gntB==1 && gntC==1)
begin
if(counter==0)
begin
@(negedge clk)begin gntA<=0; counter<=counter+1; end
end


else if(counter==1)
begin
@(negedge clk)begin gntB<=0; counter<=counter+1; end
end


else if(counter==2)
begin
@(negedge clk)begin gntC<=0; counter<=0; end
end

end




else if(frame==0)
begin
if(gntA==0)
begin
@(negedge clk) begin gntA<=1; gntB<=0; counter<=counter+1;  end
end

else if(gntB==0)
begin
@(negedge clk) begin gntB<=1; gntC<=0; counter<=counter+1;  end
end

else if(gntC==0)
begin
@(negedge clk) begin gntC<=1; gntA<=0; counter<=0;  end
end

end
end
endmodule
