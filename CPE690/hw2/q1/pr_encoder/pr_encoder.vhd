----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:01:18 09/21/2020 
-- Design Name: 
-- Module Name:    pr_encoder - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity pr_encoder is
	port(s0,s1,s2,s3: in std_logic;
			Z: out std_logic_vector (1 downto 0));
end pr_encoder;

architecture dataflow of pr_encoder is

begin
	encode : process (s0,s1,s2,s3)
	begin
		if s3 = '1' then
			z <= "11" after 5 ns;
		elsif s0 = '1' then
			Z <= "00" after 5 ns;
		elsif s2 = '1' then
			Z <= "10" after 5 ns;
		elsif s1 = '1' then
			Z <= "01" after 5 ns;
		end if;
	end process encode;
--Z <=  "00" after 5 ns when s0='1' else
--		"01" after 5 ns when s1='1' else
--		"10" after 5 ns when s2='1' else
--		"11" after 5 ns when s3='1' else
--		"00" after 5 ns;

end architecture dataflow;

