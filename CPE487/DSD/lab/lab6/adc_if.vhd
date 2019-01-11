library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity adc_if is
 Port ( SCK: in STD_LOGIC; -- serial clock that goes to ADC
 SDATA1 : in STD_LOGIC; -- serial data channel 1
 SDATA2 : in STD_LOGIC; -- serial data channel 2
 CS: in STD_LOGIC; -- chip select that initiates A/D conversion
 data_1 : out STD_LOGIC_VECTOR(11 downto 0); -- parallel 12-bit data ch1
 data_2 : out STD_LOGIC_VECTOR(11 downto 0)); -- parallel 12-bit data ch2
end adc_if;
architecture Behavioral of adc_if is
signal pdata1, pdata2: std_logic_vector (11 downto 0); -- 12-bit shift registers
begin
 -- this process waits for CS=0 and then clocks serial data from ADC into shift register
 -- MSBit first. After 16 SCK's, four leading zeros will have fallen out of the most significant
 -- end of the shift register and the register will contain the parallel12-bit data
adpr: process
begin
wait until falling_edge (SCK);
if CS='0' then
pdata1 <= pdata1 (10 downto 0) & SDATA1;
pdata2 <= pdata2 (10 downto 0) & SDATA2;
end if;
end process;
 -- this process waits for rising edge of CS and then loads parallel data
 -- from shift register into appropriate output port
sync: process
begin
wait until rising_edge (CS);
data_1 <= pdata1;
data_2 <= pdata2;
end process;
end Behavioral;
