--------------------------------------------------------------------------------
-- Company: 
-- Engineer: Kirk Vasilas
--
-- Create Date:   19:10:28 09/21/2020
-- Design Name:   
-- Module Name:   /home/kcv/Class_Work/CPE690/hw2/q1/pr_encoder/pr_encoder_tb.vhd
-- Project Name:  pr_encoder
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
 
ENTITY pr_encoder_tb IS
END pr_encoder_tb;
 
ARCHITECTURE behavior OF pr_encoder_tb IS 
 
    COMPONENT pr_encoder
    PORT(
         s0 : IN  std_logic;
         s1 : IN  std_logic;
         s2 : IN  std_logic;
         s3 : IN  std_logic;
         Z : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;
    
   --Inputs
   signal s0 : std_logic := '0';
   signal s1 : std_logic := '0';
   signal s2 : std_logic := '0';
   signal s3 : std_logic := '0';

 	--Outputs
   signal Z : std_logic_vector(1 downto 0);
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: pr_encoder PORT MAP (
          s0 => s0,
          s1 => s1,
          s2 => s2,
          s3 => s3,
          Z => Z
        );
		  s0_wave: process is
			begin
				s0<='0', '1' after 20 ns;
				wait for 40 ns;
			end process;
			s1_wave: process is
			begin
				s1<='0', '1' after 40 ns;
				wait for 80 ns;
			end process;
			s2_wave: process is
			begin
				s2<='0', '1' after 80 ns;
				wait for 160 ns;
			end process;
			s3_wave: process is
			begin
				s3<='0', '1' after 160 ns;
				wait for 320 ns;
			end process;
		  
END;
