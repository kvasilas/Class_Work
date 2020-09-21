----------------------------------------------------------------------------------
-- Company: n/a
-- Engineer: Kirk Vasilas
-- 
-- Create Date:    22:14:24 09/13/2020 
-- Design Name: 
-- Module Name:    full_adder - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: CPE 690 Hw 1
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity full_adder is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           cin : in  STD_LOGIC;
           sum : out  STD_LOGIC;
           cout : out  STD_LOGIC);
end full_adder;

architecture gate_level of full_adder is
signal s1,s2,s3:std_logic;
begin
cout <= s2 or s3 after 2ns;
sum <= (s1 xor cin) after 2ns;
s3 <= (a and b) after 2ns;
s2 <= (cin and s1) after 2ns;
s1 <= (a xor b) after 2ns;

end gate_level;

