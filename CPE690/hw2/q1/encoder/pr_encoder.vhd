----------------------------------------------------------------------------------
-- Company: n/a
-- Engineer: Kirk Vasilas
-- 
-- Create Date:    22:44:59 09/20/2020 
-- Design Name: 
-- Module Name:    encoder - Behavioral 
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
use IEEE.std_logic_1164.all;
entity pr_encoder is
port(S0,S1,S2,S3: in std_logic;
    Z: out std_logic_vector (1 downto 0));
end entity pr_encoder;

architecture dataflow of pr_encoder is
begin
    Z <= "00" after 5ns when S0='1' else
        "01" after 5 ns when S1='1' else
        "10" after 5 ns when S2='1' else
        "11" after 5 ns when S3='1' else
        "00" after 5ns;
end architecture dataflow;

