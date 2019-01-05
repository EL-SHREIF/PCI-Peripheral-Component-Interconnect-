module arbiter_fcfs(reqA,reqB,reqC,frame,clk,gntA,gntB,gntC);
input frame,clk;
input reqA,reqB,reqC;
output reg gntA ,gntB,gntC;
reg [3:0]queue[0:9];
integer front =0, rear = 0;
integer i;

initial
begin
gntA=1;
gntB=1;
gntC=1;
end

parameter A = 10 , B = 11 , C = 12;
always @(posedge clk)
begin 

if(frame==1 &&gntA==1 && gntB==1 && gntC==1) // bus is idle
begin
	if(reqA==0 /*&& queue[rear]!=10*/)  // device A needs the bus so give it the bus and no need to push it in the queue
	begin
	@(negedge clk) gntA<=0;
	end

	if(reqB==0 /*&& queue[rear] != 11*/) // device B needs the bus
	begin
	if(reqA==1)   // check if A doesn't need the bus so give the bus to B and no need to push it in the queue
	@(negedge clk) gntB<=0;
	else   // else push B in the queue
	queue[rear] = B;
	rear = rear +1;
	end

        if(reqC==0 /*&& queue[rear] != 12*/)  // device C needs the bus
	begin
	if(reqA==1 && reqB==1)       // check if A and B don't need the bus so give the bus to C and no need to push it in the queue
	@(negedge clk) gntC<=0;
	else     // else push C in the queue
	queue[rear] = C;
	rear = rear +1;
	end
end



else if(frame==1 && (gntA==0||gntB==0||gntC==0))   // bus is not idle and frame is 1
begin
	if(gntA==0)       // if A has the bus
	begin
	end



	else if(gntB==0) // if B has the bus
	begin
	end
end




else if(frame==0)  // bus is not idle and frame is 0
begin

	if(gntA==0)  // if A has the bus
	begin

	if(reqA==0 /*&& queue[rear]!=10*/ )  // check if A needs the bus again then push it in the queue
	begin
	queue[rear] = A;
	rear = rear +1;
	end

  	// now time to grant another device as A has taken the bus
	@(negedge clk)
	begin
	 gntA<=1; // disgrant A
	if(queue[0] == A)  //if the first one in the queue is A so give it the bus again
	 begin gntA<=0; for(i=0;i<9;i=i+1) queue[i] = queue[i+1]; rear = rear-1; end

	else if(queue[0] == 😎 //if the first one in the queue is B so give it the bus 
	 begin gntB<=0; for(i=0;i<9;i=i+1) queue[i] = queue[i+1]; rear = rear-1; end

	else if(queue[0]==C) //if the first one in the queue is C so give it the bus 
	begin gntC<=0;  for(i=0;i<9;i=i+1) queue[i] = queue[i+1]; rear = rear-1; end
	end
	end


	else if(gntB==0)  // if B has the bus
	begin

	if(reqB==0 /*&& queue[rear]!=11*/ )  // check if B needs the bus again then push it in the queue
	begin
	queue[rear] = B;
	rear = rear +1;
	end
	// now time to grant another device as B has taken the bus
	@(negedge clk)
	begin
	 gntB<=1; // disgrant B
	if(queue[0] == A) //if the first one in the queue is A so give it the bus 
	 begin gntA<=0; for(i=0;i<9;i=i+1) queue[i] = queue[i+1]; rear = rear-1; end

	else if(queue[0] == 😎 //if the first one in the queue is B so give it the bus again
	 begin gntB<=0; for(i=0;i<9;i=i+1) queue[i] = queue[i+1]; rear = rear-1; end

	else if(queue[0]==C) //if the first one in the queue is C so give it the bus 
	begin gntC<=0;  for(i=0;i<9;i=i+1) queue[i] = queue[i+1]; rear = rear-1; end
	end

	end



	else if(gntC==0)  // if C has the bus
	begin
	

	if(reqC==0 /*&& queue[rear]!=12 */) // check if C needs the bus again then push it in the queue
	begin
	queue[rear] = C;
	rear = rear +1;
	end

	// now time to grant another device as B has taken the bus
	@(negedge clk)
	begin
	 gntC<=1; //disgrant C
	if(queue[0] == A) //if the first one in the queue is A so give it the bus 
	 begin gntA<=0; for(i=0;i<9;i=i+1) queue[i] = queue[i+1]; rear = rear-1; end

	else if(queue[0] == 😎 //if the first one in the queue is B so give it the bus 
	 begin gntB<=0; for(i=0;i<9;i=i+1) queue[i] = queue[i+1]; rear = rear-1; end

	else if(queue[0]==C) //if the first one in the queue is C so give it the bus again
	begin gntC<=0;  for(i=0;i<9;i=i+1) queue[i] = queue[i+1]; rear = rear-1; end
	end

	end



	else
	begin
	if(reqA==0)
	@(negedge clk) begin  gntA<=0; end
	else if(reqB==0)
	@(negedge clk) begin  gntB<=0;  end
	else if(reqC==0)
	@(negedge clk) begin gntC<=0; end
	end
end


end




endmodule
