library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
-- Generates a 16-bit signed triangle wave sequence at a sampling rate determined
-- by input clk and with a frequency of (clk*pitch)/65,536
entity tone is
Port ( clk : in STD_LOGIC; -- 48.8 kHz audio sampling clock
pitch : in UNSIGNED (13 downto 0); -- frequency (in units of 0.745 Hz)
data : out SIGNED (15 downto 0)); -- signed triangle wave out
end tone;
architecture Behavioral of tone is
signal count: unsigned (15 downto 0); -- represents current phase of waveform
signal quad: std_logic_vector (1 downto 0); -- current quadrant of phase
signal index: signed (15 downto 0); -- index into current quadrant
begin
-- This process adds "pitch" to the current phase every sampling period. Generates
-- an unsigned 16-bit sawtooth waveform. Frequency is determined by pitch. For
-- example when pitch=1, then frequency will be 0.745 Hz. When pitch=16,384, frequency
-- will be 12.2 kHz.
cnt_pr: process
begin
wait until rising_edge(clk);

count <= count + pitch;
end process;
quad <= std_logic_vector (count (15 downto 14)); -- splits count range into 4 phases
index <= signed ("00" & count (13 downto 0)); -- 14-bit index into the current phase
-- This select statement converts an unsigned 16-bit sawtooth that ranges from 65,535
-- into a signed 12-bit triangle wave that ranges from -16,383 to +16,383
with quad select
data <= index when "00", -- 1st quadrant
16383 - index when "01", -- 2nd quadrant
0 - index when "10", -- 3rd quadrant
index - 16383 when others; -- 4th quadrant
end Behavioral;
