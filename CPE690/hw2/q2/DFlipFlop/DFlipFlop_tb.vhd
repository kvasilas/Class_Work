LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY DFlipFlop_tb IS
END DFlipFlop_tb;
 
ARCHITECTURE behavior OF DFlipFlop_tb IS 
 
    COMPONENT DFF
    PORT(
         D : IN  std_logic;
         clk : IN  std_logic;
         Q : OUT  std_logic;
         Qb : OUT  std_logic
        );
    END COMPONENT;
    
   --Inputs
   signal D : std_logic := '0';
   signal clk : std_logic := '0';

 	--Outputs
   signal Q : std_logic;
   signal Qb : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
   uut: DFF PORT MAP (
          D => D,
          clk => clk,
          Q => Q,
          Qb => Qb
        );

	D_wave : process is
	constant per : time:= 7 ns;
		begin
			D <= '0';
			wait for per;
			D <= '1';
			wait for per;
	end process;

   clk_process :process is
   constant per : time:= 5 ns;
	begin
		clk <= '0';
		wait for per;
		clk <= '1';
		wait for per;
   end process;

END;
