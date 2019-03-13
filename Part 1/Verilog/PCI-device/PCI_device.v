module PCI_device(add_data,
Control_Byte_enable,
Frame_low,TRDY_low,
IRDY_low,
DevSel_low,
Req_low,
GNT_low,clk,
Reset_low,
Force_req_low,
address_to_contact,
Force_control,
Force_byte_enable,
Force_data,
Force_no_of_dataphases,
Force_my_address);

inout [31:0]add_data;//address_data for system bus
inout [3:0]Control_Byte_enable;//C/BE for system bus
inout Frame_low,TRDY_low,IRDY_low,DevSel_low;//FRAME,TRDY,IRDY,DevSel for system bus
output Req_low;//Req for system bus
input GNT_low,clk,Reset_low;//GNT,clk,Reset for device Reset and clk ll top module

//these signals are not found in real life but here for simulation only(these all signals matter only in master)
input Force_req_low;//while asserted the device wants the bus for transaction
input [31:0]address_to_contact;//just for simulation to contact another device(to be given to add_data)
input [3:0]Force_control;//just for simulation to control read or write(in case the device is master)
input [3:0]Force_byte_enable;//also simulation
input [31:0]Force_data;//also simulation
input [3:0]Force_no_of_dataphases;//no. of data phases in one transaction
input [31:0]Force_my_address;
//memory of device
reg [31:0]mem[0:9];
/*
some registers to save states and data and control inside device to be assigned to signals at correct-time
the main task to put correct data inside it at correct time state&&bus_idle are flags
*/
reg [1:0] state_Who_I_Am_reg;//z not anything (to be reset firstly in testbench) 0 Master_read 1 Master_write 2 Slave_read 3 Slave_write //others don't care will not happen
reg [31:0]data_address_reg;//data/address stored in device to be written to another device
reg [3:0]control_byte_enable_reg;//stores byte enable to be written to another device
reg Master_took_bus_reg;// 0 doesn't take the bus 1 took it
reg you_are_selected_as_target_reg;//0 not selected 1 selected
reg [3:0] No_of_data_phases_reg;//suppose max data phases is 7
reg data_or_address_phase_reg;//0 address phase 1 data phase
reg [3:0]how_many_cycles_target_doesnot_respond_reg;
reg [3:0] what_data_phase_you_are_in_reg;
reg no_device_respond_reg;
reg end_of_transaction_arf3_frame;
reg end_MR_OR_MW_reg;
reg first_time_to_write_data_Master_side;
reg target_can_write_onbus_reg;
//states of device
parameter MR= 2'b00 , MW = 2'b01, SR= 2'b10, SW = 2'b11 ,Not_anything=2'bzz,occur=1,not_occur=0,read_command=4'b0010,write_command=4'b0011; 
/*now the task how to fill these registers considering bus commands I/O READ :0010 and I/O write:0011*/

//device working principal

assign Frame_low=((no_device_respond_reg==1&&(state_Who_I_Am_reg==MR||state_Who_I_Am_reg==MW))
||((state_Who_I_Am_reg==MR||state_Who_I_Am_reg==MW)&&end_of_transaction_arf3_frame==1))?1:
(Master_took_bus_reg)?0:Frame_low;//to be completed
assign add_data=(no_device_respond_reg==1&&state_Who_I_Am_reg==MR)?32'bzzzz_zzzz_zzzz_zzzz_zzzz_zzzz_zzzz_zzzz:(Master_took_bus_reg&&data_or_address_phase_reg==0)?data_address_reg:
(state_Who_I_Am_reg==MR&&Master_took_bus_reg&&data_or_address_phase_reg)?32'bzzzz_zzzz_zzzz_zzzz_zzzz_zzzz_zzzz_zzzz:add_data;//to be completed
assign Control_Byte_enable=(no_device_respond_reg==1&&state_Who_I_Am_reg==MR)?4'bzzzz:(Master_took_bus_reg&&data_or_address_phase_reg==0||Master_took_bus_reg==0&&data_or_address_phase_reg)?control_byte_enable_reg:Control_Byte_enable;//to be completed*/

assign IRDY_low=(no_device_respond_reg===1&&(state_Who_I_Am_reg===MR||state_Who_I_Am_reg===MW))?1:
(end_MR_OR_MW_reg===1&&(state_Who_I_Am_reg===MR||state_Who_I_Am_reg===MW))?1:
(state_Who_I_Am_reg===MR&&Master_took_bus_reg===1&&data_or_address_phase_reg===1)?0:
(first_time_to_write_data_Master_side==1&&state_Who_I_Am_reg===MW)?0:(IRDY_low===1'bx)?1:IRDY_low;

assign DevSel_low=(you_are_selected_as_target_reg==1)?0:(DevSel_low===1'bx||end_MR_OR_MW_reg==1)?1:DevSel_low;
assign TRDY_low=((target_can_write_onbus_reg==1&&you_are_selected_as_target_reg==1)||(you_are_selected_as_target_reg==1&&state_Who_I_Am_reg==SR))?0
:(TRDY_low===1'bx||end_MR_OR_MW_reg==1)?1:TRDY_low;
//always put Req_low = Force_req_low ;
assign Req_low=(Reset_low==0)?1:Force_req_low;//Req_low is output to arbitar;

always@(Reset_low)
begin
if(Reset_low==0)
begin
state_Who_I_Am_reg<=Not_anything;//initial state is z neither Master nor slave
Master_took_bus_reg<=not_occur;//initially no device took bus
you_are_selected_as_target_reg<=not_occur;//initially no target is selected
how_many_cycles_target_doesnot_respond_reg<=0;
what_data_phase_you_are_in_reg<=0;
no_device_respond_reg<=0;
end_of_transaction_arf3_frame<=0;
end_MR_OR_MW_reg<=0;
first_time_to_write_data_Master_side<=0;
target_can_write_onbus_reg<=0;
end
end

//reading at posedge of clk
always@(posedge clk)
begin //begin of posedge clk
//check response of devices
if(no_device_respond_reg==1) begin no_device_respond_reg<=0; state_Who_I_Am_reg<=Not_anything;end//to return to neither Master nor slave
if(end_of_transaction_arf3_frame==1)begin end_of_transaction_arf3_frame<=0; end
if(end_MR_OR_MW_reg==1) begin what_data_phase_you_are_in_reg<=0; target_can_write_onbus_reg<=0;target_can_write_onbus_reg<=0;
first_time_to_write_data_Master_side<=0; end_MR_OR_MW_reg<=0; state_Who_I_Am_reg<=Not_anything; end
if(Reset_low)
begin//begin of not reset

//first occurance of taking bus as Master(ddress_phase)
if(Frame_low==1&&IRDY_low==1&&GNT_low==0&&state_Who_I_Am_reg===Not_anything)//bus is idle and no device gets bus-this device is granted so it can take the bus
begin// begin of bus_idle and no device takes it and the device wants to get it(this the first time to take bus so it is address_phase

//put the address who wants to contact and command you want
data_address_reg<=address_to_contact;
control_byte_enable_reg<=Force_control;//at this point contain the command
No_of_data_phases_reg<=Force_no_of_dataphases;
data_or_address_phase_reg<=0;
what_data_phase_you_are_in_reg<=0;
no_device_respond_reg<=0;
end_of_transaction_arf3_frame<=0;
end_MR_OR_MW_reg<=0;
first_time_to_write_data_Master_side<=0;
if(Force_control==read_command) begin  state_Who_I_Am_reg<=MR;@(negedge clk) Master_took_bus_reg<=occur; end//now you can assign transaction for first time(nazel el frame b2a w 3esh.......)
else if(Force_control==write_command) begin state_Who_I_Am_reg<=MW;@(negedge clk) Master_took_bus_reg<=occur; end//now you can assign transaction for first time(nazel el frame b2a w 3esh.......)


end//end of if for bus_idle&&no device takes it and the device wants to get it(this the first time to take bus so it is address_phase
//end of first occurance of taking bus as Master(address phase)
else if(state_Who_I_Am_reg==MR)
begin//start Of MR

if(data_or_address_phase_reg==0)//this means that one cycle passes and address on bus read by other devices
begin @(negedge clk) control_byte_enable_reg<=Force_byte_enable; @(negedge clk)data_or_address_phase_reg<=1; end//a2dar dlw2ty a7ot el byte enable w anzl el IRDY_low
else if(data_or_address_phase_reg&&Master_took_bus_reg==occur)//now first cycle comes where address_Data=z (turn around cycle)
begin @(negedge clk) Master_took_bus_reg<=not_occur; end//not take the bus in order to give target ability to write

else if(Master_took_bus_reg==not_occur)//know check devsel and data
begin //begin check of data and devsel
if(DevSel_low==1)
begin //begin of Devsel==1
how_many_cycles_target_doesnot_respond_reg<=how_many_cycles_target_doesnot_respond_reg+1;
if(how_many_cycles_target_doesnot_respond_reg==3)
begin//begin of how_many_cycles_target_doesnot_respond_reg==3

Master_took_bus_reg<=not_occur;//to return to no device took bus
you_are_selected_as_target_reg<=not_occur;//to return no target is selected
how_many_cycles_target_doesnot_respond_reg<=0;
what_data_phase_you_are_in_reg<=0;
@(negedge clk)no_device_respond_reg<=1;
end//end how_many_cycles_target_doesnot_respond_reg==3
end //end of Devsel==1
else 
begin//begin of else //here happens tranfer of dataphase
 if(TRDY_low==0&&IRDY_low==0)
begin//begin of TRDY and IRDY==0
if(Control_Byte_enable[0]==1) begin mem[what_data_phase_you_are_in_reg][7:0]<=add_data[7:0];end
if(Control_Byte_enable[1]==1) begin mem[what_data_phase_you_are_in_reg][15:8]<=add_data[15:8];end
if(Control_Byte_enable[2]==1) begin mem[what_data_phase_you_are_in_reg][23:16]<=add_data[23:16];end
if(Control_Byte_enable[3]==1) begin mem[what_data_phase_you_are_in_reg][31:24]<=add_data[31:24];end
what_data_phase_you_are_in_reg<=what_data_phase_you_are_in_reg+1;
if(what_data_phase_you_are_in_reg==No_of_data_phases_reg-1&&TRDY_low==0) begin @(negedge clk) end_of_transaction_arf3_frame<=1;end
else if(what_data_phase_you_are_in_reg==No_of_data_phases_reg) begin @(negedge clk) end_MR_OR_MW_reg<=1; end
 end//end of TRDY and IRDY==0
 end//end of else
 end//end of check of data and devsel
end//end Of MR

else if(state_Who_I_Am_reg==MW)//kda 3da positive cycle w el address m7tot
begin//begin of state_Who_I_Am_reg==MW
if(first_time_to_write_data_Master_side==0)//first time to write data
begin//begin of first time==0
first_time_to_write_data_Master_side<=1;
@(negedge clk) control_byte_enable_reg<=Force_byte_enable;
@(negedge clk) data_address_reg<=Force_data;
end//end of first_time==0
else
begin//begin of else
if(DevSel_low==1)
begin //begin of Devsel==1
how_many_cycles_target_doesnot_respond_reg<=how_many_cycles_target_doesnot_respond_reg+1;
if(how_many_cycles_target_doesnot_respond_reg==3)
begin//begin of how_many_cycles_target_doesnot_respond_reg==3

Master_took_bus_reg<=not_occur;//to return to no device took bus
you_are_selected_as_target_reg<=not_occur;//to return no target is selected
how_many_cycles_target_doesnot_respond_reg<=0;
what_data_phase_you_are_in_reg<=0;
@(negedge clk)no_device_respond_reg<=1;
end//end how_many_cycles_target_doesnot_respond_reg==3
end //end of Devsel==1
else 
begin//begin of else //here happens tranfer of dataphase
 if(TRDY_low==0&&IRDY_low==0)
begin//begin of TRDY and IRDY==0
@(negedge clk) control_byte_enable_reg<=Force_byte_enable;
@(negedge clk) data_address_reg<=Force_data;
what_data_phase_you_are_in_reg<=what_data_phase_you_are_in_reg+1;
if(what_data_phase_you_are_in_reg==No_of_data_phases_reg-1&&TRDY_low==0) begin @(negedge clk) end_of_transaction_arf3_frame<=1;end
else if(what_data_phase_you_are_in_reg==No_of_data_phases_reg) begin @(negedge clk) end_MR_OR_MW_reg<=1; end
 end//end of TRDY and IRDY==0
end //begin of else //here happens tranfer of dataphase
end//end of else
end//end of state_Who_I_Am_reg==MW

end//end of not reset
end//end of posedge clk

always@(posedge clk)
begin//begin of posedge

if(state_Who_I_Am_reg==Not_anything&&Frame_low==0&&add_data==Force_my_address&&(Control_Byte_enable==read_command||Control_Byte_enable==write_command))
begin//this device is selected
if(Control_Byte_enable==read_command)begin state_Who_I_Am_reg=SW;@(negedge clk)you_are_selected_as_target_reg<=1;end
if(Control_Byte_enable==write_command)begin state_Who_I_Am_reg=SR;@(negedge clk)you_are_selected_as_target_reg<=1;end
what_data_phase_you_are_in_reg<=0;
end//end of this device is selected
else if(state_Who_I_Am_reg==SW)
begin//begin of state_Who_I_Am_reg==SW
if(add_data==32'bzzzz_zzzz_zzzz_zzzz_zzzz_zzzz_zzzz_zzzz)//here target can write on bus
begin @(negedge clk) data_address_reg<=Force_data;@(negedge clk) target_can_write_onbus_reg<=1;end
else if(Frame_low==1) //master ends transaction
begin @(negedge clk) end_MR_OR_MW_reg<=1;end
else if(IRDY_low==0&&TRDY_low==0) begin @(negedge clk) data_address_reg<=Force_data; end
end//end of state_Who_I_Am_reg==SW


else if(state_Who_I_Am_reg==SR)
begin//begin of state_Who_I_Am_reg==SR
if(TRDY_low==0&&IRDY_low==0)
begin//begin of TRDY and IRDY==0
if(Control_Byte_enable[0]==1) begin mem[what_data_phase_you_are_in_reg][7:0]<=add_data[7:0];end
if(Control_Byte_enable[1]==1) begin mem[what_data_phase_you_are_in_reg][15:8]<=add_data[15:8];end
if(Control_Byte_enable[2]==1) begin mem[what_data_phase_you_are_in_reg][23:16]<=add_data[23:16];end
if(Control_Byte_enable[3]==1) begin mem[what_data_phase_you_are_in_reg][31:24]<=add_data[31:24];end
what_data_phase_you_are_in_reg<=what_data_phase_you_are_in_reg+1;
if(Frame_low==1) begin @(negedge clk) end_MR_OR_MW_reg<=1;end
end//end of TRDY and IRDY==0
end //end state_Who_I_Am_reg==SR
end//end of posedge

endmodule


module tb_read();
PCI_device master(add_data,
Control_Byte_enable,
Frame_low,TRDY_low,
IRDY_low,
DevSel_low,
Req_low,
GNT_low,clk,
Reset_low,
Force_req_low,
address_to_contact,
Force_control,
Force_byte_enable,
Force_data,
Force_no_of_dataphases,
Force_my_address);

 PCI_device salve(add_data,
Control_Byte_enable,
Frame_low,TRDY_low,
IRDY_low,
DevSel_low,
Req_low,
GNT_low,clk,
Reset_low,
Force_req_low,
address_to_contact,
Force_control,
Force_byte_enable,
Force_data,
Force_no_of_dataphases,
Force_my_address);
endmodule 