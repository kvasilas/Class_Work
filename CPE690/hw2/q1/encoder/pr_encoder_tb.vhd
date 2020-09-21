--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   22:58:56 09/20/2020
-- Design Name:   
-- Module Name:   /home/kcv/Class_Work/CPE690/hw2/q1/encoder/pr_encoder_tb.vhd
-- Project Name:  encoder
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: pr_encoder
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY pr_encoder_tb IS
END pr_encoder_tb;
 
ARCHITECTURE behavior OF pr_encoder_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT pr_encoder
    PORT(
         S0 : IN  std_logic;
         S1 : IN  std_logic;
         S2 : IN  std_logic;
         S3 : IN  std_logic;
         Z : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal S0 : std_logic := '0';
   signal S1 : std_logic := '0';
   signal S2 : std_logic := '0';
   signal S3 : std_logic := '0';

 	--Outputs
   signal Z : std_logic_vector(1 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
--   constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: pr_encoder PORT MAP (
          S0 => S0,
          S1 => S1,
          S2 => S2,
          S3 => S3,
          Z => Z
        );

   -- Clock process definitions
--   <clock>_process :process
--   begin
--		<clock> <= '0';
--		wait for <clock>_period/2;
--		<clock> <= '1';
--		wait for <clock>_period/2;
--   end process;
 

    s0_waveform: process is
    begin
        S0<='0', '1' after 20ns;
        wait for 40ns;
        end process;
    
    s1_waveform: process is
    begin
        S1<='0', '1' after 40ns;
        wait for 80ns;
    end process;
    
    s2_waveform: process is
    begin
        S2<='0', '1' after 80ns;
        wait for 160ns;
    end process;
    
    s3_waveform: process is
    begin
        S3<='0', '1' after 160ns;
        wait for 320ns;
    end process;

END;
