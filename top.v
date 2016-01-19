module top();
reg [0:7] a,b;
wire [0:7] c;
adder ADDER(a,b,c);
initial 
begin
$monitor("%g c = %b",$time,c);
#0 a = 3;b = 3;
#10 a = 2; b = 2;
#15 $finish;
end
endmodule
