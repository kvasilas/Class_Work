LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY shift_reg_tb IS
END shift_reg_tb;
 
ARCHITECTURE behavior OF shift_reg_tb IS 
 
    COMPONENT shift_reg
    PORT(
         sin : IN  std_logic;
         clk : IN  std_logic;
         Q0 : OUT  std_logic;
         Q1 : OUT  std_logic;
         Q2 : OUT  std_logic;
         Q3 : OUT  std_logic;
         Qb : OUT  std_logic
        );
    END COMPONENT;
    
   --Inputs
   signal sin : std_logic := '0';
   signal clk : std_logic := '0';

 	--Outputs
   signal Q0 : std_logic;
   signal Q1 : std_logic;
   signal Q2 : std_logic;
   signal Q3 : std_logic;
   signal Qb : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: shift_reg PORT MAP (
          sin => sin,
          clk => clk,
          Q0 => Q0,
          Q1 => Q1,
          Q2 => Q2,
          Q3 => Q3,
          Qb => Qb
        );

	clk_wave : process is 
	constant per : time:= 10 ns;
		begin
			clk <= '0';
			wait for per;
			clk <= '1';
			wait for per;
		end process;
	sin_wave : process is 
	constant per : time:= 12 ns;
		begin 
			sin <= '0';
			wait for per;
			sin <= '1';
			wait for per;
		end process;

END;
